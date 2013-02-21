///////////////////////////////////////////////////////////////////////////////////////////
//	FileHandler.h	-	FileHandler Header File      							 //
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
#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__
#include <string>
using std::string;

class FileHandler
{

public : 

	bool ifFileExists(); // Check if the requested file exists.

	void getHtmlFileContent();	// Function to fetch the content of the HTML File.

	FileHandler(string); // input as a filename.

	void setFileName(string);	// Function to set the filename.

	int getFileLength();	// Function to fetch the length of file.

	string getFileContent();	// Function to fetch the content of the file read.

private : 

	string fileName;	// Store File name

	string fileContent;	// Store File content

};


#endif __FILE_HANDLER__