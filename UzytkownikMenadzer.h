#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "AdresatMenadzer.h"

using namespace std;

class UzytkownikMenadzer {
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;
    MetodyPomocnicze metodyPomocnicze;
    char wyborZMenuGlownego;
    char wyborZMenuUzytkownika;
    AdresatMenadzer adresatMenadzer;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
    void przetwarzajDecyzjeUzytkownika(char decyzja);
    void zmianaHaslaZalogowanegoUzytkownika();

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami);
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void wyswietlMenuGlowne();
    void spytajUzytkownikaODzialanie();
};

#endif // UZYTKOWNIKMENADZER_H
