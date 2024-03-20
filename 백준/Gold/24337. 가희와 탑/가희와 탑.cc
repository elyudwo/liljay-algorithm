#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, a, b, max_building;
deque<int> building;

void input() {
	cin >> n >> a >> b;
}

void addLeft() {
	for(int i=1; i<a; i++) {
		building.push_back(i);
	}	
}

void addRight() {
	for(int i=b-1; i>=1; i--) {
		building.push_back(i);
	}	
}


void solve() {
	if(a + b - 1 > n) {
		cout << "-1" ;
		return;
	}
	
	addLeft();
	building.push_back(max(a, b));
	addRight();
	
	int s = building.size();
	int tmp = building[0];
	building.pop_front();
	for(int i=0; i<n-s; i++) {
		building.push_front(1);
	}
	building.push_front(tmp);
	
	for(int i=0; i<n; i++) {
		cout << building[i] << " ";
	}
}

int main() {
	input();
	solve();
	
}