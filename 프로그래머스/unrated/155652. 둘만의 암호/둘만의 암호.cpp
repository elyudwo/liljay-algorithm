#include <string>
#include <vector>

using namespace std;

bool check[26];

char changeChar(char c, string skip, int index) {
    while(index--) {
        c = c + 1;
        int tmp = c;
        
        if(tmp == 'z' + 1) { c = 'a'; }
        
        while(1) {
            bool check = false;
            
            for(int i=0; i<skip.size(); i++) {
                if(skip[i] == c) {
                    c = c + 1;
                    int tmp = c;
                    if(tmp == 'z' + 1) { c = 'a'; }
                    check = true;
                }
            }
            
            if(!check) { break; }
        }
    }
    
    return c;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        c = changeChar(c, skip, index);
        answer += c;
    }
    
    return answer;
}