#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxn = 100+5;
int G[maxn][maxn];
bool visit[maxn];

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int m, n;
	int min;
	while(cin >> n >> m && n && m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				G[i][j] = 0;
			}
		}
		
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;	
			G[a-1][b-1] = 1;
		}
		
//		for(int i = 0; i < n; i++) {
//			for(int j = 0; j < n; j++) {
//				cout << G[i][j];
//			}
//			cout << endl;
//		}
		
		vector<int> ans;
		bool possible;
		for(int i = 0; i < n; i++) {
			visit[i] = false;
		}
		while(ans.size() != n) {
			int i;
			possible = false;
			for(i = 0; i < n; i++) {
				if(visit[i]) {
					continue;
				}
				bool find = true;
				for(int j = 0; j < n; j++) {
//					cout << "G[" << j << "][" << i << "] = " << G[j][i] << endl;
					if(G[j][i]) {
						find = false;
						break;
					}
				}
				if(find) {
					possible = true;
					break;
				}
			}
			
			if(!possible) {
				break;
			} else {
				ans.push_back(i);
//				cout << "ans.push_back(" << i << ")" << endl;
				visit[i] = true;
				for(int j = 0; j < n; j++) {
					G[i][j] = 0;
				}
			}
		}
		
		if(!possible) {
			cout << "No" << endl;
		} else {
			for(int i = 0; i < n; i++) {
				if(i != 0) {
					cout << " ";
				}
				cout << ans[i]+1;
			}
			cout << endl;
		}
	}
	
	return 0;
}
