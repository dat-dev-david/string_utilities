#ifndef STR_UTILS
#define STR_UTILS
#endif

#include <string>
#include <string_view>
#include <vector>
#include <algorithm> // For ranges
#include <cctype>    // For toupper

namespace str{
    struct utils;
}

struct str::utils{

// str::util.trim(string) Removes spaces from the string
   utils& trim(std::string& s){
       s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
       return *this;
   }
// str::utils.split breaks a string into a vector without 
   utils& split(std::string& s, std::vector<std::string>& container, char whitespace){
       size_t string_whitespace{s.find(whitespace)};
       size_t pos{0};
       while(string_whitespace != s.length()){
          container.push_back((s.substr(pos, string_whitespace - pos)));
          pos{string_whitespace + 1};
          string_whitespace{pos};
       }
       return *this;
   }
// 3. The Shouter: Converts text to UPPERCASE using Modern Ranges
// 4. The Scout: Checks if a word is hidden inside another
// 5. The Glue: Joins a list of words with a separator (like a dash)
// Bonus for v0.2: Replace all instances of a word
};