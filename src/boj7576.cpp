#include <iostream>
#include <algorithm>
#include <queue>

#define IP pair<int, int>
#define MAX 1001

using namespace std;

int N, M, days = 0, x = 0, y = 0;
IP DIR[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int tomato[MAX][MAX];
int harv_tomato();

queue<IP> tom;

IP operator + (const IP& lhs, const IP& rhs){
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> M >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) tom.push(make_pair(i, j));
		}
	}

	cout << harv_tomato();
}

int harv_tomato() {
	while(!tom.empty()){
		int len = tom.size();
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < 4; j++) {
				IP now = tom.front() + DIR[j];
				if(now.first < 0 || now.second <0 || now.first >= N || now.second >= M) {
					continue;
				}
				if(tomato[now.first][now.second] == 0) {
					tomato[now.first][now.second] = 1;
					tom.push(now);
				} else continue;
			}
			tom.pop();
		}

		days++;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(tomato[i][j] == 0) {
				return -1;
			}
		}
	}

	return days-1;
}