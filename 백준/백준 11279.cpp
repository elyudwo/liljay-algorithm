#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int,vector<int>,less<int> > pq;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		if(tmp == 0) {
			if(pq.size() == 0) {
				cout << "0" << '\n';
			}	
			else {
				cout << pq.top() << '\n';
				pq.pop();
			} 
		}
		else {
			pq.push(tmp);
		}
	}
	
	return 0;
}
