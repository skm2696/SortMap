#include "SortFile.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
 
SCENARIO("32mb", "[32mb]"){
 bool p=true;
auto begin = std::chrono::high_resolution_clock::now();
 SortFile obj("32.txt",17, "out");
 auto end = std::chrono::high_resolution_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "32 mb time: " << res << std::endl;
 
  REQUIRE(p==true);
}

SCENARIO("15mb", "[15mb]"){
 bool p=true;
auto begin = std::chrono::high_resolution_clock::now();
SortFile obj("15.txt",4, "out2");
auto end = std::chrono::high_resolution_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "15 mb time: " << res << std::endl;
 
  REQUIRE(p==true);
}

SCENARIO("8mb", "[8mb]"){
bool p=true;
auto begin = std::chrono::high_resolution_clock::now();
  SortFile obj("small.txt",1,"out8");
auto end = std::chrono::high_resolution_clock::now();
	auto res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "8 mb time: " << res << std::endl;
 
  REQUIRE(p==true);
}
