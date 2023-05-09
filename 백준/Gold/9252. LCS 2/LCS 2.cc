#include <iostream>
#include <algorithm>

using namespace std;

string s1,s2;
string answer = "";
int arr[1001][1001];

void input() {
	cin >> s1;
	cin >> s2;
}

void solve() {
	int size1 = s1.size();
	int size2 = s2.size();
	
	for(int i=1; i<=size1; i++) {
		for(int j=1; j<=size2; j++) {
			if(s1[i-1] == s2[j-1]) { arr[i][j] = arr[i-1][j-1] + 1; }
			else { arr[i][j] = max(arr[i][j-1], arr[i-1][j]); }
		}
	}
	
	
	
	int x = size1;
	int y = size2;
	
	while(1) {
		if(arr[x][y] == 0) { break; }
		if(arr[x][y] == arr[x-1][y]) {
			x = x-1;
			continue;
		}
		if(arr[x][y] == arr[x][y-1]) {
			y = y-1;
			continue;
		}
		
		answer += s1[x-1];
		x = x-1;
		y = y-1;
	}
	
	reverse(answer.begin(), answer.end());
	cout << arr[size1][size2] << '\n' << answer;
}

int main() {
	input();
	solve();
	
}