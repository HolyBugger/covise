/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/* ----------------------------------------------------------------------------
0123456789012345678901234567890123456789012345678901234567890123456789012345678
---------------------------------------------------------------------------- */

/* ============================================================================
                                   includes
============================================================================ */

#ifndef _GETCGI_H
#define _GETCGI_H

/* ============================================================================
                                   structures
============================================================================ */

struct cgi
{
    char **cgi_variable;
    char **cgi_value;
    long cgi_count;
    char *cgi_file;
};

typedef struct cgi CGI;

/* ============================================================================
                              external Prototypes
============================================================================ */

CGI *InitCgiVars(void);
char *GetCgiVar(CGI *cgi, char *name);
void FreeCgiVars(CGI *cgi);
#endif
