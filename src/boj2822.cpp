#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> Score;
bool compare(const pair<int, int> &a, const pair<int, int> &b);
int Ans[5], sum = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    for(int i = 0; i < 8; i++) {
        cin >> N;
        Score.push_back(make_pair(i+1, N));
    }
    sort(Score.begin(), Score.end(), compare);
    for(int i = 0; i < 5; i++) {
        Ans[i] = Score[i].first;
        sum+=Score[i].second;
    }
    
    cout << sum << '\n';

    sort(Ans, Ans+5);
    for(int i = 0; i < 5; i++) {
        cout << Ans[i] << " ";
    }
}

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
