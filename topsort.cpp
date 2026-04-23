#include <bits/stdc++.h>
using namespace std;

bool visit(int place, vector<vector<int>>& adj, vector<int>& state, vector<int>& sorted) {
    if (state[place] == 2) {
        return true;
    }
    if (state[place] == 1) {
        return false; // unable to be sorted due to cycle
    }

    state[place] = 1;

    int m = adj[place].size();

    for (int link = 0; link < m; link++) {
        int neighbor = adj[place][link];

        if (!visit(neighbor, adj, state, sorted)) {
            return false;
        }
    }

    state[place] = 2;
    sorted.push_back(place);

    return true;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2, 3},
        {4},
        {4},
        {},
        {}
    };

    int n = adj.size();

    vector <int> sorted;
    vector<int> state(n, 0); // unmarked, temp, perm


    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (!visit(i, adj, state, sorted)) {
                cout << "cycle detected";
                return 1;
            }
        }
    }

    reverse(sorted.begin(), sorted.end());

    for (int s: sorted) {
        cout << s << " ";
    }

    return 0;
}
