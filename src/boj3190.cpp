#include <iostream>
#include <string.h>
#define MAX 101

using namespace std;

void init_board(int n);
void snake_crawl(unsigned char flag, int len);

struct SNAKE {
	int sec;
	char angle;
};

int x = 1;
int y = 1;
int len_update = 0;
int apple[MAX][MAX];
int board[MAX][MAX];

int main() {
	int life = 0;
	int snake_len = 1;
	unsigned char flag = 1;

	int n;
	scanf("%d", &n);
	init_board(n);

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		apple[tmp1][tmp2] = 1;
	}

	int dir;
	scanf("%d", &dir);

	struct SNAKE s[dir];
	for (int i = 0; i < dir; i++) {
		scanf("%d, %s", &s[i].sec, s[i].angle);
		printf("struct %d\n", i);
	} 

	while(true){
		// if snake run into border or own body, snakes die...
		if(board[x][y] == -1){
			printf("die...\n");
			break;
		}
		
		for(int i = 0; i < dir; i++){
			if(life == s[i].sec){
				// direction change - how?
				if(s[i].angle == 'L'){
					flag = (flag>>1)|(flag<<3);
					printf("change angle L\n");
				} else{	// s[i].angle == 'D'
					flag = (flag<<1)|(flag>>3);
					printf("change angle D\n");
				}
			}
		}

		if(apple[x][y] == 1){
			// eat apple
			snake_len++;
			len_update = 1;
			printf("eat apple\n");
		}

		// increse step by original or changed(how can i know this?) dirction
		snake_crawl(flag, snake_len);
		len_update = 0;

		life++;
		printf("life is %d\n", life);
		
	}

	printf("Life is short...: %d\n", life);
}

void init_board(int n){
    for(int i = 0; i < n+1; i++){
        memset(board+i, 0, sizeof(short)*(n+1));
    }
    for(int i = 0; i <= n+1; i++){
        board[0][i] = -1;
        board[n+1][i] = -1;
    }
    for(int i = 0; i <=n+1; i++){
        board[i][0] = -1;
        board[i][n+1] = -1;
    }
}

void snake_crawl(unsigned char flag, int len){
	if(!len_update){
		board[x][y] = 0;
	}

	switch(flag){
		case 1:
			// x+1, y
			x += 1;
			board[x][y] = 1;
			if(!len_update){
				board[x-len][y] = 0;
			}
			printf("case 1\n");
			break;
		case 2:
			// x, y-1
			y -= 1;
			board[x][y] = 1;
			if(!len_update){
				board[x][y+len] = 0;
			}
			printf("case 2\n");
			break;
		case 4:
			// x-1, y
			x -= 1;
			board[x][y] = 1;
			if(!len_update){
				board[x+len][y] = 0;
			}
			printf("case 4\n");
			break;
		case 8:
			// x, y+1
			y += 1;
			board[x][y] = 1;
			if(!len_update){
				board[x][y-len] = 0;
			}
			printf("case 8\n");
			break;
	}

	printf("call crawl\n");
}