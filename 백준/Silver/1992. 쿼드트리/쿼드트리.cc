#include <iostream>
#include <string>

using namespace std;

int arr[66][66];
int n;
string answer = "";

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		
		for(int j=1; j<=n; j++) {
			arr[i][j] = str[j-1] - '0';
		}
	}
}

int cnt = 0;

void divide(int a, int b, int s) {
	cnt++;
	int tmp = arr[a][b];
//	cout << a << "  " << "  " << b  << "  "<< s << endl;
	bool check = false;
	
	for(int i=a; i<a + s; i++) {
		for(int j=b; j<b + s; j++) {
			if(arr[i][j] != tmp) {
				check = true;
				answer += "(";
				divide(a, b, s/2);
				divide(a, b + s/2, s/2);
				divide(a + s/2, b, s/2);
				divide(a + s/2, b + s/2, s/2);
				answer += ")";
				break;
			}
		}
		if(check) break;
	}
	
	if(!check) {
		answer += (tmp + '0');
		return;
	}
}

void solve() {
	divide(1, 1, n);
	cout << answer;
}

int main(){
	input();
	solve();
	
}