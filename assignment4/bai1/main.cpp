#include <iostream>
using namespace std;

void check(int l, int r, int A[], int K[], int T) {
    for (int i = 0; i < T; i++) {
        int Count = 0;
        int left = l, right = r; // reset left and right for each test case
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] >= K[i]) {
                Count++;
                right = mid - 1; // search the left half
            }
            else {
                left = mid + 1; // search the right half
            }
        }
        cout << Count << endl;
    }
}

int main() {
    int N, T;
    cin >> N >> T;
    int A[N], K[T];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < T; i++) {
        cin >> K[i];
    }
    check(0, N - 1, A, K, T);
    return 0;
}
