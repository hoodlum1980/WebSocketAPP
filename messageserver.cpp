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

    if (msg->get_payload() == "stop_1") {
        qDebug() << "Stopping thread.";
        t[0]->m_stop = true;
        t[0]->stop();
        t[0]->exit();
        //mes_server.stop_listening();
        return;
    }
    else if (msg->get_payload() == "stop_2")
    {
        qDebug() << "Stopping thread.";
        t[1]->m_stop = true;
        t[1]->stop();
        t[1]->exit();
        return;
    }
    else if (msg->get_payload() == "stop_3")
    {
        qDebug() << "Stopping thread.";
        t[2]->m_stop = true;
        t[2]->stop();
        t[2]->exit();
        return;
    }
    else if (msg->get_payload() == "stop_4")
    {
        qDebug() << "Stopping thread.";
        t[3]->m_stop = true;
        t[3]->stop();
        t[3]->exit();
        return;
    }

    if (msg->get_payload() == "run_1")
    {
        this->runScript(1);
        return;
    }
    else if(msg->get_payload() == "run_2")
    {
        this->runScript(2);
        return;
    }
    else if(msg->get_payload() == "run_3")
    {
        this->runScript(3);
        return;
    }
    else if(msg->get_payload() == "run_4")
    {
        this->runScript(4);
        return;
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

    std::cout << "Server running" << std::endl;
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


void messageServer::runScript(int number)
{
    qDebug()<<"From main thread: "<<QThread::currentThreadId();
    t[number-1] = new infoThread();
    t[number-1]->idx = number;
    t[number-1]->script = "./writeToCout";
    this->connect(t[number-1], SIGNAL(sendOutput(char*, int)), this, SLOT(sendOutputToWeb(char*, int)), Qt::DirectConnection);
    t[number-1]->start();


//    switch (number) {
//    case 1:
//        qDebug()<<"From main thread: "<<QThread::currentThreadId();
//        t[0] = new infoThread();
//        t->script = "./writeToCout";
//        this->connect(t, SIGNAL(sendOutput(char*)), this, SLOT(sendOutputToWeb(char*)), Qt::DirectConnection);
//        t->start();
//        break;
//    case 2:
//        qDebug()<<"From main thread: "<<QThread::currentThreadId();
//        t[1] = new infoThread();
//        t->script = "./writeToCout";
//        this->connect(t, SIGNAL(sendOutput(char*)), this, SLOT(sendOutputToWeb(char*)), Qt::DirectConnection);
//        t->start();
//        break;
//    case 3:
//        qDebug()<<"From main thread: "<<QThread::currentThreadId();
//        t[2] = new infoThread();
//        t->script = "./writeToCout";
//        this->connect(t, SIGNAL(sendOutput(char*)), this, SLOT(sendOutputToWeb(char*)), Qt::DirectConnection);
//        t->start();
//        break;
//    case 4:
//        qDebug()<<"From main thread: "<<QThread::currentThreadId();
//        t[] = new infoThread();
//        t->script = "./writeToCout";
//        this->connect(t, SIGNAL(sendOutput(char*)), this, SLOT(sendOutputToWeb(char*)), Qt::DirectConnection);
//        t->start();
//        break;
//    default:
//        break;
//    }


}
