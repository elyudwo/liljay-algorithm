#include <string>
#include <vector>

using namespace std;

bool can(long long mid, int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long gold = 0;
    long long silver = 0;
    long long all = 0;
    
    for(int i=0; i<t.size(); i++) {
        long long m = mid - t[i];
        long long gold_silver = w[i];
        long long g_tmp = w[i], s_tmp = w[i];
        if(m < 0) { continue; }
        
        g_tmp += w[i] * (m / (t[i] * 2));
        
        if(g_tmp > g[i]) { g_tmp = g[i]; }
        gold += g_tmp;
        
        s_tmp += w[i] * (m / (t[i] * 2));
        
        if(s_tmp > s[i]) { s_tmp = s[i]; }
        silver += s_tmp;
        
        gold_silver += w[i] * (m / (t[i] * 2));
        if(gold_silver > s[i] + g[i]) {
            gold_silver = s[i] + g[i];
        }
        
        all += gold_silver;
    }
    
    if(gold >= a && silver >= b && all >= (a + b)) {
        return true;
    } 
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    long long left = 0;
    long long right = 2e15;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        
        if(can(mid, a, b, g, s, w, t)) {
            answer = mid;
            right = mid - 1;
            continue;
        }
        left = mid + 1;
        
    }
    
    return answer;
}