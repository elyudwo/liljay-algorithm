#include <string>
#include <vector>

using namespace std;

bool check[100001];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for(int i=0; i<section.size(); i++) {
        check[section[i]] = true;
    }
    
    for(int i=1; i<=n; i++) {
        if(check[i]) {
            for(int j=i; j<i+m; j++) {
                if(j > n) {
                    continue;
                }
                check[j] = false;
            }
            answer += 1;
        }
    }
    
    return answer;
}