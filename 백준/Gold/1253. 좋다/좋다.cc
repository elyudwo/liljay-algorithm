#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int n;
unordered_map<int, int> ma;

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		ma[tmp] += 1;
	}
}

void solve() {
	long long answer = 0;
	
	for(pair<int,int> p1 : ma) {
		for(pair<int,int> p2 : ma) {
		    if(p1.first == p2.first && p1.first == 0) {
		        if(ma[p1.first] >= 3) {
		            answer += ma[p1.first];
		        }
		        break;
		    }
		    
			if(p1.first == p2.first) {
			    if(ma[p1.first] >= 2 && ma.count(0) >= 1) {
    				answer += ma[p1.first];
    				break;
			    }
			    continue; 
			}
			
			if(ma.count(p1.first - p2.first) >= 1) {
			    if(p2.first == p1.first - p2.first) {
			        if(ma[p2.first] < 2) {
			            continue;
			        }
			    }
			    if(p1.first - p2.first == p1.first) {
			        if(ma[p1.first] < 2) {
			            continue;
			        }
			    }
			    answer += ma[p1.first];
			    break;
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
}