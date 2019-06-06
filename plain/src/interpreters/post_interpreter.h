#pragma once
#include <algorithm>
#include <string>
#include <boost/spirit/home/x3.hpp>
#include <boost/beast/core.hpp>

namespace interpreters {
    using namespace std;
    using namespace std::string_literals;

    class post_interpreter {
    
        string request;
        boost::beast::string_view r;
    
    public:

        // PostInterpreter(const string& request) : request(request) {}
        post_interpreter(const boost::beast::string_view& request) : r(request) {}

        std::string interpret() {

            // TODO: trenger request body
            return "not started"s;
        } 


    };

}


// #include <iostream>
// #include <boost/spirit/home/qi.hpp>
// #include <boost/spirit/home/x3.hpp>
// #include <string>

// namespace x3 = boost::spirit::x3;

// int main()
// {
//     using namespace std;
//     using namespace literals::string_literals;
//     using namespace boost::spirit::x3;
//     auto input{std::string("Arnstein")};

//     auto iter = input.begin();
//     auto end_iter = input.end();

//     auto output{0};

//     if (parse(iter, end_iter, int_, output))
//     {
//         cout << "Jippi ! " << output << endl;
//     }
//     else
//     {
//         cout << "Uff da!" << endl;
//     }

//     cin.get();

//     return 0;
// }
