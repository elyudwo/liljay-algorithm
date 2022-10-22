#include <iostream>

using namespace std;

int n,m;
int count=0;


int main() {
    cin >> n >> m;

    int a[n+1];

    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    for(int i=0;i<n;i++) {
    	int result = 0;
        for(int j=i;j<n;j++) {
            result += a[j];

            if(result==m) {
                count++;
                cout << i << " " << j << endl;
                result==0;
                break;
            }
        }
        if(result!=0) result=0;
    }   

    cout<< count;
}
