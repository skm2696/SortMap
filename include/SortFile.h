#pragma once
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

struct full_name {
	string surname, name;
	short date;
	size_t size() const
	{
		return (surname.capacity() + name.capacity() + sizeof(date) + 2 * sizeof(" "));
	}
};

bool operator <(const full_name& s1, const full_name& s2)
{
	return (s1.name < s2.name);
}

bool operator >(const full_name& s1, const full_name& s2)
{
	return (s1.name > s2.name);
}

istream & operator >> (istream & in, full_name& s)
{
	in >> s.surname >> s.name >> s.date;
	return in;
}
ostream & operator<<(ostream & out, full_name const & s)
{
	out << s.surname << " " << s.name << " " << s.date << endl;
	return out;
}

class SortFile {
public:
	SortFile(string name_main_file, size_t buff_size, string out_file);
	auto division()->void;
	auto make_file(string name_file)->void;
	auto sort()->void;
private:
	string s_out, s_in;
	size_t count_of_files;
	vector<string> file_names;
	vector<full_name> line;
	uint_fast64_t buffer;
	multimap<full_name, size_t> map;

};

#include "SortFile.cpp"
#endif
