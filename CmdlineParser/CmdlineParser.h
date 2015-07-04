#ifndef CMDLINEPARSER_H
#define CMDLINEPARSER_H
//////////////////////////////////////////////////////////////////////////////////////
// CmdlineParser.h -  Parses Command line arguments                                 //
//				                                                                    //
// ver 1.0                                                                          //
// Language:       Visual C++ 2013                                                  //
// Application:    CSE687 - Project 1 (File Catalogue), Spring 2015                 //
// Platform:       HP G62, Windows 7 Home Premium, Visual Studio 2013               //
// Author:         Dhivya Narayanan, Master's- Computer Engineering,                //
//				   Syracuse University,                                             //
//                 dnnaraya@syr.edu                                                 //
//////////////////////////////////////////////////////////////////////////////////////
/*
Package Operations
==================
This package provides a single class: CmdlineParser
-This class is intended to provide Support for parsing command line arguments into path, patterns
and options.


Function Prologues - Public Interfaces
======================================
parsecmdline();	       //parses command line arguments to find path, patterns, options.
getPath();             //Get and return the path argument from command line parsing
getPatterns();         //Get and return the patterns collection from command line parsing
getOptions();          //Get and return the options collection from command line parsing



Required Files:
================
CmdlineParser.h, CmdlineParser.cpp

Maintenance History:
=====================
Ver 1.0 - 27 Jan 2015
- first release
*/

#include<iostream>
#include<string>
#include<vector>

class CmdlineParser
{
public:
	CmdlineParser(char* argv[]) {}			//Promotion constructor
	void parsecmdline(int argc, char* argv[]);
	std::string getPath(){ return Path_; }
	std::vector<std::string> getPatterns(){ return Patterns_; }
	std::vector<std::string> getOptions(){ return Options_; }

private:
	std::string Path_;							//stores the path from command line
	std::vector<std::string> Patterns_;			//stores patterns from command line
	std::vector<std::string> Options_;			//stores options from the command line

};

#endif