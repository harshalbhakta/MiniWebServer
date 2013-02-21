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
	// Interface. 
   // FileLogger fl;
   // fl.setErrorMessage("hello");
   // fl.Print();
*/
#include "FileLogger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include "Logger.h"
#include "ErrorLogger.h"
using std::string;
using std::cout;
using namespace std;

// Overriden Print function to append logs to a file.
void FileLogger::Print()
{
	try
	{

		// Append the log into the LogFile.

		fstream filestr;

		filestr.open ("LogFile.txt", fstream::in | fstream::out | fstream::app);

		filestr<< LogMessageMain<<endl<<endl;

		filestr.close();

	}
	catch (exception &e)
	{
		cout << endl << "File Logger Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}
