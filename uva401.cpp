/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <utility>
#include <vector>


using namespace std;

inline bool IsPalindrome(const std::string& word) {
  int n = word.size();
  for (int i = 0, j = n-1; i < j; i++, j--) {
    if (word[i] != word[j]) return false;
  }
  return true;
}

inline bool IsMirrored(const std::string& word, const vector<char>& mirrors) {
  int n = word.size();
  for (int i = 0; i < n; i++) {
    int j = n-1-i;
    if (j < i) break;
    if (mirrors[word[i]] == '.') return false; // Non mirrored char
    if (mirrors[word[i]] != word[j]) return false;
  }
  return true;
}

const std::string kPalindromeStrMsg = " -- is a regular palindrome.";
const std::string kRegularStrMsg = " -- is not a palindrome.";
const std::string kMirroredPalindromeStrMsg = " -- is a mirrored palindrome.";
const std::string kMirroredStrMsg = " -- is a mirrored string.";

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    std::string input;
    vector<char> mirrors_list(256, '.');
    const string& mirrors_s = "AEHIJLMOSTUVWXYZ12358";
    const string& mirrors_t = "A3HILJMO2TUVWXY51SEZ8";
    for (int i = 0; i < mirrors_s.size(); i++) {
      mirrors_list[mirrors_s[i]] = mirrors_t[i];
    }

    while(std::getline(std::cin, input)) {
      std::cout << input;
      bool is_palindrome = IsPalindrome(input);
      bool is_mirrored = IsMirrored(input, mirrors_list);
      if (is_palindrome && is_mirrored) {
        std::cout << kMirroredPalindromeStrMsg;
      } else if (is_palindrome) {
        std::cout << kPalindromeStrMsg;
      } else if (is_mirrored) {
        std::cout << kMirroredStrMsg;
      }else {
        std::cout << kRegularStrMsg;
      }
      std::cout << std::endl << std::endl;
    }

    
    return 0;
}

