#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif	
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int t;
		scanf("%d", &t);
		for(int i = t - 45; i < t; i++) {
			int num = i;
			for(int j = i; j != 0; j/=10) {
				num += j%10; 
			}
			if(num == t) {
				printf("%d\n", i);
				break;
			} else {
				if(i == t-1)
					printf("0\n");
			}
		}
	}

	return 0;
}
