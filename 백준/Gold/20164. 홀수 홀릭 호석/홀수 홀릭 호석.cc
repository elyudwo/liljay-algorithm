#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string str;
int max_result = -1;
int min_result = 999999999;

void dfs(string tmp, int cnt) {
	if(tmp.length() >= 3) {
	    int k = 2;
	    vector<int> vec;
	 
	    for(int i = 0; i < tmp.length()-1; i++)
	    	vec.push_back(i+1);
	    
	    vector<int> tempVector;
	    for (int i = 0; i < k; i++)
	        tempVector.push_back(1);
	    
	    for (int i = 0; i < vec.size() - k; i++)
	        tempVector.push_back(0);
	    
	    sort(tempVector.begin(), tempVector.end());
	    
	    do{
	        vector<int> rem;
	    	for (int i = 0; i < tempVector.size(); i++) {
	            if (tempVector[i] == 1){
	            	rem.push_back(vec[i]);
	            }
	        }
	        
	        int result = 0;
            int plus = 0;
            
            string str1 = "";
            for(int i=0; i<rem[0]; i++) {
            	str1 = str1 + tmp[i];
			}
			result = result + stoi(str1);
			
			
			string str2 = "";
			for(int i=rem[0]; i<rem[1]; i++) {
				str2 = str2 + tmp[i];
			}
			result = result + stoi(str2);
			
			
			string str3 = "";
			for(int i=rem[1]; i<tmp.length(); i++) {
				str3 = str3 + tmp[i];
			}
			result = result + stoi(str3);
			
			string str4 = "";
			str4 = to_string(result);
			
			
			for(int i=0; i<str4.length(); i++) {
				int a = str4[i] - '0';
				if(a % 2 == 1) {
					plus = plus + 1;
				}
			}
			dfs(str4, cnt + plus);
	        
		} while (next_permutation(tempVector.begin(), tempVector.end()));
		
		
		
	}
	else if(tmp.length() == 2) {
		int result = 0;
		int plus = 0;
		
		for(int i=0; i<2; i++) {
			int a = tmp[i] - '0';
			result = result + a;
		}
		
		string rem = to_string(result);
		for(int i=0; i<rem.length(); i++) {
			int a = rem[i] - '0';
			if(a % 2 == 1) {
				plus = plus + 1;
			}
		}
		
		dfs(rem,cnt + plus);
		
	}
	else if(tmp.length() == 1) {
		max_result = max(max_result,cnt);
		min_result = min(min_result,cnt);
		return;
	}
}


void input() {
	cin >> str;
}

void solve() {
	int answer = 0;
	for(int i=0; i<str.length(); i++) {
		int a = str[i] - '0';
		if(a % 2 == 1) {
			answer++;
		}
	}
	
	dfs(str,answer);
	
	cout << min_result << " " << max_result;
}

int main() {
	input();
	solve();
	
}