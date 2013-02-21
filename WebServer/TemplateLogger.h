///////////////////////////////////////////////////////////////////////////////////////////
//	TemplateLogger.h -	TemplateLogger Header File      											 //
//																						 //
//	Version 1.0 																		 //
//	Language : C++ , Microsoft Visual Studio 2008.									     //
//	Author : Harshal Bhakta,Shazia Bee CIS_554_WEB_SERVER, Syracuse University			 /]\/
//										
/*  C++ Timy Sensere
FileLogger fl;

ConsoleLogger cl;

TemplateLogger<FileLogger> tl; 

tl.setErrorMessage("Testing Error Message");

tl.logErrorMessage(fl);

TemplateLogger<ConsoleLogger> tl_c; 

tl_c.setErrorMessage("Testing Error Message");

tl_c.logErrorMessage(cl);*///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TEMPLATE_LOGGER__
#define __TEMPLATE_LOGGER__
#include "FileLogger.h"
#include "ConsoleLogger.h"
#include "MainLogger.h"
#include <string>
using std::string;

template <class LogTemplate>
class TemplateLogger
{

public : 

	void logMessage(LogTemplate);	// Logmessage to set the various kap

	void setMessage(string);	// Store the SetMessage

private : 

	string Message;	

};

// Template:logger
template <class LogTemplate>
void TemplateLogger<LogTemplate>::logMessage (LogTemplate logger) {
  
   MainLogger *er = &logger;

   er->setLogMessage(Message);

   er->Print();
}


template <class LogTemplate>
void TemplateLogger<LogTemplate>::setMessage(string msg)
{

	Message = msg;

}



#endif __TEMPLATE_LOGGER__