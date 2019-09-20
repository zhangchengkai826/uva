#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10;
char G[maxn][maxn];
char s[1024];

int u;
vector<int> us, vs;

int n;

map<char, int> name2id;
vector<char> id2name;
int ID(char c) {
	if(name2id.find(c) == name2id.end()) {
		name2id[c] = id2name.size();
		id2name.push_back(c);
	}
	return name2id[c];
}

int P[maxn], bestP[maxn], pos[maxn];

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	while(scanf("%s", s) == 1 && s[0] != '#') {
//		printf("%s\n", s);
		memset(G, 0, sizeof(G));
		name2id.clear();
		id2name.clear();
		
		char maxc = 'A';
		for(int i = 0; i < strlen(s); i++) {
			if(s[i] != ':' && s[i] != ';' && s[i] > maxc) {
				maxc = s[i];
			}
		}
		for(char c = 'A'; c <= maxc; c++) {
			ID(c);
		}
		
		us.clear();
		vs.clear();
		bool isr = true;
		for(int i = 0; i < strlen(s)+1; i++) {
			char &c = s[i];
//			printf("%c\n", c);
			switch(c) {
				case ':':{
//					printf("is = false\n");
					isr = false;
//					printf("%c recved\n", c);
					continue;
				}
				case ';':
				case '\0':{
//					printf("recv strlen(t)=%d\n", strlen(t));
					for(int j = 0; j < vs.size(); j++) {
						int &v = vs[j];
						G[u][v] = 1;
//						printf("%d %d\n", r-'A', chd-'A');
					}
					vs.clear();
					isr = true;
					continue;
				}
			}
//			printf("%c recved\n", c);
//			printf("%d, %c\n", isr, c);
			if(isr) {
				u = ID(c);
				us.push_back(u);
			} else {
//				printf("%d, %c\n", chdi, c);
				vs.push_back(ID(c));
			}
//			for(int i = 0; i < 10; i++) {
//				printf("%c", t[i]);
//			}
//			printf("\n");
		}
//
//		for(int i = 0; i < id2name.size(); i++) {
//			printf("%c:", id2name[i]);
//			for(int j = 0; j < id2name.size(); j++) {
//				if(G[i][j]) {
//					printf(" %c", id2name[j]);
//				}
//			}
//			printf("\n");
//		}

		int n = id2name.size();
		int minbw = (unsigned int)-1 << 1 >> 1;
//		printf("%d", minbw);
		for(int i = 0; i < n; i++) {
			P[i] = i;
		}
		do{
//			for(int i = 0; i < n; i++) {
//				printf("%d", P[i]);
//			}
//			printf("\n");
			for(int i = 0; i < n; i++) {
				pos[P[i]] = i;
			}
			int bw = 0;
			for(int i = 0; i < us.size(); i++) {
				int &u = us[i];
				for(int j = 0; j < n; j++) {
					if(G[P[i]][P[j]]) {
						if(j-i >= minbw) {
							goto next_perm;
						}
						bw = max(bw, j-i);
					}
				}
			}
//			printf("%d\n", bw);
			if(bw < minbw) {
				minbw = bw;
				memcpy(bestP, P, sizeof(P));
//				printf("%d\n", minbw);
			}
next_perm:;
		}while(next_permutation(P, P+n));
		for(int i = 0; i < n; i++) {
			printf("%c ", id2name[bestP[i]]);
		}
		printf("-> %d\n", minbw);
	}

	return 0;
}
