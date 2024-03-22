#include <bits/stdc++.h>

using namespace std;
/*
1. 홀수 보기
2. 짝수 보기
*/

int checkOddPalindrome(string s) {
    int result = 0;
    
    for(int i=0; i<s.size(); i++) {
        int left = i - 1;
        int right = i + 1;
        int cnt = 1;
        while(left >= 0 && right < s.size()) {
            if(s[left] == s[right]) {
                left--;
                right++;
                cnt += 2;
                continue;
            }
            break;
        }
        result = max(result, cnt);
    }
    
    return result;
}

int checkEvenPalindrome(string s) {
    int result = 0;
    
    for(int i=0; i<s.size(); i++) {
        int left = i;
        int right = i + 1;
        int cnt = 0;
        while(left >= 0 && right < s.size()) {
            if(s[left] == s[right]) {
                left--;
                right++;
                cnt += 2;
                continue;
            }
            break;
        }
        result = max(result, cnt);
    }
    
    return result;
}

int solution(string s)
{
    int answer = 0;
    answer = max(answer, checkOddPalindrome(s));
    answer = max(answer, checkEvenPalindrome(s));
    return answer;
}