#include <iostream>

using namespace std;

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {-1,-2,-2,-1,1,2,2,1};

int main(void)
{
	string str;
	cin >> str;
	
	
	
	int cnt = 0;
	for(int i=0; i<8; i++) {
		int x = str[0] - 'a';
		x++;
		int y = str[1] - '0';
		
		x = x + dx[i];
		y = y + dy[i];
		
		if(x>0 && y>0)
			cnt ++;	
	}
	
	cout << cnt;
	
	return 0;
}
