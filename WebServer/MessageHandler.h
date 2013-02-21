///////////////////////////////////////////////////////////////////////////////////////////
//	MessageHandler.h	-	MessageHandler Header File      							 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  MessageHandler Class Description
*   ============================================================================================
*	
*	MessageHandler Class will be the base class for Get and Post messages. Both have some 
*   common attributes that need to be shared and are available for their use at MessangeHandler
*/
#ifndef __MessageHandler__
#define __MessageHandler__
#include<string>
using std::string;

class MessageHandler
{

public : 

	string gethttpProtocol();	// Fetch the HTTP PRotocol.

	string getserver();	// Fetch server name.

	string getfilePath();	// Fetch File path.

	MessageHandler();	// Default Constructor.

protected : 

	string httpProtocol;	// HTTP Protocol

	string server;	// Server

	string filePath;	// Store File Path

};

#endif __MessageHandler__