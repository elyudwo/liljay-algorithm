#include <iostream>
#include <algorithm>
using namespace std;

int v[100001];

int main(void)
{
	int n,k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		scanf("%d",&v[i]);
	}
	
	int result = -1;
	int max_value = -1;
	int tmp = 0;
	int check = 0;
	
	for(int i=0; i<k; i++) {
		tmp = tmp + v[i];
	}
	
	result = tmp;
	max_value = tmp;
	
	for(int i=k-1; i<n-1; i++) {
		result = result - v[check];
		result = result + v[i+1];
		check++;
		max_value = max(result,max_value);
	}
 	
 	cout << max_value;
 	
	return 0;
}
