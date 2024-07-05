#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<string,string> > v;
vector<int> vec;
int max_song = 0;
int answer = 0;

void dfs(int cnt, int idx) {
	if(vec.size() == cnt) {
		bool check[50] = {false,};
		int result = 0;
		
		for(int i=0; i<vec.size(); i++) {
//			cout << vec[i] << " ";
			string tmp = v[vec[i]].second;
//			cout << tmp << " ";
			for(int j=0; j<m; j++) {
				if(tmp[j] == 'Y' && !check[j]) {
					check[j] = true;
					result++;
				}
			}
		}
//		cout << endl;
//		cout << result << endl;
		
		if(result > max_song) {
			answer = cnt;
			max_song = result;
		}
		
		
		return;
	}
	
	for(int i=idx; i<n; i++) {
		vec.push_back(i);
		dfs(cnt, i + 1);
		vec.pop_back();
	}
}

int main() {
	cin >> n >> m;

	for(int i=0; i<n; i++) {
		string a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	for(int i=1; i<=n; i++) {
		dfs(i, 0);
		vec.clear();
	}
	if(max_song == 0) {
		cout << "-1";
		return 0;
	}
	cout << answer;
}