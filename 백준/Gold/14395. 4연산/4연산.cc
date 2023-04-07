#include<iostream>
#include<string>
#include<queue>
#include<set>
 
typedef long long ll;
 
#define endl "\n"
using namespace std;
 
bool Answer = false;
ll Start, End;
string Dr[] = { "*", "+", "-", "/" };
set<ll> S;
 
void Input()
{
    cin >> Start >> End;
    if (Start == End)
    {
        cout << 0 << endl;
        exit(0);
    }
}
 
ll Calculate(ll a, int Idx)
{
    if (Idx == 0) return (a * a);
    else if (Idx == 1) return (a + a);
    else if (Idx == 2) return (a - a);
    else if (Idx == 3) return (a / a);
}
 
string BFS()
{
    queue<pair<ll, string>> Q;
    Q.push(make_pair(Start, ""));
    S.insert(Start);
 
    while (Q.empty() == 0)
    {
        ll x = Q.front().first;
        string s = Q.front().second;
        Q.pop();
 
        if (x == End)
        {
            Answer = true;
            return s;
        }
        for (int i = 0; i < 4; i++)
        {
            ll nx = Calculate(x, i);
            if (nx < 1) continue;
            if (S.find(nx) != S.end()) continue;
            S.insert(nx);
            Q.push(make_pair(nx, s + Dr[i]));
        }
    }
    return "a";
}
 
void Solution()
{
    string R = BFS();
    if (Answer == true) cout << R << endl;
    else cout << "-1" << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}