#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[51];
int result = 1;
	
int main(void)
{
	int n,score,p;
	cin >> n >> score >> p;

	if(n == 0) {
		cout << "1";
		return 0;
	}

	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		bool check = false;
		if(v[i] > score) {
			result++;
			cnt++;
		}
		else if(v[i] == score) {
			cnt++;
		}
		else if(v[i] < score){
			break;
		}
		if(check)	break;
	}
	
	if(cnt == p)	cout << "-1";
	else cout << result;
	
	return 0;
}
