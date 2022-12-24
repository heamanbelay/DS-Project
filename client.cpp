#include<sys/type> //this header file defines a collection of typedef symbols and structures
#include<unistd>  //this header defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include<stdio>  //this header file which has the necessary information to include the input/output related functions in our program
#include<string> //we should use the string header. Write #include <string> at the top of your file. When you declare a variable, the type is string
#include<stdlib> //this includes functions involving memory allocation, process control, conversions and others.
#include<signal> 
#include<sys/socket>
#include<sys/un>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#using namespace std;

using namespace std;
    #define SIM_LENGTH 10
    #define PORT 1227

int main (){
int sock;
int count;
int value;
    
 //the variables below are needed to store the ip address and the hostname of a client
int status; 
struct addrinfo hints, *p; 
struct addrinfo *servinfo; 
char ipstr[INET_ADDRSTRLEN];
char hostname[128];
   
  cin>>hostname[128];//this takes in a hostname and resolve it 
    
  //this is to check for hostname and ip address and if it fails this message will be displayed
if ((status = getaddrinfo(hostname, NULL, &hints, &servinfo)) == -1) { 
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status)); 
    exit(1); 
}    
  //this code is used to fetch the ipv4 and ipv6 address of the connected client
  for (p=servinfo; p!=NULL; p=p->ai_next) { 
    struct in_addr  *addr;  
    if (p->ai_family == AF_INET) { 
        struct sockaddr_in *ipv = (struct sockaddr_in *)p->ai_addr; 
        addr = &(ipv->sin_addr);  
    } 
    else { 
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr; 
        addr = (struct in_addr *) &(ipv6->sin6_addr); 
    }
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr); 
  
} 
    
  cout<<"Client is alive and establishing socket connection.";
     
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        perror ("Error opening channel");
         close(sock);
          exit(1);
    }
    bzero(&cli_name, sizeof(hostname));
    cli_name.sin_family = AF_INET;
    cli_name.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    cli_name.sin_port = htons(PORT);
    
     if (connect(sock,hostname, sizeof(hostname)) < 0)
    { perror ("Error established communications");
      close(sock);
      exit(1);
    }
     for (count = 1; count <= SIM_LENGTH; count++) {
         read(sock, &value, 4); //The read() function reads data that is previously written to a file
      cout<<"Client has received from socket" + value;
         
           cout<<"currently terminating ";

  close(sock);
  exit(0);
    }
return 0;
}
  




