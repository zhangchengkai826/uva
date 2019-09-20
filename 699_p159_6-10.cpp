#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

void traverse(int root, int cur, int &max, int &min, map<int, int> &m) {
	if(cur < min) {
		min = cur;
	}
	if(cur > max) {
		max = cur;
	}
	
	m[cur] += root;
	
//	cout << "m[" << cur << "] += " << root << endl;
	
	int left;
	cin >> left;
	if(left != -1) {
		traverse(left, cur-1, max, min, m);
	}
	
	int right;
	cin >> right;
	if(right != -1) {
		traverse(right, cur+1, max, min, m);
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	int kase = 0;
	int root;
	while(cin >> root && root != -1) {
		map<int, int> m;
		int min, max;
		min = max = 0;
		
		cout << "Case " << ++kase << ":" << endl;
		
		traverse(root, 0, max, min, m);
		
		for(int i = min; i <= max; i++) {
			if(i != min) {
				cout << " ";
			}
			cout << m[i];
		}
		cout << endl << endl;
	}

	return 0;
}
