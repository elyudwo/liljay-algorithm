#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void)
{
	string num;
	cin >> num;
	
	int cnt[10] = {0,};
	
	for(int i=0; i<num.length(); i++) {
		cnt[num[i] - '0']++;
	}


	double k = cnt[6] + cnt[9];

	double a = ceil(k/2);
	
	cnt[6] = 0;
	cnt[9] = a;
	
	int result = -1;
	for(int i=0; i<10; i++) {
		result = max(result,cnt[i]);
	}
	
	cout << result;
	return 0;
}
