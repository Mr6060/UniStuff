#include <iostream>
using namespace std;

class Piatto{

    friend ostream &operator<<(ostream &, const Piatto&);
    int dim;
    int *ptt;

    public:
        Piatto(int n = 1);
        Piatto(const Piatto&);
        Piatto &operator=(const Piatto&);
        int inserisci(char, int);
        int estrai(char);
        int estraiMultipro(char);
        int operator[](char c) const {
            return ((c - 'A' < 0) || (c - 'A' >= dim) ) ? 0 : ptt[c - 'A'];
        }
        int operator!() const;
        ~Piatto() { delete[] ptt; }
};

Piatto::Piatto(int n){
    dim = (n < 1) ? 1 : (n > 26 ? 26 : n);
    ptt = new int[dim];
    for (int i = 0; i < dim; i++)
        ptt[i] = 0;
}

Piatto::Piatto(const Piatto& s){
    dim = s.dim;
    ptt = new int[dim];
    for (int i = 0; i < dim; i++)
        ptt[i] = s.ptt[i];
}

Piatto &Piatto::operator=(const Piatto &s){
    if (this != &s){
        if (dim != s.dim){
            dim = s.dim;
            delete[] ptt;
            ptt = new int[dim];
        }
        for (int i = 0; i < dim; i++)
            ptt[i] = s.ptt[i];
    }
    return *this;
}

int Piatto::inserisci(char c, int v){
    
}
