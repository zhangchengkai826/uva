#include <cstdio>
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

stack<int> st;
map<set<int>, int> set2id;
vector<set<int> > id2set;

int toId(const set<int> &s) {
	map<set<int>, int>::iterator it;
	if((it = set2id.find(s)) == set2id.end()) {
		int id = id2set.size();
		set2id[s] = id;
		id2set.push_back(s);
		return id;
	}
	return it->second;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
#endif	
	
	int T;
	cin >> T;
	while(T--) {
		st = stack<int>();
		set2id.clear();
		id2set.clear();
		
		int n;
		cin >> n;
		while(n--) {
			string s;
			cin >> s;
			if(s == "PUSH") {
				st.push(toId(set<int>()));
			} else if(s == "DUP") {
				st.push(st.top());
			} else if(s == "UNION") {
				set<int> o1 = id2set[st.top()];
				st.pop();
				set<int> o2 = id2set[st.top()];
				st.pop();
				set<int> o;
				set_union(o1.begin(), o1.end(), o2.begin(), o2.end(), inserter(o, o.end()));
				st.push(toId(o));
			} else if(s == "INTERSECT") {
				set<int> o1 = id2set[st.top()];
				st.pop();
				set<int> o2 = id2set[st.top()];
				st.pop();
				set<int> o;
				set_intersection(o1.begin(), o1.end(), o2.begin(), o2.end(), inserter(o, o.end()));
				st.push(toId(o));
			} else if(s == "ADD") {
				int o1id = st.top();
				st.pop();
				set<int> o2 = id2set[st.top()];
				st.pop();
				o2.insert(o1id);
				st.push(toId(o2));
			}
			cout << id2set[st.top()].size() << endl;
			//cout << st.size() << endl;
		}
		//cout << set2id.size() << ", " << id2set.size() << endl;
		cout << "***" << endl;
	}

	return 0;
}
