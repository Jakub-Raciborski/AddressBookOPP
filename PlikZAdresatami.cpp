#include "PlikZAdresatami.h"

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        if (daneJednegoAdresataOddzielonePionowymiKreskami != "")
            idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();
    return adresaci;
}
int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawID(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIDUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
int PlikZAdresatami::pobierzidOstatniegoAdresata() {
    return idOstatniegoAdresata;
}
void PlikZAdresatami::wyczyscDane() {
    adresaci.clear();
    idOstatniegoAdresata = 0;
}
void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (MetodyPomocnicze::czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}
string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzID()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIDUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}
void PlikZAdresatami::usunWybranaLinieWPliku(const int ID_USUWANEGO_ADRESATA) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string liniaTekstu = "", nazwaTymczasowegoPlikuZAdresatami = "plikTymczasowy.txt";
    int IDSprawdzanegoUzytkownika = 0;
    bool wykonanoPierwszyWpisDoPlikuTymczasowego = false;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami, ios::out | ios::app);

    while(getline(odczytywanyPlikTekstowy,liniaTekstu)) {
        IDSprawdzanegoUzytkownika = MetodyPomocnicze::zwrocLiczbeZnajdujacaSieNaPoczatkuZmiennejString(liniaTekstu);
        if(IDSprawdzanegoUzytkownika == ID_USUWANEGO_ADRESATA){
         if(IDSprawdzanegoUzytkownika == idOstatniegoAdresata)
                idOstatniegoAdresata--;
        continue;
        }
        else if(IDSprawdzanegoUzytkownika != ID_USUWANEGO_ADRESATA && wykonanoPierwszyWpisDoPlikuTymczasowego)
            tymczasowyPlikTekstowy<<endl<<liniaTekstu;
        else {
            tymczasowyPlikTekstowy<<liniaTekstu;
            wykonanoPierwszyWpisDoPlikuTymczasowego = true;
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    PlikTekstowy::usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    PlikTekstowy::zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
}
void PlikZAdresatami::edytujWybranaLinieWPliku(const int ID_EDYTOWANEGO_ADRESATA, Adresat adresat) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string liniaTekstu = "", nazwaTymczasowegoPlikuZAdresatami = "plikTymczasowy.txt";
    int IDSprawdzanegoUzytkownika = 0;
    bool wykonanoPierwszyWpisDoPlikuTymczasowego = false;
    const string LINIA_Z_DANYMI_ADRESATA_ODDZIELONE_PIONOWYMI_KRESKAMI = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami, ios::out | ios::app);

    while(getline(odczytywanyPlikTekstowy,liniaTekstu)) {
        IDSprawdzanegoUzytkownika = MetodyPomocnicze::zwrocLiczbeZnajdujacaSieNaPoczatkuZmiennejString(liniaTekstu);
        if(IDSprawdzanegoUzytkownika == ID_EDYTOWANEGO_ADRESATA && !wykonanoPierwszyWpisDoPlikuTymczasowego) {
            tymczasowyPlikTekstowy<<LINIA_Z_DANYMI_ADRESATA_ODDZIELONE_PIONOWYMI_KRESKAMI;
            wykonanoPierwszyWpisDoPlikuTymczasowego = true;
        }
        else if(IDSprawdzanegoUzytkownika == ID_EDYTOWANEGO_ADRESATA && wykonanoPierwszyWpisDoPlikuTymczasowego){
            tymczasowyPlikTekstowy<<endl<<LINIA_Z_DANYMI_ADRESATA_ODDZIELONE_PIONOWYMI_KRESKAMI;
        }
        else if(IDSprawdzanegoUzytkownika != ID_EDYTOWANEGO_ADRESATA && wykonanoPierwszyWpisDoPlikuTymczasowego)
            tymczasowyPlikTekstowy<<endl<<liniaTekstu;
        else {
            tymczasowyPlikTekstowy<<liniaTekstu;
            wykonanoPierwszyWpisDoPlikuTymczasowego = true;
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    PlikTekstowy::usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    PlikTekstowy::zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
}
