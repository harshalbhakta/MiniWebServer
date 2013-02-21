///////////////////////////////////////////////////////////////////////////////////////////
//	Logger.h	-	Logger Header File      											 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  Logger Class Description
*   ============================================================================================
*	
*	Logger Class will make use of the TemplateLogger to generate appropriate logs as 
*	per the selection at run time. The TemplateLogger will be initiated from here
*	to choose from ConsoleLogger & FileLogger.
*/
#ifndef __LOGGER__
#define __LOGGER__
#include "TemplateLogger.h"

class Logger
{

public : 

	Logger();	//Default Constructor

	void static LogMessage(string);	// Function to log the message

	void static setMode(int);	// Function to set mode of logging.

	int static getMode();	// Fetch the mode selected.

	// mode = 1 : Console Logger
	// mode = 2 : File Logger
	// mode = 3 : Both
	 static int errorMode;
};


#endif __LOGGER__
