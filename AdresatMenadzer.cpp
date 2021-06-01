#include "AdresatMenadzer.h"

AdresatMenadzer::AdresatMenadzer() {
    PlikZAdresatami plikZAdresatami;
};

void AdresatMenadzer::ustawIDZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA) {
    idZalogowanegoUzytkownika = ID_ZALOGOWANEGO_UZYTKOWNIKA;
}
int AdresatMenadzer::pobierzIDZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
char AdresatMenadzer::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    //cout << "2. Wyszukaj po imieniu" << endl;
    //cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    //cout << "5. Usun adresata" << endl;
    //cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}
void AdresatMenadzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    nastepneWolneIDAdresata = plikZAdresatami.pobierzidOstatniegoAdresata() + 1;
}
void AdresatMenadzer::przetwarzajDecyzjeUzytkownika(char decyzja) {
    switch (decyzja) {
    case '1':
        dodajAdresata();
        break;
    /*case '2':
        wyszukajAdresatowPoImieniu(adresaci);
        break;
    case '3':
        wyszukajAdresatowPoNazwisku(adresaci);
        break;*/
    case '4':
        //wyswietlWszystkichAdresatow(adresaci);
        break;
    /*case '5':
        idUsunietegoAdresata = usunAdresata(adresaci);
        idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
        break;
    case '6':
        edytujAdresata(adresaci);
        break;*/
    case '7':
        // zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
        break;
    case '8':
        wylogujUzytkownika();
        break;
    }
}
void AdresatMenadzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
    adresaci.clear();
    plikZAdresatami.wyczyscDane();
}
void AdresatMenadzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    cout<<adresat.pobierzImie()<<" "<<adresat.pobierzID()<<endl;
    system("pause");

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}
Adresat AdresatMenadzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    string imie,nazwisko;

    adresat.ustawID(nastepneWolneIDAdresata++);
    adresat.ustawIDUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();
    imie = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    nazwisko = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}
