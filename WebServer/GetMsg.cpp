///////////////////////////////////////////////////////////////////////////////////////////
//	GetMsg.cpp	-	GetMsg Implementation File      									 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 //
//																						 //
///////////////////////////////////////////////////////////////////////////////////////////

/*  GetMsg Class Description
*   ============================================================================================
*	
*	GetMsg Class will be used to extract the GET message received via HTTP Protocol. Several 
*	parts of the GET Message are stored as variables and will will be fetched based on parse 
*	rules applied for each component.
*/
#include "GetMsg.h"
#include "Logger.h"
#include "ErrorLogger.h"
#include <vector>
#include <exception>
using std::vector;
using std::string;
using namespace std;
#include <iostream>
using std::cout;


// Extract data from the message based on rules for each component.
void GetMsg::extractGetMessageInfo(vector<string> GetRequestVector)
{
	try 
	{

		Logger::LogMessage(" Extracting information from GET Message ");

string line;

for ( int i = 0 ; i < (int)GetRequestVector.size() ; i++ )
{
	if ( GetRequestVector[i].empty() ) 
	{ 		
		break ; 
	}
	else if ( GetRequestVector[i].substr(0).find("GET") != string::npos && GetRequestVector[i].substr(0).find("HTTP") != string::npos ) 
	{	
	    filePath = GetRequestVector[i].substr(GetRequestVector[i].find_first_of("/"),GetRequestVector[i].length()-15);

		httpProtocol = GetRequestVector[i].substr(GetRequestVector[i].length()-10,8);

		cout<<"\nfilePath:"<<filePath<<" httpProtocol:"<<httpProtocol;
    }
	else if (GetRequestVector[i].substr(0, AcceptLanguageTemplate.size()) == AcceptLanguageTemplate) 
	{
		AcceptLanguage = GetRequestVector[i].substr(AcceptLanguageTemplate.size(),GetRequestVector[i].length()-AcceptLanguageTemplate.size()-1);

		cout<<"\n"<<AcceptLanguageTemplate<<AcceptLanguage;
    }
	else if (GetRequestVector[i].substr(0, AcceptTypeTemplate.size()) == AcceptTypeTemplate) 
	{
		AcceptType = GetRequestVector[i].substr(AcceptTypeTemplate.size(),GetRequestVector[i].length()-AcceptTypeTemplate.size()-1);

		cout<<"\n"<<AcceptTypeTemplate<<AcceptType;
    }
	else if (GetRequestVector[i].substr(0, UserAgentTemplate.size()) == UserAgentTemplate) 
	{
		UserAgent = GetRequestVector[i].substr(UserAgentTemplate.size(),GetRequestVector[i].length()-UserAgentTemplate.size()-1);

		cout<<"\n"<<UserAgentTemplate<<UserAgent;
    }
	else if (GetRequestVector[i].substr(0, connectionTemplate.size()) == connectionTemplate) 
	{
		connection = GetRequestVector[i].substr(connectionTemplate.size(),GetRequestVector[i].length()-connectionTemplate.size()-1);

		cout<<"\n"<<connectionTemplate<<connection;
    }
	else if (GetRequestVector[i].substr(0, hostTemplate.size()) == hostTemplate) 
	{
		server = GetRequestVector[i].substr(hostTemplate.size(),GetRequestVector[i].length()-hostTemplate.size()-1);

		cout<<"\n"<<hostTemplate<<server;
    }

}

}
	catch (exception &e)
{
	cout << endl << "GetMsg Exception: " << e.what() << endl;
	ErrorLogger::LogError( e.what());
}


}


// Default constructor to initialize values as per HTTP
GetMsg::GetMsg()
{
	try 
	{
		AcceptTypeTemplate = "Accept: ";

		AcceptLanguageTemplate = "Accept-Language: ";

		UserAgentTemplate = "User-Agent: ";

		hostTemplate = "Host: ";

		connectionTemplate = "Connection: ";
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
	}
}


// Below all are Get Methods for the GETvariables
string GetMsg::getAcceptType()
{
	try 
	{
		return AcceptType;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getAcceptLanguage()
{
	try 
	{
		return AcceptLanguage;	
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getUserAgent()
{
	try 
	{
		return UserAgent;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getAcceptEncoding()
{
	try 
	{
		return AcceptEncoding;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getconnection()
{
	try
	{
		return connection;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getAcceptTypeTemplate()
{
	try 
	{
		return AcceptTypeTemplate;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getAcceptLanguageTemplate()
{
	try
	{
		return AcceptLanguageTemplate;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}

}

string GetMsg::getUserAgentTemplate()
{
	try 
	{
		return UserAgentTemplate;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::gethostTemplate()
{
	try
	{
		return hostTemplate;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}

string GetMsg::getconnectionTemplate()
{
	try
	{
		return connectionTemplate;
	}
	catch (exception &e)
	{
		cout << endl << "GetMsg Exception: " << e.what() << endl;
		ErrorLogger::LogError( e.what());
		return "";
	}
}


