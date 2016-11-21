SCENARIO("sort", "[sort]"){
  SortFile obj("small.txt", 512, "file.txt");
 ifstream file("sort_small.txt");
 bool p=true;
 string s1,s2;
 while (!file.eof()&&!out.eof()){
 getline(file,s1);
  getline(out,s2);
  if (s1!=s2){
  p=false;
   break;
  }
 }
  file.close();
 out.close();
  REQUIRE(p==true);
}
