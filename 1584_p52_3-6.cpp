#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int T;
	scanf("%d", &T);
	while(T--) {
		char s[100];
		scanf("%s", s);
		
		int len = strlen(s);
		int min = 0;
		for(int p = 1; p < len; p++) {
			for(int i = 0; i < len; i++) {
				char ref = s[(min + i) % len];
				char c = s[(p + i) % len];
				if(ref > c) {
					min = p;
					break;
				} else if(ref < c) {
					break;
				}
			} 
		}
		for(int i = 0; i < len; i++) {
			printf("%c", s[(min + i) % len]);
		}
		printf("\n");
	} 

	return 0;
}
