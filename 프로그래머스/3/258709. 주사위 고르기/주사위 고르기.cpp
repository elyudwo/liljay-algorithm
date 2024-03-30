#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dice_size = 0;
bool check[12];
int max_value = 0, tmp = 0;
vector<int> my_dice;
vector<int> other_dice;
vector<int> answer;
vector<int> vec;
vector<vector<int>> dice_;
int a[501];
int b[501];

void init(vector<vector<int>> dice) {
    dice_size = dice.size();
}

int hi = 0;

void dfs2(int sum, int cnt, char idx) {
    if(cnt == dice_size / 2) {
        if(idx == 'B') {
            b[sum]++;
            return;
        }
        hi += b[sum-1];
        
        return;
    }
    
    
    for(int i=0; i<6; i++) {
        if(idx == 'B') {
            dfs2(sum + dice_[other_dice[cnt]][i], cnt + 1, 'B');
            continue;
        }
        dfs2(sum + dice_[my_dice[cnt]][i], cnt + 1, 'A');
    }
}

void checkOtherDice() {
    for(int i=0; i<dice_size; i++) {
        // 내 주사위
        if(!check[i]) { other_dice.push_back(i); continue; }
        my_dice.push_back(i);
    }
    
    for(int i=0; i<=500; i++) {
        b[i] = 0;
        a[i] = 0;
    }
    
    // b 굴려
    dfs2(0, 0, 'B');
    for(int i=1; i<=500; i++) { b[i] += b[i-1]; }
    
    // a 굴려
    dfs2(0, 0, 'A');
}



void dfs(int cnt, int idx) {
    if(idx == dice_size) {
        if(cnt == dice_size / 2) {
            checkOtherDice(); 
            if(max_value < hi) {
                answer.clear();
                max_value = hi;
                for(int my_idx : my_dice) {
                    answer.push_back(my_idx + 1);
                }
            }
        }
        
        other_dice.clear();
        my_dice.clear();
        hi = 0;
        return;
    }
    
    check[idx] = true;
    dfs(cnt + 1, idx + 1);
    check[idx] = false;
    dfs(cnt, idx + 1);
}

vector<int> solution(vector<vector<int>> dice) {
    for(vector<int> d : dice) {
        dice_.push_back(d);
    }
    init(dice);
    dfs(0, 0);
    
    return answer;
}