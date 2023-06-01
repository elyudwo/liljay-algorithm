#include <iostream>
#include <string>

using namespace std;

int cnt = 1;

void solve(string now, string cmp) {
	/*
	1. 물음표로 최대한 숫자 맞추는 쪽으로 감 
	2. 위치 바꾸기  
	*/
	int answer = 0; 
	int now_zero = 0;
	int now_one = 0;
	int now_ques = 0;
	int cmp_zero = 0;
	int cmp_one = 0;
	
	// 숫자 확인 
	for(int i=0; i<cmp.size(); i++) {
		if(now[i] == '0') { now_zero += 1; }
		else if(now[i] == '1') { now_one += 1; }
		else if(now[i] == '?') { now_ques += 1; }
		
		if(cmp[i] == '0') { cmp_zero += 1; }
		else if(cmp[i] == '1') { cmp_one += 1; }
	}

	// 안될 때 
	if(cmp_zero > now_zero && cmp_zero - now_zero > now_ques) {
		cout << "Case " << cnt << ": -1\n";
		return; 
	}
	
	int ques_zero = 0;
	int ques_one = 0;
	
	// 물음표 맞춰주기
	if(cmp_zero >= now_zero) {
		ques_zero = cmp_zero - now_zero;
		ques_one = now_ques - ques_zero;
	}
	else {
		ques_one = now_ques;
	}
	
	for(int i=0; i<cmp.size(); i++) {
		if(now[i] == '?') {
			if(cmp[i] == '1') {
				if(ques_one != 0) {
					ques_one -= 1;
					now[i] = '1';
				}
				else {
					now[i] = '0';
					ques_zero -= 1;
				}
			}
			else if(cmp[i] == '0') {
				if(ques_zero != 0) {
					ques_zero -= 1;
					now[i] = '0';
				}
				else {
					now[i] = '1';
					ques_one -= 1;
				}
			}
		}
	}
	
	// 만약 now의 0의 개수가 더 많으면 cmp 1로 변환해줘야함 
	int now_last_zero = 0;
	int cmp_last_zero = 0;
	for(int i=0; i<cmp.size(); i++) {
		if(cmp[i] == '0') { cmp_last_zero += 1; }
		if(now[i] == '0') { now_last_zero += 1; }
	}
	
	if(now_last_zero > cmp_last_zero) {
		int tmp = now_last_zero - cmp_last_zero;
		for(int i=0; i<cmp.size(); i++) {
			if(tmp == 0) { break; }
			if(now[i] == '0' && cmp[i] == '1') {
			    answer += 1;
				now[i] = '1';
				tmp -= 1;
			} 
		}
	}
	
	answer += now_ques;
	
	int change = 0;
	// 서로 다른 위치 찾기 
	for(int i=0; i<cmp.size(); i++) {
		if(now[i] != cmp[i]) {
			change += 1;
		}
	}
	answer += change/2;
	
	cout << "Case " << cnt << ": " << answer << "\n";
}

void input() {
	int t;
	cin >> t;
	while(t--) {
		string now = "";
		string cmp = "";
		cin >> now;
		cin >> cmp;
		
		solve(now,cmp);
		
		cnt += 1;
	}
}



int main() {
	input();
}