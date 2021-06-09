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
    char wyborZMenuGlownego;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami)
        : plikZUzytkownikami(nazwaPlikuZUzytkownikami), idZalogowanegoUzytkownika(0) {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    int pobierzIDZalogowanegoUzytkownika();

    void wypiszWszystkichUzytkownikow();
    void wyswietlMenuGlowne();
    void zmienHaslaZalogowanegoUzytkownika(); //przeniesione z prywatnych do publicznych
    void wylogujUzytkownika(); //nowe
};

#endif // UZYTKOWNIKMENADZER_H
