#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
	int sock;
	int client_addr_size;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char buff_rcv[BUFF_SIZE];
	char buff_snd[BUFF_SIZE];

	sock = socket(PF_INET, SOCK_DGRAM,0);
	if(sock == -1)
	{
		printf("socket err\n");
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(20005);

	if(bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("bind  err\n");
		exit(1);
	}
	while(1)
	{
		client_addr_size = sizeof(client_addr);
		recvfrom(sock, buff_rcv, BUFF_SIZE, 0,
				(struct sockaddr*)&client_addr, &client_addr_size);
		printf("receive : %s\n", buff_rcv);
		sprintf(buff_snd, "%s%s\n", buff_rcv, buff_rcv);
		sendto(sock,buff_snd, strlen(buff_snd)+1, 0,
				(struct sockaddr*)&client_addr,sizeof(client_addr));
	}
	
	return 0;
}

