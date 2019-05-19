
#include <arpa/inet.h>
#include <udt.h>
#include <iostream>

#include "Socket.h"

using namespace plnet;
using namespace std;

#define BUF_SIZE 128

int main(int argc, char* argv[])
{
    byte_t buf[BUF_SIZE];

    Socket socket;
    Socket::create(AF_INET, SOCK_DGRAM, &socket);
    socket.bind(INetAddress("0.0.0.0", 9000));

    socket.recvmsg(buf, BUF_SIZE);

    
    socket.listen(10);

    int namelen;
    sockaddr_in their_addr;

    socket.accept((sockaddr*)&their_addr, &namelen);

    UDTSOCKET serv = UDT::socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = 9000;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero), '\0', 8);

    if (UDT::ERROR == UDT::bind(serv, (sockaddr*)&my_addr, sizeof(my_addr)))
{
  cout << "bind: " << UDT::getlasterror().getErrorMessage();
  return 0;
}

UDT::listen(serv, 10);



UDTSOCKET recver = UDT::accept(serv, (sockaddr*)&their_addr, &namelen);

char ip[16];
cout << "new connection: " << inet_ntoa(their_addr.sin_addr) << ":" << ntohs(their_addr.sin_port) << endl;

char data[100];

if (UDT::ERROR == UDT::recv(recver, data, 100, 0))
{
  cout << "recv:" << UDT::getlasterror().getErrorMessage() << endl;
  return 0;
}

cout << data << endl;

UDT::close(recver);
UDT::close(serv);

    return 0;
}