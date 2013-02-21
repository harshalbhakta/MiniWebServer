///////////////////////////////////////////////////////////////////////////////////////////
//	ConsoleLogger.h	-	ConsoleLogger Header File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  Console Logger Class Description
*   ============================================================================================
*	
*	Console Logger class is implemented to enable the facility of console logging for 
*	our Webserver. The Web Server Administrator will have an option to disable the 
*	console logger.
*/

#ifndef __CONSOLE_LOGGER__
#define __CONSOLE_LOGGER__

#include "MainLogger.h"
#include <iostream>
#include <string>
using std::string;

// Derived from MainLogger
class ConsoleLogger : public MainLogger
{

private :

	string Message; // Store the message to be logged.

public : 

	virtual void Print();	// Virtual function to enable polymorphism.

};

#endif __CONSOLE_LOGGER__