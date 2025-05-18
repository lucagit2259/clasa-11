#include <iostream>
#include <fstream>

using namespace std;
struct Nod
{
    int info;
    Nod *stanga, *dreapta;
};

void create(Nod *&radacina, ifstream &f)
{
    int value;
    f >> value;

    if (value == 0)
        radacina = NULL;
    else
    {
        radacina = new Nod;
        radacina->info = value;
        create(radacina->stanga, f); // stanga child
        create(radacina->dreapta, f);
    }
}

void RSD(Nod *radacina)
{
    if (radacina)
    {
        cout << radacina->info << " ";
        RSD(radacina->stanga);
        RSD(radacina->dreapta);
    }
}

void SRD(Nod *radacina)
{
    if (radacina)
    {
        SRD(radacina->stanga);
        cout << radacina->info << " ";
        SRD(radacina->dreapta);
    }
}

void SDR(Nod *radacina)
{
    if (radacina)
    {
        SDR(radacina->stanga);
        SDR(radacina->dreapta);
        cout << radacina->info << " ";
    }
}

int inaltine(Nod *radacina)
{
    int x, y;
    if (radacina == nullptr)
        return -1;
    else
    {
        x = inaltine(radacina->stanga);
        y = inaltine(radacina->dreapta);
        if (x < y)
            return y + 1;
        else
            return x + 1;
    }
}

int numara_nodurile(Nod *radacina, int &n)
{
    if (radacina)
    {
        n++;
        numara_nodurile(radacina->stanga, n);
        numara_nodurile(radacina->dreapta, n);
        return n;
    }
}

int strict(Nod *radacina)
{
    int x, y;
    if (radacina == nullptr)
        return 1;
    else
    {
        bool conditia1 = radacina->stanga == nullptr && radacina->dreapta != nullptr;
        bool conditia2 = radacina->stanga != nullptr && radacina->dreapta == nullptr;
        if (conditia1 || conditia2)
            return 0;
        else
            return strict(radacina->stanga) && strict(radacina->dreapta);
    }
}

int echilibrat(Nod *radacina)
{
    int stanga_n = 0, dreapta_n = 0;
    if (radacina == nullptr)
        return 1;
    else
    {
        stanga_n = numara_nodurile(radacina->stanga, stanga_n);
        dreapta_n = numara_nodurile(radacina->dreapta, dreapta_n);

        if (abs(stanga_n - dreapta_n) > 1)
            return 0;
        return echilibrat(radacina->stanga) && echilibrat(radacina->dreapta);
    }
}
int terminal(Nod *radacina)
{
    if (radacina == nullptr)
        return 0;

    if (radacina->stanga == nullptr && radacina->dreapta == nullptr)
        return 1;

    int smt = terminal(radacina->stanga);
    int smt2 = terminal(radacina->dreapta);

    return smt + smt2;
}

void scrie_terminal(Nod* radacina)
{
    if (radacina == nullptr)
        return;

    if (radacina->stanga == nullptr && radacina->dreapta == nullptr)
        cout<<radacina->info<<" ";

    scrie_terminal(radacina->stanga);
    scrie_terminal(radacina->dreapta);



}


int main()
{
    ifstream f("../text/bfs.txt");
    ifstream file("../text/cost.txt");

    if (!f)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Nod *radacina = nullptr;
    Nod *radacina2 = nullptr;
    create(radacina, f);
    create(radacina2, file);

    cout << "Preorder Traversal (RSD): ";
    RSD(radacina);
    cout << endl;

    cout << "Inorder Traversal (SRD): ";
    SRD(radacina);
    cout << endl;

    cout << "Postorder Traversal (SDR): ";
    SDR(radacina);
    cout << endl;

    cout << "Inaltimea arborelui este: " << inaltine(radacina);

    if (strict(radacina))
        cout << "\n arborele este binar strict";
    else
        cout << "\narborele nu este binar strict";

    int n = 0;
    n = numara_nodurile(radacina, n);
    cout << "\nnumar de noduri: " << n;
    f.close();

    if (echilibrat(radacina))
        cout << "\nThe tree is balanced." << endl;
    else
        cout << "\nThe tree is not balanced." << endl;

    cout << "\nsunt " << terminal(radacina) << " noduri terminale";

    cout<<"\nse vor scrie nodurile terminale ";
    scrie_terminal(radacina);
    return 0;
}

/*

1
2 
4 
0
0
5
7
0
0
0
3 
0 
6 
8 
0
0
9
0
0
*/
