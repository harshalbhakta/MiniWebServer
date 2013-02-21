///////////////////////////////////////////////////////////////////////////////////////////
//	Socket.h -	Socket Header File      											     //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////
#ifndef __SOCKET__
#define __SOCKET__
#include <iostream>
using std::string;
#include "WinSock2.h"	// Library Added : WS2_32.Lib
const int MessageLength = 2048;

// One of the crucial class.
class Socket
{

public : 

  virtual ~Socket();	// Virtual Destructor
  Socket(const Socket&);	// Copy constructor.
  Socket& operator=(Socket&);	// Operator overloading
			
   Socket(SOCKET s); // Overload constructor.
    
   Socket();	// Default constructor

	void SendLine(string);	// Send one line at a time for interpreting.

	string GetRequestLine();	// Returm the Request line.
	
	void CloseSocket();	// Close the socket.
	
protected:

	friend class ServerSocket;	

	// Default Socket for class Socket.
	SOCKET DefaultSocket;

	// Keep conunt of array elements
	  int* refCounter_;

private : 

	static int socketCount;	// Keep count of sockets.

	static void Begin();	// Start the Socket 

	static void Finish();	// Finish the Socket links.

};

class ServerSocket : public Socket
{
    public:
        
		// Wait for clients to connect.
		Socket* ListenForClient();
		
		// Port - Number of connections
        ServerSocket(int,int);

};

#endif __SOCKET__