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

struct Node {
	int nbc;
	int nc;
	char t;
	int d;
};

int exp[10];

void traverse(vector<Node> &g, string &s, int i, int &parentNbc, int &parentNc, int parentDepth) {
	g[i].t = s[i];
	g[i].nbc = g[i].nc = 0;
	g[i].d = parentDepth + 1;
//	cout << i << ": " << g[i].t << ", " << g[i].nbc << ", " << g[i].nc << endl;
	switch(s[i]) {
		case 'e':{
			parentNc += 1;
			break;
		}
		case 'f':{
			parentNbc += (1024 / exp[g[i].d-1]); 
			parentNc += 1;
			break;
		}
		case 'p':{
			for(int j = 0; j < 4; j++) {
				traverse(g, s, i+g[i].nc+1, g[i].nbc, g[i].nc, g[i].d);
			}
			parentNbc += g[i].nbc;
			parentNc += (g[i].nc + 1);
			break;
		}
	}
//	cout << i << ": " << g[i].t << ", " << g[i].nbc << ", " << g[i].nc << ", " << g[i].d << endl;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int x = 1;
	for(int i = 0; i < 10; i++) {
		exp[i] = x;
		x *= 4;
	}
	
//	for(int i = 0; i < 10; i++) {
//		cout << exp[i] << endl;
//	}

	int T;
	cin >> T;
	string str1, str2;
	vector<Node> g1, g2;
	while(T--) {
		cin >> str1 >> str2;
//		cout << str1 << endl << str2 << endl;
		
		g1.resize(str1.length());
		g2.resize(str2.length());
		
		int dummyNbc, dummyNc;
		traverse(g1, str1, 0, dummyNbc, dummyNc, 0);
//		cout << endl;
		traverse(g2, str2, 0, dummyNbc, dummyNc, 0);
//		cout << endl;

		int nbc = 0;
		int i1 = 0, i2 = 0;
		while(i1 < g1.size() && i2 < g2.size()) {
			if(g1[i1].t == 'f') {
				nbc += (1024 / exp[g1[i1].d-1]);
				i1++;
				i2 += (g2[i2].nc + 1);
				continue;
			} else if(g2[i2].t == 'f') {
				nbc += (1024 / exp[g2[i2].d-1]);
				i1 += (g1[i1].nc + 1);
				i2++;
				continue;
			} else if(g1[i1].t == 'e') {
				nbc += g2[i2].nbc;
				i1++;
				i2 += (g2[i2].nc + 1);
			} else if(g2[i2].t == 'e') {
				nbc += g1[i1].nbc;
				i1 += (g1[i1].nc + 1);
				i2++;
			} else {
				i1++;
				i2++;
			}
		}
		cout << "There are " << nbc << " black pixels." << endl;
	} 

	return 0;
}
