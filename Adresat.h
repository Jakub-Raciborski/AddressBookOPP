#ifndef ADRESAT.H
#define ADRESAT.H

#include <iostream>

using namespace std;

class Adresat{
    int ID;
    int IDUzytkownika;
    string imie;
    string nazwisko;
    string email;
    string adres;
    string numerTelefonu;

public:
    void ustawID(int id);
    void ustawIDUzytkownika(int idUzytkownika);
    void ustawImie(string Imie);
    void ustawNazwisko(string Nazwisko);
    void ustawEmail(string Email);
    void ustawAdres(string Adres);
    void ustawNumerTelefonu(string NumerTelefonu);

    int pobierzID();
    int pobierzIDUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzEmail();
    string pobierzAdres();
    string pobierzNumerTelefonu();
};

#endif // ADRESAT
