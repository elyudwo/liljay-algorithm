#include <string>
#include <vector>

using namespace std;

bool checkBingo(vector<string> board, char c) {
    // 가로열 체크
    for(int i=0; i<3; i++) {
        bool check = true;
        for(int j=0; j<3; j++) {
            if(board[i][j] != c) { check = false; }
        }
        if(check) { return true; }
    }
    
    // 세로열 체크
    for(int i=0; i<3; i++) {
        bool check = true;
        for(int j=0; j<3; j++) {
            if(board[j][i] != c) { check = false; }
        }
        if(check) { return true; }
    }
    
    // 대각선 체크
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c) { return true; }
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c) { return true; }
    
    return false;
}

bool checkFirstSecond(vector<string> board) {
    int o = 0;
    int x = 0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O') { o += 1; }
            else if(board[i][j] == 'X') { x += 1; }
        }
    }
    
    if(x > o || o >= x+2) { return true; }
    return false;
}

bool checkThird(vector<string> board) {
    int o = 0;
    int x = 0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O') { o += 1; }
            else if(board[i][j] == 'X') { x += 1; }
        }
    }
    
    if(checkBingo(board,'O') && o == x) { return true; }
    return false;
}

bool checkFourth(vector<string> board) {
    int o = 0;
    int x = 0;
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 'O') { o += 1; }
            else if(board[i][j] == 'X') { x += 1; }
        }
    }
    
    if(checkBingo(board,'X') && o > x) { return true; }
    return false;
}

int solution(vector<string> board) {
    int answer = -1;
    
    // 많은조건 분기 문제
    /*
    1. X의 개수가 O의 개수보다 많을 때
    2. O의 개수가 X의 개수보다 2개 이상 많을때
    3. O가 빙고상태인데 O의 개수와 X의 개수가 같을때
    4. X가 빙고상태인데 O의 개수가 X의 개수보다 많을때    
    */
    
    if(checkFirstSecond(board) || checkThird(board) || checkFourth(board) ) {
        answer = 0;
    }
    else {
        answer = 1;
    }
    
    
    return answer;
}