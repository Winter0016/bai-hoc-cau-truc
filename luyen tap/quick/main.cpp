#include <iostream>
using namespace std;
void quicksort(int a[],int left,int right)
{
    int i,j,x;
    x=a[(left+right)/2];
    i=left;
    j=right;
        while(i<=j){
        while(a[i]<x)
            i++;
        while(a[j]>x)
            j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(left<j)
        quicksort(a,left,j);
    if(i<right)
        quicksort(a,i,right);
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
        quicksort(a,0,n-1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
        delete[] a;
    }
    return 0;
}
