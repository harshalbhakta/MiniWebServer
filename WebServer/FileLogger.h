///////////////////////////////////////////////////////////////////////////////////////////
//	FileLogger.h	-	FileLogger Header File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  FileLogger Class Description
*   ============================================================================================
*	
*	FileLogger class is implemented to enable the facility of file logging for 
*	our Webserver. The location of the Log File is at the server directory. The logs 
*   generated for the web served are appended to the file.
*/
#ifndef __FILE_LOGGER__
#define __FILE_LOGGER__
#include "MainLogger.h"
#include <iostream>
#include <string>
using std::string;

// Derived from MainLogger for Polymorphism.
class FileLogger : public MainLogger
{

private :

	string logFileLocation; // Store the location of the file.

public : 

	virtual void Print(); // Virtual function to be overriden.

};

#endif __FILE_LOGGER__