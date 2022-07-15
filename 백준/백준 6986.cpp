#include <iostream>
#include <algorithm>

using namespace std;

double v[100001];
#define ERROR 0.00000001

int main(void)
{
	int n,k;
	double result1,result2;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	sort(v,v+n);
	double sum = 0;
	int cnt = 0;
	for(int i=k; i<n-k; i++) {
		sum = sum + v[i];
		cnt++;
	}
	result1 = sum/cnt;
	

	sum = 0;
	cnt = 0;

	for(int i=0; i<n; i++) {
		if(i >= 0 && i <= k-1) {
			sum = sum + v[k];
		}
		else if(i >= n-k && i < n) {
			sum = sum + v[n-k-1];
		}
		else {
			sum = sum + v[i];
		}
		cnt++;
	}
	
	result2 = sum/cnt;
	
	printf("%.2f\n",result1 + ERROR);
	printf("%.2f\n",result2 + ERROR);
	
	return 0;
}
