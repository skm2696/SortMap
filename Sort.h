#pragma once
#include "stdafx.h"
#ifndef SORT_HPP
#define SORT_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include <iterator>
#include <algorithm>
#include <cstdio>
using namespace std;
class SortFile
{
public:
	SortFile(string name_main_file, size_t buffer, string name_out_file);
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto sort()->void;
	auto out_file(string line, string name_out_file)->void;
	auto remove_temp_files()->void;
	~SortFile();
private:
	fstream file, f;
	size_t buffer, count_of_files, closed_files;
	bool out;
	vector<string> lines;
	vector<string> file_names;
	multimap<string, size_t> map;
};
#include "SortFile.cpp"
#endif
