#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami {
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    vector<Adresat> adresaci;
    int idOstatniegoAdresata;

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami)
        :   NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    int pobierzidOstatniegoAdresata();

    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyczyscDane();
    void dopiszAdresataDoPliku(Adresat adresat);
    void usunWybranaLinieWPliku(const int ID_USUWANEGO_ADRESATA);
    void edytujWybranaLinieWPliku(const int ID_EDYTOWANEGO_ADRESATA, Adresat adresat);

};

#endif // PLIKZADRESATAMI
