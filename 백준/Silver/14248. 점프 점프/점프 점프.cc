#include <iostream>
#include <queue>

using namespace std;

int n, now, answer = 0;
int arr[100002];
bool check[100002];

void input() {
   cin >> n;
   for(int i=1; i<=n; i++) {
      int tmp;
      cin >> tmp;
      arr[i] = tmp;
   }
   cin >> now;
}

void bfs() {
   queue<int> q;
   q.push(now);
   check[now] = true;
   
   while(!q.empty()) {
      int x = q.front();
      answer++;
//      cout << x << endl;
      q.pop();
      
      int nx = x + arr[x];
      if(nx <= n && nx >= 1 && !check[nx]) {
         check[nx] = true;
         q.push(nx);
      }
      
      nx = x - arr[x];
      if(nx <= n && nx >= 1 && !check[nx]) {
         check[nx] = true;
         q.push(nx);
      }
      
   }
   
}

void solve() {
   
   bfs();
   
   cout << answer;
}

int main() {
   input();
   solve();
   
}