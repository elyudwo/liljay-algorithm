#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct student {
	int score;
	int cnt;
	int last;
};

bool cmp(student a, student b) {
	if(a.score == b.score) {
		if(a.cnt == b.cnt) {
			return a.last < b.last;
		}
		return a.cnt < b.cnt;
	}
	return a.score > b.score;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int n,k,t,m;
		int answer_score, answer_cnt, answer_last;
		int arr[101][101] = {0,};
		student vec[101];
		
		cin >> n >> k >> t >> m;
		
		for(int i=0; i<m; i++) {
			int a,b,c;
			cin >> a >> b >> c;
			
			// 시도 횟수 더해줌 
			vec[a].cnt += 1;
			
			// 마지막 시도횟수 초기화 
			vec[a].last = i;
			
			if(arr[a][b] < c) {
				vec[a].score -= arr[a][b];
				vec[a].score += c;
				arr[a][b] = c;
			}
		}
		
		answer_score = vec[t].score;
		answer_cnt = vec[t].cnt;
		answer_last = vec[t].last;
		
		sort(vec, vec + (n+1), cmp);
		
		for(int i=0; i<n; i++) {
			if(vec[i].score == answer_score && vec[i].cnt == answer_cnt && vec[i].last == answer_last) {
				cout << i+1 << endl;
			}
			vec[i].score = 0;
			vec[i].cnt = 0;
			vec[i].last = 0;
		}
		
	}
	
}