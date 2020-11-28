#include<iostream>
#include<vector>

using namespace std;

class DSU {
public:
	vector<int> parent;
	vector<int> rank;
	int number_of_classes;
	DSU (int n) {
		number_of_classes = n;
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	void insert (int a, int b) {
		if (find_set(a) != find_set(b)) union_sets(a,b);
	}

	int find_set (int v) {
		if (v == parent[v]) return v;
		return parent[v] = find_set (parent[v]);
	}

	void union_sets (int a, int b) {
		a = find_set (a);
		b = find_set (b);
		if (a != b) {
			if (rank[a] < rank[b]) swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b]) ++rank[a];
		}
		--number_of_classes;
	}
	bool DSU_is_connected() {
		return number_of_classes == 1;
	}
};

int main() {
	int n, m, a, b;
	cin >> n >> m;
	DSU graph(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph.insert(a,b);
		if (graph.DSU_is_connected()) {
			cout << i+1;
			return 0;
		}
	}
}
