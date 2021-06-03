#include "UzytkownikMenadzer.h"
UzytkownikMenadzer::UzytkownikMenadzer(string nazwaPlikuZUzytkownikami)
    : plikZUzytkownikami(nazwaPlikuZUzytkownikami), idZalogowanegoUzytkownika(0) {
    wczytajUzytkownikowZPliku();
};

////////////////////////////////////////////
int UzytkownikMenadzer::pobierzIDZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
////////////////////////////////////////////

void UzytkownikMenadzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawID(pobierzIdNowegoUzytkownika());
    string login, haslo;
    do {
        cout <<"Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
bool UzytkownikMenadzer::czyIstniejeLogin(string login) {
    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout<<endl<<"Istnieje uzytkownik o takim loginie.\n";
            return true;
        }
    }
    return false;
}
int UzytkownikMenadzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}
void UzytkownikMenadzer::wypiszWszystkichUzytkownikow() {
    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++)
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
}
void UzytkownikMenadzer::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
void UzytkownikMenadzer::wyswietlMenuGlowne() {
    // while (true) { Zmiana, nowy kod w liniach 66 i 67
    //if (idZalogowanegoUzytkownika == 0) {
    while (idZalogowanegoUzytkownika == 0) {
        wybierzOpcjeZMenuGlownego();
        switch (wyborZMenuGlownego) {
        case '1':
            rejestracjaUzytkownika();
            break;
        case '2':
            idZalogowanegoUzytkownika = logowanieUzytkownika();
            /*if(idZalogowanegoUzytkownika>0) {
                adresatMenadzer.ustawIDZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                spytajUzytkownikaODzialanie();
            } Przeniesione do KsiazkaAdresowa.cpp*/
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
}
void UzytkownikMenadzer::wybierzOpcjeZMenuGlownego() {
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wyborZMenuGlownego = metodyPomocnicze.wczytajZnak();
}
int UzytkownikMenadzer::logowanieUzytkownika() {
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzID();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
/*void UzytkownikMenadzer::spytajUzytkownikaODzialanie() {
    while(adresatMenadzer.pobierzIDZalogowanegoUzytkownika()>0) {
        wyborZMenuUzytkownika = adresatMenadzer.wybierzOpcjeZMenuUzytkownika();
        przetwarzajDecyzjeUzytkownika(wyborZMenuUzytkownika);
    }
    idZalogowanegoUzytkownika = 0;
} Przeniesione do KsiazkaAdresowa*/
/*void UzytkownikMenadzer::przetwarzajDecyzjeUzytkownika(char decyzja) {
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
/* case '4':
     adresatMenadzer.wyswietlWszystkichAdresatow();
     break;*/
/*case '5':
    idUsunietegoAdresata = usunAdresata(adresaci);
    idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
    break;
case '6':
    edytujAdresata(adresaci);
    break;*/
/*case '7':
    zmianaHaslaZalogowanegoUzytkownika();
    break;
case '8':
    adresatMenadzer.wylogujUzytkownika();
    break;
}
}Przeniesione do ksiazkaAdresowa*/
void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metodyPomocnicze.wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzID() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
////////////////////////////////////////////////////////
void UzytkownikMenadzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}
////////////////////////////////////////////////////////
