#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string answer = "";

struct Node {
    int prev = -1;
    int next = -1;
    int value = -1;
};

Node node[1000001];
stack<Node> stk;

void init(int n) {
    node[0].value = 0;
    node[0].next = 1;
    answer += 'O';
    for(int i=1; i<n-1; i++) {
        node[i].value = i;
        node[i].prev = i - 1;
        node[i].next = i + 1;
        answer += 'O';
    }
    node[n-1].value = n-1;
    node[n-1].prev = n-2;
    answer += 'O';
}

string solution(int n, int k, vector<string> cmd) {
    init(n);
    
    for(string c : cmd) {
        if(c[0] == 'U') {
            int cnt = stoi(c.substr(2));
            while(cnt--) {
                k = node[k].prev;
            }
        }
        if(c[0] == 'D') {
            int cnt = stoi(c.substr(2));
            while(cnt--) {
                k = node[k].next;
            }
        }
        if(c[0] == 'C') {
            int pr = node[k].prev;
            int ne = node[k].next;
            
            stk.push({node[k]});
            
            if(pr != -1) { node[pr].next = ne; }
            if(ne != -1) { node[ne].prev = pr; }
            
            if(ne != -1) {
                k = ne;
                continue;
            }
            k = pr;
        }
        if(c[0] == 'Z') {
            Node n = stk.top();
            stk.pop();
            int pr = n.prev;
            int ne = n.next;
            
            if(pr != -1) {
                node[pr].next = n.value;
            }
            if(ne != -1) {
                node[ne].prev = n.value;
            }
        }
    }

    while(!stk.empty()) {
        Node n = stk.top();
        stk.pop();
        int value = n.value;
        
        answer[value] = 'X';
    }
    
    return answer;
}