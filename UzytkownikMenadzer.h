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
    //char wyborZMenuUzytkownika; przeniesione do KsiazkaAdresowa.cpp jako zmienna lokalna
    AdresatMenadzer adresatMenadzer;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
    void przetwarzajDecyzjeUzytkownika(char decyzja); //przeniesione do KsiazkaAdresowa

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami);
    int pobierzIDZalogowanegoUzytkownika();  //nowe

    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void wyswietlMenuGlowne();
    void spytajUzytkownikaODzialanie(); //przeniesione do KsiazkaAdresowa
    void zmianaHaslaZalogowanegoUzytkownika(); //przeniesione z prywatnych do publicznych
    void wylogujUzytkownika(); //nowe
};

#endif // UZYTKOWNIKMENADZER_H
