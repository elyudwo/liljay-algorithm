#include <iostream>
#include <string>
#include <queue> 

using namespace std;

int n,m;
char c[52][52];
int dp[33][52][52];
int stock[52][52];
int lee = 0;
int start_x, start_y;
int end_x, end_y;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


void input() {
   cin >> n >> m;
   int cnt = 0;
   
   for(int i=1; i<=m; i++) {
      string str;
      cin >> str; 
      
      for(int j=1; j<=n; j++) {
         c[i][j] = str[j-1];
         if(c[i][j] == 'S') {
            start_x = i;
            start_y = j;
         }
         if(c[i][j] == 'E') {
         	end_x = i;
         	end_y = j;
		 }
         if(c[i][j] == 'X') { stock[i][j] = lee++; }
      }
   }
}

struct st {
   int x;
   int y;
   int cnt;
   int t;
};

void bfs() {
   queue<st> q;
   q.push({start_x, start_y, 0, 0});
   
   while(!q.empty()) {
      int x = q.front().x;
      int y = q.front().y;
      int cnt = q.front().cnt;
      int t = q.front().t;
//      cout << x << " " << y << endl;
      q.pop();
      
      
      for(int i=0; i<4; i++) {
         int nx = dx[i] + x;
         int ny = dy[i] + y;
         int hello = cnt;
		 if(nx < 1 || ny < 1 || nx > m || ny > n || c[nx][ny] == '#' ) continue;
         
         if(c[nx][ny] == 'X') {
         	int num = stock[nx][ny];
         	hello = cnt | (1 << num); 
		 }
		 
		 if(dp[hello][nx][ny]) continue;
		 
		 dp[hello][nx][ny] = t + 1;
		 q.push({nx, ny, hello, t + 1});
      }
   }
}

void solve() {
   bfs();
   
//   for(int i=1; i<=m; i++) {
//   	for(int j=1; j<=n; j++) {
//   		cout << dp[1][i][j] << " ";
//	   }
//	   cout << endl;
//   }
   
   cout << dp[(1 << lee) - 1][end_x][end_y];
}

int main() {
   input();
   solve();
   
}