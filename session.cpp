#include "Session.hpp"
#include <iostream>

Session::Session(tcp::socket socket)
        : socket_(std::move(socket)) {}

void Session::start() {
     do_read();
}

void Session::do_read() {
     auto self(shared_from_this());
     socket_.async_read_some(boost::asio::buffer(data_),
         [this,self](boost::system::error_code ec,std::size_t length){
             if (!ec){
                 handle_request(std::string(data_, length));
                 do_read();
             }
         });
}

void Session::handle_request(const std::string& request) {
     // Пример обработки запроса: регистрация или авторизация
     // Здесь вы можете добавить логику для работы с SQLite
     
     // Пример регистрации пользователя
     if (request.substr(0 ,9 ) == "REGISTER ") { 
         auto parts = split(request.substr(9), ' ');
         if(parts.size() == 2 && db_.register_user(parts[0], parts[1])) {
             do_write("Registration successful\n");
         } else {
             do_write("Registration failed\n");
         }
     }
     
     // Пример авторизации пользователя
     else if(request.substr(0 ,8 ) == "LOGIN ") { 
         auto parts = split(request.substr(8), ' ');
         if(parts.size() == 2 && db_.authenticate_user(parts[0], parts[1])) {
             do_write("Login successful\n");
         } else {
             do_write("Login failed\n");
         }
     }
     
     // Пример отправки сообщения
     else if(request.substr(0 ,7 ) == "MESSAGE ") { 
         auto parts = split(request.substr(7), ' ');
         if(parts.size() >= 2){
             save_message(parts[0], parts[1], request.substr(7 + parts[0].length() + parts[1].length() + 2));
             do_write("Message sent\n");
         } else{
             do_write("Invalid message format\n");
         }
     }
}

void Session ::do_write(const std :: string & response){
      auto self(shared_from_this());
      boost :: asio :: async_write(socket_, boost :: asio :: buffer(response),
          [this,self](boost :: system :: error_code ec,std :: size_t /*length*/){});
}
