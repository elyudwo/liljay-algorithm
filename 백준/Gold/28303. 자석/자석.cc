#include <iostream>
#include <cmath> 
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[500002];
ll answer = -2e18;

int main() {
   int n, k;
   cin >> n >> k;
   
   for(int i=1; i<=n; i++) {
       cin >> arr[i];
   }
   ll x = 0;
   
   for(int i=1; i<n; i++) {
       ll tmp = arr[i] - arr[i+1] - k;
       x = max(x, 0ll);
       x += tmp;
       answer = max(answer, x);
   }
   
   x = 0;
   for(int i=n; i>1; i--) {
       ll tmp = arr[i] - arr[i-1] - k;
       x = max(x, 0ll);
       x += tmp;
       answer = max(answer, x);
   }
   
   cout << answer;
   
}