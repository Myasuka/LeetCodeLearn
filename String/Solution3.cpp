#include "Solution3.h"

int Solution3::strStr(string haystack, string needle){
    if(haystack.size() < needle.size()) return -1;
        int i,j;
        for(i=0; i<= (haystack.size() - needle.size()); i++){
            int tmp = i;
            for(j=0; j< needle.size(); j++){
                if(haystack[tmp] == needle[j]){
                    ++ tmp;
                    continue;
                }else break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
}


char* Solution3::strStr(const char *haystack, const char *needle){
    int h = strlen(haystack);
    int n = strlen(needle);
    if(h < n) return nullptr;
    int j;
    for(int i=0; i<h; i++){
        int tmp = i;
        for(j = 0; j < n; j++){
            if(haystack[tmp] == needle[j]){
                ++ tmp;
                continue;
            }else break;
        }
        const char *p = haystack;
        if(j == n) return (char*)p + i;
    }
    return nullptr;
}

int Solution3::myAtoi(string str)
{
    int result = 0, ratio = 1;
    bool strange = false;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == '+' ) {
            if(!strange){
                strange = true;
                continue;
            }else return 0;
        }
        if(str[i] == '-') {
            if(!strange){
                strange = true;
                result *= -1;
                continue;
            }else return 0;
        }
        int tmp = str[i] - '0';
        if(tmp <= -16) continue;
        if(tmp < 0 && tmp > -16) {
            if(!strange){
                strange = true;
                continue;
            }else return 0;
        }
        result += (tmp) * ratio;
        ratio *= 10;
    }
    return result;
}

// force solution, 60ms
string Solution3::longestPalindrome1(string s){
        int size = s.size();
        int low = 0;
        int high = 0;
        for(int i=0; i < size; i++){
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && right <= size - 1){
                if(s[left] == s[right]){
                    --left;
                    ++right;
                }else break;
            }
            ++left;
            --right;
            if((right - left) > (high - low)){
                low = left;
                high = right;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 && right <= size - 1){
                if(s[left] == s[right]){
                    --left;
                    ++right;
                }else break;
            }
            ++left;
            --right;
            if((right - left) > (high - low)){
                low = left;
                high = right;
            }
        }
        return s.substr(low, high - low + 1);
}

// dynamic solution, 168 ms 
string Solution3::longestPalindrome2(string s){
        int size = s.size();
        int low = 0;
        int high = 0;
        bool f[size][size];
        for(int i = 0; i < size; i++){
            f[i][i] = true;
            for(int j=0;j<=i; j++){
                if(j == i) continue;
                if(j == i-1){
                if(s[i] == s[j]){
                    f[j][i] = true;
                    if(1 >(high -low)){
                        low = j;
                        high = i;
                    }
                }else f[j][i] = false;
                }else {
                    f[j][i] = f[j+1][i-1] && s[i] == s[j];
                    if(f[j][i] && (i - j)>(high -low)){
                        low = j;
                        high = i;
                    }
                }
        }
        }
        return s.substr(low, high - low + 1);
}

// dynamic solution, 314 ms 
string Solution3::longestPalindrome3(string s){
        const int n = s.size();
        bool f[n][n];
        // fill the bool matrix is needless, and consume time
        fill_n(&f[0][0], n * n, false);
        size_t max_len = 1, start = 0; // 最长回文子串的长度，起点
        for (size_t i = 0; i < s.size(); i++) {
            f[i][i] = true;
            for (size_t j = 0; j < i; j++) { // [j, i]
                f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                if (f[j][i] && max_len < (i - j + 1)) {
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, max_len);
}