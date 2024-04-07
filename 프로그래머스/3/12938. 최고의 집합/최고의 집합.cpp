#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    int div = s / n;
    int other = s % n;
    
    for(int i=0; i<n; i++) {
        answer.push_back(div);
    }
    
    for(int i=0; i<other; i++) {
        answer[i]++;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}