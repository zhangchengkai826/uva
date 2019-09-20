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

	int k;
	while(scanf("%d", &k) == 1) {
		vector<int> X, Y;
		for(int y = k+1; y <= k*2; y++) {
			if((k*y)%(y-k) == 0) {
				X.push_back((k*y)/(y-k));
				Y.push_back(y);
			}
		}
		printf("%d\n", X.size());
		for(int i = 0; i < X.size(); i++) {
			printf("1/%d = 1/%d + 1/%d\n", k, X[i], Y[i]);
		}
	}

	return 0;
}
