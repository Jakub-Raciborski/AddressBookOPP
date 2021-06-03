#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer adresatMenadzer;
    int IDZalogowanegoUzytkownika;

    void ustawIDZalogowanegoUzytkownika();
    void przetwarzajDecyzjeUzytkownika(char decyzja);
    void wyswietlMenuGlowne();
    void przejdzDoMenuUzytkownika();
    void spytajUzytkownikaODzialanie();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);

    void wypiszWszystkichUzytkownikow();
    void uruchomProgram();

};
#endif // KSIAZKAADRESOWA_H
