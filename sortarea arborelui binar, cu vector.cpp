#include <iostream>
using namespace std;
int n, a[30], contor;
struct nod {
    int nr, ap;
    nod *st, *dr;
};
void inserare(nod *& c, int k)
{
    if(c)
    {
        if (c->nr==k){
            c-> ap++;
        }
            else if (c->nr<k)
            inserare (c->dr, k);
            else inserare (c->st, k);
    }
        else {
            c=new nod;
            c->nr=k;
            c->ap=1;
            c->dr= c->st=NULL;
        }
}
void SRD(nod *radacina)
{
    if (radacina)
    {
        SRD(radacina->st);
         for (int i = 0; i < radacina->ap; i++) {
            a[contor++] = radacina->nr;
        }
        SRD(radacina->dr);
    }
}
int main()
{
    cout<<"cate elemente se citesc?\n";
    cin>>n;
    nod *radacina=NULL;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        inserare(radacina, a[i]);
    }
    contor=1;
    SRD (radacina);
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
}
