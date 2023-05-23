#include <iostream>

using namespace std;

void Input(int a[], int num){
    for(int i = 0; i<num; i++){
        cin >> a[i];
    }
}

int BinarySearch(int a[], int l, int r, int k, int sizeA){
    if(l <= r){
        int mid = (l+r)/2;
        if(mid == sizeA) return mid;
        if(a[mid] == k){
            while(a[mid-1] == k){
                    mid--;
            }
            return mid;
        }
        else if(a[mid] > k){
            r = mid - 1;
            return BinarySearch(a, l, r, k, sizeA);
        }
        else{
            l = mid + 1;
            return BinarySearch(a, l, r, k, sizeA);
        }
    }
    else{
        return -1;
    }
}

int allocateLastIndex(int a[], int firstIndex, int k){
    while(a[firstIndex+1] == k)
        firstIndex++;
    int lastIndex = firstIndex;
    return lastIndex;
}

int main(){
    int N, T;
    cin >> N >> T;
    int *arrayA = new int[N];
    int *arrayK = new int[T];
    Input(arrayA, N);
    Input(arrayK, T);
    for(int i = 0; i<T; i++){
        int firstIndex = BinarySearch(arrayA, 0, N-1, arrayK[i], N);
        if(firstIndex == -1)
            cout << endl << -1;
        else{
            int lastIndex = allocateLastIndex(arrayA, firstIndex, arrayK[i]);
            cout << endl;
            cout << lastIndex-firstIndex+1 << " " << firstIndex+1 << " " << lastIndex+1;
        }
    }
    return 0;
}
