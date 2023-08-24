#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int train[100001][22];
int n,m;
unordered_set<string> s;

int main() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b,c;
		cin >> a;
		if(a == 1) {
			cin >> b >> c;
			train[b][c] = 1;
		}
		if(a == 2) {
			cin >> b >> c;
			train[b][c] = 0;
		}
		if(a == 3) {
			cin >> b;
			for(int j=21; j>=2; j--) {
				if(train[b][j-1]) {
					train[b][j-1] = 0;
					train[b][j] = 1; 
				}
			}
		}
		if(a == 4) {
			cin >> b;
			for(int j=0; j<=19; j++) {
				if(train[b][j+1]) {
					train[b][j] = 1;
					train[b][j+1] = 0; 
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		string str = "";
		for(int j=1; j<=20; j++) {
			str += (train[i][j] + '0');
		}
		s.insert(str);
	}
	cout << s.size();
	
}