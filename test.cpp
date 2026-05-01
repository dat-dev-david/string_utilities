#include <iostream>
#include "strutils.h"

int main(){
   str::utils utils;
   std::string s{"h g h u i ytr"};
   std::string s2 = utils.despace(s);
   std::cout << s2;
   return 0;
}