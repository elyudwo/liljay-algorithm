#include <iostream>
#include <vector>

using namespace std;

// a == xรเ b == yรเ 
int a,b,n,m;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct robot {
	int x;
	int y;
	int dis;
};

vector<robot> r;

void input() {
	cin >> a >> b;
	cin >> n >> m;
	
	int x,y;
	char c;
	
	for(int i=0; i<n; i++) {
		cin >> x >> y >> c;
		if(c == 'E') {
			r.push_back({x,y,1});
		}	
		else if(c == 'W') {
			r.push_back({x,y,3});
		}	
		else if(c == 'N') {
			r.push_back({x,y,0});
		}
		else if(c == 'S') {
			r.push_back({x,y,2});
		}
	}
	
	int tmp,cnt;
	
	for(int i=0; i<m; i++) {
		cin >> tmp >> c >> cnt;
		if(c == 'L') {
			for(int j=0; j<cnt; j++) {
				r[tmp-1].dis--;
				if(r[tmp-1].dis == -1) {
					r[tmp-1].dis = 3;
				}
			}
		}
		else if(c == 'R') {
			for(int j=0; j<cnt; j++) {
				r[tmp-1].dis++;
				if(r[tmp-1].dis == 4) {
					r[tmp-1].dis = 0;
				}
			}
		}
		else {
			int nx,ny;
			for(int j=0; j<cnt; j++) {
				nx = r[tmp-1].x+dx[r[tmp-1].dis];
				ny = r[tmp-1].y+dy[r[tmp-1].dis];
				if(nx > a || nx < 1 || ny < 1 || ny > b) {
					cout << "Robot " << tmp <<" crashes into the wall";
					return;
				}
				for(int k=0; k<r.size(); k++) {
					if(k != tmp-1) {
						if(r[k].x == nx && r[k].y == ny) {
							cout << "Robot " << tmp <<" crashes into robot " << k+1;
							return;
						}
					}
				}
				r[tmp-1].x = nx;
				r[tmp-1].y = ny;
			}
		}
	}
	cout << "OK";
	
}


int main() {
	input();
}

