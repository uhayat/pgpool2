/* -*-pgsql-c-*- */
/*
 *
 * $Header$
 *
 * pgpool: a language independent connection pool server for PostgreSQL
 * written by Tatsuo Ishii
 *
 * Copyright (c) 2003-2017	PgPool Global Development Group
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of the
 * author not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission. The author makes no representations about the
 * suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * pool_passwd.h: pool_passwd related definitions.
 *
 */

#ifndef POOL_HBA_H
#define POOL_HBA_H

#include "parser/pg_list.h"
#include "pool.h"

/* UserAuth type used for HBA which indicates the authentication method */
typedef enum UserAuth
{
	uaImplicitReject,
	uaReject,
	/*  uaKrb4, */
	/*  uaKrb5, */
	uaTrust,
	/*  uaIdent, */
	/*  uaPassword, */
	/*  uaCrypt, */
	uaMD5,
	uaSCRAM
#ifdef USE_PAM
	,uaPAM
#endif /* USE_PAM */
}
UserAuth;

typedef enum ConnType
{
	ctLocal,
	ctHost,
	ctHostSSL,
	ctHostNoSSL
} ConnType;

typedef enum IPCompareMethod
{
	ipCmpMask,
	ipCmpSameHost,
	ipCmpSameNet,
	ipCmpAll
} IPCompareMethod;

struct HbaLine
{
	int         linenumber;
	char       *rawline;
	ConnType    conntype;
	List       *databases;
	List       *users;
	struct sockaddr_storage addr;
	struct sockaddr_storage mask;
	IPCompareMethod ip_cmp_method;
	char       *hostname;
	UserAuth    auth_method;
	char		*pamservice;
	bool		pam_use_hostname;
};

extern bool load_hba(char *hbapath);
extern void ClientAuthentication(POOL_CONNECTION *frontend);

#endif /* POOL_HBA_H */
