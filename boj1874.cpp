#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void){
	stack<int> s;
	queue<char> out;

	int n;
	cin >> n;

	int *sequence = new int[n];
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if((1 <= num) && (num <= n)){
			sequence[i] = num;
		} else{
			cout << "Number must be 1 <= number <= " << n << endl;
		}
	}

	int sp = 0;

	for(int i = 1; i <= n; i++){
		s.push(i);
		out.push('+');

		while(!s.empty() && s.top() == sequence[sp]){
			s.pop();
			out.push('-');
			sp++;
		}
	}

	if(s.empty()){
		int q_size = out.size();
		for(int i = 0; i < q_size; i++){
			cout << out.front() << endl;
			out.pop();
		}
	} else{
		cout << "NO" << endl;
	}

	delete[] sequence;

	return 0;
}