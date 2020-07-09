#include <iostream>
#include <string.h>
#define MAX 1000001

using namespace std;

int N, M;
int ans = 0;
string Pn[MAX];
//char S[MAX];
string S;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> S;

	Pn[1] = "IOI";
	for(int i = 2; i < N+1; i++) {
		Pn[i] = Pn[i-1].append("OI");
	}

	string nowP = Pn[N];

	int idx = 0;
	int size = nowP.size() - 1;
	for(int i = 0; i < M; i++) {
		if(nowP[idx] == S[i]) {
			if (idx == size) {
				ans++;
				if(S[i+1] == 'O') {
					idx = 1;
				} else{
					idx = 0;
				}
			} else{
				idx++;
			}

		} else {
			idx = 0;
		}
	}

	cout << ans;
	

}