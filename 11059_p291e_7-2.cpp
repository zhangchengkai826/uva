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

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int n;
	vector<int> v;
	int kase = 0;
	while(scanf("%d", &n) == 1) {
		if(n > v.size()) {
			v.resize(n);
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		
		long long maxPd = 0;
		for(int i = 0; i < n; i++) {
			long long pd = 1;
			for(int j = i; j < n; j++) {
				pd *= v[j];
				maxPd = max(maxPd, pd);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++kase, maxPd);
	}

	return 0;
}
