#include <iostream>
using namespace std;

void Input(int a[], int num){
    for(int i = 0; i<num; i++){
        cin >> a[i];
    }
}

int BinarySearch(int a[], int l, int r, int k, int sizeA){
    while(l <= r){
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

        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    int N, T;
    cin >> N >> T;
    int *arrayA = new int[N];
    int *arrayK = new int[T];
    Input(arrayA, N);
    Input(arrayK, T);
    for(int i = 0; i<T; i++){
        int mid = BinarySearch(arrayA, 0, N-1, arrayK[i], N);
        cout << N - mid << endl;
    }
    return 0;
}
