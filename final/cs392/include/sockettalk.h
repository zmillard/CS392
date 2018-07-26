#ifndef _SOCKETTALK_H_
#define _SOCKETTALK_H_

#include "my.h"
#include "list.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

#ifndef CLI_SOCK
#define CLI_SOCK 0
#endif

struct chat_client
{
    char *username;
    int fd;
};

void test_client2();
#endif
