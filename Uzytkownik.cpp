#include "Uzytkownik.h"

string Uzytkownik::pobierzHaslo(){
    return haslo;
}
string Uzytkownik::pobierzLogin(){
    return login;
}
int Uzytkownik::pobierzID(){
    return id;
}
void Uzytkownik::ustawID(int noweID){
    if(noweID >0)
        id=noweID;
}
void Uzytkownik::ustawLogin(string nowyLogin){
    login=nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo){
    haslo=noweHaslo;
}
