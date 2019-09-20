#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int test(bool &eq) {
	int wl, dl, wr, dr;
	cin >> wl >> dl >> wr >> dr;
	if(wl == 0) {
		wl = test(eq);
	}
	if(wr == 0) {
		wr = test(eq);
	}
	if(wl * dl != wr * dr) {
		eq = false;
	}
	return wl + wr;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int T;
	cin >> T;
	bool eq;
	int kase = 0;
	while(T--) {
		if(kase == 0) {
			kase = 1;
		} else {
			cout << endl;
		}
		eq = true;
		test(eq);
		if(eq) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
