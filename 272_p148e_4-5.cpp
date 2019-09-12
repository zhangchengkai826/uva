#include <bits/stdc++.h>
using namespace std;

int nr, nc;

enum {
	DR, DC, IC, IR, EX
};

map<string, int> lt;
#define ltInsert(x) lt[#x] = x

struct OpRecord{
	int op;
	vector<int> oprands;
	
	void fill() {
		char s[4];
		int n;
		scanf("%s%d", s, &n);
		if(!strcmp(s, "EX")) {
			oprands.push_back(n);
			n = 3;
		}
		
		op = lt[s];
		for(int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			oprands.push_back(t);
		}
	}
	
	void process(int &r, int &c) {
		switch(op) {
			case DR: {
				int d = 0;
				for(int i = 0; i < oprands.size(); i++) {
					if(oprands[i] < r) {
						d++;
					} else if(oprands[i] == r) {
						r = -1;
						return;
					}
				}
				r -= d;
				break;
			}
			case DC: {
				int d = 0;
				for(int i = 0; i < oprands.size(); i++) {
					if(oprands[i] < c) {
						d++;
					} else if(oprands[i] == c) {
						c = -1;
						return;
					}
				}
				c -= d;
				break;
			}
			case IC: {
				int d = 0;
				for(int i = 0; i < oprands.size(); i++) {
					if(oprands[i] <= c) {
						d++;
					}
				}
				c += d;
				break;
			}
			case IR: {
				int d = 0;
				for(int i = 0; i < oprands.size(); i++) {
					if(oprands[i] <= r) {
						d++;
					}
				}
				r += d;
				break;
			}
			case EX: {
				int &r1 = oprands[0];
				int &c1 = oprands[1];
				int &r2 = oprands[2];
				int &c2 = oprands[3];
				if(r1 == r && c1 == c) {
					r = r2; c = c2;
				} else if(r2 == r && c2 == c) {
					r = r1; c = c1;
				}
				break;
			}
		}
	}
};

vector<OpRecord> rs;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	ltInsert(DR);
	ltInsert(DC);
	ltInsert(IC);
	ltInsert(IR);
	ltInsert(EX);
	
	int n;
	int sprId = 0;
	while(scanf("%d%d%d", &nr, &nc, &n) == 3 && nr) {
		sprId++;
		if(sprId != 1)
			putchar('\n');
		printf("Spreadsheet #%d\n", sprId);
		
		// read ops
		rs.clear();
		for(int i = 0; i < n; i++) {
			OpRecord opr;
			opr.fill();
//			printf("\n([%d]", opr.op);
//			for(int i = 0; i < opr.oprands.size(); i++) {
//				printf("%d ", opr.oprands[i]);
//			}
//			printf(")\n");
			rs.push_back(opr);
		}
		
		// process queries
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int r, c;
			scanf("%d%d", &r, &c);
			printf("Cell data in (%d,%d) ", r, c);
			
			bool bGone = false;
			for(int j = 0; j < rs.size(); j++) {
				rs[j].process(r, c);
				if(r == -1 || c == -1) {
					bGone = true;
					break;
				}
			}
			
			if(bGone) {
				printf("GONE");
			} else {
				printf("moved to (%d,%d)", r, c);
			}
			putchar('\n');
		}
	}

	return 0;
}
