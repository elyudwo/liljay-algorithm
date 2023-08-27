#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> parsingMusic(string str) {
    vector<string> result;
    string tmp = "";
    
    for(int i=0; i<str.size(); i++) {
        if(str[i] == ',') {
            result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += str[i];
        }
    }
    result.push_back(tmp);
    
    return result;
}

int calTime(string t1, string t2) {
    int time1 = 0; int time2 = 0;
    
    string h1 = ""; h1 += t1[0]; h1 += t1[1];
    string h2 = ""; h2 += t2[0]; h2 += t2[1];
    int hour1 = stoi(h1); int hour2 = stoi(h2);
    
    time1 += hour1 * 60; time2 += hour2 * 60;
    
    string m1 = ""; m1 += t1[3]; m1 += t1[4];
    string m2 = ""; m2 += t2[3]; m2 += t2[4];
    int minute1 = stoi(m1); int minute2 = stoi(m2);
    
    time1 += minute1; time2 += minute2;
    return time2 - time1;
}

string playMusic(string music, int t) {
    int now = 0;
    int s = music.size();
    string result = "";
    
    while(1) {
        result += music[now % music.size()];
        now += 1; 
        if(now >= t) {
            return result;
        }
    }
}

int sizeCount(string m) {
    int m_size = 0;
    for(int i=0; i<m.size(); i++) {
        if(m[i] == '#') { m_size--; }
        m_size++;
    }
    return m_size;
}

string changeStr(string m) {
    string result = "";
    
    for(int i=0; i<m.size(); i++) {
        if(i == m.size()-1) { result += m[i]; return result;}
        if(m[i+1] == '#') {
            if(m[i] == 'C') { result += 'a'; }
            if(m[i] == 'D') { result += 'b'; }
            if(m[i] == 'E') { result += 'c'; }
            if(m[i] == 'F') { result += 'd'; }
            if(m[i] == 'G') { result += 'e'; }
            if(m[i] == 'A') { result += 'f'; }
            if(m[i] == 'B') { result += 'g'; }
            i += 1;
        }
        else {
            result += m[i];
        }
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int rem = 0;
    m = changeStr(m);
    //cout << changeStr(m);
    
    for(string str : musicinfos) {
        vector<string> vec = parsingMusic(str);
        int t_rem = calTime(vec[0], vec[1]);
        int t = t_rem;
        string music = changeStr(vec[3]);
        music = playMusic(music, t);
        
        
        if(music.find(m) != string::npos && rem < t_rem) {
            answer = vec[2];
            rem = t_rem;
        }
    }
    
    if(answer == "") { answer = "(None)"; }
    
    
    return answer;
}