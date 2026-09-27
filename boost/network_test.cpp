#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main()
{
    io_context io;

    ip::tcp::resolver resolver(io);

    auto endpoints = resolver.resolve("api.binance.com", "443");

    ip::tcp::socket socket(io);

    connect(socket, endpoints);

    cout << "Connected to server!\n";

    return 0;
}