#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int r1,c1,r2,c2;

bool check[10][10];

int dx[8] = {2,2,3,3,-2,-2,-3,-3};
int dy[8] = {3,-3,2,-2,3,-3,2,-2};

struct horse {
    int x;
    int y;
    int cnt;
};

bool checkKing(int x, int y, int i) {
	if(i == 0) {
		if((x == r2 && y+1 == c2) || (x+1 == r2 && y+2 == c2)) {
			return true;
		}
	}
	else if(i == 1) {
		if((x == r2 && y-1 == c2) || (x+1 == r2 && y-2 == c2)) {
			return true;
		}
	}
	else if(i == 2) {
		if((x+1 == r2 && y == c2) || (x+2 == r2 && y+1 == c2)) {
			return true;
		}
	}
	else if(i == 3) {
		if((x+1 == r2 && y == c2) || (x+2 == r2 && y-1 == c2) ) {
			return true;
		}
	}
	else if(i == 4) {
		if((x == r2 && y+1 == c2) || (x-1 == r2 && y+2 == c2)) {
			return true;
		}
	}
	else if(i == 5) {
		if((x == r2 && y-1 == c2) || (x-1 == r2 && y-2 == c2)) {
			return true;
		}
	}
	else if(i == 6) {
		if((x-1 == r2 && y == c2) || (x-2 == r2 && y+1 == c2)) {
			return true;
		}
	}
	else if(i == 7) {
		if((x-1 == r2 && y == c2) || (x-2 == r2 && y-1 == c2)) {
			return true;
		}
	}
	return false;
}

int bfs() {
    queue<horse> q;
    q.push({r1,c1,0});
    int result = -1;
    
    check[r1][c1] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        check[x][y] = true;
        q.pop();
        if(x == r2 && y == c2) {
            result = cnt;
            break;
        }
        
        // 이동경로에 왕이 있으면 이동을 못함 
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(checkKing(x,y,i)) {
            	continue;
			}
            if(nx < 0 || nx > 9 || ny < 0 || ny > 8 || check[nx][ny])    continue;
			q.push({nx,ny,cnt+1});
        }
    }
    
    return result;
}

int main()
{
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    
    int result = bfs();   


    cout << result;
    
    return 0;
}
