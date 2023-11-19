#include <iostream>
#include <string>
 
using namespace std;

long long t[86401] = {0,};
long long sum[86401] = {0,};
bool check = false;

int convertStringToTime(string timeString) {
    int hour, minute, second;
    
    hour = stoi(timeString.substr(0,2));
    minute = stoi(timeString.substr(3,2));
    second = stoi(timeString.substr(6,2));
    
    int totalTime = hour * 3600 + minute * 60 + second;
    return totalTime;
}

void plusTime(int a, int b) {
	t[a] += 1;
	t[b] -= 1;
}

void plusAllTime() {
	for(int i=1; i<=86400; i++) {
		t[i] = t[i-1] + t[i];
	}
	for(int i=1; i<=86400; i++) {
		sum[i] = sum[i-1] + t[i];
	}
}

void calculateTime(int a, int b) {
	long long answer = 0;
	
	if(!check) {
		check = true;
		plusAllTime();
	}
	
	cout << sum[b] - sum[a] << '\n';
}

void init() {
    for(int i=0; i<=86400; i++) {
        t[i] = 0;
        sum[i] = 0;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int a;
		string start,end;
		cin >> a >> start >> end;
		
		int startTime = convertStringToTime(start) + 1;
		int endTime = convertStringToTime(end) + 1;
		
		if(a == 1) {
			plusTime(startTime, endTime);
		}
		else {
			calculateTime(startTime-1, endTime-1);
		}
	}
}