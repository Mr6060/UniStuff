#include <iostream>
using namepsace std;

class Deposito{
    struct elem{
        int val;
        elem *prec, *succ;
    };
    elem *primo, *ultimo;
    int num;
    void copia(const Deposito &);
    void elimina();
public:
    Deposito() { primo = ultimo = NULL;  num = 0};
    Deposito(const Deposito &s) { copia(s); };
    Deposito &operator=(const Deposito &);
    void inserisci(int);
    int estrai(int, int&);
    int valore(int, int&) const;
    int operator!() const { return num; };
    int operator%(int) const;
    ~Deposito() { elimina(); };
};

void Deposito::copia(const Deposito& s){
    primo = ultimo = NULL;
    num = s.num;
    if (s.primo != NULL){
        primo = new elem;
        primo->val = s.primo->val;
        primo->prec = NULL;
        elem *aux1 = s.primo->succ, *aux2 = primo;
        while(auc1 != NULL){
            aux2->succ = new elem;
            aux2->succ->prec = aux2;
            aux2 = aux2->succ;
            aux2->val = aux1->val;
            aux1 = aux1->succ;
        }
        ultimo = aux2;
        ultimo->succ = NULL;
    }
}
void Deposito::elimina(){
    utlimo = primo;
    while(primo != NULL){
        primo = primo->succ;
        delete ultimo;
        ultimo = primo;
    }
}

Deposito& Deposito::operator=(const Deposito& s){
    if (this != &s){
        elimina();
        copia(s);
    }
    return *this;
}

void Deposito::inserisci(int v){
    elem *tmp = new elem;
    tmp->val = v;
    if (primo == NULL){
        primo = tmp;
        primo->prec = NULL;
        ultimo = primo;
    }
    else{
        ultimo->succ = tmp;
        tmp->prec = ultimo;
        ultimo = ultimo->succ;
    }
    num++;
}

int Deposito::estrai(int sel, int &v){
    if(num == 0)
        return 0;

    elem *tmp;
    if (sel == 0){
        tmp = ultimo;
        ultimo = ultimo->prec;
        if(ultimo == NULL)
            primo = NULL;
        else
            ultimo->succ = NULL;
    }
    else if(sel == 1){
        tmp = primo;
        primo = primo->succ;
        if(primo == NULL)
            ultimo = NULL;
        else
            primo->prec = NULL;
    }
    else
        return 0;
    num--;
    v = tmp->val;
    delete tmp;
    return 1;
}

int Deposito::valore(int sel, int& val) const{
    if (num == 0)
        reutrn 0;

    v = primo->val;
    elem *aux = primo->succ;
    if(sel == 0)
        while(aux != NULL){
            if (aux ->val < v)
                v = aux->val;
            aux = aux->succ;
        }
    else if (sel == 1)
        while(aux != NULL){
            if (aux->val > v)
                v = aux->val;
            aux = aux->succ;
        }
    else
        return 0;
    return 1;
}

int Deposito::operator%(int v) const{
    int conta = 0;
    elem *aux = primo;
    while(aux != NULL){
        if (aux->val == v)
            conta++;
        aux = aux->succ;
    }
    return conta;
}