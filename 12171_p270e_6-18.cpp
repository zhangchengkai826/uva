#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;

const int maxn = 100+5;
char g[maxn][maxn][maxn];
int sq, vol;
vector<int> tick[3];

struct Vec {
	int d[3];
	int &operator[](int i) {
		return d[i];
	}
	Vec(){}
	Vec(int x, int y, int z) {
		d[0] = x; d[1] = y; d[2] = z;
	}
};

istream &operator>>(istream &s, Vec& x) {
	for(int i = 0; i < 3; i++) {
		s >> x[i];
	}
	return s;
}

ostream &operator<<(ostream &s, Vec& x) {
	s << "(";
	for(int i = 0; i < 3; i++) {
		if(i != 0) {
			cout << ", ";
		}
		s << x[i];
	}
	s << ")";
	return s;
}

struct Box {
	Vec p, w;
};

istream &operator>>(istream &s, Box& x) {
	s >> x.p >> x.w;
	return s;
}

ostream &operator<<(ostream &s, Box& x) {
	s << "p: " << x.p << ", w: " << x.w;
	return s;
}

void dfs(Vec v, int d) {
//	cout << v << endl;
	for(int i = 0; i < 3; i++) {
		if(v[i] < 0 || v[i] > tick[i].size()) {
			return;
		}
	}
	char &c = g[v[0]][v[1]][v[2]];
	switch(c) {
		case 0: {
			c = 2;
			Vec real;
			for(int i = 0; i < 3; i++) {
				if(v[i] == tick[i].size() || v[i] == 0) {
					real[i] = 1;
				} else {
					real[i] = tick[i][v[i]] - tick[i][v[i]-1];
				}
			}
			vol += (real[0] * real[1] * real[2]);
//			cout << vol << endl;
			break;
		}
		case 1: {
			sq += ((tick[(d+1)%3][v[(d+1)%3]] - tick[(d+1)%3][v[(d+1)%3]-1]) * (tick[(d+2)%3][v[(d+2)%3]] - tick[(d+2)%3][v[(d+2)%3]-1]));
			return;
			break;
		}
		case 2: {
			return;
			break;
		}
	}
	for(int i = -1; i <= 1; i+=2) {
		dfs(Vec(v[0]+i, v[1], v[2]), 0);
		dfs(Vec(v[0], v[1]+i, v[2]), 1);
		dfs(Vec(v[0], v[1], v[2]+i), 2);
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		
//		cout << n;
		vector<Box> boxes;
		for(int i = 0; i < 3; i++) {
			tick[i].clear();
		}
		map<int, int> c2t[3]; // coord to tick
		for(int i = 0; i < n; i++) {
			Box b;
			cin >> b;
//			cout << b << endl;
			boxes.push_back(b);
			for(int i = 0; i < 3; i++) {
				tick[i].push_back(b.p[i]);
				tick[i].push_back(b.p[i]+b.w[i]);
			}
		}
		for(int i = 0; i < 3; i++) {
			sort(tick[i].begin(), tick[i].end());
			vector<int>::iterator it = unique(tick[i].begin(), tick[i].end());
			tick[i].resize(distance(tick[i].begin(), it));
			
			for(int j = 0; j < tick[i].size(); j++) {
				c2t[i][tick[i][j]] = j + 1;  // c2t[i][1st tick] = 1
			}
		}
		
//		for(int i = 0; i < 3; i++) {
//			cout << "[ ";
//			for(int j = 0; j < tick[i].size(); j++) {
//				cout << tick[i][j] << " ";
//			}
//			cout << "]" << endl;
//		}
		
		memset(g, 0, sizeof(g));
		for(int i = 0; i < boxes.size(); i++) {
			Box &b = boxes[i];
//			cout << b << endl;
			
			Vec tp, tm; // tick point, tick point max
			for(int j = 0; j < 3; j++) {
				tp[j] = c2t[j][b.p[j]];
				tm[j] = c2t[j][b.p[j]+b.w[j]];
			}
			for(int x = tp[0]; x < tm[0]; x++) {
				for(int y = tp[1]; y < tm[1]; y++) {
					for(int z = tp[2]; z < tm[2]; z++) {
						g[x][y][z] = 1;
//						cout << x << ", " << y << ", " << z << endl;
					}
				}
			}
//			cout << tp << endl << tm << endl << endl;
		}
		sq = 0; vol = 0;
		dfs(Vec(0, 0, 0), -1);
		
		int totalVol = 1;
		for(int i = 0; i < 3; i++) {
			totalVol *= (tick[i][tick[i].size()-1] - tick[i][0] + 2);
		}
		cout << sq << " " << totalVol - vol << endl;
//		cout << endl;
	}

	return 0;
}
