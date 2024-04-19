#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
	int n;
	
	while(cin >> n) {
		int half = 0;
		vector<pair<int,int> > vec;
		bool check[100001] = {false,};
		
		for(int i=0; i<n; i++) {
			int a,b;
			cin >> a >> b;
			vec.push_back({a, b});
			half += a * b;
		}
		
		if(half % 2 == 1) {
			cout << "0\n";
			continue;
		}
		
		half /= 2;
		sort(vec.begin(), vec.end());
	    check[0] = true;
		for(pair<int,int> p : vec) {
			for(int i=half; i>=0; i--) {
				if(i + p.first <= half && check[i]) {
				    
					for(int k=1; k<=p.second; k++) {
						if(i + k * p.first <= half) {
							check[i + k * p.first] = true;
						}
					}
				}
			}
		}
		
		if(check[half]) {
			cout << "1\n";
			continue;
		}
		cout << "0\n"; 
	}
   
} 