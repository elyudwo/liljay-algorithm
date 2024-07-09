#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

struct Trie {
	Trie* go[26];
	Trie *fail;
	bool output;
	
	Trie() {
		fill(go, go+26, nullptr);
		output = false;
	}
	~Trie() {
		for(int i=0; i<26; i++) {
			if(go[i]) delete go[i];
		}
	}

	void insert(const char* key) {
		if(*key == '\0') {
			output = true;
			return;
		}
		int next = *key - 'a';
		if(!go[next]) { go[next] = new Trie; }
		go[next]->insert(key+1);
	}
};

int main() {
	int n,m;
	char str[10001];
	
	Trie* root = new Trie;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> str;
		root->insert(str);
	}
	
	queue<Trie*> q;
	q.push(root);
	
	while(!q.empty()) {
		Trie *cur = q.front();
		q.pop();
		
		for(int i=0; i<26; i++) {
			Trie *next = cur->go[i];
			if(!next) continue;
			
			if(cur == root) {
				next->fail = root;
			}
			else {
				Trie *d = cur->fail;
				while(d != root && !d->go[i]) {
					d = d->fail;
				}
				if(d->go[i]) {
					d = d->go[i];
				}
				next->fail = d;
			}
			if(next->fail->output) {
				next->output = true;
			}
			
			q.push(next);
		}
	}
	
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> str;
		
		Trie* cur = root;
		bool result = false;
		for(int j=0; str[j]; j++) {
			int next = str[j] - 'a';
			
			while(cur != root && !cur->go[next]) {
				cur = cur->fail;
			}
			
			if(cur->go[next]) {
				cur = cur->go[next];
			}
			
			if(cur->output) {
				result = true;
				break;
			}
		}
		
		if(result) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
	
}