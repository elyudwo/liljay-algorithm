#include <iostream>
#include <string>
using namespace std;

int dx[] = {1,-1,0,0,1,-1,1,-1};
int dy[] = {0,0,1,-1,-1,-1,1,1};
string move1[8] = {"R","L","B","T","RT","LT","RB","LB"};
bool v[8][8];

int main(void)
{
	int c1[8] = {8,7,6,5,4,3,2,1};
	int c2[8] = {1,2,3,4,5,6,7,8};
	int b1[9] = {0,8,7,6,5,4,3,2,1};
	int b2[9] = {0,1,2,3,4,5,6,7,8};
	char c3[9] = {'a','A','B','C','D','E','F','G','H'};
	string s1,s2,ans1,ans2;
	int x1,y1,x2,y2;
	
	string lee;
	
	int n;
	cin >> s1 >> s2 >> n;

	x1 = c2[s1[0] - 'A'];
	y1 = c1[s1[1]-'1'];	
	
	x2 = c2[s2[0] - 'A'];
	y2 = c1[s2[1] - '1'];
	cout <<endl <<  x1 << " " << y1 << endl << x2 << " " << y2 << endl;
	
	for(int i=0; i<n; i++) {
		cin >> lee;
		for(int j=0; j<8; j++) {
			if(move1[j] == lee) {
				int nx = x1 + dx[j];
				int ny = y1 + dy[j];
				if(nx < 1 || nx > 8 || ny < 1 || ny > 8) {
					break;
				}
				if(nx == x2 && ny == y2) {
					x2 = x2 + dx[j];
					y2 = y2 + dy[j];
					if(x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
					    x2 = x2 - dx[j];
					    y2 = y2 - dy[j];
					    break;
					}
					x1 = nx;
					y1 = ny;
				}
				else {
					x1 = nx;
					y1 = ny;
				}
			}
		}
		cout <<endl << x1 << " " << y1 << endl << x2 << " " << y2 << endl;
	}
	
	/*
	ans1 = c3[x1] + to_string(b1[y1]);
	ans2 = c3[x2] + to_string(b1[y2]);
	
	cout << ans1 << endl << ans2;
	*/
	return 0;
}
