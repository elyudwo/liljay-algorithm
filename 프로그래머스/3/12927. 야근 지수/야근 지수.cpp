#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    for(int i=0; i<works.size(); i++) { pq.push(works[i]); }
    
    while(n-- && !pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        if(tmp <= 0) { continue; }
        pq.push(--tmp);
    }
    
    while(!pq.empty()) {
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}