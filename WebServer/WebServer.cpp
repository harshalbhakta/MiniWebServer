///////////////////////////////////////////////////////////////////////////////////////////
//	WebServer.cpp -	WebServer Implementation File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
//////////////////////////////////////////////////////////////////////////////////////////
#include "WebServer.h"
#include "Socket.h"
#include <ctime>
#include <process.h>
#include "FileHandler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <vector>
using std::vector;
#include "GetMsg.h"
#include "PostMsg.h"
#include "Logger.h"
#include "ErrorLogger.h"
using namespace std;

// Fetch the message from the socket.
int WebServer::getMessage(Socket &s,vector<string> &GetMessage)
{

			std::string line = s.GetRequestLine();
  
			if (line.empty()) 
			{
				return 1;
			}

			GetMessage.push_back(line);

			while(true) 
			{		
				line=s.GetRequestLine();

				if (line.empty()) break;

			//0a0dHost: 127.0.0.1
			//0a0dConnection: Keep-Alive
			//0a0d
				unsigned int pos_cr_lf = line.find_first_of("\x0a\x0d");
		
				if (pos_cr_lf == 0)
				{ break;}

				//cout<<line;
				GetMessage.push_back(line);

				Logger::LogMessage(line);

		     }

			return 0;

}

// Update port number
WebServer::WebServer(int portInput)
{
	try
	{
		port = portInput;
	}
	catch (exception &e)
	{
		cout << endl << "WebServer Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}

// Function the generate response using the Socket.
unsigned WebServer::GenerateResponse(void* ptr_sock)
{
	try 
	{

			Logger::LogMessage("Server is now reading the Request");

			Socket sNew = *(reinterpret_cast<Socket*>(ptr_sock));			

			Socket s;

			s = sNew;

			vector<string> GetMessage;
			
			int result = getMessage(s,GetMessage);

			// Fill the GetMsg Object with the information in Get Message.
	
			GetMsg getRequest;

			getRequest.extractGetMessageInfo(GetMessage);

			PostMsg postMessage;

			postMessage.generatePostMsg(getRequest);	

			Logger::LogMessage("Server is now creating the response");

			s.SendLine(postMessage.gethttpResponseHeader());
			Logger::LogMessage(postMessage.gethttpResponseHeader());
			s.SendLine(postMessage.gethttpdateTime());
			Logger::LogMessage(postMessage.gethttpdateTime());
			s.SendLine("Server: "+postMessage.getserver());
			Logger::LogMessage("Server: "+postMessage.getserver());
			s.SendLine(postMessage.getconnection()+"");
			Logger::LogMessage(postMessage.getconnection()+"");
			s.SendLine(postMessage.getcontentType()+"");
			Logger::LogMessage(postMessage.getcontentType()+"");
			s.SendLine("Content-Length: "+postMessage.getcontentLength());
			Logger::LogMessage("Content-Length: "+postMessage.getcontentLength());
			s.SendLine("");
			Logger::LogMessage(postMessage.getfileContent());
			s.SendLine(postMessage.getfileContent());

			Logger::LogMessage("closing socket");
		
			s.CloseSocket();

			return 0;
	}
	
	catch (exception &e)
	{
		cout << endl << "WebServer Exception: " << e.what() << endl;
		return 0;
	}

}



// Function to set the mode of the logging.
void WebServer::setLogger()
{
	try 
	{
		int choice ;

		cout<<"\nPlease select the logging mode : \n";
		cout<<"1. Console Logger";
		cout<<"\n2. File Logger \n";
		cout<<"3. Both \n";

		cin>>choice;

		Logger::setMode(choice);
	}
	catch (exception &e)
	{
		cout << endl << "WebServer Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}

}
// Function to start the webserver.
void WebServer::StartWebServer()
{
	try 
	{
		WebServer::setLogger();

		Logger::LogMessage("Logger Mode is now set");

		ErrorLogger::LogError("Testing Error Log");

		ServerSocket hostServer(port,5);  

		while (true)
		{
			Logger::LogMessage("Server is now listening for client");
	  
			Socket* ptr_sock = hostServer.ListenForClient();

			unsigned ret;
			
			_beginthreadex(0,0,GenerateResponse,(void*) ptr_sock,0,&ret);
		}
	}
	catch (exception &e)
	{
		cout << endl << "WebServer Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
}