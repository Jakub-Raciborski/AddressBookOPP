#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    int IDZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    bool nowyObiektAdresatMenadzerZostalUtworzony;

    void ustawIDZalogowanegoUzytkownika();
    void przetwarzajDecyzjeUzytkownika(char decyzja);
    void spytajUzytkownikaODzialanie();
    void wylogujUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
          IDZalogowanegoUzytkownika(0), nowyObiektAdresatMenadzerZostalUtworzony(false) {
        adresatMenadzer = NULL;
    };
    ~KsiazkaAdresowa() {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };

    void wypiszWszystkichUzytkownikow();
    void wyswietlMenuGlowne();

};
#endif // KSIAZKAADRESOWA_H
