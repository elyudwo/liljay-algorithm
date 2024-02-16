#include <iostream>

using namespace std;

long long arr[1002][1002];
long long sum[1002][1002];
bool check = false;
int n,m;

void calculateSum() {
	if(check) {
		return;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			sum[i][j] += arr[i][j];
		}
	}
	
	
//	cout << "START" << endl;
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout << sum[i][j] << " "; 
//		}
//		cout << '\n';
//	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	
//	cout << "RE START" << endl;
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout << sum[i][j] << " "; 
//		}
//		cout << '\n';
//	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> sum[i][j];
		}
	}
	
	while(m--) {
		int tmp, x1, y1, x2, y2, cnt;
		cin >> tmp;
		cin >> x1 >> y1 >> x2 >> y2;
		
		x1++, y1++, x2++, y2++;
		
		if(tmp == 1) {
			cin >> cnt;
			
			arr[x1][y1] += cnt;
			arr[x2+1][y2+1] += cnt;
			arr[x2+1][y1] -= cnt;
			arr[x1][y2+1] -= cnt;
			continue;
		}
		calculateSum();
		check = true;
		
		cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
	}
}