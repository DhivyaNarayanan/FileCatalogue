////////////////////////////////////////////////////////////////////////////
// Executive.cpp - The first package that gets called.                    //
//                  Oversees the control flow of the entire project       //
//                                                                        //
// ver 1.0                                                                //
// Language:       Visual C++ 2013                                        //
// Application:    CSE687 - Project 1 (File Catalogue), Spring 2015       //
// Platform:       HP G62, Windows 7 Home Premium, Visual Studio 2013     //
// Author:         Dhivya Narayanan, Master's- Computer Engineering,      //
//				   Syracuse University,                                   //
//                 dnnaraya@syr.edu                                       //
////////////////////////////////////////////////////////////////////////////
/*
Package Operations:
===================
This package doesn't conatin any class.
This module is intended to oversee the program flow. This is the
entry point to the application. All the calls to the subsequent packages
will be routed from here.

Public Interfaces:
==================
None

Build Process:
==============

Required Files:
---------------
Executive.cpp, Catalog.cpp, CmdlineParser.cpp, Display.cpp, FileMgr.cpp, FileStorage.cpp, FileSystem.cpp

Build Command:
--------------
devenv FileCatalogue.sln /rebuild debug

/Debug/Executive.exe ../../FileCatalogue /s /d /f"class FileMgr" "*.h""*.cpp"


Maintanence History:
====================
ver 1.0 - 29 Jan 2015
- first release
*/


/*
**************READ ME**************
File Catalogue Project
======================

Command Line Arguments:
=======================
Three divisions of command line arguments: path, pattern, option.

•	First argument is always considered as path.
•	Any argument which is starting with '/' is considered as option. Options are case-sensitive.
•	Remaining arguments other than above two are considered as patterns. If no pattern is entered, “*.*” is taken as default pattern.

Options applicable for this project: (options are case-insensitive)
•	/s or /S  – searches recursively for files in the entire directory
•	/d or /D  – displays duplicate files name and their paths
•	/f<textsearch> or /F<text> - displays all the files stored in the catalog that contain textsearch
- Texts are case-insensitive
- Text search effectively handles \t , ' ' , \n. The text will be searched irrespective of presence of \t or space or \n in between the substrings inside the text string.
If no command line arguments are given ( ie., no path and no patterns), then, by default "." will be taken as path and "*.*" will be taken as pattern.

Sample command line arguments:
=============================
- ../TestProject /s /d "*.*"     path = "../TestProject"  patterns = "*.*  Options = /s, /d
- . "*.h" "*.cpp"                path = "." (current directory)  patterns = "*.h", "*.cpp"  options = none
- ../TestProject /s "*.*"     path = "../TestProject"  patterns = "*.*  Options = /s
- ../TestProject /d "*.*"     path = "../TestProject"  patterns = "*.*  Options = /d
- ../TestProject /s /d /f"class" "*.*"     path = "../TestProject"  patterns = "*.*  Options = /s, /d, /f"class"
- ../TestProject /f"class Catalog" "*.*"     path = "../TestProject"  patterns = "*.*  Options = /f"class Catalog"
-	/s /d ./TestCode	         path = “/s”  Pattern=""*.*"  Option=/d
Invalid Path (first argument must be always a valid existing path)

Sample User inputs in console for text search:
=============================================
Enter the text to be searched (if any) or press enter to quit ::   class Catalog
Enter the file pattern(s) :: *.h *.cpp
*
*/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include"../CmdlineParser/CmdlineParser.h"
#include"../Display/Display.h"
#include"../FileMgr/FileMgr.h"
#include"../FileStorage/FileStorage.h"
#include"../FileMgr/FileSystem.h"
#include"../Catalog/Catalog.h"

#ifdef TEST_EXECUTIVE

int main(int argc, char* argv[])
{
	CmdlineParser cmdlp(argv);				//creating instances for CmdlineParser, FileStorage, Catalog, FileMgr, Display
	FileStorage fs;
	Catalog cs(fs);

	cmdlp.parsecmdline(argc, argv);			//call to parsecmdline method in CmdlineParser
	std::string path = cmdlp.getPath();

	FileMgr fm(path, fs);
	Display dp(fs, cmdlp);

	dp.display_cmdline_info();				//Display commandline arguments
	std::vector<std::string> options = cmdlp.getOptions();
	for (auto opt : options)
	{
		if (opt == "/s" || opt == "/S")
			fm.setRecurse(true);			//sets recursive search value as true
		if (opt == "/d" || opt == "/D")
			fm.setDuplicate(true);			//sets duplicate display value as true
		if (opt[1] == 'f'&& opt[2] != '\0' || opt[1] == 'F' && opt[2] != '\0')
		{
			std::string txt_given;
			int i = 2;
			while (opt[i] != '\0')
			{
				txt_given += opt[i];
				i++;
			}
			fm.setTextSearch(true, txt_given);				//sets text search value true
		}
	}
	std::vector<std::string> patterns = cmdlp.getPatterns();
	for (auto patt : patterns)
		fm.addPattern(patt);			//add patterns from the command line arguments

	fm.search();						// get files from the path, if needed recursively

	if (fm.Isduplicate())
		dp.display_duplicates();		//displays only duplicate file names

	if (fm.IsRecurse() && !fm.Isduplicate())
		dp.display_filesandpaths();		        //displays all files and their paths stored in catalog

	if (fm.isTextSearch())				//search text
	{
		std::cout << "\n<======================= Text Search =========================>\n";
		std::string ts = fm.text_given();
		std::cout << "\nText to be searched  ::  " << ts << "\n";
		std::cout << "--------------------------\n\n";
		if (ts != "")
			dp.display_textsearch(ts);
	}
	else if (options.size() == 0)		//display summary if no options given
		dp.display_summary();

	while (1)				//accepts the text and file patterns from the console for new text search in the catalog
	{
		std::string temp_text;
		std::string temp_pat;
		std::cout << "......... TextSearch from console- input text and File patterns......\n\n ";
		std::cout << "Enter the text (case-insensitive)to search (if any) or press enter to quit :: \n(Eg: class Display)  ::  ";
		getline(std::cin, temp_text);
		if (temp_text.empty())			//quits from the application
			return 0;
		else
		{
			std::vector<std::string>patts;
			std::cout << "\nEnter the filepattern(s) or filename or press Enter for \"*.*\" ::\n(Eg: *.h *.cpp or Display.h )  ::  ";		//accepts multiple file patterns
			getline(std::cin, temp_pat);
			if (temp_pat.empty())
				patts.push_back("*.*");
			else
			{
				std::string pat;
				std::stringstream ss(temp_pat);
				while (ss >> pat)
					patts.push_back(pat);
			}
			for (auto pt : patts)
				dp.display_text_filePatt(temp_text, pt);
		}
	}
	return 0;
}

#endif