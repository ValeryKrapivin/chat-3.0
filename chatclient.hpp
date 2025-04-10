#ifndef CHATCLIENT_HPP
#define CHATCLIENT_HPP

#include <boost/asio.hpp>
#include <iostream>

using boost : :asio : :ip : :tcp;

class ChatClient{
public:
   ChatClient(const std : : string & host , const std : : string & port);

   void send_message(const std : : string & message);

private:
   void connect(const std : : string & host , const std : : string & port);

private:
   boost : :asio : :io_context io_context_;
   tcp : :socket socket_;
};

#endif // CHATCLIENT_HPP
