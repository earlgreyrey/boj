#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, V;
int edge[MAX][MAX];
int visit[MAX];
void search_dfs(int v);
void search_bfs(int v);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> V;

	int tmp1, tmp2;
	for(int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		edge[tmp1][tmp2] = 1;
		edge[tmp2][tmp1] = 1;
	}

	fill_n(visit, MAX, 0);
	search_dfs(V);
	cout << '\n';
	search_bfs(V);

}

void search_dfs(int v) {
	cout << v << " ";
	visit[v] = 1;
	for(int i = 1; i <= N; i++) {
		if(edge[v][i] == 1 && visit[i] != 1) {
			search_dfs(i);
		} else continue;
	}
}

void search_bfs(int v) {
	queue<int> q;

	q.push(v);
	visit[q.front()] = 0;
	while(!q.empty()){
		cout << q.front() << " ";
		
		for(int i = 1; i <= N; i++) {
			if(edge[q.front()][i] == 1 && visit[i] != 0) {
				q.push(i);
				visit[i] = 0;
			}
		}
		q.pop();	
	}

}