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
#include <cmath>
#include <sstream>
using namespace std;

const int maxn = 1000 + 5;
char G[maxn][maxn];
bool vis[maxn];
int n;

struct Oppo{
	float x, y, r;
};
vector<Oppo> oppo;
vector<int> S, N;
float Ey, Wy;

float pow2(float x) {
	return x * x;
}

float dy(Oppo &o, float edge) {
	return sqrt(pow2(o.r)-pow2(o.x-edge));
}

void checkCircle(int u) {
	Oppo &o = oppo[u];
	if(o.r >= o.x) {
		Wy = min(Wy, o.y-dy(o, 0));
	}
	if(1000.f - o.x <= o.r) {
		Ey = min(Ey, o.y-dy(o, 1000));
	}
}

bool dfs(int u) {
	vis[u] = true;
	if(find(S.begin(), S.end(), u) != S.end()) {
		return true;
	}
	for(int v = 0; v < n; v++) {
		if(G[u][v] && !vis[v]) {
			if(dfs(v)) {
				return true;
			}
		}
	}
	checkCircle(u);
	return false;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	
	
	while(scanf("%d", &n) == 1) {
//		printf("%d", n);
//		break;
		oppo.resize(n);
		S.clear(); N.clear();
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; i++) {
			Oppo &oi = oppo[i];
			scanf("%f%f%f", &oi.x, &oi.y, &oi.r);
//			printf("%.2f, %.2f, %.2f\n", oi.x, oi.y, oi.r);
			if(oi.y <= oi.r) {
				S.push_back(i);
			}
			if(1000-oi.y <= oi.r) {
				N.push_back(i);
			}
			for(int j = 0; j < i-1; j++) {
				Oppo &oj = oppo[j];
				float dist2 = pow2(oi.x-oj.x) + pow2(oi.y-oj.y);
				if(dist2 <= pow2(oi.r+oj.r)) {
//					printf("%d, %d\n", i, j);
					G[i][j] = G[j][i] = 1;
				}
			}
		}
		
//		printf("N:");
//		for(int i = 0; i < N.size(); i++) {
//			printf(" %d", N[i]);
//		}
//		printf("\n");
//		printf("S:");
//		for(int i = 0; i < S.size(); i++) {
//			printf(" %d", S[i]);
//		}
//		printf("\n");
//		printf("W:");
//		for(int i = 0; i < W.size(); i++) {
//			printf(" %d", W[i]);
//		}
//		printf("\n");
//		printf("E:");
//		for(int i = 0; i < E.size(); i++) {
//			printf(" %d", E[i]);
//		}
//		printf("\n");

		bool impossible = false;
		memset(vis, 0, sizeof(vis));
		Wy = Ey = 1000.f;
		for(int i = 0; i < N.size(); i++) {
			if(!vis[N[i]]) {
				if(dfs(N[i])) {
					impossible = true;
					break;
				}
			}
		}
		
		if(impossible) {
			printf("IMPOSSIBLE\n");
		} else {
//			printf("POSSIBLE\n");
			printf("%.2f %.2f ", 0.f, Wy);
			printf("%.2f %.2f\n", 1000.f, Ey);
		}
	}

	return 0;
}
