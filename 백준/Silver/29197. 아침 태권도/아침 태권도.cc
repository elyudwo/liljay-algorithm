#include <iostream>
#include <set>

using namespace std;

set<double> s[5];

int main() {
	int n;
	cin >> n;
	
	while(n--) {
		double a,b;
		cin >> a >> b;
		
		double tmp = b/a;
		
		// 0에 걸쳐있는경우
		if(a == 0 && b > 0) {
			s[2].insert(0);
			continue;
		}
		if(a == 0 && b < 0) {
			s[4].insert(0);
			continue;
		}
		if(b == 0 && a > 0) {
			s[1].insert(0);
			continue;
		}
		if(b == 0 && a < 0) {
			s[3].insert(0);
			continue;
		}
		
		// 1 사분면 
		if(a > 0 && b > 0) { s[1].insert(tmp); }
		// 2 사분면 
		if(a < 0 && b > 0) { s[2].insert(tmp); }
		// 3 사분면
		if(a < 0 && b < 0) { s[3].insert(tmp); } 
		// 4 사분면
		if(a > 0 && b < 0) { s[4].insert(tmp); }
	}
	
	int answer = 0;
	for(int i=1; i<=4; i++) {
		answer += s[i].size();
	}
	cout << answer;
}