#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int N;
int tip[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tip[i];
    }

    sort(&tip[0], &tip[N-1], greater<int>());

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        /*if((tip[i]-i)<0) {
            ans+=0;
            //cout << "less than 0: " << tip[i]-i << '\n';
        }
        else {
            ans+=tip[i]-i;
            //cout << "greater than 0: " << tip[i]-i << '\n';
        }*/
        ans+=max(0, tip[i]-i);
    }

    cout << ans;

}