#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	char c;
	bool seekRight = false;
	while((c = getchar()) != EOF) {
		if(c == '\"'){
			if(!seekRight) {
				cout << "``";
			} else {
				cout << "''";
			}
			seekRight = !seekRight;
		} else {
			cout << c;
		}
	}

	return 0;
}
