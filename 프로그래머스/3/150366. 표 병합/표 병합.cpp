#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_[3000];
string arr[3000];
vector<string> answer;

vector<string> parsingCommand(string command) {
    vector<string> result;
    string str = "";
    
    for(int i=0; i<command.size(); i++) {
        if(command[i] == ' ') {
            result.push_back(str);
            str = "";
            continue;
        }
        str += command[i];
    }
    result.push_back(str);
    return result;
}

int find_parent(int idx) {
    if(find_[idx] == idx) { return idx; }
    
    return find_[idx] = find_parent(find_[idx]);
}

void updateByDis(int x, int y, string word) {
    int idx = (x-1) * 50 + y;
    // cout << idx << endl;
    int f = find_parent(idx);
    
    arr[f] = word;
}

void updateByWord(string beforeWord, string afterWord) {
    for(int i=1; i<=2500; i++) {
        if(arr[i] == beforeWord) {
            arr[i] = afterWord;
        }
    }
}

void merge(int x1, int y1, int x2, int y2) {
    int idx1 = (x1-1) * 50 + y1;
    int idx2 = (x2-1) * 50 + y2;
    int f1 = find_parent(idx1);
    int f2 = find_parent(idx2);
    
    if(f1 == f2) { return; }
    
    if(arr[f1] == "" && arr[f2] != "") {    
        find_[f1] = f2;
        return;
    }
    
    find_[f2] = f1;
}

void unMerge(int x, int y) {
    int idx = (x-1) * 50 + y;
    int f1 = find_parent(idx);
    string tmp = arr[f1];
    vector<int> vec;
    
    for(int i=1; i<=2500; i++) {
        int f2 = find_parent(i);

        if(f2 == f1) {
            // if(idx == i) {
            //     find_[idx] = idx;
            //     arr[idx] = tmp;
            //     continue;
            // }
            vec.push_back(i);
            // find_[i] = i;
            // arr[i] = "";
        }
    }
    
    for(int i=0; i<vec.size(); i++) {
        if(idx == vec[i]) {
            find_[idx] = idx;
            arr[idx] = tmp;
            continue;
        }
        find_[vec[i]] = vec[i];
        arr[vec[i]] = "";
    }
}

void print(int x, int y) {
    int idx = (x-1) * 50 + y;
    int f = find_parent(idx);
    
    if(arr[f] == "") {
        answer.push_back("EMPTY");
        return;
    }
    answer.push_back(arr[f]);
}

void parsingCommands(vector<string> commands) {
    for(string command_str : commands) {
        vector<string> command = parsingCommand(command_str);
        string act = command[0];
        
        if(act == "UPDATE" && command.size() == 4) {
            updateByDis(stoi(command[1]), stoi(command[2]), command[3]);
        }
        if(act == "UPDATE" && command.size() == 3) {
            updateByWord(command[1], command[2]);
        }
        if(act == "MERGE") {
            merge(stoi(command[1]), stoi(command[2]), stoi(command[3]), stoi(command[4]));
        }
        if(act == "UNMERGE") {
            unMerge(stoi(command[1]), stoi(command[2]));
        }
        if(act == "PRINT") {
            print(stoi(command[1]), stoi(command[2]));
        }
    }
}

void init() {
    for(int i=1; i<=2500; i++) {
        find_[i] = i;
    }
}

vector<string> solution(vector<string> commands) {
    init();
    parsingCommands(commands);
    
    return answer;
}