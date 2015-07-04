#ifndef DISPLAY_H
#define DISPLAY_H
//////////////////////////////////////////////////////////////////////////////////
// Display.h -     Supports console display part of Project                     //
//				                                                                //
// ver 1.0                                                                      //
// Language:       Visual C++ 2013                                              //
// Application:    CSE687 - Project 1 (File Catalogue), Spring 2015             //
// Platform:       HP G62, Windows 7 Home Premium, Visual Studio 2013           //
// Author:         Dhivya Narayanan, Master's- Computer Engineering,            //
//				   Syracuse University,                                         //
//                 dnnaraya@syr.edu                                             //
//////////////////////////////////////////////////////////////////////////////////
/*
Package Operations
==================
This package provides a single class: Display
-Provides support for displaying file names and their paths, Command Line arguments,
duplicate file names, files contains the particular text


Function Prologues - Public Interfaces
======================================
display_filesandpaths();		//Displays all the file names and paths present in the FileStorage, if needed displays only duplicate files
display_textsearch();			//Displays all the files which contains the particular text
display_summary();				//Displays summary about the files present in the filestorage
display_cmdline_info();			//Display command line arguments
display_duplicates();			//Displays duplicate file names and their paths
display_text_filePatt();		//Displays all files with the given patterns or the given file which contains the given text

Required Files:
================
Display.h, Display.cpp,FileMgr.h, FileMgr.cpp, FileSystem.h, FileSystem.cpp, FileStorage.h, FileStorage.cpp,
Catalog.h, Catalog.cpp, CmdlineParser.h, CmdlineParser.cpp

Maintenance History:
=====================
Ver 1.0 - 27 Jan 2015
- first release
*/

#include<iostream>
#include"../FileStorage/FileStorage.h"
#include"../FileMgr/FileMgr.h"
#include"../FileMgr/FileSystem.h"
#include"../CmdlineParser/CmdlineParser.h"
#include"../Catalog/Catalog.h"
#include<vector>
#include<string>
#include<map>
#include<set>

class Display
{
public:
	Display(FileStorage& fs, CmdlineParser& cmd) : filestore_(fs), cmd_(cmd){}		//Constructor
	void display_filesandpaths();
	void display_textsearch(std::string & text);
	void display_text_filePatt(std::string& text, std::string& filepatt);
	void display_summary();
	void display_cmdline_info();
	void display_duplicates();

private:
	FileStorage& filestore_;				//reference to class FileStorage
	CmdlineParser& cmd_;					//reference to class CmdlineParser
	std::vector<std::string> pattern;       //stores patterns from CmdlineParser
	std::string path;						//stores path from CmdlineParser
	std::vector<std::string> opt;			//stores options from CmdlineParser
};

#endif