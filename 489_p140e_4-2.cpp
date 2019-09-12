#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
char s[MAX_N], g[MAX_N];

int chance, leftg;
bool win, lose;

void guess(char c) {
	bool bad = true;
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == c) {
			bad = false;
			leftg--;
			s[i] = ' ';
		} 
	}
	if(bad)
		chance--;
	if(chance <= 0) {
		lose = true;
		return;
	}
		
	if(leftg <= 0) {
		win = true;
		return;
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	int rid;
	while(scanf("%d%s%s", &rid, s, g) == 3 && rid != -1) {
		leftg = strlen(s);
		chance = 7;
		win = false;
		lose = false;
		
		for(int i = 0; i < strlen(g); i++) {
			guess(g[i]);
			if(win || lose) {
				break;
			}
		} 
		
		printf("Round %d\n", rid);
		if(lose) {
			printf("You lose.\n");
		} else if(win) {
			printf("You win.\n");
		} else {
			printf("You chickened out.\n");
		}
		
		/*bool sb[26] = {0};
		for(int i = 0; i < strlen(s); i++) {
			sb[s[i] - 'a'] = true;
		}
		
		scanf("%s", g);
		int life = 7;
		for(int i = 0; i < strlen(g); i++) {
			if(!sb[g[i] - 'a']) {
				life--;
			} else {
				sb[g[i] - 'a'] = false;
			}
			
			if(!life) {
				break;
			}
		}
		
		printf("Round %d\n", rid);
		if(!life) {
			printf("You lose.\n");
		} else {
			sort(sb, sb+26, greater<bool>());
			if(sb[0]) {
				printf("You chickened out.\n");
			} else {
				printf("You win.\n");
			}
		} */
	}

	return 0;
}
