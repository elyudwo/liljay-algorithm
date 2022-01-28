#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int,int> > a,pair<string, pair<int,int> > b)
{
	if(a.second.first==b.second.first)
	{
		return a.second.second > b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
		
}


int main(void)
{
	vector<pair<string, pair<int,int> > > v;
	v.push_back(pair<string, pair<int,int> >("이영재",make_pair(90,19960405)) );
	v.push_back(pair<string, pair<int,int> >("공민태",make_pair(97,19960405)) );
	v.push_back(pair<string, pair<int,int> >("김준범",make_pair(92,19940405)) );
	v.push_back(pair<string, pair<int,int> >("김대원",make_pair(90,19990205)) );
	v.push_back(pair<string, pair<int,int> >("계영준",make_pair(93,19990405)) ); 
	
	
	sort(v.begin(),v.end(),compare);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<' ';	
	} 
	
	return 0;
}
