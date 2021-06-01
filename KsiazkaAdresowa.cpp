#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
 : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), idZalogowanegoUzytkownika(0)
 {uzytkownikMenadzer.wczytajUzytkownikowZPliku();};

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenadzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wyswietlMenuGlowne(){
    uzytkownikMenadzer.wyswietlMenuGlowne();
}
