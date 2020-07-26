#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans = 0, time = 0;
vector<pair<int, int>> meet;

bool compare(pair<int, int> argv1, pair<int, int> argv2);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    int argv1, argv2;
    for(int i = 0; i < N; i++) {
        cin >> argv1 >> argv2;
        meet.push_back(make_pair(argv1, argv2));
    }

    sort(meet.begin(), meet.end(), compare);

    for(int i = 0; i < meet.size(); i++) {
        if(time <= meet[i].first) {
            ans++;
            time = meet[i].second;
        }
    }

    cout << ans;
}

bool compare(pair<int, int> argv1, pair<int, int> argv2) {
    if(argv1.second == argv2.second) return argv1.first < argv2.first;
    else return argv1.second < argv2.second;
}