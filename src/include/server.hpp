#include<iostream>
#include<vector>
#include<netinet/in.h>
#include<sys/socket.h>
#include<cstring>
#include<unistd.h>
#include<arpa/inet.h>
#include<cstdlib>
class server
{
    private:
        int PortNumber;
        int ServerSocket;
        sockaddr_in ServerAddress;
        std::string IPAddress;
    public:
        server(std::string ipaddress, int portnum);
        ~server();
        void Server_Socketcreat();
        void Server_Socketbind();
        void Server_Listen();
        void Server_accept();
        void Server_Close();
        void Server_Close(int socketnum);


};