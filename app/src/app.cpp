#include <signal.h>
#include <thread>
#include <vector>

#include <lwcpps>
#include <regional-balancer/handlers/connectionHandler.hpp>
#include <regional-balancer/configuration.hpp>

LWServer server(connectionHandler, DDCD_REGIONAL_BALANCER_PORT);


std::vector<std::string> addresses = {"10.10.1.1"};

int numberOfConnections = 1;
int token = 0;

void sigHandler(int signum);


int main() {
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);
    signal(SIGABRT, sigHandler);
    while (true) server.handleNextConnection();
}

void sigHandler (int signum){
    server.exit();
}