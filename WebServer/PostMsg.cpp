///////////////////////////////////////////////////////////////////////////////////////////
//	PostMsg.cpp	-	PostMsg Implementation File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////
// To use localtime without warning
#define _CRT_SECURE_NO_WARNINGS
#include "PostMsg.h"
#include "GetMsg.h"
#include "FileHandler.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <iostream>
#include <exception>
#include "Logger.h"
#include "ErrorLogger.h"
using namespace std;

// Function to generate PostMsg.
void PostMsg::generatePostMsg(GetMsg gm)
{

try
{
	Logger::LogMessage(" Generating Post Message Now ");

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
    timeinfo = localtime ( &rawtime );

	FileHandler fh(gm.getfilePath());

	if ( fh.ifFileExists() )
	{

	 fh.getHtmlFileContent();	

	 httpResponseHeader = gm.gethttpProtocol() + "202 OK" ;
	 dateTime = std::string(asctime(timeinfo)).substr(0,std::string(asctime(timeinfo)).length()-1) + " EST";	 
	 connection = gm.getconnectionTemplate() + gm.getconnection();
	 contentType = "Content-Type: text/html; charset=ISO-8859-1";
	 //contentType = "Content-Type: image/jpeg";
	 contentLength = fh.getFileLength();
	 emptyLine = "";
	 fileContent = fh.getFileContent();

	}
	else 
	{
	
	 fh.setFileName("404.html");

	 fh.getHtmlFileContent();
	 httpResponseHeader = gm.gethttpProtocol() + " 404" + " NOTFOUND";
	 dateTime = std::string(asctime(timeinfo)).substr(0,std::string(asctime(timeinfo)).length()-1) + " EST";
	 connection = gm.getconnectionTemplate() + gm.getconnection();
	 contentType = "Content-Type: text/html; charset=ISO-8859-1";
	 contentLength = fh.getFileLength();
	 emptyLine = "";
	 fileContent = fh.getFileContent();
	
	}
}
catch(exception &e)
{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
}


}

PostMsg::PostMsg()
{

	

}

//Overload the contructor.
PostMsg::PostMsg(string msg)
{
	try 
	{
		if ( msg == "error")
		{

			filePath = "404.html";
		
		}
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}


// Below functions are get methods for the attrubutes.
string PostMsg::gethttpResponseHeader()
{
	try 
	{
		return httpResponseHeader;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
string PostMsg::gethttpdateTime()
{
	try 
	{
		return dateTime;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
string PostMsg::getconnection()
{
	try 
	{
		return connection;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
string PostMsg::getcontentType()
{
	try 
	{
		return contentType;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
string PostMsg::getcontentLength()
{
	try
	{

		string returnLength;

		std::stringstream out;

		out << contentLength;

		returnLength = out.str();

		return returnLength;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string PostMsg::getemptyLine()
{
	try 
	{
		return emptyLine;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
string PostMsg::getfileContent()
{
	try 
	{
		return fileContent;
	}
	catch (exception &e)
	{
		cout << endl << "PostMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}
