#include<iostream>
#include<vector>
#include<map>
#include<set>


using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m;
	map<int, set<int>> graph;
	for (int i = 0; i < n; ++i) {
		set<int> tmp = {i};
		graph[i] = tmp;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (graph[a].find(b) != graph[a].end()) continue;
		graph[a].insert(graph[b].begin(),graph[b].end());
		if (graph[a].size() == n) {
			cout << i + 1;
			return 0;
		}
		for(auto p = graph[a].begin(); p!=graph[a].end(); ++p) graph[*p] = graph[a];
	}
	return 0;
}
