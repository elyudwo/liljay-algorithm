#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x,y,h,w;
    
    h = park.size();
    w = park[0].size();
    
    for(int i=0; i<park.size(); i++) {
        for(int j=0; j<park[i].size(); j++) {
            if(park[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    
    for(string str : routes) {
        int cnt = str[2] - '0';
        int dx,dy;
        bool check = false;
        
        if(str[0] == 'E') {
            dx = x;
            dy = y + cnt;
        }
        else if(str[0] == 'W') {
            dx = x;
            dy = y - cnt;
        }
        else if(str[0] == 'N') {
            dx = x - cnt;
            dy = y;
        }
        else if(str[0] == 'S') {
            dx = x + cnt;
            dy = y;
        }
        if(dx < 0 || dy < 0 || dx >= h || dy >= w || park[dx][dy] == 'X') { continue; }
        if(x != dx) {
            if(x > dx) {
                for(int i=dx; i<=x; i++) {
                    if(park[i][dy] == 'X') {
                        check = true;
                    }
                }
            }
            else {
                for(int i=x; i<=dx; i++) {
                    if(park[i][dy] == 'X') {
                        check = true;
                    }
                }
            }
        }
        else if(y != dy) {
            if(y > dy) {
                for(int i=dy; i<=y; i++) {
                    if(park[dx][i] == 'X') {
                        check = true;
                    }
                }
            }
            else {
                for(int i=y; i<=dy; i++) {
                    if(park[dx][i] == 'X') {
                        check = true;
                    }
                }
            }
        }
        if(check) {
            continue;
        }
        x = dx;
        y = dy;
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    
    return answer;
}