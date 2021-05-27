#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika() {
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

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(string login) {
    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout<<endl<<"Istnieje uzytkownik o takim loginie.\n";
            return true;
        }
    }
    return false;
}
/*void KsiazkaAdresowa::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiUzytkownika;
        } else {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}*/
/*string KsiazkaAdresowa::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += konwerjsaIntNaString(uzytkownik.id)+ '|';
    liniaZDanymiUzytkownika += uzytkownik.login + '|';
    liniaZDanymiUzytkownika += uzytkownik.haslo + '|';

    return liniaZDanymiUzytkownika;
}*/
bool KsiazkaAdresowa::czyPlikJestPusty(fstream &plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++)
            cout<<uzytkownicy[i].pobierzLogin()<<endl;
}
