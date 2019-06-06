#pragma once
#include <boost/asio/ip/tcp.hpp>

namespace handlers {
using tcp = boost::asio::ip::tcp;    // from <boost/asio/ip/tcp.hpp>

class request_handler {
    tcp::socket socket_s;
public:
    request_handler(tcp::socket&& s) : socket_s(std::move(s)) {
    }

    

};

}