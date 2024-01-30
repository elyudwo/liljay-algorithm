#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int price[52];
int arr[52];
int n,m;
vector<pair<int,int> > vec;
vector<string> str_vec;
string str = "";
int coin;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return a.second > b.second;
	}
	
	return a.first < b.first;
}

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int tmp; 
		cin >> tmp;
		arr[i] = tmp;
		vec.push_back({tmp, i});
	}
	cin >> m;
	
	sort(vec.begin(), vec.end(), cmp);
	
// 	cout << "자 시작 : ";
// 	for(auto i : vec) {
// 	    cout << i.first << " " << i.second << endl;
// 	}
}

int calculateMaxDigit() {
	if(vec[0].second == 0) {
		int tmp = m;
		int result = 0;
	
		tmp -= vec[1].first;
		str_vec.push_back(to_string(vec[1].second));
		
		result++;
		
		while(tmp > 0) {
			if(tmp - vec[0].first >= 0) {
				result++;
				tmp -= vec[0].first;
				str_vec.push_back(to_string(vec[0].second));
			}
			else {
				break;
			}
		}
		coin = tmp;
		return result;
	}
	
	int tmp = m;
	int result = 0;
	while(tmp > 0) {
		if(tmp - vec[0].first >= 0) {
			result++;
			tmp -= vec[0].first;
			str_vec.push_back(to_string(vec[0].second));
		}
		else {
			break;
		}
	}
	coin = tmp;
	return result;
}

void print() {
    for(int i=0; i<str_vec.size(); i++) {
        cout << str_vec[i] << " ";
    }
    cout << endl << endl;
}

void solve() {
	int max_digit = calculateMaxDigit();
// 	print();
	
	if(coin < 0 || n == 1) {
	    cout << "0";
	    return;
	}
    if(coin == 0) {
        for(int i=0; i<str_vec.size(); i++) {
            cout << str_vec[i];
        }
        return;
    }
    
	for(int i=0; i<str_vec.size(); i++) {
		int idx = stoi(str_vec[i]);
		int tmp = coin + arr[idx];
		
		for(int j=n-1; j>=idx + 1; j--) {
			if(tmp - arr[j] >= 0) {
				str_vec[i] = to_string(j);
				coin = tmp - arr[j];
				break;
			}
		}
	}
	
	for(int i=0; i<str_vec.size(); i++) {
		str += str_vec[i];
	}
	
	cout << str;
}

int main() {
	input();
	solve();
	
}