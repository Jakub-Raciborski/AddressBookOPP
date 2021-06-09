#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {
public:
    static string konwerjsaIntNaString(int liczba);
    static char wczytajZnak();
    static string wczytajLinie();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static bool czyPlikJestPusty(fstream &plik);
};

#endif // METODYPOMOCNICZE_H
