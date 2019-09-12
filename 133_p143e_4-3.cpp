#include <bits/stdc++.h>
using namespace std;

bool P[24];
int N, k, m, rem;

int pick(int p, int d, int x) {
	while(x--) {
		do{
			p = (p + d + N - 1) % N + 1;
		} while(!P[p]);
	}
	return p;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	while(scanf("%d%d%d", &N, &k, &m) == 3 && N) {
		rem = N;
		for(int i = 1; i <= N; i++) {
			P[i] = true;
		}
		int pk = N, pm = 1;
		while(rem) {
			pk = pick(pk, 1, k);
			pm = pick(pm, -1, m);
			printf("%3d", pk);
			rem--;
			if(pk != pm) {
				printf("%3d", pm);
				rem--;
			}
			P[pk] = P[pm] = false;
			if(rem) {
				printf(",");
			}
		}
		printf("\n");
	}

	return 0;
}
