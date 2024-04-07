#include <string>
#include <vector>

using namespace std;

bool possible(long long mid, int n, vector<int> times) {
    long long cnt = 0;
    for(int i : times) {
        cnt += mid / i;
    }
    
    if(cnt >= n) {
        return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int tmp = 0;
    
    long long left = 0;
    long long right = 100000000000001; 
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        if(possible(mid, n, times)) {
            answer = mid;
            right = mid - 1;
            continue;
        }
        left = mid + 1;
    }
    
    
    return answer;
}