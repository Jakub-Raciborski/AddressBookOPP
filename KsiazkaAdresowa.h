#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer adresatMenadzer; //nowe
    int IDZalogowanegoUzytkownika; //nowe

    void ustawIDZalogowanegoUzytkownika(); //nowe
    void przetwarzajDecyzjeUzytkownika(char decyzja); //nowe, skopiowane z UzytkownikMenadzer

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami);

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlMenuGlowne(); //moze do prywatnych
    void uruchomProgram(); //nowe
    void przejdzDoMenuUzytkownika(); //nowe, mo¿e do prywatnych
    void spytajUzytkownikaODzialanie(); //nowe, skopiowane z UzytkownikMenadzer

};
#endif // KSIAZKAADRESOWA_H
