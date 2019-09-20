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

struct Edge{
	int u, v, c;
	Edge(int u, int v, int c):u(u), v(v), c(c) {}
};
const int maxn = 100000+5;
vector<int> G[maxn];
vector<Edge> edges;
bool vis[maxn];
int d[maxn];
vector<int> ans;

void addEdge(int u, int v, int c) {
	edges.push_back(Edge(u, v, c));
	G[u].push_back(edges.size()-1);
}

void rev_bfs(int term) {
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	
	q.push(term);
	vis[term] = true;
	d[term] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		vector<int> &vec = G[u];
		for(int i = 0; i < vec.size(); i++) {
			int v = edges[vec[i]].v;
			if(!vis[v]) {
				vis[v] = true;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

void bfs() {
	ans.clear();
	memset(vis, 0, sizeof(vis));

	vector<int> us;
	us.push_back(0);
	vis[0] = true;
	for(int i = 0; i < d[0]; i++) {
		vector<int> next;
		int min_c = -1;
		
		for(int k = 0; k < us.size(); k++) {
			int &u = us[k];
			for(int j = 0; j < G[u].size(); j++) {
				Edge &e = edges[G[u][j]];
				if(d[u] - d[e.v] == 1 && (min_c == -1 || e.c < min_c)) {
					min_c = e.c;
				}
			}
		}
		ans.push_back(min_c);
		
		for(int k = 0; k < us.size(); k++) {
			int &u = us[k];
			for(int j = 0; j < G[u].size(); j++) {
				Edge &e = edges[G[u][j]];
				if(d[u] - d[e.v] == 1 && !vis[e.v] && e.c == min_c) {
					next.push_back(e.v);
					vis[e.v] = true;
				}
			}
		}
//		printf("[1]Phase %d:", i);
//		for(int j = 0; j < us.size(); j++) {
//			printf(" %d", us[j]);
//		} 
//		printf("\n");
		us = next;
//		printf("[2]Phase %d:", i);
//		for(int j = 0; j < us.size(); j++) {
//			printf(" %d", us[j]);
//		} 
//		printf("\n");
		
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	 int n, m;
	 while(scanf("%d%d", &n, &m) == 2) {
	 	for(int i = 0; i < n; i++) {
	 		G[i].clear();
		}
		edges.clear();
	 	while(m--) {
	 		int u, v, c;
	 		scanf("%d%d%d", &u, &v, &c);
	 		addEdge(u-1, v-1, c);
	 		addEdge(v-1, u-1, c);
		}
		
		rev_bfs(n-1);
//		for(int i = 0; i < n; i++) {
//			cout << d[i] << endl;
//		}
		bfs();
		printf("%d\n", ans.size());
		printf("%d", ans[0]);
		for(int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	 }

	return 0;
}
