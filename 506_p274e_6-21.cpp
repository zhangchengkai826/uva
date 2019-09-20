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

map<string, int> name2id;
vector<string> id2name;
int ID(string &name) {
	if(name2id.find(name) == name2id.end()) {
		name2id[name] = id2name.size();
		id2name.push_back(name);
	}
	return name2id[name];
}

long long t;

struct Info{
	int id;
	vector<int> depOn, depBy;
	int state; // 0 - not installed, 1 - explicit installed, 2 - implicit installed
	long long t; // install time
	Info():state(0){}
};
vector<Info> info(1024);

Info &getInfoById(int id) {
	if(id >= info.size()) {
		info.resize(info.size() * 2); 
	}
	info[id].id = id;
	return info[id];
} 

void addDep(string &line) {
	istringstream iss(line);
	string s;
	iss >> s >> s;
	int compId = ID(s);
	while(iss >> s) {
		int depOnId = ID(s);
		getInfoById(compId).depOn.push_back(depOnId);
		getInfoById(depOnId).depBy.push_back(compId);
	}
}

void installDfs(int id, bool expl) {
	Info &info = getInfoById(id);
	if(info.state) {
		if(expl) {
			cout << "   " << id2name[id] << " is already installed." << endl;
		}
		return;
	}
	vector<int> &depOn = info.depOn;
	for(int i = 0; i < info.depOn.size(); i++) {
		installDfs(depOn[i], false);
	}
	cout << "   Installing " << id2name[id] << endl;
	info.state = (expl ? 1 : 2);
	info.t = t++;
}

void install(string &line) {
	istringstream iss(line);
	string s;
	iss >> s >> s;
	installDfs(ID(s), true);
}

void removeDfs(int id, bool expl) {
	Info &info = getInfoById(id);
	if(!info.state) {
		cout << "   " << id2name[id] << " is not installed." << endl;
		return;
	}
	vector<int> &depBy = info.depBy;
	if(expl) {
		for(int i = 0; i < depBy.size(); i++) {
			if(getInfoById(depBy[i]).state) {
				cout << "   " << id2name[id] << " is still needed." << endl;
				return;
			}
		}
	} else {
		if(getInfoById(id).state != 2) {
			return;
		}
		for(int i = 0; i < depBy.size(); i++) {
			if(getInfoById(depBy[i]).state) {
				return;
			}
		}
	}
	
	info.state = 0;
	cout << "   Removing " << id2name[id] << endl;
	vector<int> &depOn = info.depOn;
	for(int i = info.depOn.size()-1; i >= 0; i--) {
		removeDfs(depOn[i], false);
	}
}

void remove(string &line) {
	istringstream iss(line);
	string s;
	iss >> s >> s;
	removeDfs(ID(s), true);
}

struct TimeCmp {
	bool operator()(const Info &op1, const Info &op2) {
		return op1.t < op2.t;
	}
};

void listAll(string &line) {
	vector<Info> allInstalled;
	for(int id = 0; id < id2name.size(); id++) {
		if(getInfoById(id).state) {
			allInstalled.push_back(info[id]);
		}
	}
	sort(allInstalled.begin(), allInstalled.end(), TimeCmp());
	for(int i = 0; i < allInstalled.size(); i++) {
		cout << "   " << id2name[allInstalled[i].id] << endl;
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	string line;
	t = 0;
	while(getline(cin, line)) {
		cout << line << endl;
		switch(line[0]) {
			case 'E': {
				goto lbl_end;
				break;
			}
			case 'D': {
				addDep(line);
				break;
			}
			case 'I': {
				install(line);
				break;
			}
			case 'R': {
				remove(line);
				break;
			}
			case 'L': {
				listAll(line);
				break;
			}
		}
	}
lbl_end:;

//	for(int i = 0; i < id2name.size(); i++) {
//		Info &info = getInfoById(i);
//		cout << i << ", " << id2name[i] << endl;
//		cout << "DepOn:";
//		for(int j = 0; j < info.depOn.size(); j++) {
//			cout << " " << info.depOn[j];
//		} 
//		cout << endl;
//		cout << "DepBy:";
//		for(int j = 0; j < info.depBy.size(); j++) {
//			cout << " " << info.depBy[j];
//		} 
//		cout << endl;
//	}

	return 0;
}
