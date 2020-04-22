#include <iostream>
#include <cstring>
#define MAX 1000001

using namespace std;

int arr[MAX];

int main(){
	arr[1] = 0;

	int n;
	scanf("%d", &n);
	
	for(int i = 2; i <= n; i++){
		arr[i] = arr[i-1] + 1;
		if(i%2 == 0) (arr[i] > arr[i/2]+1)?arr[i]=arr[i/2]+1:arr[i]=arr[i];
		if(i%3 == 0) (arr[i] > arr[i/3]+1)?arr[i]=arr[i/3]+1:arr[i]=arr[i];	
	}

	printf("%d\n", arr[n]);

	return 0;
}