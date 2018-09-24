//
// Created by Joseph Luis González Pastora on 24/8/18.
//

#include <cstdlib>
#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include "Socket.h"


ServerSocket* ServerSocket::serverSocketInstancePTR = nullptr;

void ServerSocket::error(char *error) {
    perror(error);
    exit(1);


}

ServerSocket * ServerSocket::getInstance() {
    if (ServerSocket::serverSocketInstancePTR == nullptr){
        ServerSocket::serverSocketInstancePTR = new ServerSocket();
    }
    return ServerSocket::serverSocketInstancePTR;

}


ServerSocket::ServerSocket() {
    //Crea un socket de tipo AF_INET, con un stream de datos
    this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
    //bzero((char *)&serverSocket, sizeof(serverSocket));
    this->portNumber = atoi("5555");
    //Asigna variables del socket y el tipo
    this->serverAdress.sin_family = AF_INET;
    this->serverAdress.sin_addr.s_addr = INADDR_ANY;
    this->serverAdress.sin_port = htons(this->portNumber);
    //Relaciona el socket con un puerto en la tarjeta de red de la computadora
    bind(serverSocket,(struct sockaddr*)&serverAdress, sizeof(serverAdress));





//Acepta el cliente,
    listen(serverSocket,5);
    this->clientLenght = sizeof(this->clientAdress);
    this->client = accept(this->serverSocket,(struct sockaddr*)&clientAdress,&clientLenght);
    std::cout<< this->clientAdress.sin_port<< std::endl;
//Recibe un mensaje del cliente
    /*read(this->client,buffer, sizeof(buffer));
    printf("%s\n",buffer);

    std::string bufferString(buffer);
    std::cout<< bufferString << std::endl;*/
    //std::thread listeningClients(&ServerSocket::listenClient);
    //listeningClients.join();



}


std::string ServerSocket::readClient() {

    bzero(buffer, sizeof(buffer));
    read(this->client,buffer, sizeof(buffer));


    std::string bufferToString(buffer);
    return bufferToString;



}

void ServerSocket::listenClient() {
    std::string clientRequest = readClient();
    auto jsonClient = json::parse(clientRequest).array();

    //
    if (jsonClient["opcode"] == 0){
        requestMemory(jsonClient["size"]);


    }else if (jsonClient["opcode"] == 1){

    }





    return;




}

void ServerSocket::requestMemory(ssize_t size) {
    this->memoryBlock = malloc(size);


}

ClientSocket::ClientSocket(int port, char* ip) {
    this->port = htons(port);

    this->clientSocket = socket(AF_INET,SOCK_STREAM, 0);

    this->serverAdress.sin_family = AF_INET;
    this->serverAdress.sin_port = this->port;


    serverAdress.sin_addr.s_addr = inet_addr(ip);
    connect(this->clientSocket,(struct sockaddr *)&serverAdress, sizeof(serverAdress));

}
