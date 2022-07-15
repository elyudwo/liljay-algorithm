#include <iostream>

using namespace std;

int v[1000001];
int t[1000001];

int check[1000001][2];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	for(int i=0; i<n; i++) {
		cin >> t[i];
	}
	
	for(int i=0; i<n; i++) {
		if(i == 0) {
			check[v[i]][0] = v[n-1];
			check[v[i]][1] = v[1];
		}
		else if(i == n-1) {
			check[v[i]][0] = v[n-2];
			check[v[i]][1] = v[0];
		}
		else {
			check[v[i]][0] = v[i-1];
			check[v[i]][1] = v[i+1];
		}
		
	} 
	
	for(int i=0; i<n; i++) {
		if(i == 0) {
			if((check[t[i]][0] == t[1] || check[t[i]][0] == t[n-1]) && (check[t[i]][1] == t[1] || check[t[i]][1] == t[n-1])) {
				continue;
			}
			else {
				cout << "bad puzzle";
				return 0;
			}
		}
		else if(i == n-1) {
			if((check[t[i]][0] == t[0] || check[t[i]][0] == t[n-2]) && (check[t[i]][1] == t[0] || check[t[i]][1] == t[n-2])) {
				continue;
			}
			else {
				cout << "bad puzzle";
				return 0;
			}
		}
		else {
			if((check[t[i]][0] == t[i-1] || check[t[i]][0] == t[i+1]) && (check[t[i]][1] == t[i-1] || check[t[i]][1] == t[i+1])) {
				continue;
			}
			else {
				cout << "bad puzzle";
				return 0;
			}
		}
		
	}
	
	cout << "good puzzle";
	
	return 0;
}

