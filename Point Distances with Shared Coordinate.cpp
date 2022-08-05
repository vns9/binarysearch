// https://binarysearch.com/problems/Point-Distances-with-Shared-Coordinate

int mindis(int i, vector<int>& v) {
    int lo = 0;
    int hi = v.size() - 1;
    int currdiff = INT_MAX;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < i) {
            currdiff = min(currdiff, (int)abs(v[mid] - i));
            lo = mid + 1;
        } else if (v[mid] > i) {
            currdiff = min(currdiff, (int)abs(v[mid] - i));
            hi = mid - 1;
        } else {
            if (mid - 1 >= 0) currdiff = min(currdiff, (int)abs(v[mid - 1] - i));
            if (mid + 1 < v.size()) currdiff = min(currdiff, (int)abs(v[mid + 1] - i));
            break;
        }
    }
    return currdiff;
}
vector<int> solve(vector<vector<int>>& points) {
    unordered_map<int, vector<int>> xtoy;
    unordered_map<int, vector<int>> ytox;
    for (auto point : points) {
        xtoy[point[0]].push_back(point[1]);
        ytox[point[1]].push_back(point[0]);
    }
    for (auto kv : xtoy) {
        sort(xtoy[kv.first].begin(), xtoy[kv.first].end());
    }
    for (auto kv : ytox) {
        sort(ytox[kv.first].begin(), ytox[kv.first].end());
    }
    vector<int> manhat;
    for (auto point : points) {
        manhat.push_back(min(mindis(point[1], xtoy[point[0]]), mindis(point[0], ytox[point[1]])));
    }
    return manhat;
}
