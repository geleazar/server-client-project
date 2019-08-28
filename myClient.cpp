//Code for a simple iterative client
//geleazar v1.0
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 800813
using namespace std;

int main(){

	int newSock = 0, n = 0;
	char data[1024];
	struct sockaddr_in serverIP;
	
	memset(data, '0', sizeof(data));
	
	if((newSock = socket(AF_INET, SOCK_STREAM,0)) < 0)
	{
		cout << "Socket not created \n";
		return 1;
	}
	
	serverIP.sin_family = AF_INET;
	serverIP.sin_port = htons(PORT);
	serverIP.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(connect(newSock, (struct sockaddr *) &serverIP, sizeof(serverIP)) < 0)
	{
		cout << "Connection failed\n";
		return 1;
	}  
	
	while((n = read(newSock, data, sizeof(data) - 1)) > 0)
	{
		data[n] = 0;
		cout << data << "\n";
	}
	close(newSock);
	return 0;
}
