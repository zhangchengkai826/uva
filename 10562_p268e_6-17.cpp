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

// [min, max)
struct Range{
	char lbl;
	int min, max;
};

struct CharPos{
	char lbl;
	int pos;
};

void print(map<char, vector<char> > &t, char c) {
	vector<char> &v = t[c];
	cout << c;
	cout << "(";
	for(int i = 0; i < v.size(); i++) {
		print(t, v[i]);
	}
	cout << ")";
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	int T;
	cin >> T;
	while(T--) {
		string s;
		map<char, vector<char> > t;
		int op = 0;
		vector<CharPos> roots;
		vector<Range> ranges;
		vector<int> rangeId2rootId;
		char tRoot;
		while(getline(cin, s) && s != "#") {
			if(s == "") {
				continue;
			}
//			cout << s << endl;
			
			switch(op) {
				case 0: {
					vector<CharPos> newRoots;
					if(roots.size()) {
						int rangeId = 0;
						for(int i = 0; i < s.length(); i++) {
							if(s[i] != ' ') {
//								cout << "([1]i=" << i << ", rangeId=" << rangeId << ", ranges[rangeId].max=" << ranges[rangeId].max << endl;
								while(i >= ranges[rangeId].max) {
									rangeId++;
								}
//								cout << "([2]i=" << i << ", rangeId=" << rangeId << ", ranges[rangeId].max=" << ranges[rangeId].max << endl;
								t[roots[rangeId2rootId[rangeId]].lbl].push_back(s[i]);
//								cout << "([3]rangeId2rootId[rangeId]=" << rangeId2rootId[rangeId] << endl;
								
								CharPos cp;
								cp.lbl = s[i];
								cp.pos = i;
								newRoots.push_back(cp);
							}
						}
					} else {
						for(int i = 0; i < s.length(); i++) {
							if(s[i] != ' ') {
								CharPos cp;
								cp.lbl = s[i];
								cp.pos = i;
								newRoots.push_back(cp);
								
								tRoot = s[i];
								break;
							}
						}
					}
					
					roots = newRoots;
					break;
				}
				case 1: {
					rangeId2rootId.clear();
					int rootId = 0;
					for(int i = 0; i < roots.size(); i++) {
						switch(s[roots[i].pos]) {
							case '|': {
								rangeId2rootId.push_back(rootId++);
								break;
							}
							default: {
								rootId++;
								break;
							}
						}
					}
//					cout << "([4]rangeId2rootId=[ ";
//					for(int i = 0; i < rangeId2rootId.size(); i++) {
//						cout << rangeId2rootId[i] << " ";
//					}
//					cout << "]" << endl;
					break;
				}
				case 2: {
					ranges.clear();
					bool start = false;
					Range r;
					int rootId = 0;
					for(int i = 0; i < s.length(); i++) {
						if(s[i] == '-' && !start) {
							start = true;
							r.lbl = roots[rootId++].lbl;
							r.min = i;
						} else if(s[i] != '-' && start) {
							start = false;
							r.max = i;
							ranges.push_back(r);
						}
					}
					if(start) {
						r.max = s.length();
						ranges.push_back(r);
					}
					break;
				}
			}
			
			op = (op + 1) % 3;
		}
		
		cout << "(";
		print(t, tRoot);
		cout << ")";
		cout << endl;
	}

	return 0;
}
