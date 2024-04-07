#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    
    int now = 0;
    
    for(int num : A) {
        if(B[now] > num) {
            answer++;
            now++;
        }
    }
    
    return answer;
}