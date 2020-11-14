#include<iostream>
#include<queue>
using namespace std;

struct node {
    int key_value;
    node* left;
    node* right;
};

class btree{
public:
	node* root;
	btree() {
		root = nullptr;
	}
	~btree() {
		destroy_tree(root);
	}
	void insert(int key) {
		if(root!=nullptr) {
			insert(key, root);
		}
		else {
			root=new node;
			root->key_value=key;
			root->left=nullptr;
			root->right=nullptr;
		  }
	}
private:
	void insert(int key, node* leaf) {
		if (key < leaf->key_value) {
			if (leaf->left != nullptr) {
				insert(key, leaf->left);
			}
			else {
				leaf->left = new node;
				leaf->left->key_value = key;
				leaf->left->left = nullptr;
				leaf->left->right = nullptr;
			}
		}
		else if (key >= leaf->key_value) {
			if (leaf->right != nullptr) {
				insert(key, leaf->right);
			}
			else {
				leaf->right = new node;
				leaf->right->key_value = key;
				leaf->right->left = nullptr;
				leaf->right->right = nullptr;
			}
		}
	}
	void destroy_tree(node *leaf) {
		if(leaf!=nullptr)	{
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete leaf;
		}
	}
};



int main() {
	int tmp;
	btree tree;
	while (cin >> tmp) {
		tree.insert(tmp);
	}
	queue<node*> ans;
	ans.push(tree.root);
	while (!ans.empty()) {
		node* n = ans.front();
		cout << n->key_value << " ";
		if ( n->left != nullptr) ans.push(n->left);
		if ( n->right != nullptr) ans.push(n->right);
		ans.pop();
	}
	return 0;
}

