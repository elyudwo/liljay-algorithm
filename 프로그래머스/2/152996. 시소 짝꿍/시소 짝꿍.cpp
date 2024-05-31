#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int each[2002];

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(int i=0; i<=2000; i++) {
        each[i] = 0;
    }
    
    for(int num : weights) { each[num]++; }
    
    for(int i=100; i<=1000; i++) {
        if(!each[i]) continue;
        long long tmp;
        answer += (long long)each[i] * (each[i] - 1) / 2;
        
        if(i % 3 == 0) {
            answer += (long long)each[i] * each[i * 4 / 3];
        }
        if(i % 2 == 0) {
            answer += (long long)each[i] * each[i * 3 / 2];
        }
        answer += (long long)each[i] * each[i * 2];
    }
        
    
    
    return answer;
}