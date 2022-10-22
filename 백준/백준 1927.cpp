#include <iostream>
#include <queue>
#include <vector>
#include <functional> 
using namespace std;

int main(void)
{
	priority_queue <int, vector<int>, greater<int> > pq;
	
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d",&a);
		if(a == 0) {
		    if(pq.empty()) {
		        printf("0\n");
		    }
		    else {
		        printf("%d\n",pq.top());
			    pq.pop();
		    }
		}
		else {
			pq.push(a);
		}
	}
	
	return 0;
}
