#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rec[101];

int main(void)
{
	int n;	
	cin >> n;
	int m;	
	cin >> m;
	vector<pair <int,int> > v(20);
	for(int i=0; i<m; i++) {
		bool check = true;
		int a;
		cin >> a;
		rec[a]++;
		
		for(int j=0; j < n; j++) {
			if(v[j].second == 0) {
				v[j].second = a;
				v[j].first = i;
				check = false;
				break;
			}
			else if(v[j].second == a) {
				check = false;
				break;
			}
		}
		
		if (check) {
            int idx = 0;
            for (int j = 1; j < n; j++) {
                if (rec[v[j].second] == rec[v[idx].second]) {
                    if (v[j].first < v[idx].first) 
						idx = j;
                }
                else if (rec[v[j].second] < rec[v[idx].second]) {
                    idx = j;
                }
            }
 
            rec[v[idx].second] = 0; //바꿔쳐지면 추천수 초기화
 
            v[idx].first = i;
            v[idx].second = a;
        }
	}
	
	vector<int> lee;
	for(int i=0; i<n; i++) {
		lee.push_back(v[i].second);
	}
	sort(lee.begin(),lee.end());
	
	for(int i=0; i<n; i++) {
		cout << lee[i] << " ";
	}
	
	return 0;
}
