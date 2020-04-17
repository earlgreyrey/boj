#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main(void){
	stack<int> s;
	char out[200000] = {0, };
	int op = 0;

	int n;
	cin >> n;

	int *sequence = new int[n];
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if((1 <= num) && (num <= n)){
			sequence[i] = num;
		} else{
			cout << "Number must be 1 <= number <= " << n << '\n';
		}
	}

	int sp = 0;

	for(int i = 1; i <= n; i++){
		s.push(i);
		out[op] = '+';
		op++;

		while(!s.empty() && s.top() == sequence[sp]){
			s.pop();
			out[op] = '-';
			op++;
			sp++;
		}
	}

	out[op] = '\n';

	if(s.empty()){
		for(int i = 0; out[i] != '\n'; i++){
			cout << out[i] << '\n';
		}
	} else{
		cout << "NO" << '\n';
	}

	delete[] sequence;

	return 0;
}