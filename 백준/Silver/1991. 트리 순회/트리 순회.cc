#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> vec[26];

void inOrder(char c) {
	if(vec[c-'A'][0].first != '.') {
		inOrder(vec[c-'A'][0].first);
	}
	
	cout << c;
	
	if(vec[c-'A'][0].second != '.') {
		inOrder(vec[c-'A'][0].second);
	}
}

void preOrder(char c) {
    cout << c;
    if(vec[c-'A'][0].first != '.') {
		preOrder(vec[c-'A'][0].first);
	}
	
	if(vec[c-'A'][0].second != '.') {
		preOrder(vec[c-'A'][0].second);
	}
} 

void postOrder(char c) {
    if(vec[c-'A'][0].first != '.') {
		postOrder(vec[c-'A'][0].first);
	}
	
	if(vec[c-'A'][0].second != '.') {
		postOrder(vec[c-'A'][0].second);
	}
	cout << c;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		char a,b,c;
		cin >> a >> b >> c;
		vec[a-'A'].push_back({b,c});
	}
	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
}