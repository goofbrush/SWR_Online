#ifndef CLIENT_H
#define CLIENT_H

#include<chrono>
#include "ASIO-Networker/olc_net.h"

enum class CustomMsgTypes : uint32_t {
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
};


class customClient : public olc::net::client_interface<CustomMsgTypes> {

public:
    ~customClient() {  }

//    void start() {
////        mainThread{&customClient::start2,this}.detach();
//        mainThread(&customClient::start2,this);
////        std::thread inp(&customClient::start2, this);
////        inp.join();
//    }
//    std::thread thrContext;
    void start() {
        connected = false;
//        thrContext = std::thread([this] { start2().start(); });
        std::thread( [this] { this->start2(); } ).detach();
    }

    void start2() {

        while (!stopThread) {

            if (IsConnected()) {
                if (!Incoming().empty()) {
                    auto msg = Incoming().pop_front().msg;

                    switch (msg.header.id) {
                        case CustomMsgTypes::ServerAccept: {
                            // Server has responded to a ping request
                            connected = true;
                            std::cout << "Server Accepted Connection\n";
                        } break;

                        case CustomMsgTypes::ServerPing: {
                            // Server has responded to a ping request
                            std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();
                            std::chrono::system_clock::time_point timeThen;
                            msg >> timeThen;
                            std::cout << "Ping: " << std::chrono::duration<double>(timeNow - timeThen).count() << "\n";
                        } break;

                        case CustomMsgTypes::ServerMessage: {
                            // Server has responded to a ping request
                            uint32_t clientID;
                            msg >> clientID;
                            std::cout << "Hello from [" << clientID << "]\n";
                        } break;

                        default: {} break;
                    }
                }
            }
            else {
                std::cout << "Server Down" << std::endl;
                connected = false;
                return;
            }
        }
        std::cout << "safe ?" <<std::endl;
        threadStopped = true;
    }

    bool blockUntilConnect(int timeWait = 5) {
        auto start = std::chrono::steady_clock::now();
        while(!connected) {
            if(std::chrono::steady_clock::now() - start > std::chrono::seconds(timeWait)) {
                return false;
            }
        }
        return true;
    }
    bool isConnected() { return connected; }

//    void close() { running = false; }
    bool connected = false;
    void test() { std::cout << "yooo"; }

    bool stopThread = false;
    bool threadStopped = false;
private:
//    bool canDisconnect = false;

    void pingServer() {
        olc::net::message<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::ServerPing;
        std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();
        msg << timeNow;
        Send(msg);
    }

    void messageAll() {
        olc::net::message<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::MessageAll;
        Send(msg);
    }

protected:
    virtual void onUserDisconnect() {}
};

#endif // CLIENT_H
