//////////////////////////////////////////////////////////////////////////////////////
// CmdlineParser.cpp - Implemented to Parse Command line arguments                  //
//				                                                                    //
// ver 1.0                                                                          //
// Language:       Visual C++ 2013                                                  //
// Application:    CSE687 - Project 1 (File Catalogue), Spring 2015                 //
// Platform:       HP G62, Windows 7 Home Premium, Visual Studio 2013               //
// Author:         Dhivya Narayanan, Master's- Computer Engineering,                //
//				   Syracuse University,                                             //
//                 dnnaraya@syr.edu                                                 //
//////////////////////////////////////////////////////////////////////////////////////
#include"CmdlineParser.h"
#include<iostream>
#include<string>
#include<vector>

//----< parses command line arguments to find path, patterns, options >---------------------------------------

void CmdlineParser::parsecmdline(int argc, char* argv[])
{
	if (argc > 0)
	{
		Path_ = argv[1];
		int i = 2;
		while (i < argc)
		{
			//starting with '/' as options 
			if (argv[i][0] == '/')
				Options_.push_back(argv[i]);
			else
				Patterns_.push_back(argv[i]); //remaining as patterns
			i++;
		}
		//add default pattern, if no pattern is given
		if (Patterns_.size() == 0)
			Patterns_.push_back("*.*");
	}
	else
	{
		Path_ = ".";
		Patterns_.push_back("*.*");
	}
}

//------------------< test stub >--------------------------------------------------------

#ifdef TEST_CMDLINEPARSER

int main(int argc, char* argv[])
{
	CmdlineParser cmdlp(argv);
	std::cout << "Testing CommandLineParser....\n";
	std::cout << "-------------------------------\n";

	cmdlp.parsecmdline(argc, argv);

	std::string path = cmdlp.getPath();
	std::cout << "Path : " << path << "\n";

	std::vector<std::string> pattern = cmdlp.getPatterns();
	std::cout << "Patterns : ";
	for (auto pt : pattern)
		std::cout << pt << "\t";

	std::cout << "\nOptions : ";
	std::vector<std::string> opt = cmdlp.getOptions();
	for (auto ot : opt)
		std::cout << ot << "\t";
	std::cout << "\n\n";

	return 0;

}
#endif