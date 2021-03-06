#include "UzytkownikMenadzer.h"

int UzytkownikMenadzer::pobierzIDZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

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
void UzytkownikMenadzer::wyswietlMenuGlowne() {
    while (idZalogowanegoUzytkownika == 0) {
        wybierzOpcjeZMenuGlownego();
        switch (wyborZMenuGlownego) {
        case '1':
            rejestracjaUzytkownika();
            break;
        case '2':
            idZalogowanegoUzytkownika = logowanieUzytkownika();
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
    wyborZMenuGlownego = MetodyPomocnicze::wczytajZnak();
}
int UzytkownikMenadzer::logowanieUzytkownika() {
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

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
void UzytkownikMenadzer::zmienHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzID() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenadzer::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}
