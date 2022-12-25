#include<sys/type> //The sys/types is a header file defines a collection of typedef symbols and structures. 
#include<unistd>  //The unistd is a header defines miscellaneous symbolic constants and types, and declares miscellaneous functions. 
#include<stdio> //The stdio is a header file which has the necessary information to include the input/output related functions in our program.
#include<string>  //The string is a header which defines one variable type, one macro, and various functions for manipulating arrays of characters.
#include<stdlib> //The stdlib header defines four variable types, several macros, and various functions for performing general functions.
#include<signal> //The signal header defines a variable type sig_atomic_t, two function calls, and several macros to handle different signals reported during a program's execution.
#include<sys/socket>
#include<sys/un>
#include <iostream>
#using namespace std;

#define PORT 1227
#define SIM_LENGTH 10

int main (){
  
 int sock; 
 int connect_sock;
 struct sockaddr_in serv_name;
  size_t len; //It is the type of the result returned by sizeof operator.
  int count;
  
   //The following variables are to store the ip address and the hostname of a client.
int status; 
struct addrinfo hints, *p; 
struct addrinfo *servinfo; 
char ipstr[INET_ADDRSTRLEN];
char hostname[128];
   
  cout<<"please enter the ip address in like xxx.xxx.xxx.xxx";
  cin>>&sockaddr_in *ip;//this takes in ipv4 address and inserts it into the struct addr_in.
  
  //this is to check for hostname and ip address and if it fails this message is displayed
if ((status = getaddrinfo(hostname, NULL, &hints, &servinfo)) == -1) { 
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status)); 
    exit(1); 
}    
  //this code is to fetch the ipv4 address of the connected client.
  for (p=servinfo; p!=NULL; p=p->ai_next) { 
    struct in_addr  *addr;  
    if (p->ai_family == AF_INET) { 
        addr = &(ipv->sin_addr);  
    } 
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);//this changes the address in binary to a text format 
  
} 
  
  
    sock = socket(AF_INET, SOCK_STREAM, 0); 
  
  if (sock < 0) {
         perror ("Error opening channel");
          clean_up(1, &sock); //invoke function clean up in the agrgumentd form of con and sock.
    }
  
  
  bzero(&serv_name, sizeof(serv_name)); //The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros
  serv_name.sin_family = AF_INET;
  serv_name.sin_port = htons(PORT);
  
   if (bind(sock, addr, sizeof(serv_name)) < 0)
    { perror ("Error naming channel");
      clean_up(1, &sock);
    }
  
  
   cout<<"Server is alive and waiting for socket connection from client";
    listen(sock, 1);
  
   len = sizeof(serv_name);
  connect_sock = accept(sock, addr, &len);
  
  for (count = 1; count <= SIM_LENGTH; count++)
    { write(connect_sock, &count, 4); // //The write() function should try to write nbyte bytes from the buffer pointed to by buf to the file associated with the open file descriptor, fildes
      cout<<"Server has written %d to socket." + count;
  
  
  close(connect_sock);  
  clean_up(0, &sock);
  
  return 0;
}
  
//funciton that removes connection
void clean_up(int cond, int *sock){ 
  cout<<"Exiting now";
   close(*sock); 
    exit(cond);
}
