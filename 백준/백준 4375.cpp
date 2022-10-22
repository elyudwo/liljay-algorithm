#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	unsigned long long int a;
	int cnt = 0;
	string str;
	while(scanf("%d",&n) != EOF) {
		str = str + "1";
		a = stoi(str);
		cnt++;
		if(a % n == 0) {
			cout << cnt << '\n';
			cnt = 0;
		}
	}
	
	return 0;
}
