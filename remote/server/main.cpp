#include <iostream>
#include <list>

#include <boost/asio.hpp>

#include "messages/move.pb.h"

using boost::asio::ip::tcp;

class session
    : public std::enable_shared_from_this<session> {
public:
    session(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    void start()
    {
        do_read();
    }

private:
    void do_read()
    {
        auto self(shared_from_this());
        socket_.async_read_some(
            boost::asio::buffer(data_),
            [this, self](const boost::system::error_code& ec, std::size_t bytes_transferred) {
                if (!ec) {
                    std::cerr << "bytes_transferred = " << bytes_transferred << std::endl;
                    Move message;
                    message.ParseFromArray(data_.data(), bytes_transferred);
                    std::cout << message.left() << std::endl;
                    std::cout << message.right() << std::endl;
                }
            });
    }

    // The socket used to communicate with the client.
    tcp::socket socket_;

    // Buffer used to store data received from the client.
    std::array<char, 1024> data_;
};

class server {
public:
    server(boost::asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
    {
        do_accept();
    }

private:
    void do_accept()
    {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<session>(std::move(socket))->start();
                }

                do_accept();
            });
    }

    tcp::acceptor acceptor_;
};

int main(int argc, char* argv[])
{
    try {
        if (argc < 2) {
            std::cerr << "Usage: server <port>" << std::endl;
            return 1;
        }

        boost::asio::io_context io_context;
        server s(io_context, std::atoi(argv[1]));
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
