#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convertNum(int num, int n) {
    string result = "";
    if(num == 0) { return "0"; }
    
    while(num != 0) {
        char c;
        int tmp = num % n;
        num = num / n;
        
        if(tmp >= 10) {
            c = 'A' + (tmp - 10);
        }
        else {
            c = tmp + '0';
        }
        result += c;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0, now = 0;
    
    while(1) {
        string str = convertNum(num, n);
        num += 1;
        
        for(int i=0; i<str.size(); i++) {
            if(now % m == p-1) {
                answer += str[i];
            }
            if(answer.size() == t) return answer;
            now += 1;
        }
    }
    
    
    return answer;
}