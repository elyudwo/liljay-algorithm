#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int v[500001];
int result[500001];

int main(void)
{
	int n;
	cin >> n;

	stack<pair<int,int> > s;	//숫자 , 인덱스 
	
	//반대 접근
	
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	for(int i=n; i>=1; i--) {
		if(s.empty()) {
			s.push({v[i],i});
		}
		else {
			while(1) {
				if(s.empty()) {
					s.push({v[i],i});
					break;
				}
				if(s.top().first < v[i]) {
					result[s.top().second] = i;
					s.pop();
				}
				else {
					s.push({v[i],i});
					break;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
