#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n,c;
vector<int> vec;
int arr[100000001];

void input() {
	cin >> n >> c;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
		arr[tmp] += 1;
	}
}

void solve() {
	if(arr[c] != 0) {
		cout << "1";
		return;
	}
	
	int s = vec.size();
	
	for(int i=0; i<s; i++) {
		for(int j=i+1; j<s; j++) {
			if(vec[i] + vec[j] == c) {
				cout << "1";
				return;
			}
			if(vec[i] + vec[j] < c) {
				int tmp = c - (vec[i] + vec[j]);
				arr[vec[i]] -= 1;
				arr[vec[j]] -= 1;
				if(arr[tmp] != 0) {
					cout << "1";
					return;
				}
				arr[vec[i]] += 1;
				arr[vec[j]] += 1;
			}
		}
	}
	cout << "0";
}

int main() { 
	input();
	solve();
	
}