#include <iostream>

using namespace std;

int v[1001];

int main(void)
{
	int t;
	cin >> t;
	int cnt = 0;
	int temp;
	for(int q=0; q<t; q++) {
		int n;
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> v[j];
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n-1; j++) {
				if(v[j] > v[j+1]) {
					cnt++;
					temp = v[j];
					v[j] = v[j+1];
					v[j+1] = temp;			
				}
			}
		}
		cout << cnt << endl;
		for(int i=0; i<n; i++) {
			v[i] = 0;
		}
		cnt = 0;
	}
	
	
	
	return 0;
}
