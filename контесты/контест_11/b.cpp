#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n, m, x, y, a, b;

	cin >> n >> m >> x >> y;
	vector<bool> visited(n, false);
	vector<vector<bool>> graph(n, visited);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a][b]=true;
		graph[b][a]=true;
	}

	queue<int> bfs;
	bfs.push(x);
	vector<int> lenght(n, -1);
	lenght[x] = 0;
	visited[x] = true;

	while (!bfs.empty()) {
		if (bfs.front() == y) break;
		for (int i = 0; i < n; ++i) {
			if (graph[bfs.front()][i] == 1 && lenght[i] == -1) {
				lenght[i]= lenght[bfs.front()] + 1;
				visited[i] = 1;
				bfs.push(i);
			}
		}
		bfs.pop();
	}
	cout << lenght[y];
	return 0;
}
