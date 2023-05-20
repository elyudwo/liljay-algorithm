#include <iostream>
#include <cmath>
#include <vector>
 
using namespace std;

long long n,Hatk;

struct s {
	int num;
	long long a;
	long long h;
};

vector<s> vec;

void input() {
	cin >> n >> Hatk;

	int a,b,c;
	
	for(int i=0; i<n; i++) {
		cin >> a >> b >> c;
		vec.push_back({a,b,c});
	}
}

bool check(long long mid) {
	long long tmp = mid;
	long long atk = Hatk;
	
	for(int i=0; i<vec.size(); i++) {
		if(vec[i].num == 1) {
			int cnt = 0;
			
			if(vec[i].h % atk != 0) { cnt = vec[i].h/atk; }
			else { cnt = vec[i].h/atk - 1; }
			
			tmp -= cnt * vec[i].a;
			if(tmp <= 0) { return false; }
		}
		else {
			atk += vec[i].a;
			tmp += vec[i].h;
			
			if(tmp > mid) {
				tmp = mid;
			}
		}
	}
	
	return true;
}

void solve() {
	long long left = 0;
	long long right = 1e18;
	long long result = -1;
	
	while(left <= right) {
		long long mid = (left + right) / 2;
		
		bool tmp = check(mid);
		// 성공 
		if(tmp == true) {
			result = mid;
			right = mid - 1;
		}
		// Hp 더 필요 
		else { left = mid + 1; }
	}
	
	cout << result;
}

int main() {
	input();
	solve();
	
}