#include <iostream>
#include <queue>

using namespace std;

int n,k;
queue<int> q;
vector<int> vec;

void input() {
	cin >> n >> k;
}

void solve() {
	for(int i=1; i<=n; i++) {
		q.push(i);
	}
	
	while(n--) {
		for(int i=0; i<k-1; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		
		vec.push_back(q.front());
		q.pop();
	}
	
	cout << "<";
	for(int i=0; i<vec.size()-1; i++) {
		cout << vec[i] << ", ";
	}
	cout << vec[vec.size()-1] << ">";
}

int main() {
	input();
	solve();
	
}