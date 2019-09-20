#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;

char g[52][52];
char vis[52];

int ID(char x1, char x2) {
	return (x1-'A') * 2 + ((x2 == '+') ? 0 : 1);
}

void connect(char a1, char a2, char b1, char b2) {
	if(a1 == '0' || b1 == '0') return;
	int v = ID(b1, b2);
	int u = ID(a1, a2)^1;
	g[u][v] = 1;
}

bool dfs(int u) {
	vis[u] = -1;
	for(int v = 0; v < 52; v++) {
//		cout << u << ", " << v << endl;
		if(g[u][v]) {
			if(vis[v] == -1) {
				return false;
			}
			if(!vis[v]) {
				if(!dfs(v)) {
					return false;
				}
			}
		}
	}
	vis[u] = 1;
	// add to ans[--n] (topo sort)
	return true;
}

bool hasNoCycle() {
	for(int i = 0; i < 52; i++) {
		if(!vis[i]) {
			if(!dfs(i)) {
				return false;
			}	
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int n;
	while(cin >> n) {
		memset(g, 0, sizeof(g));
		memset(vis, 0, sizeof(vis));
		string s;
		while(n--) {
			cin >> s;
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					if(i != j) {
//						cout << s[i*2] << ", " << s[j*2] << endl;
						connect(s[i*2], s[i*2+1], s[j*2], s[j*2+1]);
					}
				}
			}
		}
		if(hasNoCycle()) {
			cout << "bounded" << endl;
		} else {
			cout << "unbounded" << endl;
		}
	}

	return 0;
}
