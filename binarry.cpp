#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> q;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;

        // Binary search
        int left = 0, right = n - 1;
        bool found = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == num) {
                found = true;
                break;
            } else if (arr[mid] < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
