#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze{
public:
    static string konwerjsaIntNaString(int liczba);
    char wczytajZnak();
    string wczytajLinie();
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    bool czyPlikJestPusty(fstream &plik);
};

#endif // METODYPOMOCNICZE_H
