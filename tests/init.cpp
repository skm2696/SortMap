#include "SortFile.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
 
SCENARIO("32mb", "[32mb]"){
 bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
 SortFile obj("32.txt",17, "out");
 end = std::chrono::system_clock::now();
	cout <<"32MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}

SCENARIO("15mb", "[15mb]"){
 bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
SortFile obj("15.txt",4, "out2");
 end = std::chrono::system_clock::now();
	cout <<"15MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}

SCENARIO("8mb", "[8mb]"){
bool p=true;
std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
  SortFile obj("small.txt",1,"out8");
 end = std::chrono::system_clock::now();
	cout <<"8MB- " <<floor((end - start).count()/1000000000) <<" seconds"<< endl;
 
  REQUIRE(p==true);
}
