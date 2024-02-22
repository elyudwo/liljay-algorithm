#include <iostream>
#include <vector>

using namespace std;

int k;
vector<pair<int,int> > vec;
vector<int> one;
int arr[5];
int answer = 0;

void input() {
	cin >> k;
	for(int i=0; i<6; i++) {
		int a,b;
		cin >> a >> b;
		vec.push_back({a,b});
		arr[a]++;
	}
}

void findOne() {
	for(int i=1; i<=4; i++) {
		if(arr[i] == 1) {
			for(int j=0; j<vec.size(); j++) {
				if(vec[j].first == i) {
					one.push_back(vec[j].second);
				}
			}
		}
	}
}

void solve() {
	findOne();
	int all = one[0] * one[1];
	int minus;
	
	for(int i=0; i<vec.size(); i++) {
		int x = vec[i].first;
		int next = vec[(i+1) % 6].first;
		
		if(arr[x] == 1 && arr[next] == 2) {
			minus = vec[(i+2) % 6].second * vec[(i+3) % 6].second;
			break;
		}
	}
	
	cout << (all - minus) * k;
}

int main() {
	input();
	solve();
	
}