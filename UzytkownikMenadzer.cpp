#include "UzytkownikMenadzer.h"

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
void UzytkownikMenadzer::wypiszWszystkichUzytkownikow(){
    const int ILOSC_UZYTKOWNIKOW = uzytkownicy.size();
    for(int i=0; i<ILOSC_UZYTKOWNIKOW; i++)
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
}
void UzytkownikMenadzer::wczytajUzytkownikowZPliku(){
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
