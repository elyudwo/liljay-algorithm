#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> vec;

int dx[] = {0,1,1};
int dy[] = {1,0,1};
bool zero_check[31][31];

int deleteZero(int m,int n) {
    int answer = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(zero_check[i][j]) {
                answer += 1;
                vec[i][j] = '0';
            }
            zero_check[i][j] = false;
        }
    }
    
    return answer;
}

int bomb(int m, int n) {
    bool c[31][31] = {false,};
    int result = 0;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(vec[i][j] == '0') continue;
            char ch = vec[i][j];
            bool check = true;

            for(int k=0; k<3; k++) {
                int nx = dx[k] + i;
                int ny = dy[k] + j;
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) { check = false; break; }
                if(vec[nx][ny] != ch) { check = false; }
            }
            
            if(check) {
                for(int k=0; k<3; k++) {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    zero_check[nx][ny] = true;
                }
                zero_check[i][j] = true;
            }
        }
    }
    
    return deleteZero(m,n);
}

void down(int m, int n) {
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>0; j--) {
            if(vec[j][i] == '0') {
                for(int k=j-1; k>=0; k--) {
                    if(vec[k][i] != '0') {
                        vec[j][i] = vec[k][i];
                        vec[k][i] = '0';
                        break;
                    }
                }
            }
        }
    }
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++) { vec.push_back(board[i]); }
    
    while(1) {
        int tmp = bomb(m,n);
        
        if(!tmp) { break; }
        answer += tmp;
        down(m,n);
    }
    
    
    return answer;
}