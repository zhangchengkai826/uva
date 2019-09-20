#include <iostream>
using namespace std;

long long exp[20];

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int n;
	cin >> n;
	long long t = 1;
	for(int i = 0; i < 20; i++) {
		exp[i] = t;
		t *= 2;
	}
//	for(int i = 0; i < 20; i++) {
//		cout << "( " << exp[i] << endl;
//	}
	while(n--) {
		int D, I;
		cin >> D >> I;
//		cout << D << I << endl;
		
		int id = exp[D-1] - 1;
		while(D--) {
			if(I % 2 == 0) {
				id += exp[D-1];
			}
			I = (I+1) / 2;
		}
		cout << id+1 << endl;
	}

	return 0;
}
