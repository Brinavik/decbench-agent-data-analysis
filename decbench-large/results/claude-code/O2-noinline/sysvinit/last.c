// Function: list @ 0x3840
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Layout of a utmp record as read by last(1); offsets must match the binary. */
struct exit_status {
	short int e_termination;
	short int e_exit;
};

struct utmp {
	short int ut_type;			/* 0x00 */
	int ut_pid;				/* 0x04 */
	char ut_line[32];			/* 0x08 */
	char ut_id[4];				/* 0x28 */
	char ut_user[32];			/* 0x2c */
	char ut_host[256];			/* 0x4c */
	struct exit_status ut_exit;		/* 0x14c */
	int ut_session;				/* 0x150 */
	struct {
		int tv_sec;
		int tv_usec;
	} ut_tv;				/* 0x154 */
	int ut_addr_v6[4];			/* 0x15c */
	char __unused[20];
};

/* Kind of record being listed. */
enum {
	R_NORMAL	= 0,	/* nice logout */
	R_CRASH		= 1,	/* boot we don't know */
	R_DOWN		= 2,	/* nice shutdown */
	R_NOW		= 4,	/* still logged in */
	R_REBOOT	= 5,	/* reboot */
	R_PHANTOM	= 6,	/* no logout record, not logged in */
	R_TIMECHANGE	= 7	/* time change */
};

/* Global options set from the command line. */
extern char **show;		/* users/ttys to restrict output to */
extern int name8;		/* narrow (8) vs wide (32) fixed name column */
extern int fulltime;		/* -F: print full login/logout timestamps */
extern int useip;		/* -i: show remote host as numeric address */
extern int usedns;		/* --dns: resolve remote host */
extern int fixedwidth;		/* use fixed-width columns instead of computed */
extern int showhost;		/* show the remote host column */
extern int altlist;		/* -a: place host column last */
extern int name_len;		/* computed width of the name column */
extern int domain_len;		/* computed width of the host column */
extern int recno;		/* number of records already shown */
extern int maxrecs;		/* stop after this many records (0 = unlimited) */

extern int dns_lookup(char *result, int size, int useip, int *a);

/*
 *	Show one line of information about a login session.
 */
int list(struct utmp *p, time_t t, int what)
{
	time_t tmp, secs;
	int days, hours, mins;
	int len, r;
	char **walk;
	char *s;
	char utline[sizeof(p->ut_line) + 1];
	char logintime[32];
	char logouttime[32];
	char length[32];
	char domain[256];
	char final[512];

	/*
	 *	uucp and ftp have special-type entries.
	 */
	utline[0] = 0;
	strncat(utline, p->ut_line, sizeof(p->ut_line));
	if (strncmp(utline, "ftp", 3) == 0 && isdigit(utline[3]))
		utline[3] = 0;
	if (strncmp(utline, "uucp", 4) == 0 && isdigit(utline[4]))
		utline[4] = 0;

	/*
	 *	Is this something we want to show?
	 */
	if (show) {
		for (walk = show; *walk; walk++) {
			if (strncmp(p->ut_user, *walk, sizeof(p->ut_user)) == 0 ||
			    strcmp(utline, *walk) == 0 ||
			    (strncmp(utline, "tty", 3) == 0 &&
			     strcmp(utline + 3, *walk) == 0))
				break;
		}
		if (*walk == NULL)
			return 0;
	}

	/*
	 *	Calculate times.
	 */
	tmp = (int) p->ut_tv.tv_sec;
	strncpy(logintime, ctime(&tmp), 31);
	logintime[31] = 0;
	if (fulltime) {
		sprintf(logouttime, "- %s", ctime(&t));
	} else {
		logintime[16] = 0;
		sprintf(logouttime, "- %s", ctime(&t) + 11);
		logouttime[7] = 0;
	}

	secs  = t - (int) p->ut_tv.tv_sec;
	mins  = (secs / 60) % 60;
	hours = (secs / 3600) % 24;
	days  = secs / 86400;
	if (days)
		sprintf(length, "(%d+%02d:%02d)", days, hours, mins);
	else
		sprintf(length, " (%02d:%02d)", hours, mins);

	switch (what) {
	case R_CRASH:
		sprintf(logouttime, "- crash");
		break;
	case R_DOWN:
		sprintf(logouttime, "- down ");
		break;
	case R_NOW:
		length[0] = 0;
		if (fulltime)
			sprintf(logouttime, "  still logged in");
		else {
			sprintf(logouttime, "  still");
			sprintf(length, "logged in");
		}
		break;
	case R_PHANTOM:
		length[0] = 0;
		if (fulltime)
			sprintf(logouttime, "  gone - no logout");
		else {
			sprintf(logouttime, "   gone");
			sprintf(length, "- no logout");
		}
		break;
	case R_TIMECHANGE:
		logouttime[0] = 0;
		length[0] = 0;
		break;
	default:
		break;
	}

	/*
	 *	Look up the remote host if needed, else use ut_host as-is.
	 */
	r = -1;
	if (useip || usedns)
		r = dns_lookup(domain, sizeof(domain), useip, p->ut_addr_v6);
	if (r < 0) {
		domain[0] = 0;
		strncat(domain, p->ut_host, sizeof(domain) - 1);
	}

	if (showhost) {
		if (!altlist) {
			if (fixedwidth)
				len = snprintf(final, sizeof(final),
					name8 ?
					"%-8.8s %-12.12s %-16.16s %-16.16s %-7.7s %-12.12s\n" :
					"%-32.32s %-12.12s %-16.16s %-16.16s %-7.7s %-12.12s\n",
					p->ut_user, utline, domain,
					logintime, logouttime, length);
			else
				len = snprintf(final, sizeof(final),
					fulltime ?
					"%-8.*s %-12.12s %-16.*s %-24.24s %-26.26s %-12.12s\n" :
					"%-8.*s %-12.12s %-16.*s %-16.16s %-7.7s %-12.12s\n",
					name_len, p->ut_user, utline, domain_len, domain,
					logintime, logouttime, length);
		} else {
			if (fixedwidth)
				len = snprintf(final, sizeof(final),
					name8 ?
					"%-8.8s %-12.12s %-16.16s %-7.7s %-16.16s %s\n" :
					"%-32.32s %-12.12s %-16.16s %-7.7s %-16.16s %s\n",
					p->ut_user, utline,
					logintime, logouttime, length, domain);
			else
				len = snprintf(final, sizeof(final),
					fulltime ?
					"%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s %s\n" :
					"%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s %s\n",
					name_len, p->ut_user, utline,
					logintime, logouttime, length, domain);
		}
	} else {
		if (fixedwidth)
			len = snprintf(final, sizeof(final),
				name8 ?
				"%-8.8s %-12.12s %-16.16s %-7.7s %-12.12s\n" :
				"%-32.32s %-12.12s %-16.16s %-7.7s %-12.12s\n",
				p->ut_user, utline,
				logintime, logouttime, length);
		else
			len = snprintf(final, sizeof(final),
				fulltime ?
				"%-8.*s %-12.12s %-24.24s %-26.26s %-12.12s\n" :
				"%-8.*s %-12.12s %-16.16s %-7.7s %-12.12s\n",
				name_len, p->ut_user, utline,
				logintime, logouttime, length);
	}

	/*
	 *	Print the line, replacing anything unprintable with '*'.
	 */
	for (s = final; *s; s++) {
		if ((*s < 32 || (unsigned char) *s > 126) && *s != '\n')
			putchar('*');
		else
			putchar(*s);
	}
	if ((unsigned) len >= sizeof(final))
		putchar('\n');

	recno++;
	return maxrecs != 0 && recno >= maxrecs;
}


