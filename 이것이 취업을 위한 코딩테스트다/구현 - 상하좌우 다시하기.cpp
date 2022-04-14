#include <iostream>
#include <vector>

using namespace std;

int n;
string plans;
int x = 1 , y = 1;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
char movetypes[4] = {'L','R','U','D'};

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	
	string plans;
	getline(cin,plans);
	
	for(int i=0; i<plans.size(); i++) {
		char plan = plans[i];
		int nx = -1, ny = -1;
		
		for(int j=0; j<4; j++) {
			if(plan == movetypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
	}
	
	
	
	return 0;
}
