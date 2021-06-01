#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include "PlikZAdresatami.h"
#include "Adresat.h"

using namespace std;

class AdresatMenadzer{
    vector<Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int nastepneWolneIDAdresata;
    MetodyPomocnicze metodyPomocnicze;
    PlikZAdresatami plikZAdresatami;

    void wylogujUzytkownika();
    void sprawdzNastepneWolneIDAdresata();
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata();

public:
    AdresatMenadzer();
    void ustawIDZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    int pobierzIDZalogowanegoUzytkownika();

    char wybierzOpcjeZMenuUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void przetwarzajDecyzjeUzytkownika(char decyzja);

};

#endif // ADRESATMENADZER
