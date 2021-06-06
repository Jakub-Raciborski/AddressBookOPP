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

    void ustawIDZalogowanegoUzytkownika();
    void przetwarzajDecyzjeUzytkownika(char decyzja);
    void wyswietlMenuGlowne();
    void przejdzDoMenuUzytkownika();
    void spytajUzytkownikaODzialanie();
    void wylogujUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
    ~KsiazkaAdresowa();

    void wypiszWszystkichUzytkownikow();
    void uruchomProgram();

};
#endif // KSIAZKAADRESOWA_H
