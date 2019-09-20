#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right; 
	Node(int x){
		val = x;
		left = 0;
		right = 0;
	}
};

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	Node *tr = new Node(-1);
	string s;
	bool failed = false;
	while(cin >> s) {
//		cout << s << " != () ? " << (s != "()" )<< endl;
		if(failed && s != "()") {
			continue;
		}
		Node *p = tr;
		int pos = s.find(',');
		int kase = 0;
		queue<Node *> q;
		if(pos != string::npos) {
			s[pos] = ' ';
			s[0] = ' ';
			istringstream iss(s);
			int val;
			string op;
			iss >> val >> op;
			for(int i = 0; i < op.length(); i++) {
				if(op[i] == ')')
					break;
				switch(op[i]) {
					case 'L':{
						if(!p->left)
							p->left = new Node(-1);
						p = p->left;
						break;
					}
					case 'R':{
						if(!p->right)
							p->right = new Node(-1);
						p = p->right;
						break;
					}
				}
			}
			if(p->val != -1) {
				failed = true;
				continue;
			} 
			p->val = val;
		} else {
			if(failed) {
				cout << "not complete" << endl;
				failed = false;
				goto lbl_end;
			} else {
				q.push(tr);
				vector<int> ans;
				while(!q.empty()) {
					Node *t = q.front();
					q.pop();
					if(t->val == -1) {
						cout << "not complete" << endl;
						goto lbl_end;
					} 
					ans.push_back(t->val);
					if(t->left)
						q.push(t->left);
					if(t->right)
						q.push(t->right);
				}
				for(int i = 0; i < ans.size(); i++) {
					if(!kase) {
						kase = 1;
					} else {
						cout << " ";
					}
					cout << ans[i];
				}
				cout << endl;
			}	
lbl_end:
			tr->val = -1;
			tr->left = tr->right = 0;
		} 
	}

	return 0;
}
