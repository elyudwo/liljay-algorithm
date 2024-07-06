#include <iostream>
#include <set>
#include <map> 
using namespace std;

set<int> se[101];
map<int,int> ma;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, m;
	
	cin >> n;
	for(int i=0; i<n; i++) {
		int p,l;
		cin >> p >> l;
		se[l].insert(p);
		ma[p] = l;
	}
	
	cin >> m;
	
	for(int i=0; i<m; i++) {
		string cmd;
		cin >> cmd;
		if(cmd == "add") {
			int p, l;
			cin >> p >> l;
			se[l].insert(p);
			ma[p] = l;
		}
		if(cmd == "recommend") {
			int num;
			cin >> num;
			if(num == 1) {
				for(int j=100; j>=1; j--) {
					if(se[j].size() >= 1) {
						cout << *prev(se[j].end()) << '\n';
						break;
					}
				}
			}
			if(num == -1) {
				for(int j=1; j<=100; j++) {
					if(se[j].size() >= 1) {
						cout << *se[j].begin() << '\n';
						break;
					}
				}
			}
		}
		if(cmd == "solved") {
			int num;
			cin >> num;
			int rank = ma[num];
			se[rank].erase(num);
		}
	}
}