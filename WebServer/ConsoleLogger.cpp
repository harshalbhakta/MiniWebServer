///////////////////////////////////////////////////////////////////////////////////////////
//	ConsoleLogger.h	-	ConsoleLogger Implementation File      							 //
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

#include <iostream>
#include <string>
#include <exception>
#include "ConsoleLogger.h"
#include "Logger.h"
#include "ErrorLogger.h"
using namespace std;
using std::string;
using std::cout;
using std::endl;

// Virtual function overloaded for polymorphism.
void ConsoleLogger::Print()
{
	try
	{

		// Log the message on console.
		cout<<endl<<LogMessageMain;

	}
	catch (exception &e)
	{
	
		cout << endl << "Console Logger Exception: " << e.what() << endl;
		
		ErrorLogger::LogError(e.what());
	
	}
}
