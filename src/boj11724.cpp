#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;

int N, M, node = 0;
vector<vector<int>> edge;
vector<bool> visited;
void dfs(int v);
void dfsAll();

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	edge.resize(N + 1);

	int tmp1, tmp2;
	for(int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		edge[tmp1].push_back(tmp2);
		edge[tmp2].push_back(tmp1);
	}

	visited = vector<bool>(N+1, 0);

	dfsAll();

	cout << node;

	return 0;
}

void dfs(int v) {
	//cout << v << " ";
	visited[v] = 1;
	for(int i = 0; i < edge[v].size(); i++) {
		int u = edge[v][i];
		if(!visited[u]) {
			dfs(u);
		} 
		//else continue;
	}
}

void dfsAll() {
	//visited = vector<bool>(edge.size(), 0);
	for(int i = 1; i < N+1; i++) {
		if(!visited[i]) {
			node++;
			dfs(i);

			//cout << endl;
		}
	}
}