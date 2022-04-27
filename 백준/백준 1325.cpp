#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 10001

int n,m;
vector<int> v[MAX];
vector<int> cnt;
bool c[MAX];
int count1;

void dfs(int n) 
{
    c[n] = true;
    
    for(int i=0; i<v[n].size(); i++) {
        int asd = v[n][i];
        
        if(!c[asd])
        {
            count1++;
            dfs(asd);    
        }
        
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	
	int maxhac = 0;
	
	for(int i=1; i<=n; i++) {
	    memset(c,false,sizeof(c));
	    count1 = 0;
	    
		dfs(i);
		if(maxhac == count1) {
		    cnt.push_back(i);
		}
		else if(maxhac < count1) {
		    maxhac = count1;
		    cnt.clear();
		    cnt.push_back(i);
		}

	}
	
	sort(cnt.begin(),cnt.end());
	for(int i=0; i<cnt.size(); i++) {
	    cout << cnt[i] << ' ';
	}
	
	return 0;
}
