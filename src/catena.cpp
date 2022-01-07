#include <iostream>
using namespace std;

enum metallo
{
    RAME,
    ARGENTO,
    ORO
};

class Catena{

    friend ostream& operator<<(ostream& os, const Catena& c);
    struct elemento{
        metallo metallo;
        elemento *next;
    };
    elemento *testa;
    elemento *coda;
    int num;
    void copia(const Catena& s);
    void elimina();

public:
    Catena()
    {
        testa = coda = NULL;
        num = 0;
    };

    Catena(const Catena &s) {  copia(s); };
    Catena& operator=(const Catena&);
    void inserisci(metallo m);
    int estrai();
    int estrai(metallo m);
    int operator%(metallo m) const;
    int operator!() const { return num; };

    ~Catena () { elimina(); };
};
void Catena::copia(const Catena &s)
    {
        num = 0;
        testa = coda = NULL;
        if (s.testa != NULL)
        {
            testa = new elemento;
            testa->metallo = s.testa->metallo;
            num++;
            elemento *tmp = testa, *aux = s.testa->next;
            while (aux != NULL)
            {
                tmp->next = new elemento;
                tmp = tmp->next;
                tmp->metallo = aux->metallo;
                aux = aux->next;
                num++;
            }
            coda = tmp;
            tmp->next = NULL;
        }
}

void Catena::elimina(){
    elemento *tmp = testa;
    while(testa != NULL){
        testa = testa->next;
        delete tmp;
        tmp = testa;
    }
}

Catena &Catena::operator=(const Catena &s){
    if(this != &s){
        elimina();
        copia(s);
    }
    return *this;
}

void Catena::inserisci(metallo m){
    elemento *tmp = new elemento;
    tmp->metallo = m;
    tmp->next = NULL;
    if (num == 0)
        testa = coda = tmp;
    else{
        coda->next = tmp;
        coda = coda->next;
    }
    num++;
}

int Catena::estrai(){
    if (num == 0)
        return 0;
    elemento *tmp = testa;
    testa = testa->next;
    delete tmp;
    num--;
    return 1;
}

int Catena::estrai(metallo m){
    if(testa == NULL)
        return 0;
    elemento *tmp, *prec;
    for (tmp = testa; tmp != NULL && tmp->metallo != m; tmp = tmp->next)
        prec = tmp;
    if (tmp == NULL)
        return 0;
    if(tmp == testa)
        testa = tmp->next;
    else
        prec->next = tmp->next;
    delete tmp;
    num--;
    return 1;
}

int Catena::operator%(metallo m) const{
    int totale = 0;
    for (elemento *aux = testa; aux != NULL; aux = aux->next)
        if(aux->metallo == m)
            totale++;
    return totale;
}

ostream &operator<<(ostream &os, const Catena &s){
    Catena::elemento *tmp;
    for (tmp = s.testa; tmp != NULL; tmp=tmp->next){
        if(tmp->metallo == RAME)
            os << 'R';
        else if(tmp->metallo == ARGENTO)
            os << 'A';
        else
            os << 'O';
    }
    os << '\n';
    return os;
}

int main(){
    Catena c;
    c.inserisci(ARGENTO);
    c.inserisci(RAME);
    c.inserisci(ORO);
    c.inserisci(ARGENTO);
    c.inserisci(ARGENTO);
    c.inserisci(ARGENTO);
    c.inserisci(ORO);
    c.inserisci(ARGENTO);
    c.inserisci(ORO);
    c.inserisci(ARGENTO);
    c.inserisci(RAME);
    c.inserisci(ARGENTO);
    c.inserisci(ORO);
    c.inserisci(ARGENTO);
    cout << c % ORO << '\n';
    cout << c;
    cout << !c << '\n';

    c.estrai(ORO);

    cout << !c << '\n';
    cout << c;
    cout << c % ORO << '\n';
    c.estrai();
    c.estrai();
    cout << c % ARGENTO << '\n';
    cout << c << ' ' << !c << '\n';
}