#include <bits/stdc++.h>
using namespace std;

char s[80], last, el;
int cnt[4], i;
void doit(int cnti) {
	el = s[i];
	switch(last) {
		case 'C':
			cnt[0]++;
			break;
		case 'H':
			cnt[1]++;
			break;
		case 'O':
			cnt[2]++;
			break;
		case 'N':
			cnt[3]++;
			break;
	}
	int x, inc;
	if(sscanf(s + i + 1, "%d%n", &x, &inc) == 1) {
		cnt[cnti] += x;
		i += inc;
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int T;
	scanf("%d", &T);
	while(T--){
		for(int i = 0; i < 4; i++)
			cnt[i] = 0;
		scanf("%s", s);
		last = 0;
		el = 0;
		for(i = 0; i < strlen(s); i++) {
			//printf("\n[%c]\n", s[i]);
			switch(s[i]) {
				case 'C':
					doit(0);
					break;
				case 'H':
					doit(1);
					break;
				case 'O':
					doit(2);
					break;
				case 'N':
					doit(3);
					break;				
			}
			last = s[i];
		}
		
		switch(last) {
			case 'C':
				cnt[0]++;
				break;
			case 'H':
				cnt[1]++;
				break;
			case 'O':
				cnt[2]++;
				break;
			case 'N':
				cnt[3]++;
				break;
		}
		
		printf("%.3f\n", cnt[0]*12.01f + cnt[1]*1.008f + cnt[2]*16.00f + cnt[3]*14.01);
	} 

	return 0;
}
