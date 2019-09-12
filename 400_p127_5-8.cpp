#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif	

	int N;
	while(cin >> N) {
		vector<string> strs;
		int maxLen = 0;
		for(int i = 0; i < N; i++) {
			string str;
			cin >> str;
			if(maxLen < str.length())
				maxLen = str.length();
			strs.push_back(str);
		}
		sort(strs.begin(), strs.end());
		
		int C = 1 + (60-maxLen) / (maxLen+2);
		int R = (N-1) / C + 1;
		cout << setw(0) << "------------------------------------------------------------" << endl;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				int id = j*R+i;
				if(id >= N)
					continue;
				int w = maxLen + 2;
				if(j == C-1)
					w = maxLen;
				cout << left << setw(w) << strs[id];
			}
			cout << setw(0) << endl;
		}
		
	//	cout << maxLen << endl;
		
//		cout << endl;
//		for(int i = 0; i < N; i++) {
//			cout << strs[i] << endl;
//		}
//		cout << endl;
		//cout << strs.size() << endl;
	}

	return 0;
}
