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

int m, n;
const int maxn = 100+5;
char b[maxn][maxn];
int cnt;

void dfs(int i, int j) {
	if(i < 0 || i >= m || j < 0 || j >= n)
		return;
	switch(b[i][j]) {
		case '@':{
			b[i][j] = ' ';
			dfs(i-1, j-1);
			dfs(i-1, j);
			dfs(i-1, j+1);
			dfs(i, j-1);
			dfs(i, j+1);
			dfs(i+1, j-1);
			dfs(i+1, j);
			dfs(i+1, j+1);
			break;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	while(cin >> m >> n && m && n) {
		cnt = 0;
//		cout << m << n;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		
//		for(int i = 0; i < m; i++) {
//			for(int j = 0; j < n; j++) {
//				cout << b[i][j];
//			}
//			cout << endl;
//		}

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(b[i][j] == '@') {
					cnt++;
//					cout << i << ", " << j << endl;
					dfs(i, j);
				}
			}
		}
//		cout << endl;
		cout << cnt << endl;
	}

	return 0;
}
