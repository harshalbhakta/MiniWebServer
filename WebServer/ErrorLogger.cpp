///////////////////////////////////////////////////////////////////////////////////////////
//	ErrorLogger.h	-	ErrorLogger Implementation File      						     //
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
   // Interface. 
   // ErrorLogger el;
   // el.setErrorMessage("hello");
   // el.Print();
*/
// To use localtime without warning
#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include "ErrorLogger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <exception>
using std::string;
using std::cout;
using namespace std;

// Function to log error messages to File : ErrorLog.txt
void ErrorLogger::LogError(string error)
{
	try
	{
		// Generate Time Stamp for Logging.
		time_t rawtime;
		struct tm * timeinfo;

		time ( &rawtime );
		timeinfo = localtime ( &rawtime );

		// Also display the logged error on console.
		cout<<endl<<"Error Log : "<<error<<endl;

		// Write the log by appending to file.
		fstream filestr;

		filestr.open ("ErrorLog.txt", fstream::in | fstream::out | fstream::app);

		filestr<< asctime(timeinfo) + error <<endl<<endl;

		filestr.close();

	}
	catch (exception &e)
	{
	
		cout << endl << "Error Logger Exception: " << e.what() << endl;

		ErrorLogger::LogError( e.what());
	
	}
}


