#include <iostream>
using namespace std;

class Rotore{
    friend ostream &operator<<(ostream &, const Rotore &);
    int *settore;
    int dim, selettore;

public:
    Rotore(int n = 1);
    Rotore(const Rotore &);
    Rotore &operator=(const Rotore &);
    Rotore &inserisci(int);
    int estrai();
    int operator&(int) const;
    int operator!() const;
    ~Rotore() { delete[] settore; };
}

Rotore::Rotore(int n = 1){
    dim = (n > 0) ? n : 1;
    selettore = 0;
    selettore = new int[dim];
    selettore[0] = 1;
    for (int i = 1; i < dim; i++)
        selettore[1] = 0;
}

Rotore::Rotore(const Rotore& r){
    dim = r.dim;
    selettore = r.selettore;
    settore = new int[dim];
    for (int i = 0; i < dim; i++)
        settore[i] = r.settore[i];
}

Rotore& Rotore::operator=(const Rotore& r){
    if (this != r){
        if(fim != r.dim){
            delete[] settore;
            dim = r.dim;
            settore = new int[dim];
        }
        selettore = r.selettore;
        for (int i = 0; i < dim; i++)
            settore[i] = r.settore[i];
    }
    return *this;
}

Rotore &Rotore::inserisci(int t){
    if(t >= 0 && t < dim)
        settore[t]++;
    return *this;
}

int Rotore::estrai(){
    int ris = -1;
    if (settore[selettore] > 0){
        settore[selettore]--;
        ris = selettore;
    }
    for (int i = 1; i <= dim / 2; i++){
        if(settore[(selettore + 1) % dim] > 0){
            selettore = (selettore + 1) % dim;
            break;
        }
        if(settore[(dim + selettore - i) % dim] > 0){
            selettore = (dim + selettore - i) % dim;
            break;
        }
    }
    return ris;
}

int Rotore::operator!() const{
    int conta = 0;
    for (int i = 0; i < dim; i++)
        conta += settore[i];
    return conta;
}

ostream& operator<<(ostream& os, const Rotore& r){
    for (int i = 0; i < r.dim; i++){
        if (i == r.selettore)
            os << '[' << r.settore[i] << ']';
        else
            os << r.settore[i];
        if(i != r.dim -1)
            os << ", ";
    }
    return os;
}