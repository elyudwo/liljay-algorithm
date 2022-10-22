#include <iostream>
#include <deque>
using namespace std;

bool check[5001];
deque<int> dq;

int main(void)
{
	int n,k;
	cin >> n >> k;
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		dq.push_back(i);
	}
	
	if(n == 1) {
		cout << "<1>";
		return 0;
	}
	
	cout << "<" << dq[k-1] << ", ";
	int pos = k-1;
	dq.erase(dq.begin() + pos);
	
	for(int i=0; i<n-1; i++) {
		pos = (pos + k-1) % dq.size();
		if(i == n-2) {
			cout << dq[pos];
			break;
		} 
		cout << dq[pos] << ", ";
		dq.erase(dq.begin() + pos);
		if(pos == dq.size()) {
			pos = 0;
		}
	}
	cout << ">";
	
	return 0;
}
