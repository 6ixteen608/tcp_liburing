#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "server.h"

string port_num;

void on_connection_established(UringChannel *channel) {
    cout << "connection from client " << channel->client_address() << " established\n";
}

void on_message(UringChannel *channel) {
    string line = string{channel->buffer_head_line_view()};
    ofstream requests;
    requests.open(port_num.c_str(), ios::app);
    requests << "received from client :" << channel->client_address() << " : ";
    requests << line << "\n";
    channel->send(line);
}

void on_connection_closed(UringChannel *channel) {
    cout << "connection from client " << channel->client_address() << " closed\n";
}

int main(int argc, char *argv[]) {
    port_num=argv[1];
    int port = strtol(argv[1], NULL, 10);
    UringServer server{port};
    port_num += ".txt";
    ofstream createFile;
    createFile.open(port_num.c_str());
    server.connection_callback = on_connection_established;
    server.message_callback = on_message;
    server.connection_closed_callback = on_connection_closed;
    server.start();

}
