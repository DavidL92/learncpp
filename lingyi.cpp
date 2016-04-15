#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<climits>
#include<cstring>
#define max(a,b) ((a) > (b) ? a : b)
using namespace std;
const int c = 10;             //背包的容量
const int w[] = {0,2,2,6,5,4};//物品的重量，其中0号位置不使用 。 
const int v[] = {0,6,3,5,4,6};//物品对应的待加，0号位置置为空。
const int n = sizeof(w)/sizeof(w[0]) - 1 ; //n为物品的个数 
int m[6][11] = {0};
int main()
{
    for(int i = 0;i <= c;i++)
    {
        if(i < w[n])
            m[n][i] = 0;
        else
            m[n][i] = v[n];
    }
    for(int i = n - 1;i >= 1;i--)
    {
        for(int j = 0;j < 11;j++)
        {
            if(w[i] > j)
            {
                m[i][j] = m[i + 1][j];
            }
            else
            {
                m[i][j] = max(m[i + 1][j],m[i + 1][j - w[i]] + v[i]); 
            }
        }
    }
    for(int i = 0;i<6;i++)
    {
        for(int j = 0;j < 11;j++)
            cout << m[i][j] << ",";
        cout<<endl;
    }
    return 0;
}
