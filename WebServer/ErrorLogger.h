///////////////////////////////////////////////////////////////////////////////////////////
//	ErrorLogger.h	-	ErrorLogger Header File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  ErrorLogger Class Description
*   ============================================================================================
*	
*	ErrorLogger class is implemented to enable the facility of Error logging for 
*	our Webserver. The ErrorLog.txt file has been created on the server directory for 
*   storing the results.
*/
#ifndef __ERROR_LOGGER__
#define __ERROR_LOGGER__

#include "MainLogger.h"
#include <iostream>
#include <string>
using std::string;

// Derived from MainLogger.
class ErrorLogger : public MainLogger
{

public : 

	// Function to initiate the Error Logging.
	static void LogError(string);

};

#endif __ERROR_LOGGER__