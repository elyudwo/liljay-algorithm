#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    int size = queries.size();
    long long row_start = x, row_end = x;
    long long col_start = y, col_end = y;
    for(int i=size - 1; i >= 0; i--) {
        int dir = queries[i][0];
        int dist = queries[i][1];
        
        if(dir == 0) { // 열 다시 증가시킴
            if(col_start != 0) 
                col_start = col_start + dist;
            
            col_end = col_end + dist;
            if(col_end > m - 1) 
                col_end = m - 1; 
            
        } else if(dir == 1){ // 열 다시 감소시킴
            col_start = col_start - dist;    
            if(col_start < 0) 
                col_start = 0;
            
            if(col_end != m - 1) 
                col_end = col_end - dist;
            
        } else if(dir == 2) { // 행 다시 증가시킴
            if(row_start != 0) 
                row_start = row_start + dist;
            
            row_end = row_end + dist;
            if(row_end > n - 1) 
                row_end = n - 1;
            
        } else if(dir == 3) { // 행 다시 감소시킴
            row_start = row_start - dist;    
            if(row_start < 0) 
                row_start = 0;
            
            if(row_end != n - 1) 
                row_end = row_end - dist;
            
        }
        if(row_start > n - 1 || row_end < 0 || col_start > m - 1 || col_end < 0) 
            return answer;
    }
    answer = (row_end - row_start + 1) * (col_end - col_start + 1);
    
    return answer;
}