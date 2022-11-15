#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"


using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(std::string rawWords)
{

    //rawWords = "test hello test. test";
    rawWords = trim(rawWords);
    std::stringstream ss(rawWords);
    std::string token;

    std::set<std::string> s;

    while(std::getline(ss, token, ' ')) //separate at spaces
    {
      int lstIndex = 0; //keep track of index at last split at punctuation
      for (unsigned int i = 0; i < token.length(); i++)
      {
        if (ispunct(token[i]))
        {
          //if size of keyword > 1 -> insert substring from last punc to current punc
          if (i-lstIndex > 1) s.insert(convToLower(token.substr(lstIndex, i-lstIndex)));
          lstIndex = i+1; //move lstIndex so its not sitting on the punc
        }
      }

      //add remaning space from last punc to keywords
      if (token.length()-lstIndex > 1) s.insert(convToLower(token.substr(lstIndex, token.length()-lstIndex)));
    }

  return s;









}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
