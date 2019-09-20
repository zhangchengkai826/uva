#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;

void test() {
	vector<int> v;
	v.resize(N);
	
	while(true) {
		for(int i = 0; i < N; i++) {
			cin >> v[i];
			//cout << "v[i]: " << v[i] << endl;
			if(!v[i])
				return;
		}
		
		int base, minVal;
		for(int i = 0; i < N-1; i++) {
			base = minVal = v[i];
			for(int j = i+1; j < N; j++) {
				if(v[j] > base)
					continue;
				if(v[j] < minVal)
					minVal = v[j];
				else {
					cout << "No" << endl;
					goto next;
				}
			}
		}
		cout << "Yes" << endl;
		next:;
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	while(cin >> N && N) {
		//cout << "N: " << N; 
		test();
		cout << endl;
	}

	return 0;
}
