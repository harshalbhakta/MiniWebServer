#include "WebServer.h"

#include "FileHandler.h"

#include "ConsoleLogger.h"

#include "FileLogger.h"

#include "MainLogger.h"

#include "TemplateLogger.h"

#include "Logger.h"

#include "ErrorLogger.h"

#include <exception>

using std::endl;
using std::cout;

#define port 80

void main()
{
	try
	{

		cout<<"Starting the Web server on Port : "<<port<<"\n";

		WebServer newWebServer(port);

		newWebServer.StartWebServer();	

	}
	catch (exception &e)
	{
	
		cout << endl << "Main Exception: " << e.what() << endl;
		ErrorLogger::LogError(e.what());
	
	}
	 
}