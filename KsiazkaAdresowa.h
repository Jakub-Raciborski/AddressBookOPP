#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"

using namespace std;

class KsiazkaAdresowa{
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    UzytkownikMenadzer uzytkownikMenadzer;

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};

#endif // KSIAZKAADRESOWA_H
