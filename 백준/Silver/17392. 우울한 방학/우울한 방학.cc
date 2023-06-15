#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int sum = 0;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp + 1;
	}
}

long long cal(int a) {
	long long result = 0;
	
	for(int i=1; i<=a; i++) {
		result += pow(i,2);
	}	
	
	return result;
}

/*
2 2 2 1
1 1 1 1

5 5 5 1
*/
void solve() {
	int tmp = m - sum;
	long long result = 0;
	
	if(tmp <= 0) { cout << "0"; return ;}
	else if(tmp <= n) {
		cout << tmp;
		return;
	}
	else { 
		if(tmp % (n+1) != 0) {
			int a = tmp / (n+1);
			int mi = tmp - a * (n+1);
			
			for(int i=0; i<(n+1) - mi; i++) {
				result += cal(a);
			}
			
			for(int i=0; i<mi; i++) {
				result += cal(a + 1);
			}
		}
		else {
			int a = tmp / (n+1);
			result = cal(a) * (n+1);
		} 
		
		cout << result;
	}
	
}

int main() {
	input();
	solve();
	
}