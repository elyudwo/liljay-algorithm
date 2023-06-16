#include <iostream>
#include <vector>

using namespace std;

int n;
int answer = 0;
int check[1001];
vector<int> line;
vector<int> correct;
vector<vector<int> > collect_line;

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		line.push_back(tmp);
	}
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		correct.push_back(tmp);
	}
}

void checkIndent() {
	for(int i=0; i<n; i++) {
		if(line[i] < correct[i]) { check[i] = 1; }
		else if(line[i] > correct[i]) { check[i] = 2; }
		else { check[i] = 3; }
	}
}

void collect() {
	vector<int> rem;
	
	if(check[0] == 1) { rem.push_back({correct[0] - line[0]}); }
	else if(check[0] == 2) { rem.push_back({line[0] - correct[0]}); }
	
	for(int i=1; i<n; i++) {
		if(check[i] != check[i-1]) {
			collect_line.push_back(rem);
			rem.clear();
			if(check[i] == 1) { rem.push_back({correct[i] - line[i]}); }
        	else if(check[i] == 2) { rem.push_back({line[i] - correct[i]}); }
		}
		else {
		    if(check[i] == 1) { rem.push_back({correct[i] - line[i]}); }
	        else if(check[i] == 2) { rem.push_back({line[i] - correct[i]}); }
		}
	}
	
	collect_line.push_back(rem);
}

void solve() {
	checkIndent();
	collect();
	 
	for(vector<int> vec : collect_line) {
		for(int i=0; i<vec.size(); i++) {
		    if(vec[i] <= 0) { continue; }
		    
		    int s = vec[i];
		    for(int k=0; k<s; k++) {
		        for(int j=i; j<vec.size(); j++) {
    				if(vec[j] <= 0) { break; }
    				vec[j] = vec[j] - 1;
    			}
    			answer += 1;
		    }
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}