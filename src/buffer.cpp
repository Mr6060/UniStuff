#include <iostream>
using namespace std;

enum prio
{
    ALTA,
    BASSA
};

class Buffer{
    private:
        class BufferCircolare
            {
                int prox_in, prox_out, num_elem, dim_buffer;
                int *buf;
            public:
                BufferCircolare(int = 1);
                BufferCircolare(const BufferCircolare &b);
                BufferCircolare &operator=(const BufferCircolare &b);
                int estrai(int &n);
                int inserisci(int n);
                int operator!() const { return num_elem; }
                ~BufferCircolare() { delete[] buf; }
        };
        BufferCircolare bb[2];
    public:
        Buffer(int c = 1){
            if(c>1){
                bb[ALTA] = BufferCircolare(c);
                bb[BASSA] = BufferCircolare(c);
            }
        }
        //Buffer(const Buffer&);
        //Buffer& operator=(const Buffer&);
        int inserisci(int v, prio p) { return bb[p].inserisci(v); }
        int inserisci(int v){
            return (bb[ALTA].inserisci(v) || bb[BASSA].inserisci(v));
        }
        int estrai(int &v, prio p) { return bb[p].estrai(v); }
        int estrai(int &v){
            return (bb[ALTA].estrai(v) || bb[BASSA].estrai(v));
        }
        int operator%(prio p) const { return !bb[p]; }
        int operator!() const { return !bb[ALTA] + !bb[BASSA]; }
};

Buffer::BufferCircolare::BufferCircolare(const BufferCircolare& b){
    prox_in = b.prox_in;
    prox_out = b.prox_out;
    num_elem = b.num_elem;
    buf = new int[dim_buffer];
    for (int i = 0; i < dim_buffer; i++)
        buf[i] = b.buf[i];
}

Buffer::BufferCircolare& Buffer::BufferCircolare::operator=(const BufferCircolare& b){
    if (this != &b){
        prox_in = b.prox_in;
        prox_out = b.prox_out;
        num_elem = b.num_elem;
        if(dim_buffer != b.dim_buffer){
            delete[] buf;
            dim_buffer = b.dim_buffer;
            buf = new int[dim_buffer];
        }
        for (int i = 0; i < dim_buffer; i++)
            buf[i] = b.buf[i];
    }
    return *this;
}

int Buffer::BufferCircolare::estrai(int &n){
    if (num_elem > 0){
        n = buf[prox_out];
        prox_out++;
        if(prox_out == dim_buffer)
            prox_out;
        num_elem--;
        return 1;
    }
    return 0;
}

int Buffer::BufferCircolare::inserisci(int n){
    if(num_elem<dim_buffer){
        buf[prox_in] = n;
        prox_in++;
        if (prox_in == dim_buffer)
            prox_in = 0;
        num_elem++;
        return 1;
    }
    return 0;
}