#include <iostream>
#include <boost/asio.hpp>
#include "ChatServer.hpp"

int main(int argc , char * argv[]) {
   try{
       boost ::asio ::io_context io_context;
       ChatServer server(io_context ,12345);
       io_context.run();
   } catch(std :: exception & e){
       std :: cerr << "Exception: " << e.what() << "\n";
   }
}
