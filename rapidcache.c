#include "rapidcache.h"

bool scontinuation; // server continuation
bool ccontinuation; // client/child continuation

void zero(int8* buf, int16 size) {
	int8* p;
	int16 n;
	for(n=0, p=buf; n<size; n++, p++) {
		*p = 0;
	}
	return ;
}

void childloop(Client* cli) {
	sleep(1);
	return;
}

void mainloop(int s) {
	struct sockaddr_in cli;
	int16 len;
	int s2;
	char *ip;
	int16 port;
	Client *client;
	pid_t pid;

	s2 = accept(s, (struct sockaddr *)&cli, (unsigned int *)&len);
	if(s2 < 0) {
		sleep(1);
		return;
	}

	port = (int16)htons((int)cli.sin_port);
	ip = inet_ntoa(cli.sin_addr);

	printf("Connection from %s:%d\n", ip, port);

	client = (Client *)malloc(sizeof(struct s_client));
	assert(client);

	zero((int8 *)client, sizeof(struct s_client));
	client -> s = s;
	client -> port = port;

	strncpy(client-> ip, ip, 15);

	pid = fork();
	if(pid){
		free(client);
		return;
	}
	else {
		dprintf(s2, "100 connected to rapidchache server\n");
		ccontinuation = true;
		while(ccontinuation) {
			childloop(client);
		}
		close(s2);
		free(client);
		return;
	}
	return;
}


int initserver(int16 port) {
	struct sockaddr_in sock;
	int s;
	
	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	sock.sin_addr.s_addr = inet_addr(HOST);

	s = socket(AF_INET, SOCK_STREAM, 0);
	assert(s > 0);
	
	errno = 0;
	if (bind(s, (struct sockaddr * )&sock, sizeof(sock))) 
		assert_perror(errno);

	errno = 0;
	if (listen(s, 20))
		assert_perror(errno);

	printf("Server listening on %s:%d \n", HOST, port);
	return s;
}

int main(int argc, char *argv[]) {
	char *sport;
	int16 port;
	int s;
	if (argc < 2) 
		sport = PORT;
	else 
		sport = argv[1];

	port = (int16)atoi(sport);

	scontinuation= true;

	s = initserver(port);
	while(scontinuation) {
		mainloop(s);
	}
	return 0;
}
