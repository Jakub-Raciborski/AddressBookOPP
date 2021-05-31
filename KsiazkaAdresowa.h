#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"

using namespace std;

class KsiazkaAdresowa{
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    int idZalogowanegoUzytkownika;
    UzytkownikMenadzer uzytkownikMenadzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlMenuGlowne();
};

#endif // KSIAZKAADRESOWA_H
