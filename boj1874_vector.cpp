#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
	stack<int> s;
	vector<char> out;

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
		out.push_back('+');

		while(!s.empty() && s.top() == sequence[sp]){
			s.pop();
			out.push_back('-');
			sp++;
		}
	}

	if(s.empty()){
		vector<char>::iterator it;
		for(it = out.begin(); it != out.end(); it++){
			cout << *it << '\n';
		}
	} else{
		cout << "NO" << '\n';
	}

	delete[] sequence;

	return 0;
}
