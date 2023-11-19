#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long arr[1000001];
long long *tree;

long long makeTree(int node, int start, int end) {
	if(start == end) {
		return tree[node] = arr[start]; 
	}
	int mid = (start + end) / 2;
	return tree[node] = makeTree(node*2, start, mid) + makeTree(node*2+1, mid+1, end);
}

long long sum(int node, int start, int end, int left, int right) {
	if(left > end || right < start) return 0;
	if(left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	
	return sum(node * 2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
	if(idx < start || idx > end) return;
	tree[node] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(node*2, start, mid, idx, diff);
	update(node*2+1, mid+1, end, idx, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,m,k;
	cin >> n >> m >> k;
	
	int height = (int)ceil(log2(n));
	tree = new long long[1 << (height+1)];
	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	makeTree(1,0,n-1);
	
	for(int i=0; i<m+k; i++) {
		long long a,b,c;
		cin >> a >> b >> c;
		if(a == 1) {
			long long diff = c-arr[b-1];
			arr[b-1] = c;
			update(1,0,n-1,b-1,diff);
		}
		else {
			cout << sum(1,0,n-1,b-1,c-1) << '\n';
		}
	}
}