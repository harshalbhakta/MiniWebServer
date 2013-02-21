///////////////////////////////////////////////////////////////////////////////////////////
//	GetMsg.h	-	GetMsg Header File      											 //
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
#ifndef __GetMsg__
#define __GetMsg__
#include "MessageHandler.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

// Inhereted from MessageHandler
class GetMsg : public MessageHandler
{

public : 

	void extractGetMessageInfo(vector<string>);	// Function to populate the attributes by extracting data from GET.

	GetMsg(); // Default constructor.

	string getAcceptType(); // get Method

	string getAcceptLanguage();	// get Method

	string getUserAgent();	// get Method

	string getAcceptEncoding(); // get Method

	string getconnection();	// get Method

	string getAcceptTypeTemplate();	// get Method

	string getAcceptLanguageTemplate();	// get Method

	string getUserAgentTemplate();	// get Method

	string gethostTemplate();	// get Method

	string getconnectionTemplate();	// get Method
	
private : 

	bool msgValidity;	// Validity of the message
	
	string AcceptType;	// GET Message Component

	string AcceptLanguage;	// GET Message Component

	string UserAgent;	// GET Message Component

	string AcceptEncoding;	// GET Message Component

	string connection;	// GET Message Component	

	string AcceptTypeTemplate;	// GET Message Component

	string AcceptLanguageTemplate;	// GET Message Component

	string UserAgentTemplate;	// GET Message Component

	string hostTemplate;	// GET Message Component

	string connectionTemplate;	// GET Message Component

};


#endif __GetMsg__