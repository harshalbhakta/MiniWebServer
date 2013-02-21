///////////////////////////////////////////////////////////////////////////////////////////
//	MainLogger.h	-	MainLogger Header File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  MainLogger Class Description
*   ============================================================================================
*	
*	MainLogger class is implemented to be the base class for the Console, Error and File 
*   logger for our Webserver. MainLogger has the virtual function defined to overload
*	using polymorphism.
*/
#ifndef __MainLogger__
#define __MainLogger__
#include <iostream>
#include <string>
using std::string;

// Base class for polymorphism.
class MainLogger
{
public : 	
	// Function to be overloaded.
	virtual void Print() = 0;

	// Set the LogMessage string.
	void setLogMessage(string);
protected : 
	// Store the LogMessage string.
	string LogMessageMain;
}; 
#endif __MainLogger__