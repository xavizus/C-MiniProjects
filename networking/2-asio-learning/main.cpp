//
// Created by stephan-jobb on 2020-08-05.
//

#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>

using asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    try {
        // Creates io_context object
        asio::io_context ioContext;
        //Create an acceptor object
        tcp::acceptor acceptor(ioContext, tcp::endpoint(tcp::v4(), 1337));

        // Handles one connection at a time.
        for(;;) {
            // Create a socket
            tcp::socket socket(ioContext);
            // accepts socket
            acceptor.accept(socket);
            // Generate string
            std::string message = make_daytime_string();
            // Some kind of error handler?
            asio::error_code ignored_error;
            // write to socket.
            asio::write(socket, asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}