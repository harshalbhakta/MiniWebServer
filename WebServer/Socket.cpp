///////////////////////////////////////////////////////////////////////////////////////////
//	Socket.cpp -	Socket Implementation File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
using namespace std;

#include "Socket.h"
#include "Logger.h"
#include "ErrorLogger.h"

using std::string;
using std::cout;
using std::endl;

int Socket::socketCount = 0;

void Socket::Begin()
{
	Logger::LogMessage("Begin the Socket : WSA");

	try 
	{
		// Create new instance of WSADATA using WSAStartup
		if (!socketCount) 
		 {
			WSADATA info;
	       if (WSAStartup(MAKEWORD(2,0), &info)) 
			{
				throw "Could not start WSA";
			}
		 }
		++socketCount;
	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
}

void Socket::Finish()
{
	try 
	{
		Logger::LogMessage(" WSACleanup ");

		WSACleanup();

	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
}



Socket::Socket() : DefaultSocket(0) {

	try 
	{

		Begin();
		// UDP: use SOCK_DGRAM instead of SOCK_STREAM
		DefaultSocket = socket(AF_INET,SOCK_STREAM,0);

		if (DefaultSocket == INVALID_SOCKET) 
		{
			throw "INVALID_SOCKET";
		}	

		refCounter_ = new int(1);
	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}

Socket::Socket(SOCKET s) : DefaultSocket(s) {

	try
	{

		Begin();

		refCounter_ = new int(1);

	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

};

Socket::~Socket() {
  
	try 
	{

		 if (! --(*refCounter_)) 
		{
			CloseSocket();
			delete refCounter_;
		}  
			--socketCount;

		if (!socketCount) Finish();
	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}

Socket::Socket(const Socket& o) {
  
	try 
	{
		refCounter_=o.refCounter_;

		(*refCounter_)++;

		DefaultSocket         =o.DefaultSocket;

		socketCount++;
	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
}

Socket& Socket::operator =(Socket& o)
{
	try 
	{
		refCounter_=o.refCounter_;

		(*o.refCounter_)++;

		DefaultSocket         =o.DefaultSocket;

	    socketCount++;

	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());
	}

		return *this;


}
void Socket::CloseSocket()
{
try
{
	Logger::LogMessage(" Closing Socket ");
	closesocket(DefaultSocket);
}
catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());
	}
}


// Server host initiate.
ServerSocket::ServerSocket(int portInput, int noOfConnections)
{
try 
{
  // Structure is used by Windows Sockets to specify a local or remote endpoint address to which to connect a socket.
  sockaddr_in sockAddress;


  // Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
  memset(&sockAddress, 0, sizeof(sockAddress));

  sockAddress.sin_family = PF_INET;             
  sockAddress.sin_port = htons(portInput);          
  DefaultSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (DefaultSocket == INVALID_SOCKET) {
    throw "INVALID_SOCKET";
  }
  /* bind the socket to the internet address */
  if (bind(DefaultSocket, (sockaddr *)&sockAddress, sizeof(sockaddr_in)) == SOCKET_ERROR) {
    closesocket(DefaultSocket);
    throw "INVALID_SOCKET";
  }
  
  listen(DefaultSocket, noOfConnections);                               
}
catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());
	}

}

// Function that waits till the clients againg request
Socket* ServerSocket::ListenForClient()
{
try
{

  Logger::LogMessage(" Listening for client ");

  SOCKET newSocket = accept(DefaultSocket, 0, 0);

  if (newSocket == INVALID_SOCKET) 
  {
	  int checkError = WSAGetLastError();
          
		  if(checkError==WSAEWOULDBLOCK) 
		  {
                  return 0; 
          }
          else { throw "Invalid Socket"; }
  }

  Socket* returnSocket = new Socket(newSocket);

  return returnSocket;
}
catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());

		 Socket* returnSocketErr = 0;

		return returnSocketErr;
	}
 

}

string Socket::GetRequestLine()
{
try
{
   string request;

   while (1) {
     
	 char r;

	 switch(recv(DefaultSocket, &r, 1, 0)) {
       case 0: // not connected anymore;
         return "";
       case -1: // #define EAGAIN 11 - errno.h - Microsoft
          if (errno == 11) {
             return request;
          } else {
            // not connected anymore
           return "";
         }
     }

     request += r;

     if (r == '\n')  return request;

   }
}
catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());

		return "";
	}

}
void Socket::SendLine(string message)
{
	try 
	{
		message += '\n';
		send(DefaultSocket,message.c_str(),message.length(),0);
	}
	catch (exception &e)
	{
		cout << endl << "Socket Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());
	}

}











