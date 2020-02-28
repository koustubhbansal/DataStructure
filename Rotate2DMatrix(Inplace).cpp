#include<bits/stdc++.h>
using namespace std;

void rotatematrix(int matrix[5][5], int i, int j)
{
    if (i==j || i>j)
        return;
    int temp, next1, next2;
    int current1, current2;
    for(int a=i; a<j; a++)
    {
        current1 = i;
        current2 = a;
        for(int t=0; t<3; t++)
        {
            next1 = current2;
            next2 = i+j-current1;
            temp = matrix[next1][next2];
            matrix[next1][next2] = matrix[i][a];
            matrix[i][a] = temp;
            current1 = next1;
            current2 = next2;
        }
    }
    rotatematrix(matrix, i+1, j-1);
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

    rotatematrix(matrix, 0, 4);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
