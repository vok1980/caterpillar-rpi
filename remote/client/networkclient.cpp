#include "networkclient.h"

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "messages/move.pb.h"

NetworkClient::NetworkClient(QObject* parent)
    : QObject(parent)
{
    m_message.set_left(0);
    m_message.set_right(0);
}

void NetworkClient::setLeft(const int& value)
{
    m_message.set_left(value);
    send();
}

void NetworkClient::setRight(const int& value)
{
    m_message.set_right(value);
    send();
}

int NetworkClient::left()
{
    return m_message.left();
}

int NetworkClient::right()
{
    return m_message.right();
}

void NetworkClient::send()
{
    std::string message;

    try {
        if (m_message.SerializeToString(&message)) {
            boost::asio::io_service ios;
            boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(m_host), m_port);
            boost::asio::ip::tcp::socket socket(ios);
            socket.connect(endpoint);
            boost::array<char, 128> buf;
            std::copy(message.begin(), message.end(), buf.begin());
            boost::system::error_code error;
            std::size_t bytes_written = socket.write_some(boost::asio::buffer(buf, message.size()), error);
            std::cerr << "Error code " << error << std::endl;
            std::cerr << "Bytes written: " << bytes_written << std::endl;
            socket.close();
        }
    } catch (std::exception ex) {
        std::cerr << ex.what() << std::endl;
    }
}
