#include <bits/stdc++.h>
using namespace std;

vector<int> ls[30];
int n;

void find(int i, int &p, int &h) {
	for(p = 0; p < n; p++) {
		for(h = 0; h < ls[p].size(); h++) {
			if(ls[p][h] == i)
				return;
		}
	}
}

void clearTop(int p, int h) {
	for(int i = h+1; i < ls[p].size(); i++) {
		int t = ls[p][i];
		ls[t].push_back(t);
	}
	ls[p].resize(h+1);
}

void pileOver(int p, int h, int p2) {
	for(int i = h; i < ls[p].size(); i++) {
		ls[p2].push_back(ls[p][i]);
	}
	ls[p].resize(h);
}

void print() {
	for(int i = 0; i < n; i++) {
		printf("%d:", i);
		for(int j = 0; j < ls[i].size(); j++) printf(" %d", ls[i][j]);
		printf("\n");
	}  
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		ls[i].push_back(i);
		
	char cmd1[8], cmd2[8];
	int d1, d2;
	
	while(scanf("%s%d%s%d", cmd1, &d1, cmd2, &d2) == 4) {
		//print();
		//putchar('\n');
		//putchar('\n');
		int p1, p2, h1, h2;
		find(d1, p1, h1);
		find(d2, p2, h2);
		if(p1 == p2)
			continue;
		//printf("(%d %d %d %d %d %d)", d1, p1, h1, d2, p2, h2);
		if(!strcmp(cmd2, "onto")) {
			clearTop(p2, h2);
		}
		if(!strcmp(cmd1, "move")) {
			clearTop(p1, h1);
		}
		pileOver(p1, h1, p2);
	}

	print();
	
	return 0;
}
