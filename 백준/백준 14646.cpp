#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int arr[100000] = {0, };
	int temp = 0;
	int cnt = 0;
	int ans = 0;
	
	for(int i=0; i<2*n; i++)
	{
		cin >> temp;
		arr[temp-1]++;
		cnt++;
		if(arr[temp-1] == 2)
			cnt = cnt - 2;
		
		if(ans < cnt)
			ans = cnt;
	}

	cout << ans;
	return 0;
}
