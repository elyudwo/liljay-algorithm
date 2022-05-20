#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int v[500001];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	double a;
	double sum = 0;
	
	for(int i=0; i<n; i++) {
		sum = sum + v[i];
	}
	
	if(sum / n > -0.5 && sum < 0) {
		cout << 0 << endl;
	}
	else {
		a = sum / n; 
		a = round(a);
	
		cout << a << endl;	
	}
	
	
	sort(v,v+n);
	
	cout << v[n/2] << endl;
	
	int max_cnt = -1;
	
	for(int i=0; i<n; i++) {
		int cnt = 0;
		while(1) {
			if(v[i] == v[i+1]) {
				cnt++;
				i++;
			}
			else {
				break;
			}
		}
		max_cnt = max(max_cnt,cnt);
	}
	
	int lee[500001];
	int j = 0;
	for(int i=0; i<n; i++) {
		int cnt = 0;
		while(1) {
			if(v[i] == v[i+1]) {
				cnt++;
				i++;
			}
			else {
				break;
			}
		}
		if(cnt == max_cnt) {
			lee[j++] = v[i];
		}
	}
	
	sort(lee,lee+j);
	if(j < 2) {
		cout << lee[0] << endl;
	}
	else {
		cout << lee[1] << endl;	
	}
	
	
	cout << v[n-1] - v[0];
	
	return 0;
}
