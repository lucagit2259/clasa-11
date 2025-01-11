#include <iostream>
#include <fstream>
using namespace std;
int a[10] [10], n;
ifstream fin("fisier.txt");
void citire()
{   int i,j;
        fin>>n;
    for (i = 1; i <=n; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            fin>>a[i] [j];
        }
    }
}
int grad (int o)
{   int i, j, k=0;
    for ( i = 1; i < n; i++)
        {
            for ( j = i+1; j <=n; j++)
                {
                    if (i==o|| j==o)
                    if (a[i][j])
                    k++;
                }
        }
    return k;
}
void afisare ()
{   int i, j, k;
    for ( i = 1; i < n; i++)
        for ( j = i+1; j <=n; j++)
            if (a[i][j])
                cout<<"["<<i<<"],"<<"["<<j<<"] ";
}
void noduri_terminale()
{
   int i;
    for ( i=1; i<=n; i++){
    if (grad (i)==1)
    {
        cout<<"nodul "<<i<<" este terminal"<<"\n";
    }
    if (grad (i)==0)
    {
        cout<<"nodul "<<i<<" este izolat"<<"\n";
    }
    }
}
int main()
{
    int o;
   citire();
   cout<<"ce nod doriti sa ii aflati gradul?"<<"\n";
   cin>>o;
   cout<<"gradul nodului "<<o<<" este: "<<grad(o)<<"\n";
   noduri_terminale();
   cout<<"muchiile nodurilor grafului sunt: ";
   afisare();
   return 0;
}
/* fifier.txt
8
0 1 0 0 1 0 0 0
1 0 1 0 1 0 0 0
0 1 0 1 1 0 0 0
0 0 1 0 1 1 1 0
0 0 0 1 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0*/
