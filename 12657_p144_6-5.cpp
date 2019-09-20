#include <iostream>
using namespace std;

int n, m;
const int MAX = 100000+5;
int lef[MAX], righ[MAX];

void link(int X, int Y) {
	righ[X] = Y;
	lef[Y] = X;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int kase = 0;
	while(cin >> n >> m) {
		bool inv = false;
		kase++;
		for(int i = 1; i <= n; i++) {
			lef[i] = i-1;
			righ[i] = (i+1) % (n+1);
		}
		lef[0] = n;
		righ[0] = 1;
		
		for(int i = 0; i < m; i++) {
			int op;
			cin >> op;
			if(op == 4) {
				inv = !inv;
				continue;
			}
			int X, Y;
			cin >> X >> Y;
			if(op != 3 && inv) 
				op = 3 - op;
			if(op == 1 && lef[Y] == X)
				continue;
			if(op == 2 && righ[Y] == X)
				continue;
			
			int LX = lef[X], RX = righ[X], LY = lef[Y], RY = righ[Y];
			if(op == 1) {
				link(LX, RX); link(LY, X); link(X, Y);
			} else if(op == 2) {
				link(LX, RX); link(Y, X); link(X, RY);
			} else if(op == 3) {
				if(LY == X ){
					link(LX, Y); link(Y, X); link(X, RY);
				} else if(RY == X) {
					link(LY, X); link(X, Y); link(Y, RX);
				} else {
					link(LX, Y); link(Y, RX); link(LY, X); link(X, RY);
				}
			}
		}
		
		long long sum = 0;
		int b = righ[0];
		for(int i = 1; i <= n; i++) {
			if(i % 2 == 1)
				sum += b;
			b = righ[b];
		}
		if(inv && n % 2 == 0) {
			sum = (1+(long long)n)*n/2 - sum;
		}
		cout << "Case " << kase << ": " << sum << endl;
	}

	return 0;
}
