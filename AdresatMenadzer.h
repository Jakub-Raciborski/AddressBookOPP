#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include "PlikZAdresatami.h"
#include "Adresat.h"

using namespace std;

class AdresatMenadzer {
    vector<Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int nastepneWolneIDAdresata;
    MetodyPomocnicze metodyPomocnicze;
    PlikZAdresatami plikZAdresatami;

    void sprawdzNastepneWolneIDAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenadzer();
    void ustawIDZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    int pobierzIDZalogowanegoUzytkownika();

    char wybierzOpcjeZMenuUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
};

#endif // ADRESATMENADZER
