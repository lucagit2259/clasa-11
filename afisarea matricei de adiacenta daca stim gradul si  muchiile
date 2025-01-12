#include <iostream>
#include <fstream>
using namespace std;
int a[10] [10], n;
ifstream fin("fisier.txt");
void citire()
{   int i,j, x,y;
        fin>>n;
    for (i = 1; i <=n; i++)
        for ( j = 1; j <= n; j++)
            a[i][j]=0;
    while (fin>>x>>y)
    {
        a[x][y]=1;
        a[y][x]=1;
    }   
}
void afisare()
{ int i, j;
    for ( i = 1; i <=n; i++)
    {
        for ( j = 1; j <=n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }   
}
int main()
{
   citire();
   afisare();
   return 0;
}
/*  fisier.txt
4
1 2
2 3
3 4
4 1
*/
