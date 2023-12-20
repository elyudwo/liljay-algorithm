#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][4];
int max_answer = -1;
int min_answer = 2000000000;
int n;

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++) {
			cin >> dp[i][j];
		}
	}
}

int calculateMaxValue() {
	int maxDpBefore[5] = {0,};
	int maxDpAfter[5] = {0,};
	
	for(int i=1; i<=3; i++) {
		maxDpBefore[i] = dp[1][i];
	}
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=3; j++) {
			maxDpAfter[j] = max({dp[i][j] + maxDpBefore[j-1], dp[i][j] + maxDpBefore[j], dp[i][j] + maxDpBefore[j+1]});
		}
		for(int j=1; j<=3; j++) {
			maxDpBefore[j] = maxDpAfter[j];
		}
	}
	
	int max_value = -1;
	for(int i=1; i<=3; i++) {
		if(max_value < maxDpBefore[i]) {
			max_value = maxDpBefore[i];
		}
	}
	
	return max_value;
}

int calculateMinValue() {
	int minDpBefore[5] = {11,11,11,11,11};
	int minDpAfter[5] = {0,};
	
	for(int i=1; i<=3; i++) {
		minDpBefore[i] = dp[1][i];
	}
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=3; j++) {
		    if(j == 1) {
		        minDpAfter[j] = min(dp[i][j] + minDpBefore[j], dp[i][j] + minDpBefore[j+1]);
		    }
		    if(j == 2) {
		        minDpAfter[j] = min({dp[i][j] + minDpBefore[j-1], dp[i][j] + minDpBefore[j], dp[i][j] + minDpBefore[j+1]});
		    }
		    if(j == 3) {
		        minDpAfter[j] = min(dp[i][j] + minDpBefore[j], dp[i][j] + minDpBefore[j-1]);
		    }
		}
		for(int j=1; j<=3; j++) {
			minDpBefore[j] = minDpAfter[j];
		}
	}
	
	int min_value = 2000000000;
	for(int i=1; i<=3; i++) {
		if(min_value > minDpBefore[i]) {
			min_value = minDpBefore[i];
		}
	}
	
	return min_value;
}

void solve() {
	calculateMaxValue();
	calculateMinValue();

	cout << calculateMaxValue() << " " << calculateMinValue();
}

int main() {
	input();
	solve();	
	
}