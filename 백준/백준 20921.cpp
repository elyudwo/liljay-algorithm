#include <iostream>

using namespace std;

int v[4243];

int main(void)
{
	int n,k;
	cin >> n >> k;
	int shin=1;
	int lee = n;
	if(k < n) {
		for(int i=0; i<=n-k-1; i++) {
			if(i == n-k-1) {
				v[i] = lee;
			}
			else {
				v[i] = shin;
				shin++;	
			}
		}
		for(int i=n-k; i<n; i++) {
			v[i] = shin;
			shin++;
		}
	}
	
	int j=0;
	int q = 1;
	int temp = 0;
	if(k >= n) {
		for(int i=n-1; i>=0; i--) {
			temp++;
			j = j + i;
			if(j > k) {
				temp--;
				for(int i=0; i<temp; i++) {
					v[i] = lee;
					lee--;
				}
				int w = j-k;
		
				for(int i=temp; i<=temp + w; i++) {
					if(i == temp + w) {
						v[i] = lee;
					}
					else {
						v[i] = q;
						q++;	
					}
					
				}
				for(int i=temp+w+1; i<n; i++) {
					v[i] = q;
					q++;
				}
				break;
			}
			else if(j == k) {
				for(int i=0; i<temp; i++) {
					v[i] = lee;
					lee--;
				}
				for(int i=temp; i<n; i++) {
					v[i] = q;
					q++;
				}
				break;
			}
		}
		
	}
	
	for(int i=0; i<n; i++) {
		cout << v[i] << " ";
	}
	
	return 0;
}
