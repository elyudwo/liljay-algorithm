#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

int main() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	int answer = 1;
	int weight = m;
	for(int i=0; i<vec.size(); i++) {
		int cur = vec[i];
		if(weight - cur < 0) {
			answer++;
			weight = m - cur;
			continue;
		}
		weight -= cur;
	}
	if(answer == 1 && weight == m) {
		cout << "0";
		return 0;
	}
	
	cout << answer;
}