///////////////////////////////////////////////////////////////////////////////////////////
//	Logger.cpp	-	Logger Implementaion File      										 //
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
#include "Logger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "TemplateLogger.h"
#include "Logger.h"
#include "ErrorLogger.h"
#include <exception>
using namespace std;
// Static Variable to store the mode of logging.
int Logger::errorMode = 2;

Logger::Logger()
{

}

// Set mode of logging.
void Logger::setMode(int modeInput)
{
	try 
	{
		errorMode = modeInput;
	}
	catch (exception &e)
{
	cout << endl << "Logger Exception: " << e.what() << endl;
	ErrorLogger::LogError( e.what());
}

}

// Fetch the mode.
int Logger::getMode()
{
	try 
	{
		return errorMode;
	}
	catch (exception &e)
	{
		cout << endl << "Logger Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return 1;
	}
}

// Function to implement selected logging mechanism.
void Logger::LogMessage(string message)
{	
	try 
	{ 
	switch ( Logger::getMode() )
	{

	default : 

	// Only console logger
	case 1 :
		{
	 ConsoleLogger cl;
	
	 TemplateLogger<ConsoleLogger> tl_c; 

	 tl_c.setMessage(message);

	 tl_c.logMessage(cl);
		
		break;
		}
	// Only File logger
	case 2 :
		{
	FileLogger fl;

	 TemplateLogger<FileLogger> tl; 

	 tl.setMessage(message);

	 tl.logMessage(fl);

		break;
		}
	// Both logger
	case 3 : 
		{
	 FileLogger fl;

	 ConsoleLogger cl;

	 TemplateLogger<FileLogger> tl; 

	 tl.setMessage(message);

	 tl.logMessage(fl);

	 TemplateLogger<ConsoleLogger> tl_c; 

	 tl_c.setMessage(message);

	 tl_c.logMessage(cl);

	
		break;
		}

	}

	}
	catch (exception &e)
	{
		cout << endl << "Logger Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
	

}