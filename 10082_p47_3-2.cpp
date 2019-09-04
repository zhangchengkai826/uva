#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	char ref[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while((c = getchar()) != EOF) {
		char *p = strchr(ref, c);
		if(p) {
			cout << *(p-1);
		} else {
			cout << c;
		}
	}

	return 0;
}
