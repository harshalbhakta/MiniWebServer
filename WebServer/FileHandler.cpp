///////////////////////////////////////////////////////////////////////////////////////////
//	FileHandler.h	-	FileHandler Implementation File      							 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  FileHandler Class Description
*   ============================================================================================
*	
*	FileHandler class is implemented to be used for handling File IO tasks for our webserver.
*   In our webserver we need to fetch the requested page from server directory. Reading the
*   content of the HTML file is handled by FileHandler.
	// Interface : 
	// FileHandler fh("test.html");
	// cout<<fh.getHtmlFileContent();
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>
#include "FileHandler.h"
#include "Logger.h"
#include "ErrorLogger.h"
using namespace std;

FileHandler::FileHandler(string file)
{
	try
	{

		fileName = file;
	}
	catch (exception &e)
	{
	
		cout << endl << "File Handler Exception: " << e.what() << endl;
	
		ErrorLogger::LogError( e.what());

	}
}

void FileHandler::setFileName(string fname)
{
	try 
	{
		fileName = fname;
	}
	catch (exception &e)
	{
	
		cout << endl << "File Handler Exception: " << e.what() << endl;
	
		ErrorLogger::LogError( e.what());

	}
}

int FileHandler::getFileLength()
{
	try 
	{
		return fileContent.length();
	}
	catch (exception &e)
	{
		cout << endl << "File Handler Exception: " << e.what() << endl;

		ErrorLogger::LogError( e.what());

		return 0;
	}
}

string FileHandler::getFileContent()
{
	try 
	{
		return fileContent;
	}
	catch (exception &e)
	{
		cout << endl << "File Handler Exception: " << e.what() << endl;

		ErrorLogger::LogError( e.what());

		return 0;
	}
}

void FileHandler::getHtmlFileContent()
{
	try 
	{
		fileContent = ""; 

		string line = "";

		// Fetch the contents of the file.

		ifstream myfile (fileName.c_str());
  
		if (myfile.is_open())
		{

			Logger::LogMessage("Reading file for HTML content");

			while ( myfile.good() )
			{
				getline (myfile,line);
				fileContent = fileContent + line;
				cout << line << endl;
			}
    
			myfile.close();
		}
	}
	catch (exception &e)
	{
	
		cout << endl << "File Handler Exception: " << e.what() << endl;

		ErrorLogger::LogError( e.what());
	
	}
}


bool FileHandler::ifFileExists()
{
	try
	{

		Logger::LogMessage("Checking if requested file exists or not");

		bool returnFileExists = true;	

		ifstream ifile(fileName.c_str());

		if ( ifile == 0 )
		{ 
			Logger::LogMessage("File does not exists");
			returnFileExists = false; 
		}
		
		Logger::LogMessage("File exists");

		return returnFileExists;
	}
	catch (exception &e)
	{
		cout << endl << "File Handler Exception: " << e.what() << endl;

		ErrorLogger::LogError( e.what());

		return false;
	}
}