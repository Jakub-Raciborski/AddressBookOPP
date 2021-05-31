#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"

using namespace std;

class KsiazkaAdresowa{
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    UzytkownikMenadzer uzytkownikMenadzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlMenuUzytkownika();
};

#endif // KSIAZKAADRESOWA_H
