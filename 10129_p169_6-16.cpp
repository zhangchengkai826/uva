#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

int G[26][26];
int vis[26];
int visCnt;
bool noedge;
set<int> vset;
int in[26], out[26];

void dfs(int u) {
	vis[u] = 1;
	visCnt++;
	for(int v = 0; v < 26; v++) {
		if(G[u][v] || G[v][u]) {
			noedge = false;
			if(!vis[v]) {
				dfs(v); 
			}
		}
	}
}

bool isCont() {
//	cout << "Is G cont?" << endl;; 
	for(int i = 0; i < 26; i++) {
		if(find(vset.begin(), vset.end(), i) == vset.end()) {
			continue;
		}
		dfs(i);
//		cout << "(visCnt=" << visCnt << endl;
		if(noedge) {
			continue;
		} else if(visCnt == vset.size()) {
//			cout << "YES" << endl;
			return true;
		} else {
//			cout << "NO" << endl;
			return false;
		}
	}
//	cout << "YES" << endl;
	return true;
}

bool degCheck() {
	int igo1 = 0;
	int ogi1 = 0;
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			if(G[i][j]) {
				out[i] += G[i][j];
				in[j] += G[i][j];
			}
		}
	}
	
//	for(int i = 0; i < 26; i++) {
//		cout << "[" << in[i] << ", " << out[i] << endl;
//	}
	
	for(int i = 0; i < 26; i++) {
		int igo = in[i] - out[i];
		if(igo > 1 || igo < -1) {
			return false;
		} else if(igo == 1) {
			igo1++;
		} else if(igo == -1) {
			ogi1++;
		}
		
		if(igo1 > 1 || ogi1 > 1) {
			return false;
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	
	
	int T;
	cin >> T;
	while(T--) {
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		visCnt = 0;
		vset.clear();
		noedge = true;
		
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			G[s[0]-'a'][s[s.length()-1]-'a']++;
			vset.insert(s[0]-'a');
			vset.insert(s[s.length()-1]-'a');
		}
//		cout << "(v=" << vset.size() << endl; 
		
//		for(int i = 0; i < 26; i++) {
//			for(int j = 0; j < 26; j++) {
//				if(G[i][j]) {
//					cout << "(" << i << ", " << j << ", " << G[i][j] << endl;
//				}
//			}
//		}
		
		if(isCont() && degCheck()) {
			cout << "Ordering is possible." << endl;
		} else {
			cout << "The door cannot be opened." << endl;
		}
		
//		cout << endl;
	} 

	return 0;
}
