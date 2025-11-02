#include <bits/stdc++.h>

using namespace std;

#include <cctype>
#include <vector>
#include <algorithm> 
#include <cctype>

/*
 * Complete the 'isAlphabeticPalindrome' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code as parameter.
 */

bool isAlphabeticPalindrome(string code) {
  if (code.length() == 0) {return true;}
  if (code.length() == 1) {return true;}
  vector<char> temp;
  for(size_t i = 0 ; i < code.length();++i) {
    if (std::isalpha(static_cast<unsigned char>(code.at(i)))) {
        temp.push_back(code.at(i));
    }
  }
  string temp1(temp.begin(),temp.end());
  std::transform(temp1.begin(), temp1.end(),temp1.begin(),
                   [](unsigned char c){ return std::toupper(c); });
  int left =0;
  int right = temp1.length()-1;
  while(left < right) {
  if(temp1.at(left) != temp1.at(right)) {
    return false;
  } else {
    left++;
    right--;
  }  
  }
  return true;
}
