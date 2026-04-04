#ifndef STR_UTILS
#define STR_UTILS
#endif

#include <string>
#include <vector>
#include <algorithm> // For ranges
#include <cctype>    // For toupper

namespace str{
    struct utils;
}

struct str::utils{

// str::util.trim(string) removes spaces from the string
   utils& despace(std::string& s){
       s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
       return *this;
   }
// str::utils.split(string, vector) breaks a string into a vector without 
   utils& split(std::string& s, std::vector<std::string>& container){
       size_t string_whitespace{s.find(' ')};
       size_t pos{0};
       while(string_whitespace != s.length()){
          container.push_back(std::string(s.substr(pos, string_whitespace - pos)));
          pos = string_whitespace + 1;
          string_whitespace = pos;
       }
       return *this;
   }
//str::utils.uppercase(string) - converts text to UPPERCASE using ::toupper
    utils& uppercase(std::string& s){
       std::transform(s.begin(), s.end(), s.begin(), ::toupper);
       return *this;
 }
//str::utils.bond - joins a list of words with a separator (like a dash)
    utils& bond(std::vector<std::string>& sentence, const char separator){
        std::string s;
        for(auto& word : sentence){
            s += word + separator;
        }
        return *this;
    }
// Bonus for v0.2: Replace all instances of a word
};
