#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int T;
	scanf("%d", &T);
	while(T--){
		char s[80];
		scanf("%s", s);
		int score = 0;
		int accu = 0;
		for(int i = 0; i < strlen(s); i++) {
			switch(s[i]) {
				case 'O':
					accu++;
					score += accu;
					break;
				case 'X':
					accu = 0;
					break;
			}
		}
		printf("%d\n", score);
	} 

	return 0;
}
