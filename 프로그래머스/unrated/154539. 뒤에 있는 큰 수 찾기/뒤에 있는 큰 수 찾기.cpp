#include <string>
#include <vector>
#include <stack>

using namespace std;

int arr[1000001];

struct num {
    int number;
    int index;
};

stack<num> stk;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++) {
        while(!stk.empty()) {
            if(stk.top().number >= numbers[i]) {
                break;
            }
            int tmp = stk.top().index;
            stk.pop();
            
            arr[tmp] = numbers[i];
        }
        stk.push({numbers[i],i});
    }
    
    
    for(int i=0; i<numbers.size(); i++) {
        if(arr[i] == 0) { answer.push_back(-1); }
        else { answer.push_back(arr[i]); }
    }
    
    return answer;
}