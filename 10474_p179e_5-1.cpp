#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	int N, Q;
	int caseId = 0;
	while(scanf("%d%d", &N, &Q) && N) {
		printf("CASE# %d:\n", ++caseId);
		vector<int> v;
		for(int i = 0; i < N; i++) {
			int t;
			scanf("%d", &t);
			v.push_back(t);
		}
		
		sort(v.begin(), v.end());
		for(int i = 0; i < Q; i++) {
			int t;
			scanf("%d", &t);
			vector<int>::iterator it = std::find(v.begin(), v.end(), t);
			if(it == v.end())
				printf("%d not found", t);
			else
				printf("%d found at %d", t, it - v.begin() + 1);
			putchar('\n');
		}
	}

	return 0;
}
