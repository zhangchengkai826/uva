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
	char buf[99];
	int kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		if(!kase) {
			kase = 1;
		} else {
			printf("\n");
		}
		int cnt = 0;
		for(int fghij = 1234; ; fghij++) {
			int abcde = fghij * n;
			ostringstream oss;
			sprintf(buf, "%05d%05d", abcde, fghij);
			if(strlen(buf) > 10) {
				break;
			}
			sort(buf, buf+10);
			bool ok = true;
			for(int i = 0; i < 10; i++) {
				if(buf[i] - '0' != i) {
					ok = false;
					break;
				}
			}
			if(ok) {
				cnt++;
				printf("%05d / %05d = %d\n", abcde, fghij, n);
			}
		}
		if(!cnt) {
			printf("There are no solutions for %d.\n", n);
		}
	}

	return 0;
}
