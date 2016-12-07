
#include <iostream>
#include "SortFile.h"
#include <stdexcept>
#ifndef SORT_CPP
#define SORT_CPP

SortFile::~SortFile()
{
	file_names.clear();
}
SortFile::SortFile(string name_main_file, size_t buffer_, string name_out_file) :file(name_main_file), buffer(buffer_*1024*1024), s_out(name_out_file), count_of_files(0), closed_files(0)
{
	if (file.is_open())
	{
		division();
	}
}
auto SortFile::make_file(string name_file)->void
{
	file_names.push_back(name_file);
	ofstream temp(name_file);
	for (auto i : lines)
	{
		temp << i.surname+' '+i.name+' '+i.date << endl;
	}
	temp.close();
	lines.clear();
}
auto SortFile::file_size(string name_file)->size_t
{
	long fsize;
	ifstream temp(name_file);
	temp.seekg(0, ios::end);
	fsize = temp.tellg();
	temp.close();
	return fsize;
}
auto SortFile::out_file(full_name line)->void
{
	ofstream file(s_out, ios::app);
	file << line.surname+' '+line.name+' '+line.date << endl;
	file.close();

}
auto SortFile::remove_temp_files()->void
{
	for (int i = 0; i < file_names.size(); ++i)
	{
		if (remove(file_names[i].c_str()) == -1)
		{
			throw;
		}
		else
		{
			cout << "Good";
		}
	}

}
auto SortFile::sort()->void
{
	ifstream *streams = new ifstream[count_of_files];
	string *top_line = new string[count_of_files];
	for (int i = 0; i < count_of_files; ++i)
	{
		streams[i].open(file_names[i]);
		getline(streams[i], top_line[i]);
		map.insert(pair<string, size_t>(top_line[i], i));
	}

	while (!map.empty())
	{
		auto it = map.begin();
		int n = (*it).second;
		out_file((*it).first);
		if (!streams[n].eof())
		{
			getline(streams[n], top_line[n]);
			map.erase(map.begin());
			map.insert(pair<string, size_t>(top_line[n], n));
		}
		else
		{
			closed_files++;
			streams[n].close();
			map.erase(map.begin());

		}
	}

}

auto SortFile::division()->void
{
	string line_of_file;
	size_t temp_size_files = 0;
	while (!file.eof())
	{
		getline(file, line_of_file);
		temp_size_files += line_of_file.size();
		if (temp_size_files <= buffer)
		{
			lines.emplace(line_of_file);
		}
		else
		{
			count_of_files++;
			make_file(to_string(count_of_files) + ".txt");
			lines.emplace(line_of_file);
			temp_size_files = line_of_file.size();
		}
	}
	file.close();

	if (lines.size())
	{
		count_of_files++;
		make_file(to_string(count_of_files) + ".txt");
	}


	sort();
};

/*int main()
{
	new_file("names.txt", 120);
	SortFile obj("names.txt");
	const int N = 256;
	char S[N] = { "" };
	ifstream in1("abcd.txt"); 
	while (!in1.eof()) 
	{
		in1.getline(S, N); 
		cout << S << endl; 
	}
	in1.close();  
	system("pause");
	return 0;
}*/
#endif
