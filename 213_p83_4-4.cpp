#include <bits/stdc++.h>
using namespace std;

#define MAX_N 512
char keys[MAX_N];

int lok;

void ate() {
	char c;
	
	while(true) {
		lok = 0;
		int exp[] = {4, 2, 1};
		for(int i = 0; i < 3; i++) {
			c = getchar();
			if(c == '\n') {
				i--;
			} else {
				switch(c) {
					case '0':
						break;
					case '1': {
						lok += exp[i];
						break;
					}
				}
			}
		}
		//printf("(%d)", lok);
		
		if(!lok)
			break;
		
		while(true) {
			int exp2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
			int base[] = {0, 1, 4, 11, 26, 57, 120, 247};
			int sum = 0;
			for(int i = 0; i < lok; i++) {
				c = getchar();
				if(c == '\n') {
					i--;
				} else {
					switch(c) {
						case '0':
							break;
						case '1': {
							sum += exp2[lok-i-1];
							break;
						}
					}
				}
			}
			//printf("(%d)", sum);
			if(sum == exp2[lok] - 1) {
				break;
			} else {
				putchar(keys[base[lok-1] + sum]);
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	while(cin.getline(keys, MAX_N)) {
		if(!strlen(keys))
			continue;
		ate();
		putchar('\n');
	}

	return 0;
}
