#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int board[101][101];
int n, k, l, x, y;
int dir = 0;
int life = 0;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
const int L[] = {3, 2, 0, 1}, D[] = {2, 3, 1, 0};

queue<pair<int, char>> rote;
queue<pair<int, int>> snake;

int life_is_short() {
	snake.push({1, 1});
	board[1][1] = 2;

	while(1) {
		
		life++;
		//cout<<"life: "<<life<<endl;
		//x = snake.back().first;
		x += dx[dir];
		//y = snake.back().second;
		y += dy[dir];

		if(x<0 || y<0 || x>=n || y>= n || board[x][y]==2) {
			//cout<<"die"<<endl;
			return life;
		}

		if(board[x][y] == 0) {
			int nx = snake.front().first;
			int ny = snake.front().second;

			board[nx][ny] = 0;
			//cout<<"0"<<endl;
			//snake.pop();
		}

		board[x][y] = 2;
		//cout<<"2"<<endl;

		if(life == rote.front().first) {
			if(rote.front().second == 'L') dir = L[dir];
			else dir = D[dir];
			//cout<<"rotate"<<endl;
			rote.pop();
		}

		snake.push(make_pair(x, y));
		//cout<<"push"<<endl;

	}

	return life;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		int apple_x, apple_y;
		cin >> apple_x >> apple_y;
		board[apple_x][apple_y] = 1;
	}

	cin >> l;
	for(int i = 0; i < l; i++) {
		int rotate_sec;
		char rotate_dir;
		cin >> rotate_sec >> rotate_dir;
		rote.push(make_pair(rotate_sec, rotate_dir));
	}

	cout << life_is_short();
}