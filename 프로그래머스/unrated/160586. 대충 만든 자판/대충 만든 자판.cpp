#include <string>
#include <vector>
#include <map>

using namespace std;

map<char,int> ma;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i=0; i<keymap.size(); i++) {
        for(int j=0; j<keymap[i].size(); j++) {
            if(ma[keymap[i][j]] == 0) {
                ma[keymap[i][j]] = j+1;
            }
            else if(ma[keymap[i][j]] > j+1) {
                ma[keymap[i][j]] = j+1;
            }
        }
    }
    
    for(int i=0; i<targets.size(); i++) {
        int tmp = 0;
        bool c = true;
        for(int j=0; j<targets[i].size(); j++) {
            if(ma[targets[i][j]] == 0) {
                answer.push_back(-1);
                c = false;
                break;
            }
            else {
                tmp = tmp + ma[targets[i][j]];
            }
        }
        if(c) {
            answer.push_back(tmp);
        }
    }
    
    return answer;
}