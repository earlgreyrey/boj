#include <iostream>
#define MAX 100001

using namespace std;

int max(int a, int b);
int max(int a, int b, int c);
int sticker_play(int n);

int sticker[MAX][2];
int dp[MAX][3];

int main() {
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for(int j = 0; j < 2; j++) {
			for(int k = 1; k <= n; k++) {
				scanf("%d", &sticker[k][j]);
			}
		}
		printf("%d\n", sticker_play(n));
	}

	return 0;
}

int max(int a, int b) {
	if(a > b) return a;
	else return b;
}

int max(int a, int b, int c) {
	if(a > b){
		if(a > c) return a;
		else return c;
	}
	else {
		if(b > c) return b;
		else return c;
	}
}

int sticker_play(int n) {
	dp[1][0] = sticker[1][0];	//up
	dp[1][1] = sticker[1][1];	//down
	dp[1][2] = 0;				//none
	for(int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + sticker[i][0];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + sticker[i][1];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
	}

	return max(dp[n][0], dp[n][1], dp[n][2]);
}