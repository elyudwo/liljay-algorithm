#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int k;
	cin >> k;
	int N = 1000 - k;
	int cnt = 0;
	while(N!=0)
	{
		if(N>=500) {
			N = N - 500 ;
			cnt ++;
		}
		else if(N<500 && N >= 100){
			N = N - 100;
			cnt++;
		}
		else if(N<100 && N >= 50){
			N = N - 50;
			cnt++;
		}
		else if(N<50 && N >= 10){
			N = N - 10;
			cnt++;
		}
		else if(N<10 && N >= 5){
			N = N - 5;
			cnt++;
		}
		else if(N<5 && N >= 1){
			N = N - 1;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
