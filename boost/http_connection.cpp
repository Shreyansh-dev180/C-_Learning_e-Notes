#include<iostream>
#include<boost/asio.hpp>
#include<boost/beast/core.hpp>
#include<boost/beast/http.hpp>

using namespace std;
using namespace boost::asio;

int main(){

    io_context io;

    ip::tcp::resolver resolver(io);

    auto endpoint = resolver.resolve("api.ipmyp.com", "80");

    ip::tcp::socket socket(io);

    connect(socket, endpoint);

    cout<<"Tcp connection built \n";

    //request sending

    boost::beast::http::request<boost::beast::http::string_body> request;

    //we need to get data so method get
    request.method(boost::beast::http::verb::get);

    //where to send the get request
    request.target("/json");

    //setting the host
    request.set(boost::beast::http::field::host, "api.ipmyp.com");

    request.version(11);

    boost::beast::http::write(socket, request);

    /*
        YOU
         │
         │  GET /json
         ▼
        SERVER
    */

    //buffer memory to store server response in bytes temporarily
    boost::beast::flat_buffer buffer;

    //object to hold the response
    boost::beast::http::response<boost::beast::http::string_body> response;

    /*
        buffer
           ↓
        temporary incoming data

        response
           ↓
        actual HTTP response
    */

    boost::beast::http::read(socket, buffer, response);

    //accessing the response body
    cout<<response.body()<<'\n';

    return 0;
}