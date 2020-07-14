#include <iostream>
#include <string.h>

using namespace std;

string N;
int ans;
int flag = 0;

int main() {
	cin >> N;

	for(int i = 0; i < N.size(); i++) {
		if(stoi(N[i]) == 6 || stoi(N.at(i)) == 9) {
			if(flag == 0) {
				ans+=1;
				flag = 1;
			} else {
				flag = 0;
			}
		} else {
			ans+=1;
		}
	}

	cout << ans;
}