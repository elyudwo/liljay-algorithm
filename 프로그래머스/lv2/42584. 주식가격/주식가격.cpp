#include <string>
#include <vector>
#include <stack>

using namespace std;

int arr[100001];

struct stock {
    int price;
    int index;
    int time;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<stock> stk;
    
    int time = 0;
    
    for(int i=0; i<prices.size(); i++) {
        if(stk.empty()) { stk.push({prices[i],i,time}); }
        else {
            while(1) {
                if(stk.empty()) {
                    stk.push({prices[i],i,time});
                    break;
                }
                if(stk.top().price <= prices[i]) {
                    stk.push({prices[i],i,time});
                    break;
                } 
                else {
                    int i = stk.top().index;
                    int t = time - stk.top().time;
                    arr[i] = t;
                    stk.pop();
                }
            }
        }
        time++;
    }
    
    time--;
    
    while(!stk.empty()) {
        int i = stk.top().index;
        int t = time - stk.top().time;
        arr[i] = t;
        stk.pop();
    }
    
    for(int i=0; i<prices.size(); i++) {
        answer.push_back(arr[i]);
    }
    
    
    return answer;
}