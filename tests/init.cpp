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
 bool p=true;
 string s1,s2;
 while (!file.eof()&&!out.eof()){
 getline(file,s1);
  getline(out,s2);
  if (s1!=s2||s1==""){
  p=false;
   break;
  }
 }
  file.close();
  out.close();
  REQUIRE(p==true);
}
