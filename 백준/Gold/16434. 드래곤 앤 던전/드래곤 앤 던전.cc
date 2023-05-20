#include <iostream>
#include <cmath>
 
using namespace std;

long long n,Hatk;

void input() {
	cin >> n >> Hatk;
}

void solve() {
	long long t,a,h;
	long long life = 0;
	long long store_life = 0;
	
	for(int i=0; i<n; i++) {
		cin >> t >> a >> h;
		
		if(t == 1) {
			long long cnt = 0;
			
			if(h % Hatk != 0) { cnt += h / Hatk; }
			else { cnt = h/Hatk -1; }
			
			long long damage = cnt * a;
			
			if(store_life != 0) {
				if(damage > store_life) {
					damage -= store_life;
					store_life = 0;
				}
				else {
					store_life -= damage;
					damage = 0;
				}
			}
			
			life += damage;
		}
		else if(t == 2) {
			Hatk += a;
			store_life += h;
			
			if(store_life > life) {
				store_life = life;
			}
		}
	}
	
	cout << life + 1;
}

int main() {
	input();
	solve();
	
}