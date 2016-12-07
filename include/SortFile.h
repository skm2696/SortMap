#pragma once
#ifndef SORT_HPP
#define SORT_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue> 
#include <map> 
#include <set>
#include <iterator>
#include <algorithm>
#include <cstdio>
using namespace std;
class full_name
{
public:
	string name;
	string surname;
	string date;
	full_name(string current_str);
	friend bool operator<(const full_name& a, const full_name& b)
	{
		if (a.name == "" || b.name == "")
			return false;
		return a.name < b.name;
	}
	
};

full_name::full_name(string current_str)
{
	if (current_str != "")
	{
		size_t k = 0;
		size_t i = 0;

		while (current_str[i] != ' ')
			++i;

		surname = current_str.substr(k, i - k);
		k = i + 1;
		++i;
		while (current_str[i] != ' ')
			++i;

		name = current_str.substr(k, i - k);
		date = current_str.substr(i + 1, current_str.length() - i - 1);
	}
	else
	{
		surname = "";
		name = "";
		date = "";
	}
}

class SortFile
{
public:
	SortFile(string name_main_file, size_t buffer_, string name_out_file);
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto sort()->void;
	auto out_file(full_name line)->void;
	auto remove_temp_files()->void;
	~SortFile();
	auto division() -> void;
private:
	fstream file, f;
	size_t buffer, count_of_files, closed_files;
	string s_out;
	multiset<full_name> lines;
	vector<string> file_names;
	multimap<full_name, size_t> map;
};

#include "SortFile.cpp"
#endif
