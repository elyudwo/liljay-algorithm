#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) 
{
	queue<int> q;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		q.push(i+1);
	}
	
	while(1) {
		if(q.size() == 1) {
			cout << q.front();
			break;
		}
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
		
	}
	
	return 0;
}
