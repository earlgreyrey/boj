#include <iostream>
#define MAX 1001

using namespace std;

int arr[MAX];

int main(){
	int n;
	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 3;

	if(n != 1 | n != 2){
		for(int i = 3; i <= n; i++){
			arr[i] = (arr[i-1] + 2 * arr[i-2]) % 10007;
		}
	}

	printf("%d\n", arr[n] % 10007);

	return 0;
}