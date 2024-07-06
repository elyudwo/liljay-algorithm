#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>

using namespace std;

int arr[102][102];
int w = 3, l = 3;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void rotateRow() {
    int max_cnt = 0;
	for(int i=1; i<=w; i++) {
		vector<pair<int,int> > vec;
		map<int,int> ma;
		
		for(int j=1; j<=l; j++) {
			if(!arr[i][j]) continue;
			ma[arr[i][j]]++;
		}
		
		for(pair<int,int> p : ma) {
			vec.push_back(p);
		}
		sort(vec.begin(), vec.end(), cmp);
		
		int cnt = 1;
		
		for(int j=0; j<vec.size(); j++) {
			if(j >= 50) { break; }
			arr[i][cnt++] = vec[j].first;
			arr[i][cnt++] = vec[j].second;
		}
		max_cnt = max(max_cnt, cnt);
		
		for(int j=cnt; j<=100; j++) {
	        arr[i][j] = 0;
	    }
	}
	l = max_cnt-1;
}

void rotateColumn() {
    int max_cnt = 0;
	for(int i=1; i<=100; i++) {
		vector<pair<int,int> > vec;
		map<int,int> ma;
		
		for(int j=1; j<=100; j++) {
			if(!arr[j][i]) continue;
			ma[arr[j][i]]++;
		}
		
		for(pair<int,int> p : ma) {
			vec.push_back(p);
		}
		sort(vec.begin(), vec.end(), cmp);
		
		int cnt = 1;
		
		for(int j=0; j<vec.size(); j++) {
			if(j >= 50) { break; }
			arr[cnt++][i] = vec[j].first;
			arr[cnt++][i] = vec[j].second;
		}
		max_cnt = max(max_cnt, cnt);
	    
	    for(int j=cnt; j<=100; j++) {
	        arr[j][i] = 0;
	    }
	}
	w = max_cnt - 1;
}

void print() {
    cout << w << " " << l << '\n'; 
    cout << '\n';
    for(int i=1; i<=w; i++) {
        for(int j=1; j<=l; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int r,c,k;
	cin >> r >> c >> k;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			cin >> arr[i][j];
		}
	}
	
	if(arr[r][c] == k) { cout << "0"; return 0; }
	
	int t = 0;
	while(t < 100) {
		t++;
		if(w >= l) { rotateRow(); }
		else { rotateColumn(); }
// 		print();
		
		if(arr[r][c] == k) { cout << t; return 0;}
	}
	
	cout << "-1";
	
}