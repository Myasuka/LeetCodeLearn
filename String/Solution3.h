#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#ifndef SOLUTION3_H
#define SOLUTION3_H
class Solution3 {
public:
    // Implement strStr()
    int strStr(string haystack, string needle);
    // old Implement strStr()
    char *strStr(const char *haystack, const char *needle);
    // String to Integer (atoi)
    int myAtoi(string str);
    // Longest Palindromic Substring
    string longestPalindrome1(string s);
    string longestPalindrome2(string s);
    string longestPalindrome3(string s);
};
#endif //SOLUTION3_H