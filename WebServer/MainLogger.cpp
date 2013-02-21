///////////////////////////////////////////////////////////////////////////////////////////
//	MainLogger.h	-	MainLogger Implementation File      							 //
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
#include "MainLogger.h"
#include "Logger.h"
#include "ErrorLogger.h"
#include <exception>
using namespace std;

// Function to set the LogMessage for logging.
void MainLogger::setLogMessage(string msg)
{
	try 
	{

		LogMessageMain = msg;

	}
	catch (exception &e)
	{
	
		cout << endl << "Main Logger Exception: " << e.what() << endl;
	
        ErrorLogger::LogError(e.what());

	}
}

