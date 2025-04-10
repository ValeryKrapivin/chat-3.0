#ifndef CHATSERVER_HPP
#define CHATSERVER_HPP

#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include "Session.hpp"

using boost ::asio ::ip ::tcp;

class ChatServer {
public:
   ChatServer(boost ::asio ::io_context & io_context , short port);

private:
   void start_accept();

private:
   tcp ::acceptor acceptor_;
};

#endif // CHATSERVER_HPP
