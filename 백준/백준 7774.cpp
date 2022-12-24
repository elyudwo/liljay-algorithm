#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> a;
vector<int> b;
int n,m;

bool cmp(int a,int b) {
	return a > b;
}

void input() {
	cin >> n >> m;
	int tmp;
	
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	for(int i=0; i<m; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}
}

void solve() {
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	int aConsent = 0;
	int bConsent = 0;
	
	for(int i=0; i<a.size(); i++) {
		bConsent += a[i];
		if(i != 0 && aConsent != 0) { aConsent--; }
		while(1) {
			if(b.size() == 0) {
				cout << aConsent;
				return;
			}
			if(bConsent == 0) { break; }
			else {
				bConsent--;
				if(b.size() != 0) {
					aConsent += b[0];
					b.erase(b.begin());
				}
			}
		}
	}
	cout << aConsent;
	return;
}

int main() {
	input();
	solve();
		
}
