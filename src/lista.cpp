#include <iostream>

using namespace std;

struct elemento{
    int info;
    elemento* ptr;
};

typedef elemento* Lista;

void inserisciInTesta(Lista& s, int val);
int contaElementi(Lista s);

inline void inizializza(Lista& s){
    s = NULL;
}

void inserisciInTesta(Lista& s, int val){
    Lista q = new elemento;
    q->info = val;
    q->ptr = s;
    s = q;
}

void inserisciPerPosizione(Lista& s, int val, int pos){
    elemento* q = new elemento;
    q->info = val;
    if (pos <= 1 || s == NULL){
        q->ptr = s;
        s = q;
        return;
    }
    elemento* p = s;

    for (int j = 1; j <= pos - 2 && p->ptr != NULL; j++)
        p = p->ptr;
    q->ptr = p->ptr;
    p->ptr = q;
}

int estraiPerPosizione(Lista&s, int& val, int pos){
    if (s == NULL) return 0;
    if (pos <= 1 || s->ptr == NULL){
        elemento* q = s;
        val = s->info;
        s = s->ptr;
        delete q;
        return 1;
    }
    elemento *p = s, *q = s->ptr;
    for (int j = 1; j <= pos - 2 && q->ptr != NULL; j++){
        p = p->ptr;
        q = q->ptr;
    }

    val = q->info;
    p->ptr = q->ptr;
    delete q;
    return 1;
}

int estraiInTesta(Lista& s, int& val){
    if (s == NULL)
        return 0;

    elemento* q = s;
    val = s->info;
    s = s->ptr;
    delete q;
    return 1;
}


void visualizza(Lista s){
    cout << '<';
    if (s == NULL){
        cout << '>';
        return;
    }
    elemento* q = s;
    cout << q->info;
    q = q->ptr;
    while (q != NULL){
        cout << ", ";
        cout << q->info;
        q = q->ptr;
    }
    cout << ">\t";
    int elementi = contaElementi(s);
    cout << '[' <<elementi << " Elementi]" << endl;
}

int contaElementi(Lista s){
    if(s == NULL)
        return 0;

    elemento* q = s;
    int c = 0;
    while( q != NULL){
        c++;
        q = q->ptr;
    }
    return c;
}

void distruggi(Lista& s){
    elemento* q;
    
    while(s != NULL){
        visualizza(s);
        q = s->ptr;
        delete s;
        s = q;
    }
}

void reverse(Lista& s){
    if(s == NULL){
        cout << "Lista vuota"<<endl;
        return;
    }
    elemento *temp = NULL;
    elemento *prev = NULL;
    elemento *current = s;

    while(current != NULL){
        temp = current->ptr;
        current->ptr = prev;
        prev = current;
        current = temp;
    }
    s = prev;
}

int main(){
    char cmd;
    Lista lista;
    inizializza(lista);
    visualizza(lista);
    cout << endl;
    while(1){
        
        cout << "t: Inserisci in testa\np: Inserisci per posizione\nT: Estrai in testa\nP: Estrai per posizione\nInserire un comando: "; 
        cin >> cmd;
        if (cmd == '-')
            break;
        
        int val, pos, ok;
        switch(cmd){
            case 't':
                cin >> val;
                inserisciInTesta(lista, val);
                break;
            case 'p':
                cin >> val >> pos;
                inserisciPerPosizione(lista, val, pos);
                break;
            case 'T':
                ok = estraiInTesta(lista, val);
                if (ok)
                    cout << "Estratto " << val << endl;
                else
                    cout << "Estrazione fallita"<< endl;
                break;
            case 'P':
                cin >> pos; 
                ok = estraiPerPosizione(lista, val, pos);
                if (ok)
                    cout << "Estratto " << val << endl;
                else   
                    cout << "Estrazione fallita" << endl;
            case 'r':
                reverse(lista);
                break;
        }
        visualizza(lista);
        cout << endl;
    }
    distruggi(lista);
    return 0;
}