#include <string>
#include <vector>
#include <deque>

using namespace std;

struct s {
    int sum;
    int left;
    int right;
};

int solution(vector<vector<int>> scores) {
    int answer = 1;
    // 완호보다 점수가 높은데 한쪽은 작은 것들 중 인센티브를 받지 못하는 사람을 구하는게 관건
    // 반복문 한번을 이용해야한다.
    
    deque<pair<int,int>> dq;
    int ho_sum = scores[0][0] + scores[0][1];
    
    for(int i=1; i<scores.size(); i++) {
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) {
            answer = -1;
            break;
        }
        
        int left = scores[i][0];
        int right = scores[i][1];
        int sum = left + right;
        
        if(sum > ho_sum) {
            deque<pair<int,int>> dq_tmp;
            bool check = false;
            
            for(int j=0; j<dq.size(); j++) {
                if(left < dq[j].first && right < dq[j].second) {
                    check = true;
                    break;
                }
            }
            
            if(!check) {
                answer += 1;
                for(int j=0; j<dq.size(); j++) {
                    if(left > dq[j].first && right > dq[j].second) {
                        answer -= 1;
                    }
                    else {
                        dq_tmp.push_back({dq[j].first, dq[j].second});
                    }
                }
                dq.clear();
                dq = dq_tmp;
                dq.push_back({left,right});
            }
        }
    }
    
    return answer;
}