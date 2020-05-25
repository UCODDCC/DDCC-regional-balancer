#include <regional-balancer/handlers/connectionHandler.hpp>

extern int token, numberOfConnections;
extern std::vector<std::string> addresses;
std::string connectionHandler(const std::string& message) {
    token=(token+1)%numberOfConnections;
    LWClient client(addresses[token], DDCD_CONTAINER_ORCHESTRATOR_PORT);
    client.sendMessage(message);
    return client.listenAndExit();
}