#include <iostream>
#define MAX 11

using namespace std;

int N, K, ans = 0;
int money[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> money[i];
    }
    
    for(int i = 1; i <= N; i++) {
        ans += K/money[N-i];
        K %= money[N-i];
        if(K == 0) break; 
    }

    cout << ans << "\n";
}