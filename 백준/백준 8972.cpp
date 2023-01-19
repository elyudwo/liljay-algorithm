#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string arr;
string str;
vector<int> moving;
vector<pair<int,int> > mad;
int dx[] = {1,1,1,0,0,0,-1,-1,-1};
int dy[] = {-1,0,1,-1,0,1,-1,0,1};
int n,m,x,y;
int cnt = 0;

// 1 == 아두이노, 2 == 미친 아두이노 
int v[101][101];
int rem[101][101];

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> arr;
		for(int j=0; j<arr.length(); j++) {
			if(arr[j] == 'I') {
			 	v[i][j] = 1;
				x = i;
				y = j; 
			}
			if(arr[j] == 'R') {
				v[i][j] = 2;
				mad.push_back({i,j});
			}
		}
	}
	
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		moving.push_back(str[i] - '0');
	}
}

void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v[i][j] == 1) {
				cout << "I";
			}
			else if(v[i][j] == 2) {
				cout << "R";
			}
			else {
				cout << ".";
			}
		}
		cout << '\n';
	}
}

void copy() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(rem[i][j] == 1 || rem[i][j] == 2) {
				v[i][j] = rem[i][j];
			}
			else {
			    v[i][j] = 0;
			}
			rem[i][j] = 0;
			
		}
	}
}

void solve() {
	// 종수 움직임 
	for(int i : moving) {
		cnt++;
		int kx = dx[i-1] + x;
		int ky = dy[i-1] + y;
		
		if(v[kx][ky] == 2) {
			cout << "kraj " << cnt;
			return;
		}
		
		
		rem[kx][ky] = 1;
		x = kx;
		y = ky;
		
		
		for(int j=0; j<n; j++) {
		    for(int k=0; k<m; k++) {
		        if(v[j][k] == 2) {
		            int min_tmp = 99999999;
            		int d;
            		
            		for(int q=0; q<9; q++) {
            			int nx = j + dx[q];
            			int ny = k + dy[q];
            			int tmp;
            			tmp = fabs(x - nx) + fabs(y - ny);
            			if(tmp < min_tmp) {
            				min_tmp = tmp;
            				d = q;
            			}
            		}
            		
            		int nx = dx[d] + j;
            		int ny = dy[d] + k;
            		if(x == nx && y == ny) {
            			cout << "kraj " << cnt;
            			return;
            		}
            		rem[nx][ny] += 2;
		        }
		    }
		}
		
		
		
    	copy();
	}
	
	print();
}

int main() {
	input();
	solve();
	
}
