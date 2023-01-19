#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int t, n;
vector<string> result;

void calculate(vector<string> vec, string str) {
	stack<int> stk;
	stack<string> op;

	for (int i = vec.size() - 1; i >= 0; i--) {
		if (vec[i] == "+" || vec[i] == "-") {
			op.push(vec[i]);
		}
		else {
			stk.push(stoi(vec[i]));
		}
	}
	int s = op.size();
	for (int i = 0; i < s; i++) {
		string c = op.top();
		op.pop();
		if (c == "+") {
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(a + b);
		}
		else if (c == "-") {
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			stk.push(a - b);
		}
	}

	if (stk.top() == 0) {
		result.push_back(str);
	}
}

void dfs(string str, string a, int cnt) {
	if (cnt == n) {
		str = str + to_string(n);
		a = a + to_string(n);
		vector<string> vec;
		string b = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+' || str[i] == '-') {
				vec.push_back(b);
				string rem = "";
				rem = rem + str[i];
				vec.push_back(rem);
				b = "";
			}
			else {
				b = b + str[i];
			}
		}
		vec.push_back(b);


		calculate(vec, a);
		return;
	}

	// 0 == +, 1 == ฐ๘น้, 2 == - 
	for (int i = 0; i < 3; i++) {
		string tmp = str + to_string(cnt);
		string k = a + to_string(cnt);

		if (i == 0) {
			tmp = tmp + "+";
			k = k + "+";
		}
		else if (i == 1) {
			k = k + " ";
		}
		else if (i == 2) {
			tmp = tmp + "-";
			k = k + "-";
		}
		dfs(tmp, k, cnt + 1);
	}
}

void input() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		dfs("", "", 1);
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
		result.clear();
		cout << '\n';
	}
}

int main() {
	input();

}
