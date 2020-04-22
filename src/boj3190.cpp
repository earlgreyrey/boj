#include <iostream>
// #include <string.h>
#define MAX 101

using namespace std;

struct snake_load {
	int sec;
	char angle;
} SNAKE, *SNAKE;

int apple[2][MAX];
int board[MAX][MAX];	// board array - dynamic allo. vs static allo. 

int main() {
	int life = 0;

	int n;
	scanf("%d", &n);
	memset(board, 0, sizeof())

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", apple[0][i], apple[1][i]);
	}

	int dir;
	scanf("%d", &dir);

	SNAKE s[dir];
	for (int i = 0; i < dir; i++) {
		scanf("%d, %s", &s[i].sec, s[i].angle);
	} 

	// code
	// code


	printf("Life is short...: %d\n", life);
}