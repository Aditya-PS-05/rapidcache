#ifndef RAPIDCACHE
#define RAPIDCACHE

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdarg.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT		"12049"
#define HOST		"127.0.0.1"
#define log(x, args...) \
	printf(x , args)

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;

struct s_client {
	int s;
	char ip[16];
	int16 port;
};

typedef struct s_client Client;

void zero(int8*, int16);
void childloop(Client* );
void mainloop(int);
int initserver(int16);
int main(int, char**);

#endif
