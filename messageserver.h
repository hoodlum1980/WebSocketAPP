#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <infothread.h>

#include <iostream>

#include <QObject>




class messageServer : public QObject
{
public:
    messageServer();

    infoThread* t;


    typedef websocketpp::server<websocketpp::config::asio> server;
    typedef server::message_ptr message_ptr;

    server mes_server;

    void runServer();
    void on_message(websocketpp::connection_hdl hdl, message_ptr msg);

private:
    void runScript();

private slots:
    void sendOutputToWeb(char* data);

};

#endif // MESSAGESERVER_H
