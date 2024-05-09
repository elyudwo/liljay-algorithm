#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<pair<int,int> > vec[26];
char lef;
char rig;
set<char> se;
string str;

void input() {
   vec['q' - 'a'].push_back({0,0});   
   vec['w' - 'a'].push_back({0,1});   
   vec['e' - 'a'].push_back({0,2});   
   vec['r' - 'a'].push_back({0,3});   
   vec['t' - 'a'].push_back({0,4});   
   vec['y' - 'a'].push_back({0,5});   
   vec['u' - 'a'].push_back({0,6});   
   vec['i' - 'a'].push_back({0,7});   
   vec['o' - 'a'].push_back({0,8});   
   vec['p' - 'a'].push_back({0,9});   

   vec['a' - 'a'].push_back({1,0});   
   vec['s' - 'a'].push_back({1,1});   
   vec['d' - 'a'].push_back({1,2});   
   vec['f' - 'a'].push_back({1,3});   
   vec['g' - 'a'].push_back({1,4});   
   vec['h' - 'a'].push_back({1,5});   
   vec['j' - 'a'].push_back({1,6});   
   vec['k' - 'a'].push_back({1,7});   
   vec['l' - 'a'].push_back({1,8});   

   vec['z' - 'a'].push_back({2,0});   
   vec['x' - 'a'].push_back({2,1});
   vec['c' - 'a'].push_back({2,2});   
   vec['v' - 'a'].push_back({2,3});   
   vec['b' - 'a'].push_back({2,4});   
   vec['n' - 'a'].push_back({2,5});   
   vec['m' - 'a'].push_back({2,6});   
   
   se.insert('q');
   se.insert('w');
   se.insert('e');
   se.insert('r');
   se.insert('t');
   se.insert('a');
   se.insert('s');
   se.insert('d');
   se.insert('f');
	se.insert('g');
   se.insert('z');
   se.insert('x');
   se.insert('c');
   se.insert('v');
   
   cin >> lef >> rig;
   cin >> str;
}

void solve() {
	int answer = 0;
	
	for(char c : str) {
	    answer++;
		int nx = vec[c - 'a'][0].first; int ny = vec[c - 'a'][0].second;
		if(se.count(c)) {
			int x = vec[lef - 'a'][0].first; int y = vec[lef - 'a'][0].second;
			
			answer += abs(x - nx) + abs(y - ny);
			lef = c;
			continue;
		}
		int x = vec[rig - 'a'][0].first; int y = vec[rig - 'a'][0].second;
		
		answer += abs(x - nx) + abs(y - ny);
		rig = c;
	}
	
	cout << answer;
}

int main() {
   input();
   solve();
}