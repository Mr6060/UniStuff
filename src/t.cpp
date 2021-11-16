#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#define sleep(TIME) this_thread::sleep_for(chrono::seconds(TIME))

int main(){
    cout << "testing\t";
    sleep(2);
    cout << "done" << endl;

    return 0;
}