#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct Tuple{
	int r, c;
	char d;
};

struct RuleEle{
	char a;  // action
	bool b;  // is encountered
	RuleEle(char a){
		this->a = a;
		this->b = false;
	}
};

struct Rule{
	map<char, vector<RuleEle> > m;
}; 

struct TupleRCCmp{
	bool operator()(const Tuple &a, const Tuple &b) {
		return (a.r < b.r) || (a.r == b.r && a.c < b.c);
	}
};

struct TupleWithPath{
	Tuple t;
	vector<Tuple> p; // root->...->parent
};

void move(const Tuple &old, char d, Tuple &newt) {
	newt.d = old.d;
	newt.r = old.r;
	newt.c = old.c;
	switch(d) {
		case 'L':{
			switch(old.d) {
				case 'N':{
					newt.d = 'W';
					break;
				}
				case 'S':{
					newt.d = 'E';
					break;
				}
				case 'E':{
					newt.d = 'N';
					break;
				}
				case 'W':{
					newt.d = 'S';
					break;
				}
			}
			break;
		}
		case 'R':{
			switch(old.d) {
				case 'N':{
					newt.d = 'E';
					break;
				}
				case 'S':{
					newt.d = 'W';
					break;
				}
				case 'E':{
					newt.d = 'S';
					break;
				}
				case 'W':{
					newt.d = 'N';
					break;
				}
			}
			break;
		}
	}
	switch(newt.d) {
		case 'N':{
			newt.r--;
			break;
		}
		case 'S':{
			newt.r++;
			break;
		}
		case 'E':{
			newt.c++;
			break;
		}
		case 'W':{
			newt.c--;
			break;
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif	

	string name;
	while(cin >> name && name != "END") {
		cout << name << endl;
		Tuple s, e, olds;
		cin >> s.r >> s.c >> s.d >> e.r >> e.c;
		olds.r = s.r; olds.c = s.c;
		switch(s.d) {
			case 'N': {
				s.r--;
				break;
			} 
			case 'S': {
				s.r++;
				break;
			}
			case 'E': {
				s.c++;
				break;
			}
			case 'W': {
				s.c--;
				break;
			}
		}
		map<Tuple, Rule, TupleRCCmp> rs; 
		while(true) {
			Tuple t;
			Rule r;
			cin >> t.r;
			if(t.r == 0) {
				break;
			}
			cin >> t.c;
			string str;
			while(cin >> str && str != "*") {
				for(int i = 1; i < str.length(); i++) {
					r.m[str[0]].push_back(RuleEle(str[i]));
				}
			}
			rs[t] = r;
		}
		
//		cout << name << endl; 
//		for(map<Tuple, Rule, TupleRCCmp>::iterator it = rs.begin(); it != rs.end(); it++) {
//			cout << it->first.r << ", " << it->first.c << ", " << it->second.m.size() << endl;
//		}

		queue<TupleWithPath> q;
		TupleWithPath swp;
		swp.t = s;
		q.push(swp);
		while(!q.empty()) {
			TupleWithPath twp = q.front();
			q.pop();
			
			Tuple &t = twp.t;
			vector<RuleEle> &v = rs[t].m[t.d];
//			cout << t.r << ", " << t.c << ", " << t.d << endl;
			for(int i = 0; i < v.size(); i++) {
				if(v[i].b) {
					continue;
				}
				
				TupleWithPath ntwp;
				Tuple &n = ntwp.t;
				move(t, v[i].a, n);
				v[i].b = true;
				
				if(n.r == e.r && n.c == e.c) {
					int cnt = 0;
					
					cnt++;
					cout << " ";
					cout << " (" << olds.r << "," << olds.c << ")";
					for(int j = 0; j < twp.p.size(); j++) {
						cnt++;
						if(cnt > 10) {
							cnt = 0;
							cout << endl << " ";
						}
						cout << " (" << twp.p[j].r << "," << twp.p[j].c << ")";
					}
					
					cnt++;
					if(cnt > 10) {
						cnt = 0;
						cout << endl << " ";
					}
					cout << " (" << t.r << "," << t.c << ")";
					
					cnt++;
					if(cnt > 10) {
						cnt = 0;
						cout << endl << " ";
					}
					cout << " (" << n.r << "," << n.c << ")";
					
					cout << endl;
					goto lbl_end;
				}
				
				ntwp.p = twp.p;
				ntwp.p.push_back(t);
				q.push(ntwp);
			}
//			break;
		}
		cout << "  No Solution Possible" << endl;
lbl_end:;
	}

	return 0;
}
