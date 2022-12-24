#include <iostream>
#include <string>
#include <vector>

using namespace std;
int t;
vector<string> end;
vector<string> day;

void input() {
	cin >> t;
	string str1,str2;
	for(int i=0; i<t; i++) {
		cin >> str1 >> str2;
		end.push_back(str1);
		day.push_back(str2);
	}
}

vector<string> splitStr(string str) {
	vector<string> tmp;
	string rem = "";
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '/') {
			tmp.push_back(rem);
			rem = "";
		}
		else {
			rem+=str[i];
		}
	}
	return tmp;
}

bool checkBack(string endMonth,string dayMonth) {
	if(stoi(endMonth) == 1 && stoi(dayMonth) == 12) {
		return true;
	}
	return false;
}

bool checkFront(string endMonth,string dayMonth) {
	if(stoi(endMonth) == 12 && stoi(dayMonth) == 1) {
		return true;
	}
	return false;
}

string calculateDay(string endYear,string dayYear, string endMonth,string dayMonth,string endDay, string dayDay) {
	string result = "";
	
	if(endMonth == dayMonth) {
		int ed = stoi(endDay);
		int dd = stoi(dayDay);
		if(ed > dd) {
			result = to_string(ed-dd) + " DAYS PRIOR";
		}
		else if(ed < dd) {
			result = to_string(dd-ed) + " DAYS AFTER";
		}
		else if(ed == dd) {
			result = "SAME DAY"; 
		}
	}
	
	if(endYear > dayYear) {
		int ed = stoi(endDay);
		int dd = 31 - stoi(dayDay);
		
		if(ed + dd > 7) {
			result = "OUT OF RANGE";
		}
		else {
			result = to_string(ed+dd) + " DAYS PRIOR";
		}
	}
	else if(endYear < dayYear) {
		int ed = 31 - stoi(endDay);
		int dd = stoi(dayDay);
		
		if(ed + dd > 7) {
			result = "OUT OF RANGE";
		}
		else {
			result = to_string(ed+dd) + " DAYS AFTER";
		}
	}
	else if(endYear == dayYear) {
		if(endMonth > dayMonth) {
			if(dayMonth == 1 || dayMonth == 3 || dayMonth == 5 || dayMonth == 7 || dayMonth == 8 || dayMonth == 10 || dayMonth == 12) {
				int ed = stoi(endDay);
				int dd = 31 - stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
			else if(dayMonth == 2) {
				int ed = stoi(endDay);
				int dd = 28 - stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
			else {
				int ed = stoi(endDay);
				int dd = 30 - stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
		}
		else if(endMonth < dayMonth) {
			if(endMonth == 1 || endMonth == 3 || endMonth == 5 || endMonth == 7 || endMonth == 8 || endMonth == 10 || endMonth == 12) {
				int ed = 31 - stoi(endDay);
				int dd = stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
			else if(endMonth == 2) {
				int ed = 28 - stoi(endDay);
				int dd = stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
			else {
				int ed = 30 - stoi(endDay);
				int dd = stoi(dayDay);
				if(ed + dd > 7) {
					result = "OUT OF RANGE";
				}
				else {
					result = to_string(ed+dd) + " DAYS AFTER";
				}
			}
		}
	}
	
	
	
	return result;
}

void solve() {
	string endYear,endMonth,endDay,dayYear,dayMonth,dayDay;
	for(int i=0; i<t; i++) {
		vector<string> tmp1 = splitStr(end[i]);
		endYear = tmp[2];
		endMonth = tmp[0];
		endDay = tmp[1];
		
		vector<string> tmp2 = splitStr(day[i]);
		dayMonth = tmp[0];
		dayDay = tmp[1];
		
		if(checkBack()) {
			dayYear = endYear - 1;
			
		
		}
		if(checkFront()) {
			dayYear = endYear + 1;
			
		
		}
		if(!checkBack() && !checkFront()) {
			dayYear = endYear;
		}
		
		
		string lee = calculateDay( endYear, dayYear,  endMonth, dayMonth, endDay,  dayDay);
		cout << dayMonth << "/" << dayDay << "/" << dayYear << " IS " << result << endl;
	}
}

int main()
{
	input();
	solve();
}
