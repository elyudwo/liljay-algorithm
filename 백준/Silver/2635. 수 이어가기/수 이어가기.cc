#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> answer;

void input() {
	cin >> n;
	answer.push_back(n);
}

void calculateNumber(int x) {
	vector<int> vec;
	vec.push_back(n);
	vec.push_back(x);
	int before = n;
	int after = x;
	
	while(1) {
		if(before - after < 0) {
			break;
		}
		vec.push_back(before - after);
		int tmp = after;
		after = before - after;
		before = tmp;
	}
	
	if(vec.size() > answer.size()) {
		answer = vec;
	}
}

void solve() {
	for(int i=30000; i>0; i--) {
		calculateNumber(i);
	}
	cout << answer.size() << '\n';
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

int main() {
	input();
	solve();
	
}