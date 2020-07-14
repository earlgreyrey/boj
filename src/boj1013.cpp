#include <iostream>
#include <string.h>
#define MAX 201
using namespace std;

int N;

int main(){
	cin >> N;
	string Ans[N];

	for(int i = 0; i < N; i++) {
		string Radio;
		cin >> Radio;
		int idx = 0;

		if(Radio.substr(idx, 3) == "100") {
			idx+=3;
			while(Radio[idx] == '0') {
				idx++;
			}
			while(Radio[idx] == '0') {
				idx++;
			}
			Ans[i] = "Yes";
		}

		else if(Radio.substr(idx, 2) == "01") {
			idx+=2;
			Ans[i] = "Yes";
		}

		else {
			Ans[i] = "No";
		}
	}

	for(int i = 0; i < N; i++) {
		cout << Ans[i] << "\n";
	}


}