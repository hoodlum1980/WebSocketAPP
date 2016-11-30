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

    infoThread* t[4];


    typedef websocketpp::server<websocketpp::config::asio> server;
    typedef server::message_ptr message_ptr;

    server mes_server;
    websocketpp::connection_hdl cn;

    void runServer();
    void on_message(websocketpp::connection_hdl hdl, message_ptr msg);

private:
    void runScript(int number);

public slots:
    void sendOutputToWeb(char* data, int idx_th){
        qDebug() << "prisla data: "<<data;
        std::stringstream ss;
        ss << data << "/" << idx_th;
        std::string output = ss.str();
        mes_server.send(cn,output,websocketpp::frame::opcode::text);
    }

};

#endif // MESSAGESERVER_H
