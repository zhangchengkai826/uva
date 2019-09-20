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

bool isp[50];
int A[50], vis[50], n;

bool isprime(int x) {
	for(int i = 2; i*i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

void dfs(int cur) {
	if(cur == n-1 && isp[A[n-1]+1]) {
		for(int i = 0; i < n; i++) {
			if(i) {
				printf(" ");
			}
			printf("%d", A[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 2; i <= n; i++) {
		if(!vis[i] && isp[A[cur]+i]) {
			A[cur+1] = i;
			vis[i] = true;
			dfs(cur+1);
			vis[i] = false;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	for(int i = 2; i < 50; i++) {
		isp[i] = isprime(i);
	}
	int kase = 0;
	while(scanf("%d", &n) == 1) {
		if(kase++) {
			printf("\n");
		}
		printf("Case %d:\n", kase);
		memset(vis, 0, sizeof(vis));
		A[0] = 1;
		dfs(0);
	}
	

	return 0;
}
