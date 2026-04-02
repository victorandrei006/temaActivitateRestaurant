#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <vector>
#include <ostream>
#include "rezervari.h"


class Angajat{
    private:
        char *nume, *prenume;
        int varsta, salariu, schimb, vechime;
        bool ospatar, bucatar;
        std::vector<Rezervari> rezervariPreluate;
    public:
        Angajat();
        Angajat(const char *numeAtribuit,const char *prenumeAtribuit ,int varsta,int salariu,int schimb, const char* angajat);
        Angajat(const Angajat &angajat);


        void setNume(const char *nume);
        void setPrenume(const char *prenume);
        void setVarsta(int varsta);
        void setSalariu(int salariu);
        void setSchimb(int schimb);
        void setOspatar(bool ospatar);
        void setBucatar(bool bucatar);
        void setVechime(int vechime);


        char* getNume() const;
        char* getPrenume() const;
        int getVarsta()const;
        int getSalariu()const;
        int getSchimb()const;
        bool getOspatar()const;
        bool getBucatar()const;
        int getVechime()const;
        void getAllAngajat() const;
        void promovareAngajat();
        void promovareAngajat(int schimbNou);
        void pensionareAngajat();
        void cresteVechimea();
        void cresteVechimea(int ani);
        void preiaRezervare(const Rezervari &rezervareNoua);
        void reviewOspatar(int nota);
        Angajat& operator=(const Angajat &nou);
        friend std::ostream& operator<<(std::ostream& os, const Angajat& angajat);        
        // friend void treceUnAn(vector<Angajat>listaAngajati);


        ~Angajat();

};
#endif