#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

void error_handle(char *msg)
{
	perror(msg);
	exit(2);
}

int main(int argc, char **argv)
{
	int sock;
	sockaddr_in addr;
	char message[64];
	int str_len;

	if(argc != 3)
	{
		printf("usage : %s<IP> <port>\n",argv[0]);
		return 1;
	}
	sock = socket(PF_INET, SOCK_STREAM,0);
	if(sock == -1)
	{
		error_handle("socket err\n");
	}

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock,(struct sockaddr *)&addr, sizeof(addr)) == -1)
		error_handle("connect err");

	str_len = read(sock,message,sizeof(message));
	if(str_len == -1)
		error_handle("read err");
	message[str_len] = '\0';
	printf("msg from server : %s\n", message);
	close(sock);
	return 0;
}

