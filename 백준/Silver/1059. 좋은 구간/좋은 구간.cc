#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int answer = 0;

int main() {
	int l,n,tmp;
	cin >> l;
	for(int i=0; i<l; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	cin >> n;
	vec.push_back(n);
	
	sort(vec.begin(),vec.end());
	
	for(int i=0; i<vec.size(); i++) {
		if(vec[i] == n) {
			if(i == 0) {
				int minus = vec[i];
				int sum = vec[i+1] - vec[i];
				
				answer = minus * sum -1;
			}
			else {
				int minus = vec[i] - vec[i-1];
				int sum = vec[i+1] - vec[i];
				
				answer = minus * sum - 1;
				break;
			}
		}
	}
	
	if(answer == -1) { answer = 0; } 
	
	cout << answer;
	
}