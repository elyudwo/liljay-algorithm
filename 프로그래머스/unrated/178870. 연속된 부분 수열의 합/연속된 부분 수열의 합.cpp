#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left = 0;
    int right = 0;
    int sum = sequence[0];
    int minus = 1000000000;
    
    while(1) {
        if(sum == k) {
            if(right - left < minus) {
                answer.clear();
                answer.push_back(left); 
                answer.push_back(right);
                minus = right - left;
            }
            sum = sum - sequence[left];
            left += 1;
            
            
            continue;
        }

        if(sum < k) {
            if(right == sequence.size()-1) { break; }
            right += 1;
            sum = sum + sequence[right];
        }
        else if(sum > k) {
            sum = sum - sequence[left];
            left += 1;
        }
    }
    
    
    return answer;
}