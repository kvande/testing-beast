#pragma once
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http.hpp>

namespace handlers
{
using namespace std;
using tcp = boost::asio::ip::tcp;    // from <boost/asio/ip/tcp.hpp>
namespace http = boost::beast::http; // from <boost/beast/http.hpp>

struct request_demystified
{
    http::verb verb{};
    string url{};
    string body{};
    boost::system::error_code error_code; // TODO add, got it below

    request_demystified(http::verb verb, const string &&url, const string &&body, const boost::system::error_code code) : verb(verb), url(url), body(body), error_code(code) {}
};

class request_handler
{
    tcp::socket tcp_socket;

public:
    request_handler(tcp::socket &&s) : tcp_socket(std::move(s))
    {
    }

    auto parse_request()
    {
        boost::beast::flat_buffer buffer;
        boost::system::error_code error_code;
        http::request<http::string_body> req;

        http::read(tcp_socket, buffer, req, error_code);

        // for inspection
        const auto method{req.method()};
        const auto url{string{req.target()}};
        const auto body{req.body()};

        return request_demystified{method, std::move(url), std::move(body), error_code};
    }
};

} // namespace handlers