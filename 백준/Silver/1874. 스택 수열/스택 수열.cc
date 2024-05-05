#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool check[100001];
vector<char> result;
int main(void)
{
	int n;
	scanf("%d",&n);
	stack<int> s;
	int max_value = 1;
	while(n--) {
		int a,b;
		cin >> a;
		
		if(check[a]) {
			b = s.top();
			if(b != a) {
				printf("NO");
				return 0;
			}
			else {
				result.push_back('-');
				s.pop();
			}
		}
		else {
			for(int i=max_value; i<=a; i++) {
				if(check[i]) {
					continue;
				}
				else {
					check[i] = true;
					s.push(i);
					result.push_back('+');
				}
			}
			b = s.top();
			if(b != a) {
				printf("NO");
				return 0;
			}
			else if(b == a) {
				result.push_back('-');
				s.pop();
			}
		}
		max_value = max(max_value,a);
	}
	
	for(int i=0; i<result.size(); i++) {
		printf("%c\n",result[i]);
	}
	
	return 0;
}