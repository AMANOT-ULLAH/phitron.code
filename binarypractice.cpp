#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;

        if (binarySearch(arr, query)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
/*
5

6 3 2 1 8


4


1

5

2

9
yes
no
yes
no

*/
