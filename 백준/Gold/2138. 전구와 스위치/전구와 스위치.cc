#include <iostream>
#define INF 1000000
using namespace std;

string str1, str2;
bool arr1[100002] = {0,};
bool arr2[100002] = {0,};

int n;
int answer = INF;

void input() {
	cin >> n;
	cin >> str1;
	cin >> str2;
	
	for(int i=0; i<str1.size(); i++) {
		arr1[i] = str1[i] - '0';
		arr2[i] = str2[i] - '0';
	}
}

void goPush(int x) {
	int result = 0;
	
	if(x == 1) {
		result++;
		arr1[0] = !arr1[0];
		arr1[1] = !arr1[1];
	} 
	
	for(int i=1; i<n-1; i++) {
		if(arr1[i-1] != arr2[i-1]) {
			result++;
			arr1[i-1] = !arr1[i-1];
			arr1[i] = !arr1[i];
			arr1[i+1] = !arr1[i+1];
		}
	}
	
	if(arr1[n-2] != arr2[n-2]) {
		result++;
		arr1[n-2] = !arr1[n-2];
		arr1[n-1] = !arr1[n-1];
	}
	
	for(int i=0; i<n; i++) {
		if(arr1[i] != arr2[i]) {
			return;
		}
	}
	answer = min(answer, result);
}

void solve() {
	
	goPush(0);
	
	for(int i=0; i<str1.size(); i++) {
		arr1[i] = str1[i] - '0';
	}
	
	goPush(1);
	
	if(answer == INF) {
		cout << "-1";
		return;
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}