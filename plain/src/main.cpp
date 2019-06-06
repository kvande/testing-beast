
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <functional>
#include "./interpreters/post_interpreter.h"
#include "./handlers/request_handler.h"

using tcp = boost::asio::ip::tcp;    // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http; // from <boost/beast/http.hpp>




// Handles an HTTP server connection
void do_session(tcp::socket &socket)
{
    using namespace std;

    cout << "Recived request" << endl;

    bool close = false;
    boost::system::error_code ec;




    // This buffer is required to persist across reads
    boost::beast::flat_buffer buffer;

    // This lambda is used to send messages
    // send_lambda<tcp::socket> lambda{socket, close, ec};

    // for (;;)
    // {
    //     // Read a request
    //     http::request<http::string_body> req;
    //     http::read(socket, buffer, req, ec);
    //     if (ec == http::error::end_of_stream)
    //         break;
    //     if (ec)
    //         return fail(ec, "read");

    //     // Send the response
    //     handle_request(doc_root, std::move(req), lambda);
    //     if (ec)
    //         return fail(ec, "write");
    //     if (close)
    //     {
    //         // This means we should close the connection, usually because
    //         // the response indicated the "Connection: close" semantic.
    //         break;
    //     }
    // }

    // Send a TCP shutdown
    socket.shutdown(tcp::socket::shutdown_send, ec);

    // At this point the connection is closed gracefully
}

int main(int argc, char *argv[])
{
    using namespace std;
    
    try
    {
        // Check command line arguments.
        if (argc != 4)
        {
            std::cerr << "Usage: http-server-sync <address> <port> <doc_root>\n"
                      << "Example:\n"
                      << "    http-server-sync 0.0.0.0 8080 .\n";
            return EXIT_FAILURE;
        }
        auto const address = boost::asio::ip::make_address(argv[1]);
        auto const port = static_cast<unsigned short>(std::atoi(argv[2]));

        cout <<"Up and running at: " << address << ":" << port << endl;
        

        // The io_context is required for all I/O
        boost::asio::io_context ioc{1};

        // The acceptor receives incoming connections
        tcp::acceptor acceptor{ioc, {address, port}};
        for (;;)
        {
            // This will receive the new connection
            tcp::socket socket{ioc};

            // Block until we get a connection
            acceptor.accept(socket);

            auto next = [](tcp::socket socket){
                
                auto a {1};
                auto b{a};
                
                //return handlers::request_handler{};
            };

            //std::thread(next());

            // Launch the session, transferring ownership of the socket
            //std::thread({std::bind(&do_session, std::move(socket))}).detach();


            std::thread{next, std::move(socket)}.detach();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}