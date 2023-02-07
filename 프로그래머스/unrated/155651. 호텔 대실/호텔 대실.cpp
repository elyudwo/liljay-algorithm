#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<string,string> > vec;
priority_queue<string, vector<string>, greater<string>> pq;
int answer = 1;

string convertTime(string str) {
    string tmp = "";
    int hour = stoi(str.substr(0,2));
    int min = stoi(str.substr(3,2));
    
    min = min + 10;
    if(min >= 60) {
        min = min - 60;
        hour = hour + 1;
    }
    
    if(hour < 10) {
        tmp += "0" + to_string(hour);
    }
    else {
        tmp += to_string(hour);
    }
    tmp += ":";
    
    if(min < 10) {
        tmp += "0" + to_string(min);
    }
    else {
        tmp += to_string(min);
    }
    
    return tmp;
}

int solution(vector<vector<string>> book_time) {
    for(int i=0; i<book_time.size(); i++) {
        vec.push_back({book_time[i][0],book_time[i][1]});
    }
    
    sort(vec.begin(),vec.end());
    string str = convertTime(vec[0].second);
    pq.push(str);
    
    for(int i=1; i<vec.size(); i++) {
        while(1) {
            if(answer < pq.size()) {
                answer = pq.size();
            }
            if(pq.empty()) {
                pq.push(vec[i].second);
                break;
            }
            
            if(vec[i].first >= pq.top()) {
                pq.pop();
            }
            else {
                pq.push(convertTime(vec[i].second));
                break;
            }
        }
    }
    
    if(answer < pq.size()) {
        answer = pq.size();
    }
    return answer;
}