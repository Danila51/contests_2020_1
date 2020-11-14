#include<iostream>
#include<string>
#include<queue>
#include "Avl_tree.h"
#include "node.h"
using namespace std;


int main() {
	int n;
	int value;
	string key;
	Avl_tree <string, int> tr;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> key >> value;
		tr.insert(key, value);
    cout << tr.root->key << endl;
	}
	queue<std::shared_ptr<node<string,int>>> ans;
	ans.push(tr.begin());
	while (!ans.empty()) {
		auto n = ans.front();
		cout << "key: " << n->key << endl;
		if (n->left != nullptr) ans.push(n->left);
		if (n->right != nullptr) ans.push(n->right);
		ans.pop();
	}
	return 0;
}


