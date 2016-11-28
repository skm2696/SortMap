#include "SortFile.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
SCENARIO("sort", "[sort]")
{
  SortFile obj("sort.txt", 1, "fl.txt");
ifstream file("sort_small.txt");
  ifstream out("fl.txt");
 bool p=false;
 string s1,s2;
 while (!file.eof()&&!out.eof()){
 getline(file,s1);
  getline(out,s2);
  if (s1==s2 || s1==""||s2==""){
  p=true;
  }
   else
   {
     p==false;
     break;
   }
 
 }
  file.close();
  out.close();
  REQUIRE(p==true);
}
SCENARIO("file - 15 mb, memory - 4 mb", "[15 - 4]") {
	auto begin = std::chrono::high_resolution_clock::now();
	external_sort("15.txt", 4 * 1024 * 1024,"sorted15.txt");
	auto end = std::chrono::high_resolution_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	

	std::ifstream output_first("sorted15"), output_second("sorted15");
	data first, second;
	bool flag = true;
	bool check = false;
	output_second >> first.last_name >> first.first_name >> first.year;
	while (output_second) {
		output_first >> first.last_name >> first.first_name >> first.year;
		output_second >> second.last_name >> second.first_name >> second.year;
		if (!output_second) { 
			check = true;
			break;
		}
		if (!(first <= second)) {
			output_first.close();
			output_second.close();
			flag = false;
			break;
		}
	}

	REQUIRE(flag);
	REQUIRE(check);
	REQUIRE(res);
}
