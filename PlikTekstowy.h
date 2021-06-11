#ifndef PLIKTESKTOWY_H
#define PLIKTESKTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
public:
    static void usunPlik(string nazwaPlikuZRozszerzeniem);
    static void zmienNazwePliku(string staraNazwa, string nowaNazwa);
};

#endif // PLIKTESKTOWY_H
