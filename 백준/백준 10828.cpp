#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	stack<int> s;
	
	for(int i=0; i<n; i++) {
		string str;
		int a;
		cin >> str;
		if(str == "push") {
			int a;
			cin >> a; 
			s.push(a);
		}
		else if(str == "pop") {
			if(s.empty()) {
				printf("-1\n");
			}
			else {
				int b = s.top();
				s.pop();
				printf("%d\n",b);
			}
		}
		else if(str == "size") {
			printf("%d\n",s.size());
		}
		else if(str == "empty") {
			if(s.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if(str == "top") {
			if(s.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n",s.top());
			}
		}
	}
	
	
	return 0;
}
