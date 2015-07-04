#ifndef CATALOG_H
#define CATALOG_H
//////////////////////////////////////////////////////////////////////////////////////
// Catalog.h -     Supports Text Search in the files present in the filestorage and //
//                 provides supporrt to store the file in the filestorage           //
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
This package provides a single class: Catalog.
-This class is intended to Support Text Search in the files present in the filestorage and
provides supporrt to store the file in the filestorage


Function Prologues - Public Interfaces
======================================
TextSearch();			//search for particular text in the files stored in the filestorage


Required Files:
================
Catalog.h, Catalog.cpp, FileSystem.cpp

Maintenance History:
=====================
Ver 1.0 - 02 Feb 2015
- first release
*/

#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<string>
#include"../FileStorage/FileStorage.h"
#include"../FileMgr/FileMgr.h"
#include"../FileMgr/FileSystem.h"
#include"../Display/Display.h"

class Catalog 
{
public:
	Catalog(FileStorage &fs) : store(fs){}					//constructor for named instance
	std::string TextSearch(std::string& text, std::string& file);
	void FindTextinFile_Patt(std::string&text, std::string&patt);
	
private:
	FileStorage& store;							// reference to class FileStorage 
	

};
#endif
