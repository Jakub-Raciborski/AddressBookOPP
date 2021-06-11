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

    void sprawdzNastepneWolneIDAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();

public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int IDZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), idZalogowanegoUzytkownika(IDZalogowanegoUzytkownika) {};
    int pobierzIDZalogowanegoUzytkownika();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    char wybierzOpcjeZMenuUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
};

#endif // ADRESATMENADZER
