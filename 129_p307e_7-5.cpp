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

int n, L;
char S[100];
int cnt;

bool dfs(int cur) {
	if(cnt == n) {
		for(int i = 0; i < cur; i++) {
			if(i != 0) {
				if(i%64 == 0) {
					printf("\n");
				} else if(i%4 == 0) {
					printf(" ");
				}
			}
			printf("%c", S[i]+'A');
		}
		printf("\n%d\n", cur);
		return true;
	}
	for(int i = 0; i < L; i++) {
		S[cur] = i;
		bool allDiffer = true;
		for(int j = 1; j <= (cur+1)/2; j++) {
			bool differ = false;
			for(int k = 0; k < j; k++) {
				if(S[cur-k] != S[cur-j-k]) {
					differ = true;
					break;
				}
			}
			if(!differ) {
				allDiffer = false;
				break;
			}
		}
		if(allDiffer) {
			cnt++;
			if(dfs(cur+1)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	while(scanf("%d%d", &n, &L) == 2 && n) {
		cnt = 0;
		dfs(0);
	}

	return 0;
}
