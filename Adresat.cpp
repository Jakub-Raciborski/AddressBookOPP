#include "Adresat.h"

void Adresat::ustawID(int id) {
    ID = id;
}
void Adresat::ustawIDUzytkownika(int idUzytkownika) {
    IDUzytkownika = idUzytkownika;
}
void Adresat::ustawImie(string Imie) {
    imie=Imie;
}
void Adresat::ustawNazwisko(string Nazwisko) {
    nazwisko = Nazwisko;
}
void Adresat::ustawAdres(string Adres) {
    adres = Adres;
}
void Adresat::ustawNumerTelefonu(string NumerTelefonu) {
    numerTelefonu = NumerTelefonu;
}
void Adresat::ustawEmail(string Email) {
    email = Email;
}
int Adresat::pobierzID() {
    return ID;
};
int Adresat::pobierzIDUzytkownika() {
    return IDUzytkownika;
}
string Adresat::pobierzImie() {
    return imie;
}
string Adresat::pobierzNazwisko() {
    return nazwisko;
}
string Adresat::pobierzEmail() {
    return email;
}
string Adresat::pobierzAdres() {
    return adres;
}
string Adresat::pobierzNumerTelefonu() {
    return numerTelefonu;
}
