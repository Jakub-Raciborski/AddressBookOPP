#include <vector>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    string nazwaPlikuZUzytkownikami;
    vector<Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string konwerjsaIntNaString(int liczba);

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
