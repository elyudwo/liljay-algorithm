#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
	string name;
	int day;
	int month;
	int year;
}students[101];

bool compare(const student& s1,const student& s2)
{
	if(s1.year == s2.year) {
		if(s1.month == s2.month) {
			return s1.day > s2.day;
		}
		else
			return s1.month > s2.month;
	}
	else {
		return s1.year > s2.year;
	}
}

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		string na;
		int d,m,y;
		cin >> na >> d >> m >> y;
		students[i].name = na;
		students[i].day = d;
		students[i].month = m;
		students[i].year = y;
	}
	
	sort(students,students+n,compare);
	
	cout << students[0].name << endl << students[n-1].name;
	
	
	return 0;
}
