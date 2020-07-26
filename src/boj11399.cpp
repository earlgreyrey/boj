#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, ans = 0;
int people[MAX], atm[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> people[i];
    }

    sort(people, people+N);

    atm[0] = people[0];
    ans+=atm[0];
    for(int i = 1; i < N; i++) {
        atm[i] = atm[i-1] + people[i];
        ans+=atm[i];
    }

    cout << ans;
}