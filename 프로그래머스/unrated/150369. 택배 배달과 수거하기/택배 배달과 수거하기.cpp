#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

deque<int> d_vec;
deque<int> p_vec;

long long answer = 0;

void erase_d() {
    int size = d_vec.size();
    for(int i=size; i>=0; i--) {
        if(d_vec.size() == 0) {break;}
        if(d_vec[d_vec.size()-1] == 0) { d_vec.pop_back(); }
        else { break; }
    }
}

void erase_p() {
    int size = p_vec.size();
    for(int i=size; i>=0; i--) {
        if(p_vec.size() == 0) {break;}
        if(p_vec[p_vec.size()-1] == 0) { p_vec.pop_back(); }
        else { break; }
    }
}

bool Finish() {
    if(d_vec.size() == 0 && p_vec.size() == 0) {
        return true;
    }
    return false;
}

int go_pickups(int cap) {
    int cnt = cap;
    int result;
    bool check = false;
    
    for(int i=p_vec.size()-1; i>=0; i--) {
        if(p_vec[i] > cnt) {
            if(!check) {
                check = true;
                result = (i+1) * 2;
            }
            p_vec[i] -= cnt;
            break;
        }
        else {
            if(!check) {
                check = true;
                result = (i+1) * 2;
            }
            cnt = cnt - p_vec[i];
            p_vec[i] = 0;
        }
    }
    
    return result;
}

int go_deliveries(int cap) {
    int cnt = cap;
    int result;
    bool check = false;
    
    for(int i=d_vec.size()-1; i>=0; i--) {
        if(d_vec[i] > cnt) {
            if(!check) {
                check = true;
                result = (i+1) * 2;
            }
            d_vec[i] -= cnt;
            break;
        }
        else {
            if(!check) {
                check = true;
                result = (i+1) * 2;
            }
            cnt = cnt - d_vec[i];
            d_vec[i] = 0;
        }
    }
    
    return result;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    for(int i=0; i<n; i++) {
        d_vec.push_back(deliveries[i]);
        p_vec.push_back(pickups[i]);
    }

    while(1) {
        erase_d();
        erase_p();
        if(Finish()) { break; }
        int max_tmp = go_deliveries(cap);
        max_tmp = max(max_tmp, go_pickups(cap));
        answer += max_tmp;
    }
    
    return answer;
}