#include <iostream>

using namespace std;

 int n,a[100],s=0,p=1;

void citire(int i)
{
    cout<<i<<":";
    cin>>a[i];
    if(i!=n-1) citire(i+1);
}

void scrie(int i)
{
    cout<<a[i]<<"  ";
    if(i!=n-1) scrie(i+1);
}

void suma(int i)
{
    if(i%2==0)  s+=a[i];
    if (i!=n-1) suma(i+1);
}

void prod(int i)
{
    if (i%2!=0) p*=a[i];
    if (i!=n-1) prod(i+1);
}

int cmmdc(int a,int b)
{
    if(b==0) return a;
    if(a==0) return b;
    if(b!=0 && a!=0) return (cmmdc(b,a%b));
}

int maxim(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int sum_c(int a)
{
    if(a!=0) return a%10+sum_c(a/10);
}
int main()
{
    s=0;
    p=1;
    cout<<" vectorul de pozitia: "; cin>>n;
    citire(0);
    scrie(0);
    suma(0);
    prod(0);
     cout<<"suma elem de pe pozitiile pare din vect este egala cu:"<<s<<endl;
     cout<<"srodusul elem de pe pozitiile pare din vect este egal cu:"<<p<<endl;
     cout<<"cmmdc dintre "<<s<<" si "<<p<<" este:"<<cmmdc(s,p)<<endl;
     cout<<"maximul dintre "<<s<<" si "<<p<<" este "<<maxim(s,p)<<endl;
     cout<<"suma cifrelor lui "<<p<<" este:"<< sum_c(p);
    return 0;
}