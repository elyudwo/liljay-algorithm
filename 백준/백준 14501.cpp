#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int day[16];
int price[16];
int result = -1;
int n;

void dfs(int sum,int num)
{
	if(num == n+1) {
		result = max(result,sum);
		return;
	}
	else if(num + day[num] <= n+1) {
		dfs(sum + price[num] , num + day[num]);
		dfs(sum,num+1);
	}
	else if(num + day[num] > n+1) {
		result = max(result,sum);
		dfs(sum,num+1);
		return;
	}
}

int main(void)
{
	cin >> n;
	for(int i=1; i<=n; i++) {
		int d,p;
		cin >> d >> p;
		day[i] = d;
		price[i] = p;
	}
	
	dfs(0,1);
	
	cout << result;
	
	return 0;
}
