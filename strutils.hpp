#ifndef STR_UTILS
#define STR_UTILS
#endif

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string_view>

namespace str{

//i really don't know why i added this space :/
    struct utils;

}

struct str::utils{

// str::utils.despace(string) - removes spaces from the string
   utils& despace(std::string& s){

       /*erase the spaces from the string using ::isspace as a sub for: *
        * (' ' || '\n' || '\t' || '\r' || '\v' || '\f')                 */
       s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
       return *this;

   }

// str::utils.split(string, vector) - breaks a string into a string vector 
   utils& split(std::string_view s, std::vector<std::string>& container){

       //"string_whitespace" is for where 
       size_t whitespace_pos{s.find(' ' || '\n' || '\t' || '\r' || '\v' || '\f')};

       //"pos" is for the range of the substring to add to the container
       size_t pos{0};

       //updated position of where the whitespace is
       size_t updated_whitespacepos{s.find(' ' || '\n' || '\t' || '\r' || '\v' || '\f', whitespace_pos)};

       //while the position of the whitespace is in the string bounds
       //add the substring to the container                         
       while(whitespace_pos != std::string::npos){
          container.push_back(std::string(s.substr(pos, whitespace_pos - pos)));
          pos = whitespace_pos + 1;
          whitespace_pos = updated_whitespacepos;
          updated_whitespacepos = s.find(' ', whitespace_pos + 1);

       }
       return *this;

   }

//str::utils.uppercase(string) - converts text to UPPERCASE using ::toupper
    utils& uppercase(std::string& s){

       //transform the range of the start and end of the string to uppercase
       std::transform(s.begin(), s.end(), s.begin(), ::toupper);
       return *this;

 }

//str::utils.bond - joins a list of words with a separator (like a dash)
    utils& bond(std::vector<std::string_view>& sentence, const char separator){

        //make a string to store the otuput of the function
        std::string s;

        //for every word in the string vector make the string equal to the word with the seperator
        for(auto& word : sentence){
            s += std::string(word) + separator;
        }
        return *this;

    }

// str::utils.replace(string, temporary, replacement) - replaces all instances of a word with another word
    utils& replace(std::string& s, std::string_view temporary, std::string_view replacement){

        //position of the replaceable word
        size_t pos{0};
        size_t new_pos{s.find(temporary, pos)};

        //if the position of the replaceable word is in the string bounds:
        while(new_pos != std::string::npos){

            //make the position move to the next possible replaceable word and replace the current one
            s.replace(new_pos, temporary.length(), replacement);
            pos = new_pos + replacement.length();
            new_pos = s.find(temporary, pos);

        }

    }

};
