#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
    IDZalogowanegoUzytkownika(0){
    adresatMenadzer = NULL;
};
KsiazkaAdresowa::~KsiazkaAdresowa() {
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wyswietlMenuGlowne() {
    uzytkownikMenadzer.wyswietlMenuGlowne();
}
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
    adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, IDZalogowanegoUzytkownika);
    adresatMenadzer->wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    spytajUzytkownikaODzialanie();
}
void KsiazkaAdresowa::spytajUzytkownikaODzialanie() {
    while(adresatMenadzer->pobierzIDZalogowanegoUzytkownika()>0) {
        char wyborZMenuUzytkownika = adresatMenadzer->wybierzOpcjeZMenuUzytkownika();
        przetwarzajDecyzjeUzytkownika(wyborZMenuUzytkownika);
    }
    IDZalogowanegoUzytkownika = 0;
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
void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenadzer.wylogujUzytkownika();
    adresatMenadzer->wylogujUzytkownika();
    delete adresatMenadzer;
    //adresatMenadzer = NULL;  ZAWIESZA PROGRAM
}
