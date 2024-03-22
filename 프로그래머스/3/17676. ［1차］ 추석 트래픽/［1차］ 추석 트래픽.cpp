#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

/*
1. 시작과 끝에 +1, -1
2. 누적합 구함
3. 슬라이딩 윈도우로 결과값찾기
*/

vector<pair<int,int> > time_vec;

vector<string> parsingStringToTime(string str) {
    vector<string> answer;
    string tmp = "";
    
    for(int i=0; i<str.size(); i++) {
        if(str[i] == ' ') {
            answer.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += str[i];
    }
    
    tmp.pop_back();
    answer.push_back(tmp);
    return answer;
}

int parsingTimeToInt(string time) {
    int a = time.size();
    for(int i=0; i<12 - a; i++) {
        time += '0';
    }
    
    int answer = 0;
    int hour, minute, second, other;
    
    
    hour = stoi(time.substr(0,2));
    minute = stoi(time.substr(3,2));
    second = stoi(time.substr(6,2));
    other = stoi(time.substr(9));
    answer += hour * 3600 + minute * 60 + second;
    answer *= 1000;
    answer += other;
    // cout << answer << " ";
    return answer;
}

int parsingStringToT(string str) {
    int answer = 0;
    for(int i=0; i<5 - str.size(); i++) {
        str += '0';
    }
    int a = str[0] - '0';
    int b = stoi(str.substr(2));
    answer += a * 1000;
    answer += b;
    return answer;
}

void plusLines(vector<string> lines) {
    for(string str : lines) {
        vector<string> time = parsingStringToTime(str);
        int t = parsingStringToT(time[2]);
        
        int t_end = parsingTimeToInt(time[1]);
        int t_start = t_end - t;
        
        
        if(t_start < 0) {
            time_vec.push_back({0, t_end});
            continue;
        }
        
        time_vec.push_back({t_start+1, t_end});
    }
}

int solution(vector<string> lines) {
    int answer = 0;
    plusLines(lines);
    // sort(time_vec.begin(), time_vec.end(), cmp);
    
    for(int i=0; i<time_vec.size(); i++) {
        int cnt = 1;
        int t_start = time_vec[i].first;
        int t_end = time_vec[i].second;
        // cout << t_start << " " << t_end << endl;
        for(int j=0; j<time_vec.size(); j++) {
            if(i == j) continue;
            int t1_start = time_vec[j].first;
            int t1_end = time_vec[j].second;
            
            if((t1_start >= t_end && t1_start <= t_end + 999) || 
              (t1_end >= t_end && t1_end <= t_end + 999) || 
              (t1_start <= t_end && t1_end >= t_end + 999)) {
                cnt++;
            }
        }   
        answer = max(answer, cnt);
    }
    
    return answer;
}