#include<bits/stdc++.h>
using namespace std;

int maxsum(int n, int a[])
{
    int b[n];
    b[n-1] = a[n-1];
    int sum = b[n-1];

    for(int i=n-2; i>=0; i--)
    {
        b[i] = max(a[i], a[i]+b[i+1]);
        if(b[i]>sum)
            sum = b[i];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<maxsum(n, a)<<endl;
}
