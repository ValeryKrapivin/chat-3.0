#include "ChatClient.hpp"

ChatClient: : ChatClient(const string & host ,const string & port)
      : resolver_(io_context_), socket_(io_context_) {

      connect(host ,port);
}

void ChatClient: : send_message(const string & message){
      boost: asio: write(socket_, boost: asio: buffer(message));

      char reply[1024];
      size_t reply_length = boost: asio: read(socket_, boost: asio: buffer(reply));

      cout << "Reply: ";
      cout.write(reply ,reply_length);
      cout << "\n";
}

void ChatClient: : connect(const string & host ,const string & port){
      tcp: resolver resolver(io_context_);
      auto endpoints = resolver.resolve(host ,port);

      boost: asio: connect(socket_ ,endpoints);
}
