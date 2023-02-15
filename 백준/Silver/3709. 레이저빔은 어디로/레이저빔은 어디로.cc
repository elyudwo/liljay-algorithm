#include <iostream>

using namespace std;

// 같은 길을 세번 갔을 경우 (0,0) 출력 
// 나머지 경우는 그냥 빙빙돌자 
int n,r;
int arr[52][52];
int cnt[52][52];

// 동,남,서,북 
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void init() {
	for(int i=0; i<52; i++) {
		for(int j=0; j<52; j++) {
			arr[i][j] = 0;
			cnt[i][j] = 0;
		}
	}
}

void go(int index, int x, int y) {
	int nx = x;
	int ny = y;
	while(1) {
		nx = nx + dx[index];
		ny = ny + dy[index];
		cnt[nx][ny] += 1;
		if(nx <= 0 || nx >= n+1 || ny <= 0 || ny >= n+1) {
			cout << nx << " " << ny << '\n';
			break;
		}
		
		if(arr[nx][ny] == 1) {
			index++;
			if(index == 4) {
				index = 0;
			} 
		}
	}
}

void start(int x, int y) {
	int index;
	
	// 동쪽으로 뻗는 경우 
	if(y == 0) {
		index = 0;
		go(index,x,y);
	}
	// 서쪽으로 뻗는 경우
	if(y == n+1) {
		index = 2;
		go(index, x, y);
	} 
	// 남쪽으로 뻗는 경우
	if(x == 0) {
		index = 1;
		go(index, x, y);
	} 
	// 북쪽으로 뻗는 경우 
	if(x == n+1) {
		index = 3;
		go(index, x, y);
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		cin >> n >> r;
		for(int i=0; i<r; i++) {
			int a,b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		int x,y;
		cin >> x >> y;
		start(x,y);
		
		init();
	}
}