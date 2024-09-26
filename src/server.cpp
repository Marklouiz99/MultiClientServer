#include"include/server.hpp"
server::server(std::string ipaddress, int portnum): IPAddress(ipaddress),PortNumber(portnum)
{

}
server::~server()
{
    Server_Close();
}
void server:: Server_Socketcreat()
{
    ServerSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ServerSocket==-1)
    {
        std::cerr<<"error in creating socket"<<std::endl;
        exit(EXIT_FAILURE);
    }

}
void server::Server_Socketbind()
{
    ServerAddress.sin_family=AF_INET;
    ServerAddress.sin_port=htons(PortNumber);
    const char* IP = IPAddress.data();
    inet_pton(AF_INET,IP,&ServerAddress.sin_addr.s_addr);
    if(bind(ServerSocket,reinterpret_cast<sockaddr*>(&ServerAddress),sizeof(ServerAddress))!=0)
    {
        std::cerr<<"error in binding socket"<<std::endl;
        Server_Close(ServerSocket);
        exit(EXIT_FAILURE);
    }

}

void server::Server_Listen()
{
    if(listen(ServerSocket, 5)!=0)
    {
        std::cerr<<"error in accepting another device as a clinet"<<std::endl;
        Server_Close(ServerSocket);
        exit(EXIT_FAILURE);
    }
}

void server::Server_Close()
{
    close(ServerSocket);

}

void server::Server_Close(int socketnum)
{
    close(ServerSocket);
}