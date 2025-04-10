#include <iostream>
#include "ChatClient.hpp"

int main(int argc ,char * argv[]) {
   try{
       ChatClient client("127.0.0.1" ,"12345");

       client.send_message("REGISTER user password"); // Регистрация пользователя 
       client.send_message("LOGIN user password"); // Авторизация пользователя 
       client.send_message("MESSAGE user Hello!"); // Отправка сообщения 

   } catch(std exception & e){
       cerr << "Exception: "<< e.what()<<"\n";
   }
}
