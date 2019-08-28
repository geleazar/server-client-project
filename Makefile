all: client server
client: myClient.cpp
	g++ myClient.cpp -o client
server: myServer.cpp
	g++ myServer.cpp -o server
