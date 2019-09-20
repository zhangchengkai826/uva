#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <sstream>
using namespace std;

int N, t[5], Q;

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	int T;
	cin >> T;
	while(T--) {
		cin >> N >> t[0] >> t[1] >> t[2] >> t[3] >> t[4] >> Q;
		map<char, int> symbolTable; 
		vector<string> progs;
		vector<int> ptrs;
		deque<int> R;
		queue<int> W;
		
		string s;
		int lineNo = 0;
		int ptr = 0;
		while(ptrs.size() < N && getline(cin, s)) {
			if(s == "")
				continue;
//			printf("%s\n", s.c_str());
			if(s == "end") {
				ptrs.push_back(ptr);
				ptr = lineNo + 1;
			}
			progs.push_back(s);
			++lineNo;
		}
//		for (int i = 0; i < ptrs.size(); i++)
//			cout << ptrs[i] << endl;
		
		for(int i = 0; i < N; i++) {
			R.push_back(i);
		}
			
		int lockedProg = -1;
		while(!R.empty()) {
			int pid = R.front();
			R.pop_front();
//			cout << "(pop: " << pid << endl;
			
			int p = ptrs[pid];
			int q = 0;
			string s = progs[p];
			bool bShouldWait = false;
			while(s != "end" && q < Q) {
//				cout << "exec " << pid << ", " << s << endl;
				if(s == "lock") {
					if(lockedProg != -1) {
						W.push(pid);
						bShouldWait = true;
						break;
					}
					lockedProg = pid;
					q += t[2];
				} else if(s == "unlock") {
					lockedProg = -1;
					if(!W.empty()) {
						R.push_front(W.front());
						W.pop();
					}
					q += t[3];
				} else if(s.substr(0, 5) == "print") {
					char valName = s[6];
					cout << pid+1 << ": " << symbolTable[valName] << endl;
					q += t[1];
				} else {
					istringstream iss(s);
					char valName;
					char ignore;
					int val;
					iss >> valName >> ignore >> val;
					symbolTable[valName] = val;
					q += t[0];
				}
				++p;
				s = progs[p];
//				cout << "(q: " << q << endl;
//				cout << "(R size: " << R.size() << endl; 
			}
//			cout << "s = " << s << endl;
//			cout << "s != \"end\" && s != \"lock\"? " << (s != "end" && s != "lock") << endl;
			if(s != "end" && !bShouldWait) {
//				cout << "(push: " << pid << endl;
				R.push_back(pid);
			} 
			ptrs[pid] = p;
		}
		if(T)
			cout << endl;
	}

	return 0;
}
