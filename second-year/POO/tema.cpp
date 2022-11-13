#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class carti
{
public:
    char *autor;
    char *titlu;
    int imprumutat;
    carti(char *a, char *t, int i)
    {
        autor = new char[20];
        titlu = new char[20];
        strcpy(autor, a);
        strcpy(titlu, t);
        imprumutat = i;
    };
    virtual void display(){};
};
class tehnice : public carti
{
    int nr_exemp;
    char *limba;
    int an_ap;
    tehnice *head;
    tehnice *next;

public:
    tehnice(char *a, char *t, int i, int nr, char *l, int an) : carti(a, t, i)
    {
        head = NULL;
        limba = new char[20];
        nr_exemp = nr;
        strcpy(limba, l);
        an_ap = an;
    }
    void display();
    void adaugare();
};
class literatura : public carti
{
    char *tip_carte;
    literatura *head;
    literatura *next;

public:
    literatura(char *a, char *t, int i, char *tip) : carti(a, t, i)
    {
        head = NULL;
        tip_carte = new char[20];
        strcpy(tip_carte, tip);
    }
    void display();
    void adaugare();
};
void tehnice::adaugare()
{
    char *autor = new char[20];
    char *titlu = new char[20];
    int imprumutat, nr_exemp, an_ap;
    char *limba = new char[20];
    cout << "Dati autorul: ";
    cin >> autor;
    cout << "Dati titlul: ";
    cin >> titlu;
    cout << "Dati starea cartii(imprumutata=1/neimprumutata=0): ";
    cin >> imprumutat;
    cout << "Dati nr de exemplare: ";
    cin >> nr_exemp;
    cout << "Dati limba: ";
    cin >> limba;
    cout << "Dati anul aparitiei: ";
    cin >> an_ap;
    tehnice *p = new tehnice(autor, titlu, imprumutat, nr_exemp, limba, an_ap);
    p->next = head;
    head = p;
}
void literatura::adaugare()
{
    char *autor = new char[20];
    char *titlu = new char[20];
    int imprumutat;
    char *tip_carte = new char[20];
    cout << "Dati autorul: ";
    cin >> autor;
    cout << "Dati titlul: ";
    cin >> titlu;
    cout << "Dati starea cartii(imprumutata=1/neimprumutata=0): ";
    cin >> imprumutat;
    cout << "Dati tipul cartii: ";
    cin >> tip_carte;
    literatura *p = new literatura(autor, titlu, imprumutat, tip_carte);
    p->next = head;
    head = p;
}
void tehnice::display()
{
    tehnice *p = head;
    while (p != NULL)
    {
        cout << "----------------------------\n";
        cout << "Autor: " << p->autor << endl;
        cout << "Titlu: " << p->titlu << endl;
        cout << "Imprumutat(DA=1/NU=0): " << p->imprumutat << endl;
        cout << "Nr exemplare: " << p->nr_exemp << endl;
        cout << "Limba: " << p->limba << endl;
        cout << "An aparitie: " << p->an_ap << endl;
        cout << "----------------------------\n";
        p = p->next;
    }
}
void literatura::display()
{
    literatura *p = head;
    while (p != NULL)
    {
        cout << "------------------------------\n";
        cout << "Autor: " << p->autor << endl;
        cout << "Titlu: " << p->titlu << endl;
        cout << "Imprumutat(DA=1/NU=0): " << p->imprumutat << endl;
        cout << "Tip carte: " << p->tip_carte << endl;
        cout << "----------------------------\n";
        p = p->next;
    }
}
int main()
{
    unsigned opt;
    char autor[30];
    tehnice *c = new tehnice(" ", " ", 0, 0, " ", 0);
    literatura *o = new literatura(" ", " ", 0, " ");
    do
    {
        cout << "1.Adaugare carte tehnica.\n";
        cout << "2.Adaugare carte literatura.\n";
        cout << "3.Afisare carti tehnice.\n";
        cout << "4.Afisare carti literatura.\n";
        cout << "5.Iesire.\n";
        cout << "Opt dvs: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            c->adaugare();
            break;
        case 2:
            o->adaugare();
            break;
        case 3:
            c->display();
            break;
        case 4:
            o->display();
            break;
        case 5:
            exit(0);
        }
    } while (opt != 5);
    return 0;
}