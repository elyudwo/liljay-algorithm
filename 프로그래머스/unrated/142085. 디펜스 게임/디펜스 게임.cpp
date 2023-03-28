#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int person = n;
    
    if(enemy.size() == k) {
        return enemy.size();
    }
    
    for(int i=0; i<enemy.size(); i++) {
        pq.push(enemy[i]);
        
        if(pq.size() > k) {
            person = person - pq.top();
            if(person < 0) {
                answer = i;
                break;
            }
            pq.pop();
        }
    }
    
    if(!answer && enemy.size() > 1) {
        answer = enemy.size();
    }
    
    
    return answer;
}