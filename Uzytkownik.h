#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik{
    int id;
    string login, haslo;

public:
    void ustawID(int noweID);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzID();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif // UZYTKOWNIK_H
