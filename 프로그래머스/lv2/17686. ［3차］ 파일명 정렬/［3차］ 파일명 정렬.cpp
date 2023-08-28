#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct file {
    string head;
    int number;
    string tail;
    int idx;
};

vector<file> vec;

vector<string> parsingFile(string str) {
    vector<string> result;
    string head = "", number = "", tail = "";
    int idx, idx2;
    for(int i=0; i<str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9') { idx = i; break; }
        if(isupper(str[i])) { str[i] += 32; }
        head += str[i];
    }
    for(int i=idx; i<str.size(); i++) {
        if(i - idx > 5 || !(str[i] <= '9' && str[i] >= '0')) { idx2 = i; break; }
        number += str[i];
        idx2 = i;
    }
    for(int i=idx2; i<str.size(); i++) { tail += str[i]; }
    result.push_back(head); result.push_back(number); result.push_back(tail);
    return result;
}

bool cmp(file a, file b) {
    if(a.head == b.head) {
        if(a.number == b.number) {
            return a.idx < b.idx;
        }
        return a.number < b.number;
    }
    
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int cnt = 0;
    for(string str : files) {
        vector<string> v = parsingFile(str);
        vec.push_back({v[0], stoi(v[1]), v[2], cnt++});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for(int i=0; i<vec.size(); i++) {
        answer.push_back(files[vec[i].idx]);
    }
    return answer;
}