#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
 
using namespace std;

vector<pair<int,int> > vec;
int n;
stack<int> stk;
int answer = 0;

void input() {
   cin >> n;
   for(int i=0; i<n; i++) {
      int a,b;
      cin >> a >> b;
      vec.push_back({a,b});
   }   
   
   sort(vec.begin(), vec.end());
}

void solve() {
    stk.push(vec[0].second);
    
	for(int i=1; i<vec.size(); i++) {
        while(!stk.empty()) {
	        if(vec[i].second < stk.top()) {
	            answer++;
	            stk.pop();
	            continue;
	        }
	        break;
      	}
      	if(stk.empty()) {
      		if(vec[i].second == 0) continue;
      		stk.push(vec[i].second);
      		continue;
		  }
        if(stk.top() == vec[i].second || vec[i].second == 0) { continue; }
        stk.push(vec[i].second);
    }
    
    for(int i=0; i<stk.size(); i++) {
    	if(stk.top() == 0) {
    		stk.pop();
		}
		else {
			answer++;
			stk.pop();
		}
	}
    
	answer += stk.size();

   cout << answer;
}

int main() {
   input();
   solve();
   
}