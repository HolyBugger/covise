/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

#ifndef TCPTUNNEL_H
#define TCPTUNNEL_H

#define VERSION "0.8"

#define TUNNEL_HOST_OPTION 'a'
#define TUNNEL_PORT_OPTION 'k'
#define REMOTE_PORT_OPTION 'b'
#define REMOTE_HOST_OPTION 'c'
#define BUFFER_SIZE_OPTION 'e'
#define FORK_OPTION 'f'
#define LOG_OPTION 'g'
#define STAY_ALIVE_OPTION 'h'
#define HELP_OPTION 'i'
#define VERSION_OPTION 'j'

#define PATH_SEPARATOR '/'

const char *name;

int build_tunnel(void);
int connectRemote(void);
int use_tunnel(void);
int fd(void);

void set_options(int argc, char *argv[]);
void set_option(char **option, char *value);

char *get_current_timestamp(void);

void print_help(void);
void print_helpinfo(void);
void print_usage(void);
void print_version(void);
void print_missing(const char *message);

struct struct_settings
{
    unsigned int tunnel_port : 1;
    unsigned int tunnel_host : 1;
    unsigned int remote_port : 1;
    unsigned int remote_host : 1;
    unsigned int buffer_size : 1;
    unsigned int fork : 1;
    unsigned int log : 1;
    unsigned int stay_alive : 1;
};

struct struct_options
{
    char *tunnel_port;
    char *tunnel_host;
    char *remote_port;
    char *remote_host;
    unsigned int buffer_size;
};

struct struct_rc
{
    int tunnel_socket;
    int remote_socket;

    struct sockaddr_in tunnel_addr;
    struct sockaddr_in remote_addr;
    struct hostent *tunnel_host;
    struct hostent *remote_host;
};

#endif
