///////////////////////////////////////////////////////////////////////////////////////////
//	WebServer.h -	WebServer Header File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __WEBSERVER__
#define __WEBSERVER__

#include <stdio.h>
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

// Forward declaration.
class Socket;

class WebServer{

int port ;	// Save the port number.

// Define structure to hold on the data for PR05
struct httpRequest 
{
    
   Socket* HttpSocket;
	 
};

public : 

	// Port as input for the constructor.
	WebServer(int);

	void static setLogger();

	// Function to Start the Web server.
	void StartWebServer();

	

private  :

	// The __stdcall calling convention is used to call Win32 API functions. The callee cleans the stack, so the compiler makes vararg functions __cdecl.
	// The routine at start_address passed to _beginthreadex must use the __stdcall calling convention and must return a thread exit code.
	// http://msdn.microsoft.com/en-us/library/kdzttdcb(VS.80).aspx
	static unsigned __stdcall GenerateResponse(void*);
	
	static int getMessage(Socket &,vector<string>&);

};

#endif __WEBSERVER__