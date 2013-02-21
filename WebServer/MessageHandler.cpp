///////////////////////////////////////////////////////////////////////////////////////////
//	MessageHandler.cpp	-	MessageHandler Implementation File      					 //
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
#include <exception>	
#include <iostream>
#include "MessageHandler.h"
#include "Logger.h"
#include "ErrorLogger.h"
using namespace std;

// Below are the Get methods to fetch the value stored in the variables.
string MessageHandler::gethttpProtocol()
{
	try 
	{
		return httpProtocol;
	}
	catch (exception &e)
	{
		cout << endl << "MessageHandler Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

	
string MessageHandler::getserver()
{
	try 
	{
		return server;	
	}
	catch (exception &e)
	{
		cout << endl << "MessageHandler Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

	
string MessageHandler::getfilePath()
{
	try 
	{
		// Ignore "\" at beginning of the file path : \test.html
		return filePath.substr(1);
	}
	catch (exception &e)
	{
		cout << endl << "MessageHandler Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

MessageHandler::MessageHandler()
{
	try 
	{
		server = "127.0.0.1";
	}
	catch (exception &e)
	{
		cout << endl << "MessageHandler Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}