#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

set<int> st;
bool check[1001];

struct card_pair {
    int first;
    int second;
    int price;
};

bool cmp(card_pair a, card_pair b) {
    return a.price < b.price;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size() + 1;
    
    for(int i=0; i<cards.size()/3; i++) {
        st.insert(cards[i]);
        check[cards[i]] = true; 
    }
    
    int money = coin;
    int idx = cards.size()/3;
    
    while(idx <= cards.size()) {
        answer++;
        st.insert(cards[idx++]);
        st.insert(cards[idx++]);
        bool next = false;
        vector<card_pair> vec;
            
        for(auto i : st) {
            if(st.count(n - i)) {
                int tmp = money;
                if(!check[i]) { tmp--;}
                if(!check[n-i]) { tmp--; }
                if(tmp >= 0) {
                    // cout << i << " " << n - i << endl;
                    next = true;
                    vec.push_back({i, n-i, money - tmp});
                    
                    // money = tmp;
                    // st.erase(i);
                    // st.erase(n-i);
                }
            }
        }
        if(!vec.empty()) {
            sort(vec.begin(), vec.end(), cmp);
            money -= vec[0].price;
            // cout << vec[0].first << " " << vec[0].second << " " << vec[0].price << endl;
            st.erase(vec[0].first);
            st.erase(vec[0].second);
        }
        
        if(!next) break;
    }
    
    
    return answer;
}