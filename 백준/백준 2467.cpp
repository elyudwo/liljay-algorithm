#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
int min_value = 2147483647;

int main(void)
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int rem_r,rem_l;	// 투 포인터 인덱스 정보 저장 
	
	int l = 0;
	int r = n-1;
	
	while(l < r) {
		int tmp = v[r]+v[l];
		if(min_value > fabs(tmp)) {
			min_value =	fabs(tmp) ;
			rem_r = v[r];
			rem_l = v[l];
		}
		
		if(tmp < 0) {
			l++;
		}
		else {
			r--;
		}
	}
	
	
	
	if(rem_r > rem_l) {
		cout << rem_l << " " << rem_r;
	}
	else {
		cout << rem_r << " " << rem_l;
	}
	
	return 0;
}
