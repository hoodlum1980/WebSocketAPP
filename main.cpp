#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>
#include <stdio.h>

#include <QtCore>
#include <QCoreApplication>

#include <infothread.h>
#include <messageserver.h>


//typedef websocketpp::server<websocketpp::config::asio> server;

//using websocketpp::lib::placeholders::_1;
//using websocketpp::lib::placeholders::_2;


//// pull out the type of messages sent by our config
//typedef server::message_ptr message_ptr;

//infoThread t;

//// run another script in its own thread
//void runScript(){
//    qDebug()<<"From main thread: "<<QThread::currentThreadId();
//    t.script = "./writeToCout";
//    connect( t, SIGNAL(sendOutput(char*)), this, SLOT(sendOutputToWeb(char*) ));
//    t.start();
//}

//void sendOutputToWeb(char* data)
//{

//}

//// Callback for handling incoming messages
//void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
//    std::cout << "on_message called with hdl: " << hdl.lock().get()
//              << " and message: " << msg->get_payload()
//              << std::endl;

//    if (msg->get_payload() == "stop-listening") {
//        s->stop_listening();
//        return;
//    }

//    if (msg->get_payload() == "run")
//    {
//        //run another thread for getting data
//        runScript();
//    }


//    try {
//        s->send(hdl, msg->get_payload(), msg->get_opcode());
//    } catch (const websocketpp::lib::error_code& e) {
//        std::cout << "Echo failed because: " << e
//                  << "(" << e.message() << ")" << std::endl;
//    }
//}


////runs server which handles messages
//void runServer()
//{
//    // Create a server endpoint
//    server echo_server;

//    try {
//        // Set logging settings
//        echo_server.set_access_channels(websocketpp::log::alevel::all);
//        echo_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

//        // Initialize Asio
//        echo_server.init_asio();

//        // Register our message handler
//        echo_server.set_message_handler(websocketpp::lib::bind(&on_message,&echo_server,::_1,::_2));

//        // Listen on port 9002
//        echo_server.listen(9002);

//        // Start the server accept loop
//        echo_server.start_accept();

//        // Start the ASIO io_service run loop
//        echo_server.run();
//    } catch (websocketpp::exception const & e) {
//        std::cout << e.what() << std::endl;
//    } catch (...) {
//        std::cout << "other exception" << std::endl;
//    }
//}



int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    //-------------------
    //this doesnt work
    messageServer ms;
    ms.runServer();
    //-------------------
    //runServer();
    return a.exec();
}
