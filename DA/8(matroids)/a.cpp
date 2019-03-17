#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("schedule.in", "r", stdin);
    freopen("schedule.out", "w", stdout);//*/
    int n;
    cin >> n;
    long long ans = 0;
    vector<pair<int, int> > task;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        int d, w;
        cin >> d >> w;
        if (d == 0) {
            ans += w;
        } else {
            task.push_back({d, w});
        }
    }
    sort(task.begin(), task.end());
    for (size_t i = 0; i < task.size(); ++i) {
        int d = task[i].first, w = task[i].second;
        if (q.size() < d) {
            q.push(-w);
        } else {
            int W = -q.top();
            if (W < w) {
                q.pop();
                q.push(-w);
                ans += W;
            } else {
                ans += w;
            }
        }
    }
    cout << ans;
    return 0;
}
