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
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    void sprawdzNastepneWolneIDAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int IDZalogowanegoUzytkownika);
    int pobierzIDZalogowanegoUzytkownika();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    char wybierzOpcjeZMenuUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
};

#endif // ADRESATMENADZER
