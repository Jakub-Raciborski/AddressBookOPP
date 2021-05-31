#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include <vector>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenadzer{
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;
    MetodyPomocnicze metodyPomocnicze;
    char wyborZMenuGlownego;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami);
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void wyswietlMenuGlowne();
};

#endif // UZYTKOWNIKMENADZER_H
