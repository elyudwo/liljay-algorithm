#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(),v.end());
	vector<int> v1;
	vector<int> v2;
	
	for(int i=0; i<v.size(); i++) {
		if(v[i] <= 0)
			v1.push_back(v[i]);
		else
			v2.push_back(v[i]);
	}
	
	int sum = 0;
	
	if(sizeof(v1) % 2 == 0) {
		for(int i=0; i<sizeof(v1); i = i+2) {
			sum = sum + v1[i] * v1[i+1];
		}
		for(int i=sizeof(v2)-1; i>=0; i = i-2) {
			if(i == 0) {
				sum = sum + v2[i];
				continue;
			}
			if(v2[i] == 1 && v2[i-1] == 1) {
				sum = sum + 2;
				continue;
			}
			sum = sum + v2[i] * v2[i-1];
		}
	}
	else {
		for(int i=0; i<sizeof(v1); i = i+2) {
			if(sizeof(v1) == 1) {
				sum = sum + v1[i];
				break;
			}
			
			if(i == sizeof(v1)-1) {
				sum = sum + v1[i];
				continue;
			}
			sum = sum + v1[i] * v1[i+1];
		}
		for(int i=sizeof(v2)-1; i>=0; i = i-2) {
			if(i == 0) {
				sum = sum + v2[i];
				continue;
			}
			if(v2[i] == 1 && v2[i-1] == 1) {
				sum = sum + 2;
				continue;
			}
			sum = sum + v2[i] * v2[i-1];
		}
	}
	
	cout << sizeof(v2);
		
	return 0;
}
