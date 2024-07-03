#include <iostream>

using namespace std;

typedef long long ll;

ll arr[500003];
ll sum_ns[500003];
ll sum_sn[500003];

ll answer_ns[500003];
ll answer_sn[500003];
ll answer = -60000000000000;

int main() {
	int n, k;
	cin >> n >> k;
	
	for(int i=0; i<n; i++) { cin >> arr[i]; }
	for(int i=1; i<n; i++) {
		sum_ns[i-1] = arr[i-1] - arr[i] - k;
	}
	for(int i=1; i<n; i++) {
		sum_sn[i-1] = arr[i] - arr[i-1] - k;
	}
	
	answer_ns[0] = sum_ns[0];
	answer = max(answer, answer_ns[0]);
	for(int i=1; i<n-1; i++) {
		ll tmp = 0;
		answer_ns[i] = sum_ns[i] + max(tmp, answer_ns[i-1]);
		answer = max(answer, answer_ns[i]);
	}
	
	answer_sn[0] = sum_sn[0];
	answer = max(answer, answer_sn[0]);
	for(int i=1; i<n-1; i++) {
		ll tmp = 0;
		answer_sn[i] = sum_sn[i] + max(tmp, answer_sn[i-1]);
		answer = max(answer, answer_sn[i]);
	}
	
	
	cout << answer;
}