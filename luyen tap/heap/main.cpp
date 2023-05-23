#include <iostream>
using namespace std;

void shift(int a[], int l, int r)
{
    int x, i, j;
    i = l;
    x = a[i];
    j = 2 * i + 1;
    while (j <= r) {
        if (j < r && a[j] < a[j + 1]) { // còn j thì phải bé hơn j + 1
            j++;
        }
        if (a[j]<=x) //sắp xếp từ bé đến lớn thì x phải lớn hơn

            return;
        else {
            a[i] = a[j];
            a[j] = x;
            i = j;
            j = 2 * i + 1;
            x = a[i];
        }
    }
}

void createheap(int a[], int n)
{
    int l;
    l = n / 2 - 1;
    while (l >= 0) {
        shift(a, l, n - 1);
        l = l - 1;
    }
}

void heapsort(int a[], int n)
{
    int r;
    createheap(a, n);
    r = n - 1;
    while (r > 0) {
        swap(a[0], a[r]);
        r--;
        shift(a, 0, r);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        cout << "cc";
    else {
        int* a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << endl;
        heapsort(a, n);
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
        delete[] a;
    }
    return 0;
}
