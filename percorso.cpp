#include <iostream>
#include <stdlib.h>
using namespace std;

void errore(const char* s){
    cerr << "Percorso: " << s << '\n';
    exit(1);
}

enum colore{
    BIANCO,
    NERO
};

class Percorso{
    friend ostream &operator<<(ostream &os, const Percorso&);

    class Casella{
        enum stato
        {
            LIBERA,
            OCCUPATA
        } st;
        colore col;
    public:
        Casella(colore c = BIANCO) { col = c; st = LIBERA;}
        void cambiaColore(){col = (col == BIANCO) ? NERO : BIANCO};
        void occupa() { st = OCCUPATA; }
        void libera() { st = LIBERA; }
        int seiOccupata() const { return st == OCCUPATA; }
        colore qualeColore() const { return col; }
    };

    Casella *cc;
    int lunghezza;
    int avanza(int);
public:
    Percorso(int = 10, colore = BIANCO);
    Percorso(const Percorso &);
    Percorso& operator=(const Percorso&);
    Percorso &immetti(colore);
    Percorso &cambiaColore(int);
    inline ~Percorso() {delete[] cc};
}

int Percorso::avanza(int i){
    int j;
    for (j = i + 1; j < lunghezza && !cc[j].seiOccupata() && cc[i].qualeColore() == cc[j].qualeColore(); j++);
    return j - 1;
}

Percorso::Percorso(int n = 10, colore = BIANCO){
    if (n < 1)
        errore("Lunghezza errata");
    lunghezza = n;
    cc = new Casella[lunghezza];
    if(c == NERO)
        for (int i = 0; i < lunghezza; i++)
            cc[i].cambiaColore();
}

Percorso::Percorso(const Percorso& p){
    lunghezza = p.lunghezza;
    cc = new Casella[lunghezza];
    for (int i = 0; i < lunghezza; i++)
        cc[i] = p.cc[i];
}

Percorso& Percorso::operator=(const Percorso& p){
    if(this != &p){
        delete[] cc;
        lunghezza = p.lunghezza;
        cc = new Casella[lunghezza];
        for (int i = 0; i < lunghezza; i++)
            cc[i] = p.cc[1];
    }
    return *this;
}

Percorso &Percorso::immetti(colore c){
    if(!cc[0].seiOccupata() && cc[0].qualeColore() == c){
        int i = avanza(0);
        if (i < lunghezza - 1)
            cc[i].occupa();
    }
    return *this;
}

Percorso& Percorso::cambiaColore(int i){
    if ( i < 1 || i > lunghezza)
        errore("Numero di casella errato");
    --i;
    if(!cc[i].seiOccupata()){
        cc[i].cambiaColore();
        for (int j = i - 1; j >= 0 && cc[j].seiOccupata() && cc[i].qualeColore() == cc[j].qualeColore(); j--){
            cc[j].libera();
            int k = avanza(j);
            if(k < lunghezza - 1)
                cc[k].occupa();
        }
    }
    return *this;
}

ostream& operator<<(ostream& os, Percorso& p){
    for (int i = 0; i < p.lunghezza; i++)
        if(p.cc[i].seiOccupata())
            if(p.cc[i].qualeColore() == BIANCO)
                os << 'B';
            else
                os << 'N';
        else
            if(p.cc[i].qualeColore() == BIANCO)
                os << 'b';
            else
                os << 'n';
    return os;
}
