#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include "infothread.h"

#include <iostream>
#include <stdio.h>

#include <QObject>



class messageServer : public QObject
{
Q_OBJECT
public:
    messageServer();
    ~messageServer();

    infoThread* t;


    typedef websocketpp::server<websocketpp::config::asio> server;
    typedef server::message_ptr message_ptr;

    server mes_server;
    websocketpp::connection_hdl cn;

    void runServer();
    void on_message(websocketpp::connection_hdl hdl, message_ptr msg);

private:
    void runScript();

public slots:
    void sendOutputToWeb(){
        qDebug() << "prisla data: ";
        //std::cout << "kulovy";
        const std::string test = "test";
        mes_server.send(cn,test,websocketpp::frame::opcode::text);
    }

};

#endif // MESSAGESERVER_H
