#ifndef ADRESAT.H
#define ADRESAT.H

#include <iostream>

using namespace std;

class Adresat{
    int ID;
    string imie;
    string nazwisko;
    string email;
    string adres;
    string numerTelefonu;

public:
    void ustawID(int id);
    void ustawImie(string Imie);
    void ustawNazwisko(string Nazwisko);
    void ustawEmail(string Email);
    void ustawAdres(string Adres);
    void ustawNumerTelefonu(string NumerTelefonu);

    int pobierzID();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzEmail();
    string pobierzAdres();
    string pobierzNumerTelefonu();
};

#endif // ADRESAT
