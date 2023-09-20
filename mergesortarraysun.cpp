#include<bits/stdc++.h>
using namespace std;

bool mergeSort(vector<int>& a, int k) {
    if (a.size() <= 1)
        return false;

    int mid = a.size() / 2;

    vector<int> b;
    vector<int> c;

    for (int i = 0; i < mid; i++) {
        b.push_back(a[i]);
    }
    for (int i = mid; i < a.size(); i++) {
        c.push_back(a[i]);
    }

    bool foundInLeft = mergeSort(b, k);
    bool foundInRight = mergeSort(c, k);

    vector<int> sorted_a;
    int idx1 = 0, idx2 = 0;

    while (idx1 < b.size() && idx2 < c.size()) {
        if (b[idx1] + c[idx2] == k) {
            return true; 
        } else if (b[idx1] + c[idx2] < k) {
            idx1++;
        } else {
            idx2++;
        }
    }

    a = sorted_a; 

    return foundInLeft || foundInRight;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    if (mergeSort(a, k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
