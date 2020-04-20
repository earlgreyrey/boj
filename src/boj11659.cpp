#include <iostream>

using namespace std;

int num[100001];
int sum[100001];

int main(){
	int numN;
	int sumN;

	scanf("%d", &numN);
	scanf("%d", &sumN);

	for(int i = 1; i <= numN; ++i){
		scanf("%d", &num[i]);
		sum[i] = sum[i-1] + num[i];
	}

	int from;
	int to;

	for(int i = sumN; i > 0; i--){
		scanf("%d", &from);
		scanf("%d", &to);

		printf("%d\n", sum[to]-sum[from-1]);
	}

}