///////////////////////////////////////////////////////////////////////////////////////////
//	PostMsg.h	-	PostMsg Header File      											 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  PostMsg Class Description
*   ============================================================================================
*	
*	PostMsg Class will derived from MessageHandler and will be respinsible for generating the 
*	HTTP Response in reply to the GET message that is interpreted by GetMsg. This means
*	PostMsg will use the GetMsg for generating the approprite reply
*/
#ifndef __PostMsg__
#define __PostMsg__

#include "MessageHandler.h"
#include "GetMsg.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

class PostMsg : public MessageHandler
{

public : 

	PostMsg();	// Default constructor.

	PostMsg(string);	// Overload constructor

	void generatePostMsg(GetMsg);	// Function to generate Post Message.

	// All below methods are get methods to fetch string values.
	string gethttpResponseHeader();
	string gethttpdateTime();
	string getconnection(); 
	string getcontentType();
	string getcontentLength();
	string getemptyLine();
	string getfileContent();

private : 

	bool msgValidity;	// Message Validity

	// GET Response Attributes.
	string httpResponseHeader;
	string dateTime;
	string connection; 
	string contentType;
	int contentLength;
	string emptyLine;
	string fileContent;
	// sample request.
	/*s.SendLine("Date: Wed Dec 01 02:49:03 2010 GMT");
	s.SendLine("Server: Harshal Localhost");
	s.SendLine("Connection: close");
	s.SendLine("Content-Type: text/html; charset=ISO-8859-1");
	s.SendLine("Content-Length: 394");
	s.SendLine("");
	s.SendLine("HTML");*/

};



#endif __PostMsg__