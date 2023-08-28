#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;
vector<string> user;
vector<string> banned;
vector<string> vec;
unordered_set<string> st; 
bool check[9];

bool checkBanned(int num, string str) {
    string cmp = banned[num];
    if(cmp.size() != str.size()) { return false; }
    for(int i=0; i<str.size(); i++) {
        if(cmp[i] == '*') { continue; }
        if(cmp[i] != str[i]) { return false; }
    }
    
    return true;
}

void dfs(int num) {
    if(num > banned.size()) return;
    if(vec.size() == banned.size()) {
        string str = "";
        vector<string> rem = vec;
        sort(rem.begin(), rem.end());
        
        for(int i=0; i<rem.size(); i++) { str += rem[i]; }
        
        if(st.find(str) == st.end()) {
            st.insert(str);
            answer += 1;
        }
        return;
    }
    
    for(int i=0; i<user.size(); i++) {
        if(check[i]) continue;
        if(checkBanned(num, user[i])) {
            check[i] = true;
            vec.push_back(user[i]);
            dfs(num + 1);
            check[i] = false;
            vec.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id; banned = banned_id;
    dfs(0);
    
    return answer;
}