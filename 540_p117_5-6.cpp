#include <iostream>
#include <vector> 
#include <queue>
#include <cstring>
#include <map>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int sid = 0;
	
	int t;
	while(scanf("%d", &t) && t) {
		printf("Scenario #%d\n", ++sid);
		
		//cout << "(" << t << ")";
		
		vector<queue<int> > qs(t);
		//cout << "(" << qs.size() << ")";
		queue<int> gq;
		map<int, int> teams;
		for(int i = 0; i < t; i++) {
			int n;
			scanf("%d", &n);
			//cout << "(" << n << ")";
			for(int j = 0; j < n; j++) {
				int tmp;
				scanf("%d", &tmp);
				teams[tmp] = i;
				//cout << "(" << tmp << ")";
			}
		}
		
		//printf("(%d)", teams.size());
		
		char cmd[16];
		while(scanf("%s", cmd) && cmd[0] != 'S') {
			//cout << "(" << cmd << ")";
			if(cmd[0] == 'E') {
				int id;
				scanf("%d", &id);
				
				queue<int> &q = qs[teams[id]];
				if(!q.size())
					gq.push(teams[id]);
				q.push(id);
				
				//cout << "(" << q.size() << ", " << gq.size() << ")";
//				cout << "( ";
//				for(list<int>::iterator fit = q.begin(); fit != q.end(); ++fit) {
//					cout << *fit << " ";
//				}
//				cout << ")";
				//cout << "(" << teams[id] << ")";
			} else {
				queue<int> &q = qs[gq.front()];
				printf("%d\n", q.front());
				q.pop();
				if(!q.size())
					gq.pop();
			} 
		}
		putchar('\n');
	}

	return 0;
}
