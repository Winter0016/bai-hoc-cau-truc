#include <iostream>
#include <string>

using namespace std;

void output1(string b[],int &hihi,int n)
{
    cout<<"#STEP "<<hihi<<":"<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    hihi=hihi+1;
}

int binarySearch(float a[],string b[],int n,float haha)
{
    int left =0;int right=n-1;int mid;
    while(left<=right){
        mid=(left+right)/2;
        cout<<"[Left="<<left+1<<",Mid="<<mid+1<<",Right="<<right+1<<"]";
        cout<<endl;
        if(a[mid]==haha){
            while(a[mid-1]==haha){
                right=mid-1;
                mid=(left+right)/2;
                if(left>right)
                    break;
                cout<<"[Left ="<<left+1<<", Mid="<<mid+1<<",Right="<<right+1<<"]";
                cout<<endl;
                if(a[mid]<haha)
                    left=mid+1;
                mid--;
            }
            mid=(left+right)/2;
            cout<<"[Left ="<<left+1<<", Mid="<<mid+1<<",Right="<<right+1<<"]";
            cout<<endl;
            return mid;
        }
        else{
            if(a[mid]<haha)
                left=mid+1;
            else
                right=mid-1;
        }
    }
    return 0;
}

int main() {
    int n;
    float x;
    float y;
    cin >> n;

    if (n == 0) {
        cout << "Empty list" << endl;
    } else {
        float* a = new float[n];
        string* b = new string[n];
        float huhu;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            int x2=x;
            int y2=y;
            huhu = x / y;
            a[i] = huhu;
            b[i] = to_string(x2) + "/" + to_string(y2);
        }
        float z;float x;
        cin>> z>> x;
        float haha=z/x;
        int hihi=1;
        for(int i = 0 ;i<n-1;i++){
            int Min=i;
            for(int z =i+1;z<n;z++){
                if(a[z]<a[Min])
                    Min=z;
            }
            swap(a[i],a[Min]);
            swap(b[i],b[Min]);
            output1(b,hihi,n);
        }
        int found=binarySearch(a,b,n,haha);
        if(found==0){
            cout<<"Khong tim thay phan so bang X";
        }
        else{
            cout<<"Tim thay phan so bang X tai vi tri be nhat la: "<<found+1;
        }
    }
    return 0;
}
