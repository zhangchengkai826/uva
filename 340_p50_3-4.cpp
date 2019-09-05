#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	
	
	int gameNo = 0;
	while(true) {
		int N;
		cin >> N;
		if(!N) 
			break;
		
		gameNo++;
		printf("Game %d:\n", gameNo);
		
		vector<int> s;
		s.resize(N);
		for(int i = 0; i < N; i++) {
			cin >> s[i];
		}
		
		while(true) {
			int strong = 0, weak = 0;
			
			int sCnt[9] = {0}, gCnt[9] = {0};
			
			for(int i = 0; i < N; i++) {
				int gi;
				cin >> gi;
				if(gi == 0) {
					do{
						cin >> gi;
						i++;
					} while(i < N-1);
					goto gameEnd;
				}
				
				if(s[i] == gi) {
					strong++;
				} else {
					sCnt[s[i]-1]++;
					gCnt[gi-1]++;
				}
			}
			
			for(int i = 0; i < 9; i++) {
				weak += min(sCnt[i], gCnt[i]);
				
				/*printf("\n[%d, %d, %d]\n", sCnt[i], gCnt[i], min(sCnt[i], gCnt[i])); */ 
			}
			
			printf("    (%d,%d)\n", strong, weak);
		}
gameEnd:;
	} 

	return 0;
}
