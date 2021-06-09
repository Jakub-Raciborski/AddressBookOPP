#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::ustawIDZalogowanegoUzytkownika() {
    IDZalogowanegoUzytkownika = uzytkownikMenadzer.pobierzIDZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::wyswietlMenuGlowne() {
    while(true) {
        ustawIDZalogowanegoUzytkownika();
        if(IDZalogowanegoUzytkownika == 0)
            uzytkownikMenadzer.wyswietlMenuGlowne();
        else {
            adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, IDZalogowanegoUzytkownika);
            adresatMenadzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku();
            spytajUzytkownikaODzialanie();
        }
    }
}
void KsiazkaAdresowa::spytajUzytkownikaODzialanie() {
    char wyborZMenuUzytkownika = adresatMenadzer->wybierzOpcjeZMenuUzytkownika();
    przetwarzajDecyzjeUzytkownika(wyborZMenuUzytkownika);
}
void KsiazkaAdresowa::przetwarzajDecyzjeUzytkownika(char decyzja) {
    switch (decyzja) {
    case '1':
        adresatMenadzer->dodajAdresata();
        break;
    /*case '2':
        wyszukajAdresatowPoImieniu(adresaci);
        break;
    case '3':
        wyszukajAdresatowPoNazwisku(adresaci);
        break;*/
    case '4':
        adresatMenadzer->wyswietlWszystkichAdresatow();
        break;
    /*case '5':
        idUsunietegoAdresata = usunAdresata(adresaci);
        idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
        break;
    case '6':
        edytujAdresata(adresaci);
        break;*/
    case '7':
        uzytkownikMenadzer.zmienHaslaZalogowanegoUzytkownika();
        break;
    case '8':
        wylogujUzytkownika();
        break;
    }
}
void KsiazkaAdresowa::wylogujUzytkownika() {
    IDZalogowanegoUzytkownika = 0;
    uzytkownikMenadzer.wylogujUzytkownika();
    adresatMenadzer->wylogujUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}
