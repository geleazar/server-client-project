//Code for simple iterative server
//geleazar v1.0
#include <iostream>
#include <cstring>
#include <string>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 800813
#define MAXSIZ 1048576
using namespace std;



int main(int argc, char *argv[])
{
	char data[1025]; //packet
	int listenSock, connectSock, len, n;
	struct sockaddr_in serverAddr;
	
	listenSock = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serverAddr, 0, sizeof(serverAddr));
	memset(data, '0', sizeof(data));

	serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(listenSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
	listen(listenSock, 5);

	while(1)
	{
		cout << "Initializing...\n";
		connectSock = accept(listenSock, NULL, NULL);
		snprintf(data, sizeof(data), "hewwo\n");
		write(connectSock, data, strlen(data));
		close(connectSock);
	}
	return 0;
}
