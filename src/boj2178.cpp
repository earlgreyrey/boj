#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 101

using namespace std;

int N, M, x = 0, y = 0;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int maze[MAX][MAX];
int maze_escape();

queue<pair<int, int>> road;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < M; j++) {
			maze[i][j] = s[j] - '0';
		}
	}

	cout << maze_escape();
}

int maze_escape() {
	maze[x][y] = 2;
	road.push({x, y});

	while(!road.empty()) {
		x = road.front().first;
		y = road.front().second;
		road.pop();

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx<0 || nx>N-1 || ny<0 || ny>M-1 ) {
				continue;
			}

			if(maze[nx][ny] == 1) {
				 road.push(make_pair(nx, ny));
				 maze[nx][ny] = maze[x][y] + 1;
			}

		}
	}

	return maze[N-1][M-1]-1;
}
