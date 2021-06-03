#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
    : uzytkownikMenadzer(nazwaPlikuZUzytkownikami) {};

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenadzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wyswietlMenuGlowne() {
    uzytkownikMenadzer.wyswietlMenuGlowne();
}

/////////////////////////////////////////////
void KsiazkaAdresowa::ustawIDZalogowanegoUzytkownika() {
    IDZalogowanegoUzytkownika = uzytkownikMenadzer.pobierzIDZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::uruchomProgram() {
    while(true) {
        ustawIDZalogowanegoUzytkownika();
        if(IDZalogowanegoUzytkownika == 0)
            wyswietlMenuGlowne();
        else
            przejdzDoMenuUzytkownika();
    }
}
void KsiazkaAdresowa::przejdzDoMenuUzytkownika() {
    adresatMenadzer.ustawIDZalogowanegoUzytkownika(IDZalogowanegoUzytkownika);
    adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    spytajUzytkownikaODzialanie();
}
void KsiazkaAdresowa::spytajUzytkownikaODzialanie() {
    while(adresatMenadzer.pobierzIDZalogowanegoUzytkownika()>0) {
        char wyborZMenuUzytkownika = adresatMenadzer.wybierzOpcjeZMenuUzytkownika();
        przetwarzajDecyzjeUzytkownika(wyborZMenuUzytkownika);
    }
    IDZalogowanegoUzytkownika = 0;
}
void KsiazkaAdresowa::przetwarzajDecyzjeUzytkownika(char decyzja) {
    switch (decyzja) {
    case '1':
        adresatMenadzer.dodajAdresata();
        break;
    /*case '2':
        wyszukajAdresatowPoImieniu(adresaci);
        break;
    case '3':
        wyszukajAdresatowPoNazwisku(adresaci);
        break;*/
    case '4':
        adresatMenadzer.wyswietlWszystkichAdresatow();
        break;
    /*case '5':
        idUsunietegoAdresata = usunAdresata(adresaci);
        idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
        break;
    case '6':
        edytujAdresata(adresaci);
        break;*/
    case '7':
        uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
        break;
    case '8':
        uzytkownikMenadzer.wylogujUzytkownika();
        adresatMenadzer.wylogujUzytkownika();
        break;
    }
}
