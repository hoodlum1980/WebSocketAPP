#include "messageserver.h"

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/endpoint.hpp>

#include <QtCore>

#include <iostream>
#include <stdio.h>

#include "infothread.h"

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;


messageServer::messageServer()
{

}

messageServer::~messageServer()
{
;
}

void messageServer::on_message(websocketpp::connection_hdl hdl, message_ptr msg)
{
    this->cn = hdl;

    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    if (msg->get_payload() == "stop-listening") {
        qDebug() << "radoby stop";
        t->m_stop = true;
        t->stop();
        t->exit();
        //mes_server.stop_listening();

        return;
    }

    if (msg->get_payload() == "run")
    {
        this->runScript();
    }


    try {
        mes_server.send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (const websocketpp::lib::error_code& e) {
        std::cout << "Echo failed because: " << e
                  << "(" << e.message() << ")" << std::endl;
    }
}

void messageServer::runServer()
{
    //server mes_server;

    std::cout << "tada" << std::endl;
    try {
        // Set logging settings
        mes_server.set_access_channels(websocketpp::log::alevel::all);
        mes_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        mes_server.init_asio();

        // Register our message handler
        //error here (no matching function to call) with set message handler
        mes_server.set_message_handler(bind(&messageServer::on_message,this,::_1,::_2));

        // Listen on port 9002
        mes_server.listen(9002);

        // Start the server accept loop
        mes_server.start_accept();

        // Start the ASIO io_service run loop
        mes_server.run();
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "other exception" << std::endl;
    }
}


void messageServer::runScript()
{
    qDebug()<<"From main thread: "<<QThread::currentThreadId();
    t = new infoThread();
    t->script = "./writeToCout";

    this->connect(t, SIGNAL(sendOutput(int)), this, SLOT(sendOutputToWeb(int)), Qt::DirectConnection);
    t->start();
}


void messageServer::pokus()
{
    int old = -1;
    while(1){
        if (old != t->test){
        qDebug() << t->test;
        old = t->test;
        }

        if (t->m_stop) break;
    }

}
