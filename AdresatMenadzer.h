#ifndef ADRESATMENADZER.H
#define ADRESATMENADZER.H

#include <iostream>
#include <vector>
#include "PlikZAdresatami.h"
#include "Adresat.h"

using namespace std;

class AdresatMenadzer{
    vector<Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idDodanegoUzytkownika;
    PlikZAdresatami plikZAdresatami;
public:
    AdresatMenadzer();
};

#endif // ADRESATMENADZER
