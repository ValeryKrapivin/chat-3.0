#include "ChatServer.hpp"

ChatServer :: ChatServer(boost ::asio ::io_context & io_context , short port)
       : acceptor_(io_context , tcp ::endpoint(tcp ::v4() , port)) {
       start_accept();
}

void ChatServer :: start_accept() {
       acceptor_.async_accept([this](boost ::system :: error_code ec , tcp ::socket socket){
           if (!ec){
               std :: make_shared<Session>(std :: move(socket))->start();
           }
           start_accept();
       });
}
