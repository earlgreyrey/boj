#include <iostream>
#define MAX 16
using namespace std;

int N;
int T[MAX], P[MAX];
int doby_is_free();

int main() {
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	cout << doby_is_free();

}

int doby_is_free() {
	
}