#include<bits/stdc++.h>
using namespace std;

void rotatematrix(int matrix[5][5])
{
    int tempmat[5][5]={0};

    for( int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            tempmat[j][4-i] = matrix[i][j];
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<tempmat[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    int matrix[5][5];

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            matrix[i][j] = 5*i + j + 1;
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<matrix[i][j];
            if(i<2) cout<<"     ";
            else cout<<"    ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    rotatematrix(matrix);
}
