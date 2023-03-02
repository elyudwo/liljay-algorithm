#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    // west
    int a = 51;
    //east
    int b = -1;
    //north
    int c = 51;
    //south
    int d = -1;
    
    for(int i=0; i<wallpaper.size(); i++) {
        for(int j=0; j<wallpaper[i].size(); j++) {
            if(wallpaper[i][j] == '#') {
                a = min(a,j);
                b = max(b,j);
                c = min(c,i);
                d = max(d,i);
            }
        }
    }
    
    answer.push_back(c);
    answer.push_back(a);
    answer.push_back(d+1);
    answer.push_back(b+1);
    
    
    return answer;
}