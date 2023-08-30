#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string,int> m;
set<string> st;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for(string str : gems) { st.insert(str); } 
    
    int l = 0, r = 0, answer_r, answer_l = 0;
    int length;
    
    for(int i=0; i<gems.size(); i++) {
        st.erase(gems[i]);
        m[gems[i]] += 1;
        if(st.size() == 0) {
            length = i;
            answer_r = i;
            r = i;
            break;
        }
    }
    
    
    while(l < gems.size()) {
        string left = gems[l];
        m[left] -= 1;
        l += 1;
        if(m[left] == 0) {
            bool check = false;
            
            for(int j=r+1; j<gems.size(); j++) {
                m[gems[j]] += 1;
                if(gems[j] == left) {
                    check = true;
                    r = j;
                    break;
                }
            }
            
            if(!check) { break; }
        }
        else if(r - l < answer_r - answer_l) {
            answer_r = r; answer_l = l;
        }
    }
    
    answer.push_back(answer_l+1); answer.push_back(answer_r+1);
    return answer;
}