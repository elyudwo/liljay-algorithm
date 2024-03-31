#include <string>
#include <vector>

using namespace std;

long long arr1[500002];
long long arr2[500002];

void init(vector<int> sequence) {
    int a = 1;
    int b = -1;
    for(int i=0; i<sequence.size(); i++) {
        arr1[i] = sequence[i] * a;
        arr2[i] = sequence[i] * b;
        a = a * -1;
        b = b * -1;
    }
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    init(sequence);
    
    long long tmp = 0;
    for(int i=0; i<sequence.size(); i++) {
        if(tmp + arr1[i] <= 0) { tmp = 0; continue; }
        tmp += arr1[i];
        answer = max(answer, tmp);
    }
    
    tmp = 0;
    for(int i=0; i<sequence.size(); i++) {
        if(tmp + arr2[i] <= 0) { tmp = 0; continue; }
        tmp += arr2[i];
        answer = max(answer, tmp);
    }
    
    return answer;
}