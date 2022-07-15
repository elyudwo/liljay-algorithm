#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;

int result = 0;

int main(void)
{
	int n,m;	//n은 가로 m은 세로 
	cin >> n >> m;
	int t;
	cin >> t;
	vector< pair <int,int> > v;
	for(int i=0; i<t; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	int a,b;
	cin >> a >> b;
	v.push_back({a,b});
	
	for(int i=0; i<t; i++) {
		int tmp = 0;
		int max_value = -1;
		if((v[i].first + v[v.size()-1].first) % 4 == 3) {	//반대편에 있는경우
		 	if(v[i].first == 1 || v[i].first == 2) {
		 		tmp = tmp + abs(v[i].second - v[v.size()-1].second);
				max_value = max(abs((n/2 - v[v.size()-1].second)),abs((n/2 - v[i].second)));
				max_value = n/2-max_value;
				tmp = tmp + max_value * 2 + m;
			}
			else if(v[i].first == 3 || v[i].first == 4) {
				tmp = tmp + abs(v[i].second - v[v.size()-1].second);
				max_value = max(abs(m/2 - v[v.size()-1].second),abs(m/2 - v[i].second));
				max_value = m/2 - max_value;
				tmp = tmp + max_value * 2 + n;
			}
			result = result + tmp;
		}
		
		else if(v[i].first == v[v.size()-1].first) {
			tmp = abs(v[i].second - v[v.size()-1].second);
			result = result + tmp;
		}
		else {
			if(v[i].first == 1) {
				if(v[v.size()-1].first == 3) {
					tmp = tmp + v[i].second + v[v.size()-1].second;
				}
				else if(v[v.size()-1].first == 4) {
					tmp = tmp + n - v[i].second + v[v.size()-1].second;
				}
			}
			else if(v[i].first == 2) {
				if(v[v.size()-1].first == 3) {
					tmp = tmp + v[i].second + m-v[v.size()-1].second;
				}
				else if(v[v.size()-1].first == 4) {
					tmp = tmp + n-v[i].second +  m-v[v.size()-1].second;
				}
			}
			else if(v[i].first == 3) {
				if(v[v.size()-1].first == 1) {
					tmp = tmp + v[i].second + v[v.size()-1].second;
				}
				else if(v[v.size()-1].first == 2) {
					tmp = tmp + m-v[i].second + v[v.size()-1].second;
				}
			}
			else if(v[i].first == 4) {
				if(v[v.size()-1].first == 1) {
					tmp = tmp + v[i].second + n-v[v.size()-1].second;
				}
				else if(v[v.size()-1].first == 2) {
					tmp = tmp + m-v[i].second + n-v[v.size()-1].second;
				}
			}
			
			result = result + tmp;
		}
	}
	
	cout << result;
	
	return 0;
}
