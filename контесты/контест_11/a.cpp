#include<iostream>
#include<vector>
using namespace std;

int dfs(int u, vector<bool>& visited, vector<vector<bool>>& automat) {
	int visitedVertices = 1;
	visited[u]=true;
	for (int i = 0; i < automat.size(); ++i) {
		if ((!visited[i]) && (i!= u) && (automat[u][i])) visitedVertices += dfs(i, visited, automat);
	}
	return visitedVertices;
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	if (m + 1 < n) {
		cout << "NO";
		return 0;
	}
	vector<vector<bool>> ans;
	ans.resize(n);
	for (int i = 0; i < n; ++i) ans[i].resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		ans[a][b]=true;
		ans[b][a]=true;
	}
	vector<bool> visited(n, false);
	if (n!=dfs(0,visited,ans)) cout << "NO";
	else cout << "YES";
	return 0;
}
