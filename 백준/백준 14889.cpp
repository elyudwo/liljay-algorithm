#include <iostream>
#include <vector>
using namespace std;

int v[21][21];
int min_tmp = 9999;
int n;
bool check[21];
int c = 0;
void combination(int x,int y) 
{
	if(y == n/2) {
		c++;
		int sum;
		int sum_lee = 0;
		int sum_shin = 0;
		int lee[21];
		int lee_cnt = 0;
		int shin[21];
		int shin_cnt = 0;
		
		for(int i=1; i<=n; i++) {
			if(check[i] == true) {
				lee[lee_cnt++] = i;
			}
			else {
				shin[shin_cnt++] = i;
			}
		}
		for(int i=0; i<lee_cnt; i++) {
			for(int j=0; j<lee_cnt; j++) {
				if(i == j) {
					continue;
				}
				else {
					sum_lee = sum_lee + v[lee[i]][lee[j]];
				}
			}
		}
		
		for(int i=0; i<lee_cnt; i++) {
			for(int j=0; j<lee_cnt; j++) {
				if(i == j) {
					continue;
				}
				else {
					sum_shin = sum_shin + v[shin[i]][shin[j]];
				}
			}
		}
		sum = sum_lee-sum_shin;
		if(sum < 0) {
			sum = -sum;
		}
		if(min_tmp > sum) {
			min_tmp = sum;
		}
	}
	
	for(int i=x; i<=n; i++) {
		if(check[i])	continue;
		check[i] = true;
		combination(i,y+1);
		check[i] = false;
	}
	
	
} 


int main(void)
{
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> v[i][j];
		}
	}
	
	combination(1,0);
	
	cout << min_tmp;
	return 0;
}
