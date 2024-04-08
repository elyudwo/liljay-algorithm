#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
1. 키 돌리기
2. 돌린 키에서 확인
3. 
*/
int k, l;

void rotateKey(vector<vector<int>> & key) {
    vector<vector<int>> rem;
    
    for(int i=0; i<key.size(); i++) {
        vector<int> vec;
        for(int j=key.size()-1; j>=0; j--) {
            vec.push_back(key[j][i]);
        }
        rem.push_back(vec);
    }
    
    key = rem;
}

void printKey(vector<vector<int>> key) {
    cout << '\n';
    for(int i=0; i<key.size(); i++) {
        for(int j=0; j<key.size(); j++) {
            cout << key[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

bool possible(vector<vector<int>> board, vector<vector<int>> key, vector<vector<int>> lock, int x, int y) {
    bool result = true;
    // 움직이기
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            board[i+x][j+y] += key[i][j];
        }
    }
    
    // 체크
    for(int i=0; i<l; i++) {
        for(int j=0; j<l; j++) {
            if(board[i+k-1][j+k-1] != 1) {
                result = false;
                break;
            }
        }
    }
    
    // 복원
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            board[i+x][j+y] -= key[i][j];
        }
    }
    
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    k = key.size();
    l = lock.size();
    
    int s = 2 * (key.size() - 1) + lock.size();
    vector<vector<int>> board(s, vector<int>(s, 0));
    
    for(int i=0; i<l; i++) {
        for(int j=0; j<l; j++) {
            board[i+k-1][j+k-1] = lock[i][j];
        }
    }
    
    for(int i=0; i<4; i++) {
        rotateKey(key);
        
        for(int j=0; j<=s-k; j++) {
            for(int q=0; q<=s-k; q++) {
                if(possible(board, key, lock, j, q)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}