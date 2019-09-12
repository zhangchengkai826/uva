#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	char s1[100], s2[100];
	while(scanf("%s%s", s1, s2) == 2) {
		int len = strlen(s1);
		int s1c[26] = {0}, s2c[26] = {0};
		for(int i = 0; i < len; i++) {
			s1c[s1[i] - 'A']++;
			s2c[s2[i] - 'A']++;
		}
		sort(s1c, s1c + 26);
		sort(s2c, s2c + 26);
		bool bCanEncr = true;
		//printf("\n[");
		for(int i = 0; i < 26; i++) {
			//printf("(%d, %d), ", s1c[i], s2c[i]);
			if(s1c[i] != s2c[i]) {
				bCanEncr = false;
				break;
			}
		}
		//printf("]\n");
		if(bCanEncr) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
