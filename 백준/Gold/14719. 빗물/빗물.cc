#include <iostream>

using namespace std;

int h,w;
int arr[502];

void input() {
	cin >> h >> w;
	
	for(int i=1; i<=w; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int answer = 0;
	
	for(int i=1; i<=h; i++) {
		bool check = false;
		int tmp = 0;
		
		for(int j=1; j<=w; j++) {
			if(arr[j] >= i && !check) { tmp = 0; check = true; continue; }
			if(arr[j] >= i && check) {
				answer += tmp;
				tmp = 0;
			}
			else {
				tmp++;
			}
		}
	} 
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}