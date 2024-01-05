#include <iostream>
#include <vector>

using namespace std;

vector<long long> segment_tree;

void build_tree(const vector<long long> &arr, int node, int start, int end) {
    if (start == end) {
        segment_tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build_tree(arr, 2 * node, start, mid);
        build_tree(arr, 2 * node + 1, mid + 1, end);
        segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
    }
}

void update_tree(int node, int start, int end, int left, int right, int val) {
    if (left > end || right < start) {
        return;
    }
    if (start == end) {
        segment_tree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    update_tree(2 * node, start, mid, left, right, val);
    update_tree(2 * node + 1, mid + 1, end, left, right, val);
    segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
}

long long query_tree(int node, int start, int end, int idx) {
    if (start == end) {
        return segment_tree[node];
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        return query_tree(2 * node, start, mid, idx);
    } else {
        return query_tree(2 * node + 1, mid + 1, end, idx);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Build segment tree
    segment_tree.resize(4 * n);
    build_tree(arr, 1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update_tree(1, 0, n - 1, a - 1, b - 1, u);
        } else {
            int k;
            cin >> k;
            cout << query_tree(1, 0, n - 1, k - 1) << endl;
        }
    }

    return 0;
}
