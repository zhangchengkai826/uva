#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>

struct Item{
	int id;
	int sc;
	bool operator<(const Item &op) const {
		return sc>op.sc || (sc==op.sc && id<op.id);
	}
};

using namespace std;

int m;
int n;
int opm;

const int maxn = 30000+5;
const int maxm = 50+5;
set<Item> dt[maxm];
map<int, int> dtmp[maxm]; /* id -> sc */

int op;

int lmt[maxm];

vector<int> rst[maxm];
set<Item>::iterator its[maxm];
int itpos[maxm];

struct PioItem {
	int tp;
	int md;
	int sc;
	bool operator<(const PioItem &op) const{
		return sc > op.sc || (sc == op.sc && tp < op.tp) || (sc == op.sc && tp == op.tp && md < op.md);
	}
};

set<PioItem> pio;

void add(int tp, int md, int sc){
	Item itm;
	itm.id = md;
	itm.sc = sc;
	dt[tp].insert(itm);
	dtmp[tp][md] = sc;
}

void del(int tp, int md) {
	Item itm;
	itm.id = md;
	itm.sc = dtmp[tp][md];
	dt[tp].erase(itm);
}

void que() {
	int &K = lmt[0];
	int *L = lmt+1;
	for(int i = 0; i < m; i++) {
		rst[i].clear();
		its[i] = dt[i].begin();
		itpos[i] = 0;
	}
	pio.clear();
	int K2 = K; 
	while(K2 > 0){
		bool isallfail = true;
		for(int i = 0; i < m; i++) {
			set<Item>::iterator &it = its[i];
			
			if(it != dt[i].end() && itpos[i] < L[i]) {
				isallfail = false;
				Item itm = *it;
				PioItem pioitm;
				pioitm.tp = i;
				pioitm.md = itm.id;
				pioitm.sc = itm.sc;
				pio.insert(pioitm);
				its[i]++;
				itpos[i]++; 
				K2--;
			}
		}
		if(isallfail){
			break;
		}
	}
//	set<PioItem>::iterator pit = pio.begin();
//	while(pit != pio.end()) {
//		printf("(%d, %d, %d)\n", pit->tp, pit->md, pit->sc);
//		pit++;
//	}
	set<PioItem>::iterator it = pio.begin();
	for(int i = 0; i < K; i++) {
		if(it != pio.end()) {
			PioItem pioitm = *it;
			rst[pioitm.tp].push_back(pioitm.md);
			//printf("Push %d to %d\n", pioitm.md, pioitm.tp);
			it++;
		} else {
			break;
		}
	}
	//printf("\n");
	for(int i = 0; i < m; i++) {
		vector<int> &r = rst[i];
		if(r.size() == 0) {
			printf("-1");
		} else {
			printf("%d", r[0]);
			for(int j = 1; j < r.size(); j++) {
				printf(" %d", r[j]);
			}
		}
		printf("\n");
	}
}

void doop() {
	switch(op){
		case 1: {
			int tp, md, sc;
			scanf("%d%d%d", &tp, &md, &sc);
			add(tp, md, sc);
			break;
		}
		case 2:{
			int tp, md;
			scanf("%d%d", &tp, &md);
			del(tp, md);
			break;
		}
		case 3:{
			for(int i = 0; i <= m; i++) {
				scanf("%d", &lmt[i]); 
			}
			que();
			break;
		}
	}
} 

int main() {
	//freopen("data.in", "r", stdin);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++) {
		Item itm;
		scanf("%d%d", &itm.id, &itm.sc);
		for(int j = 0; j < m; j++) {
			dt[j].insert(itm);
			dtmp[j][itm.id] = itm.sc;
		}
	}
	
	scanf("%d", &opm);
	for(int i = 0; i < opm; i++) {
		scanf("%d", &op);
		doop();
//		for(int i = 0; i < m; i++) {
//			set<Item>::iterator it = dt[i].begin();
//			while(it != dt[i].end()) {
//				printf("(%d %d) ", it->id, it->sc);
//				it++;
//			}
//			printf("\n");
//		}
//		printf("\n");
	}
}
