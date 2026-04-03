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
// 2. The Bread Knife: Slices a string into a container (vector)
// 3. The Shouter: Converts text to UPPERCASE using Modern Ranges
// 4. The Scout: Checks if a word is hidden inside another
// 5. The Glue: Joins a list of words with a separator (like a dash)
// Bonus for v0.2: Replace all instances of a word
};