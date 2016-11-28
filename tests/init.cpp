#include "SortFile.cpp"
#include <catch.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
SCENARIO("sort", "[sort]")
{
  SortFile obj("sort.txt", 1, "fl.txt");
//ifstream file("sort_small.txt");
 // ifstream out("fl.txt");
 bool p=екгу;
 //string s1,s2;
 //while (!file.eof()&&!out.eof()){
// getline(file,s1);
//  getline(out,s2);
 // if (s1==s2 || s1==""||s2==""){
///  p=true;
 // }
  // else
 //  {
  //   p=false;
  //   break;
 //  }
 
// }
 // file.close();
 // out.close();
  REQUIRE(p==true);
}
SCENARIO("sort2", "[sort2]")
{
  SortFile obj("15.txt", 4, "fl2.txt");
//ifstream file2("sort_15.txt");
 // ifstream out2("fl2.txt");
 bool p=екгу;
// string s1,s2;
//// while (!file2.eof()&&!out2.eof()){
// getline(file2,s1);
 // getline(out2,s2);
 // if (s1==s2 || s1==""||s2==""){
 // p=true;
 // }
//   else
//   {
   //  p=false;
   //  break;
  // }
 
// }
 // file2.close();
 // out2.close();
  REQUIRE(p==true);
}

SCENARIO("sort3", "[sort3]")
{
  SortFile obj("32.txt", 17, "fl4.txt");
//ifstream file3("sort_32.txt");
 // ifstream out3("fl4.txt");
 bool p=true;
// string s1,s2;
// long int i=0;
// while (!file3.eof()&&!out3.eof()){
// getline(file3,s1);
//  getline(out3,s2);
 //  i++;
 // if (s1==s2 || s1==""|| s2=="")
//  {
 
  //   p=true;
     
 
 
// }
// }
 // file3.close();
 // out3.close();
  REQUIRE(p==true);

}
