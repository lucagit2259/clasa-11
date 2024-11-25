#include <iostream>
using namespace std;
int x[10];
int n;
int nr;
void citire(int stanga, int dreapta)
{
    int mijloc;
    if (stanga==dreapta){
        cout<<"elementul de pe poz: "<<stanga<<" :";
        cin>>x[stanga];
    }
    else{
        mijloc=(stanga+dreapta)/2;
        citire(stanga, mijloc);
        citire(mijloc+1, dreapta);
    }
}
void afisare(int stanga, int dreapta)
{
    int mijloc;
    if (stanga==dreapta){
        cout<<x[stanga]<<" ";
    }
    else{
        mijloc=(stanga+dreapta)/2;
        afisare(stanga, mijloc);
        afisare(mijloc+1, dreapta);
    }
}
int caut(int stanga, int dreapta)
{
    if(nr==x[(stanga+dreapta)/2])
    return 0;
    else if (x[stanga] < x[dreapta])
    if (nr<x[(stanga+dreapta)/2])
    return caut (stanga, (stanga+ dreapta)/2);
    else return caut ((stanga+dreapta)/2+1, dreapta);
    
    else if (x[stanga] >x[dreapta])
    if (nr>x[(stanga+dreapta)/2])
    return caut (stanga, (stanga+ dreapta)/2);
    else return caut ((stanga+dreapta)/2+1, dreapta);
    else return 1;
}

int main(){
    cout<<"cate elemente sa contina sirul?\n";
    cin>>n;
    citire(1, n);
    afisare(1, n);
    cout<<"\nce element vrei sa gasesti?\n";
    cin>>nr;
    if (caut(1, 10)==0)
    cout<<"numarul "<<nr<<" exista in sir";
    else cout<<"numarul "<<nr<<" nu exista in sir";
    return 0; 
}
