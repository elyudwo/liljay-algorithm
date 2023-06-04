#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> vec;
		
		for(int i=0; i<n; i++) {
			int tmp;	
			cin >> tmp;
			vec.push_back(tmp);
		}
		
		// false 일때는 >, true 일때는 < 
		bool check = false;
		int result = 1;
		int now = vec[0];
		
		for(int i=1; i<n; i++) {
			if(!check) {
				if(now > vec[i]) { result += 1; check = !check; }
			}
			else {
				if(now < vec[i]) { result += 1; check = !check; }
			}
			now = vec[i];
		}
		
		cout << result << '\n';
	}
}