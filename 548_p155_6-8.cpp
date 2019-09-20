#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int w;
	int sw;
	bool isLeaf;
	Node(int w){
		this->w = w;
		this->sw = w;
		this->isLeaf = false;
	}
	bool operator==(const Node &op) {
		return w == op.w;
	}
};

bool fill(vector<Node> &in, int inStart, int inN, vector<Node> &post, int postStart, int postN, Node *parent) {
//	cout << inStart << ", " << inN << ", " << postStart << ", " << postN << endl;
	if(inN == 0 || postN == 0) {
		return false;
	}
	
	Node &root = post[postStart+postN-1];
	int rootInPos = distance(in.begin()+inStart, find(in.begin()+inStart, in.begin()+inStart+inN, root));
//	cout << root << ", " << rootInPos << endl;

	if(parent != 0) {
		root.sw = parent->sw + root.w;
	}

	bool leftExist = fill(in, inStart, rootInPos, post, postStart, rootInPos, &root);
	bool rightExist = fill(in, inStart+rootInPos+1, postN-rootInPos-1, post, postStart+rootInPos, postN-rootInPos-1, &root);
	
	if(!leftExist && !rightExist) {
		root.isLeaf = true;
	}
	
	return true;
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif	

	string line;
	while(getline(cin, line)) {
		vector<Node> inodr, postodr;
		istringstream iss(line);
		int t;
		while(iss >> t) {
			inodr.push_back(Node(t));
		}
		getline(cin, line);
		istringstream iss2(line);
		while(iss2 >> t) {
			postodr.push_back(Node(t));
		}
		
//		cout << inodr.size() << ", " << postodr.size() << endl;
		
		fill(inodr, 0, inodr.size(), postodr, 0, postodr.size(), 0);
//		cout << endl;

		int min_sw = -1;
		int min_sw_w = -1;
		for(int i = 0; i < postodr.size(); i++) {
			if(postodr[i].isLeaf) {
				if(min_sw == -1) {
					min_sw = postodr[i].sw;
					min_sw_w = postodr[i].w;
				} else {
					if(postodr[i].sw < min_sw) {
						min_sw = postodr[i].sw;
						min_sw_w = postodr[i].w;
					} else if(postodr[i].sw == min_sw && postodr[i].w < min_sw_w) {
						min_sw = postodr[i].sw;
						min_sw_w = postodr[i].w;
					}
				}
			}
		}
		cout << min_sw_w << endl;
	}

	return 0;
}
