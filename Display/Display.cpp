//////////////////////////////////////////////////////////////////////////////////
// Display.cpp -   Implemented to support console display part of Project       //
//				                                                                //
// ver 1.0                                                                      //
// Language:       Visual C++ 2013                                              //
// Application:    CSE687 - Project 1 (File Catalogue), Spring 2015             //
// Platform:       HP G62, Windows 7 Home Premium, Visual Studio 2013           //
// Author:         Dhivya Narayanan, Master's- Computer Engineering,            //
//				   Syracuse University,                                         //
//                 dnnaraya@syr.edu                                             //
//////////////////////////////////////////////////////////////////////////////////
#include"Display.h"

//----< Displays only duplicate files and their paths >------------------------------------

void Display::display_duplicates()
{
	int count_files = 0;
	std::set<std::string> temp_pathset;
	std::cout << "\n\n<======= Duplicate Files and their paths ==========>\n\n";
	std::cout << " File Name\t" << " Paths in which the file is present\n";
	std::cout << "-------------    -------------------------------------\n";
	FileStorage::iter_map it_map = filestore_.begin();
	while (it_map != filestore_.end())
	{
		if (it_map->second.size() > 1)
		{
			FileStorage::iter_list it_list = it_map->second.begin();
			count_files++;
			std::cout << "\n " << it_map->first << "\n    \t\t";
			while (it_list != it_map->second.end())
			{
				std::cout << *(*(it_list)) << "\n    \t\t";
				temp_pathset.insert(**it_list);
				it_list++;
			}
			std::cout << "\n";
		}
		it_map++;
	}
	//std::cout << "\n-----------------------------End of files------------------------\n\n";
	std::cout << "\n\n-------------< Summary of duplicates files found in the given path >-----------\n\n";
	std::cout << " No.of Files       :\t " << count_files << "\n";
	std::cout << " No.of Directories :\t " << temp_pathset.size() << "\n\n";
	std::cout << "------------------------------------------------------------------------------\n\n";
}

//----< Displays all the file names and paths present in the FileStorage, if needed displays only duplicate files >---------------------------------------

void Display::display_filesandpaths()
{
	//display all files and their paths

	std::cout << "\n\n<=== All Files and their paths present in the given path and patterns ====>\n\n";
	std::cout << " File Name\t" << " Paths in which the file is present\n";
	std::cout << "-------------     ------------------------------------\n";
	FileStorage::iter_map it_map = filestore_.begin();
	while (it_map != filestore_.end())
	{
		FileStorage::iter_list it_list = it_map->second.begin();
		std::cout << "\n " << it_map->first << "\n    \t\t";
		while (it_list != it_map->second.end())
		{
			std::cout << *(*(it_list)) << "\n    \t\t";
			it_list++;
		}
		std::cout << "\n";
		it_map++;
	}
	std::cout << "\n\n-------------< Summary of all files found in the given path >-----------\n\n";
	std::cout << " No.of files       :\t" << filestore_.size() << "\n";
	std::cout << " No.of directories :\t" << filestore_.set_size() << "\n\n";
	std::cout << "-----------------------------------------------------------------\n\n";
}

//----< Displays all the files with the given pattern or given file which contains the particular text >---------------------------------------

void Display::display_text_filePatt(std::string& text, std::string& filepatt)
{
	Catalog cs(filestore_);
	std::set<std::string> temp_file;
	std::set<std::string> temp_path;
	std::vector<std::string> TextinFiles = cs.FindText_in_File(text, filepatt);
	std::cout << "\n------< The given text found in following file paths >--------\n\n";
	std::cout << " File Name\t" << " Paths in which the file is present\n";
	std::cout << "-----------     ------------------------------------\n";
	for (size_t i = 0; i < TextinFiles.size(); i++)
	{
		std::cout << FileSystem::Path::getName(TextinFiles[i]) << "\n    \t\t";
		temp_file.insert(FileSystem::Path::getName(TextinFiles[i]));
		std::cout << FileSystem::Path::getPath(TextinFiles[i]) << "\n\n";
		temp_path.insert(FileSystem::Path::getPath(TextinFiles[i]));
	}

	std::cout << "\n\n---------< Summary of files which contains the given text >-------\n\n";
	std::cout << " Total No.of files  :  " << TextinFiles.size() << "\n";
	std::cout << " No.of Unique files :  " << temp_file.size() << "\n";
	std::cout << " No.of Unique paths :  " << temp_path.size() << "\n\n";
	std::cout << ".....................................................................\n\n";
}

//----< Displays all the files which contains the particular text >---------------------------------------

void Display::display_textsearch(std::string & text)
{
	int count = 0;
	Catalog cs(filestore_);
	std::set<std::string> temp_file;
	std::set<std::string> temp_path;
	std::cout << "--------< The given text found in following file paths >--------\n\n";
	std::cout << " File Name\t" << " Paths in which the file is present\n";
	std::cout << "-------------     ------------------------------------\n";
	// iterate through the map to get the files
	FileStorage::iter_map it_map = filestore_.begin();
	while (it_map != filestore_.end())
	{
		FileStorage::iter_list it_list = it_map->second.begin();
		while (it_list != it_map->second.end())
		{
			std::string t_path = FileSystem::Path::fileSpec(**it_list, it_map->first);
			std::string FileContainsText = cs.TextSearch(text, t_path);
			if (FileContainsText != "")
			{
				std::cout << "\n " << it_map->first << "\n    \t\t";
				temp_file.insert(it_map->first);
				std::cout << *(*(it_list)) << "\n    \t\t";
				temp_path.insert(**it_list);
				count++;
			}
			it_list++;
		}
		it_map++;
	}
	std::cout << "\n\n-------< Summary of files which contains the given text >-------\n\n";
	std::cout << " Total No.of files  :  " << count << "\n";
	std::cout << " No.of unique files :  " << temp_file.size() << "\n";
	std::cout << " No.of unique paths :  " << temp_path.size() << "\n\n";
	std::cout << "..................................................................\n\n";
}

//----< Displays summary about the files present in the filestorage  >---------------------------------------

void Display::display_summary()
{
	std::cout << "\nSummary of files found in the given path with the given patterns\n";
	std::cout << "===================================================================\n\n";
	std::cout << "Path : \t" << cmd_.getPath() << "\n\n";
	std::cout << "No.of files       : \t" << filestore_.size() << "\n";
	std::cout << "No.of directories : \t" << filestore_.set_size() << "\n\n";
	std::cout << "---------< List of file(s) and their path(s) >---------------\n\n";
	std::cout << "  File Name \t" << "        Path name\n";
	std::cout << "-----------\t" << "---------------------------------\n";

	FileStorage::iter_map it_map = filestore_.begin();
	while (it_map != filestore_.end())
	{
		FileStorage::iter_list it_list = it_map->second.begin();
		std::cout << "\n " << it_map->first << "\n    \t\t";
		while (it_list != it_map->second.end())
		{
			std::cout << *(*(it_list)) << "\n    \t\t";
			it_list++;
		}
		std::cout << "\n";
		it_map++;
	}
	std::cout << "\n\n-----------------------------------------------------------------\n\n";
}

//----< Display command line arguments  >---------------------------------------

void Display::display_cmdline_info()
{
	std::cout << "\n\n<==== Given Commandline Arguments =====>\n\n";
	path = cmd_.getPath();
	std::cout << " Path     : " << path << "\n";

	pattern = cmd_.getPatterns();
	std::cout << " Patterns : ";
	for (auto pt : pattern)
		std::cout << pt << "\t";

	std::cout << "\n Options  : ";
	opt = cmd_.getOptions();
	for (auto ot : opt)
		std::cout << ot << "\t";
	std::cout << "\n\n";
}

//----< test stub >--------------------------------------------------------

#ifdef TEST_DISPLAY

int main(int argc, char*argv[])
{
	std::cout << "Testing Display....\n";
	std::cout << "-------------------------------\n";
	FileStorage fs;
	CmdlineParser cmd(argv);

	cmd.parsecmdline(argc, argv);				//parse commandline arguments
	std::string Path_ = cmd.getPath();

	FileMgr fm(Path_, fs);
	Display dp(fs, cmd);

	std::vector<std::string> Patterns_ = cmd.getPatterns();
	for (auto pat : Patterns_)
		fm.addPattern(pat);
	fm.search();								//search and store all files in the given path

	dp.display_cmdline_info();
	dp.display_filesandpaths();
	dp.display_duplicates();
	dp.display_summary();

	std::string sample_txt = "class";
	dp.display_textsearch(sample_txt);

	return 0;
}

#endif