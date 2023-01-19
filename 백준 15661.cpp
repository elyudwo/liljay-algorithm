#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;

int arr[21][21];
int n;
bool check[21];
int answer = 999999999;
int lee = 0;
map<string,int> ma;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
}

int calculate1() {
	int result = 0;
	for(int i=1; i<=n; i++) {
		if(check[i]) {
			for(int j=1; j<=n; j++) {
				if(check[j]) {
					result = result + arr[i][j];
				}
			}
		}
	}
	
	return result;
}

int calculate2() {
	int result = 0;
	for(int i=1; i<=n; i++) {
		if(!check[i]) {
			for(int j=1; j<=n; j++) {
				if(!check[j]) {
					result = result + arr[i][j];
				}
			}
		}
	}
	
	return result;
}

void dfs(int p, int cnt, int x) {
	if(cnt == p) {
		string str1 = "";
		string str2 = "";
		for(int i=1; i<=n; i++) {
			if(check[i]) {
				str1 = str1 + to_string(i);
			}
			else {
				str2 = str2 + to_string(i);
			}
		}
		if(ma[str1] == 1 || ma[str2] == 1) {
			return;
		}
		ma[str1] = 1;
		ma[str2] = 1;
		
		int sum1 = 0;
		int sum2 = 0;
		sum1 = calculate1();
		sum2 = calculate2();
		if(answer > fabs(sum1-sum2)) {
			answer = fabs(sum1-sum2);
		}
		return;
	}
	
	for(int i=x; i<=n; i++) {
		if(check[i]) {continue;}
		check[i] = true;
		dfs(p,cnt+1,x+1);
		check[i] = false;
	}
}

void solve() {
	for(int i=1; i<=n/2; i++) {
		dfs(i,0,1);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
}


/*
123, 124, 125, 126, 234, 235, 236, 345, 346, 456


*/
