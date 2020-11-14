#include<iostream>
#include<queue>
using namespace std;

struct node {
    int key_value;
    int h;
    node* left;
    node* right;
};

class btree{
public:
	node* root;
	btree(){
		root = NULL;
	}
	~btree() {
		destroy_tree(root);
	}
	void insert(int key){
		if(root!=NULL) {
			insert(key, root);
		}
		else {
			root=new node;
			root->key_value=key;
			root->h = 0;
			root->left=NULL;
			root->right=NULL;
		  }
	}

private:
	void insert(int key, node* leaf) {
		if (key < leaf->key_value) {
			if (leaf->left != NULL) {
				insert(key, leaf->left);
			}
			else {
				leaf->left = new node;
				leaf->left->key_value = key;
				leaf->left->h = leaf->h + 1;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
		}
		else if (key >= leaf->key_value) {
			if (leaf->right != NULL) {
				insert(key, leaf->right);
			}
			else {
					leaf->right = new node;
					leaf->right->key_value = key;
					leaf->right->h = leaf->h + 1;
					leaf->right->left = NULL;
					leaf->right->right = NULL;
			}
		}
	}
	void destroy_tree(node *leaf) {
		if(leaf!=NULL)	{
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
	int H = tree.root->h;
	while (!ans.empty()) {
		node* n = ans.front();
		if (n->h > H) {
			H = n->h;
		}
		if (n->left != NULL) ans.push(n->left);
		if (n->right != NULL) ans.push(n->right);
		ans.pop();
	}
	cout << H + 1;
	return 0;
}

