#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int v[3001];
int result = -1;
int n,d,k,c;
int size_tmp = 0;

void calculator()
{
	int tmp = size_tmp;
	if(v[c] == 0) {
		tmp++;
	}
	
	if(result < tmp) {
		result = tmp;
	}
}

int main(void)
{
	cin >> n >> d >> k >> c;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i=0; i<k; i++) {
		int a = vec[i];
		v[a]++;
		if(v[a] == 1) {
			size_tmp++;
		}
	}
	calculator();
	
	int left = 0;
	int right = k-1;
	while(left < n) {
		int a,b;
		a = vec[left];
		right = (right+1) % n;
		b = vec[right];
		v[a]--;
		if(v[a] == 0) {
			size_tmp--;
		}
		v[b]++;
		if(v[b] == 1) {
			size_tmp++;
		}
		calculator();
		left++;
	}
	
	cout << result;
	
	return 0;
}
