#include <iostream>
using namespace std;

enum metallo
{
    FERRO,
    RAME
};

class Barra{
    int maxRame, numRame, numFerro;
    int *barra;

public:
    Barra(int n = 1)
    {
        maxRame = (n < 1) ? 1 : n;
        numFerro = 0;
        numRame = 1;

        barra = new int[maxRame];
        barra[0] = 1;
        for (int i = 1; i < maxRame; i++)
            barra[i] = 0;
        };

        Barra &operator=(const Barra& s){
            if (this != &s){
                if(maxRame != s.maxRame){
                maxRame = s.maxRame;
                delete[] barra;
                barra = new int[maxRame];
                }
                numFerro = s.numFerro;
                numRame = s.numRame;
                for (int i = 0; i < maxRame; i++)
                    barra[i] = s.barra[i];
            }
            return *this;
        }

        int aggiungi(metallo m){
            int nuovaPosizione = numRame + numFerro + 1;
            if (m == RAME){
                if (numRame == maxRame)
                    return 0;
                barra[numRame++] = nuovaPosizione;
            }
            else
                numFerro++;
            return 1;
        }
        int elimina(int posizione, metallo& m){
            if (numRame + numFerro <= 1 || posizione > numRame + numFerro)
                return 0;
            int j;
            for (j = 0; j < numRame; j++)
                if(posizione == barra[j])
                    break;
            if (j<numRame){
                m = RAME;
                for (; j < numRame - 1; j++)
                    barra[j] = barra[j + 1];
                numRame--;
            }
            else{
                m = FERRO;
                numFerro--;
            }
            for (int i = 0; i < numRame; i++)
                if(barra[i] > posizione)
                    barra[i]--;
            return 1;
        }
        metallo operator[](int posizione) const{
            int totale = numRame + numFerro;
            posizione = (posizione > totale) ? totale : posizione;
            for (int i = 0; i < numRame; i++)
                if (posizione == barra[i])
                    return RAME;
            return FERRO;
        }

        int operator%(metallo m) const{
            if(m == RAME)
                return numRame;
            return numFerro;
        }

        friend ostream& operator<<(ostream& os, const Barra& s){
            int totale = s.numRame + s.numFerro;
            int contRame = 0;
            for (int i = 1; i <= totale; i++)
                if( (contRame < s.numRame) && (i == s.barra[contRame])){
                    cout << 'R';
                    contRame++;
                }else
                    cout << 'F';
            os << '\n';
            return os;
        }
};


int main(){
    Barra miaBarra(5);

    cout << miaBarra;

    miaBarra.aggiungi(RAME);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(RAME);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(FERRO);
    miaBarra.aggiungi(RAME);
    miaBarra.aggiungi(RAME);
    miaBarra.aggiungi(RAME);

    int success = miaBarra.aggiungi(RAME);
    if(success)
        cout << "YAY\n";
    else
        cout << "NAY\n";

    cout << miaBarra;
    metallo m;
    miaBarra.elimina(5, m);
    if (m == FERRO)
        cout << "FERRO\n";
    else
        cout << "RAME\n";
    miaBarra.elimina(2, m);
    if (m == FERRO)
        cout << "FERRO\n";
    else
        cout << "RAME\n";
    cout << miaBarra;
    return 0;
}