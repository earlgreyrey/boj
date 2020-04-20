#include <iostream>
#define MAX 41

using namespace std;

int memo[2][MAX];

int main(){
	int n;

	scanf("%d", &n);

	memo[0][0] = 1;
	memo[1][1] = 1;
	for(int i = 2; i <= 40; i++){
		memo[0][i] = memo[0][i-1] + memo[0][i-2];
		memo[1][i] = memo[1][i-1] + memo[1][i-2];
	}

	for(int i = 0; i < n; i++){
		int fibo;
		scanf("%d", &fibo);

		printf("%d %d\n", memo[0][fibo], memo[1][fibo]);
	}

	return 0;
}