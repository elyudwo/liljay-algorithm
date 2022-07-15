#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string,string>> student;

int main(void)
{
	int n,p;
	cin >> n >> p;
	int w,l,g;
	cin >> w >> l >> g;
	int sum = 0;
	bool ccc = false;

	for(int i=0; i<p; i++) {
		string name;
		cin >> name;
		string game;
		cin >> game;
		student.push_back({name,game});
	}
	
	for(int i=0; i<n; i++) {
		string str;
		bool lee = false;
		cin >> str;
		for(int j = 0; j<student.size(); j++) {
			if(student[j].first == str) {
				lee = true;
				if(student[j].second == "W") {
					sum = sum + w;
				}
				else if(student[j].second == "L") {
					if(sum <= l) {
						sum = 0;
					}
					else {
						sum = sum - l;
					}
				}
			}
		}
		if(!lee) {
			if(sum <= l) {
				sum = 0;
			}
			else {
				sum = sum - l;
			}
		}
		
		if(sum >= g) {
		    ccc = true;
		
		}
	}
	
	if(ccc) {
	    cout <<"I AM NOT IRONMAN!!";
	}
	else {
	    cout << "I AM IRONMAN!!";
	}
	
	
	return 0;
}
