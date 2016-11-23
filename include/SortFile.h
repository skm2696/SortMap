#pragma once
#ifndef SORT_HPP
#define SORT_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue> 
#include <map> 
#include <iterator>
#include <algorithm>
#include <cstdio>
using namespace std;
auto str_to_vec(string str) -> vector<string>
{
	std::vector<string> buf;
	if (str == "")
		return buf;
	size_t k = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			if (str[k] != ' ')
			{
				buf.push_back(str.substr(k, i - k));
			}

			k = i + 1;
			continue;
		}
		if (i == str.length() - 1)
		{
			buf.push_back(str.substr(k, i - k + 1));

		}
	}
	return buf;
}
struct Compare
{
	bool operator() (string str1, string str2)
	{
		if (str1 == "" || str2 == "")
			return false;
		if (str_to_vec(str1)[1] == str_to_vec(str2)[1])
			return (str_to_vec(str1)[0] < str_to_vec(str2)[0]);
		return (str_to_vec(str1)[1] < str_to_vec(str2)[1]);
	}
};
class SortFile
{
public:
	SortFile(string name_main_file, size_t buffer_, string name_out_file);
	auto file_size(string name_file)->size_t;
	auto make_file(string name_file)->void;
	auto sort()->void;
	auto out_file(string line)->void;
	auto remove_temp_files()->void;
	~SortFile();
	auto division() -> void;

private:
	fstream file, f;
	size_t buffer, count_of_files, closed_files;
	bool out;
	string s_out;
	vector<string> lines;
	vector<string> file_names;
	multimap<string, size_t, Compare> map;
};
#include "SortFile.cpp"
#endif
