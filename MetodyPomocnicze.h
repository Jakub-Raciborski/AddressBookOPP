#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class MetodyPomocnicze{
public:
    static string konwerjsaIntNaString(int liczba);
    char wczytajZnak();
    string wczytajLinie();
};

#endif // METODYPOMOCNICZE_H
