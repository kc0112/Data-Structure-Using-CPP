
#include<iostream>
#include<cstdlib>
#include"Trie.h"
#include<cstring>

using namespace std;
int main()
{
    cout<<boolalpha;
   Trie my;
   my.create_root();


   my.add("car");
  my.add("bite");
  my.add("biker");

  cout<<my.searching("bike")<<endl;
  cout<<my.searching("bite")<<endl;

   return 0;
}
