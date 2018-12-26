//
// Created by oriya on 12/19/18.
//

#include "OpenDataServerCommand.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <netinet/in.h>

pthread_mutex_t lock;
struct thread_data {
    int port;
    int hrz;
    int new_sock;
    int socket;
};

OpenDataServerCommand::OpenDataServerCommand(int port, int hrz) {
    this->port = port;
    this->hrz = hrz;
}

double OpenDataServerCommand::doCommand() {
    pthread_t thread;
    int rc;

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    listen(server_fd, 5);

    if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                             (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    thread_data *my_thread_data = new thread_data();
    my_thread_data->port = this->port;
    my_thread_data->hrz = this->hrz;
    my_thread_data->new_sock = new_socket;
    my_thread_data->socket = server_fd;
    rc = pthread_create(&thread, nullptr, runServer, my_thread_data);
    if (rc) {
        cout << "Error! unable to create thread";
        exit(1);
    }
}

void OpenDataServerCommand::setInTable(string buffer) {
    string number;
    int counter = 0;
    for (int i = 0; i < buffer.size(); ++i) {
        if (buffer.at(i) == ',') {
            double n = stod(number);
            data.setVarInIndex(counter, n);
            number = "";
            counter++;
            continue;
        }
        number += buffer.at(i);
    }
}

void *runServer(void *s) {
    struct thread_data *my_data;
    my_data = (thread_data *) s;
    int port = my_data->port;
    int hrz = my_data->hrz;
    int new_socket = my_data->new_sock;
    char buffer[5000];
    OpenDataServerCommand op = OpenDataServerCommand(port, hrz);
    while (true) {
        ssize_t erez = 0;
        const char *g = buffer;
        string str(g);
        while (erez >= 0) {
            pthread_mutex_lock(&lock);
            erez = read(new_socket, buffer, 5000);
            op.setInTable(str);
            printf("%s\n", buffer);
            pthread_mutex_unlock(&lock);
        }
        sleep((unsigned int) 1 / hrz);
    }
    close(my_data->socket);
}


