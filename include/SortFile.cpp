
#include <iostream>
#include "SortFile.h"
#include <stdexcept>
#ifndef SORT_CPP
#define SORT_CPP
#include <memory>

using namespace std;

inline SortFile::SortFile(string name_main_file, size_t buff_size, string out_file) :s_in(name_main_file), s_out(out_file), count_of_files(0), buffer(buff_size * 1024 * 1024 * 0.9) 
{
	line.reserve(buffer);
	file_names.reserve(512);
	division();
};

inline auto SortFile::make_file(string name_file)->void 
{
	file_names.push_back(name_file);
	std::sort(line.begin(), line.end());
	ofstream temp(name_file, ios::binary);
	for (auto i : line) 
		if (i.surname != "") 
			temp << i;
	temp.close();
	line.clear();
}

inline auto SortFile::sort()->void 
{
	ifstream *streams = new ifstream[count_of_files];
	full_name person;
	for (int i = 0; i < count_of_files; ++i)
	{
		streams[i].open(file_names[i]);
		*streams >> person;
		map.insert(pair<full_name, size_t>(person, i));
	}

	ofstream f12(s_out, ios::binary);
	while (!map.empty())
	{
		auto it = map.begin();
		int n = (*it).second;
		f12<<((*it).first);
		if (!streams[n].eof())
		{
			streams[n]>> person;
			map.erase(map.begin());
			map.insert(pair<full_name, size_t>(person, n));
		}
		else
		{
			streams[n].close();
			map.erase(map.begin());

		}
	}

	for (int i = 0; i < file_names.size(); ++i) 
	{
		remove(file_names[i].c_str());
	}

}

inline auto SortFile::division()->void {
	size_t i(0);
	full_name person;
	ifstream file(s_in, ios::binary);
	while (!file.eof()) 
	{
		file >> person;
		i += person.size();
		if (i<buffer) 
		{
			line.push_back(person);
		}
		else 
		{
			count_of_files++;
			make_file(to_string(count_of_files));
			line.push_back(person);
			i = person.size();
		}
	}
	file.close();
	if (!line.empty()) {
		count_of_files++;
		make_file(to_string(count_of_files));
	}
	sort();
}


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
