//
// Created by Joseph Luis González Pastora on 24/8/18.
//

#include <cstdlib>
#include <iostream>
#include <thread>
#include <arpa/inet.h>
//#include <tclDecls.h>
#include "Socket.h"






ClientSocket::ClientSocket(int port, char* ip) {
    this->port = htons(port);

    this->clientSocket = socket(AF_INET,SOCK_STREAM, 0);

    this->serverAdress.sin_family = AF_INET;
    this->serverAdress.sin_port = this->port;


    serverAdress.sin_addr.s_addr = inet_addr(ip);
    connect(this->clientSocket,(struct sockaddr *)&serverAdress, sizeof(serverAdress));


}

void ClientSocket::send(json Json) {


write(this->clientSocket,Json.dump().data(),256);


}

void ClientSocket::requestMemory(int cantInt) {
    json jsonMemory = {{"opcode",0},{"size",cantInt}};
    send(jsonMemory);

}
//Retorna el id guardado en el server
int ClientSocket::saveValue(int value) {
    json saveValueJson = {{"opcode",1},{"Data",value}};
    send(saveValueJson);
    bzero(this->buffer, sizeof(buffer));
    read(this->clientSocket,buffer,256);
    std::string bufferString(buffer);
    json jsonValue;
    bool complete = false;
    while (!complete) {

        try {

            jsonValue = json::parse(bufferString);
            complete = true;
        } catch (...) {}

    }

    return jsonValue["ID"];
}
//Retorna vlaor en el server
int ClientSocket::getValue(int id) {
    json idJson = {{"opcode", 2},
                   {"id",   id}};
    send(idJson);
    bzero(this->buffer, sizeof(buffer));
    read(this->clientSocket, buffer, 256);
    std::string bufferString(buffer);
    bool complete = false;
    json jsonValue;
    while (!complete) {

        try {

            jsonValue = json::parse(bufferString);
            complete = true;
        } catch (...) {}

    }
    return jsonValue["Data"];
}

void ClientSocket::changeValue(int id, int value) {
    json change = {{"opcode",3},{"id", id},{"Data",value}};
    send(change);

}

void ClientSocket::removeValue(int id) {
    json remove = {{"opcode",4},{"id",id}};
    send(remove);

}
