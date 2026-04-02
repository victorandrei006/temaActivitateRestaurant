#include "angajati.h"
#include <cstring>
#include "meniu.h"
#include "rezervari.h"
#include <vector>
#include <iostream>
using namespace std;

//constructor default

Angajat::Angajat(){
    varsta=0; salariu=0; schimb=0; vechime=0; nume = nullptr; prenume = nullptr; ospatar=false; bucatar=false;                       
}


 //constructor cu parametrii

Angajat::Angajat(const char *numeAtribuit,const char *prenumeAtribuit ,int varsta,int salariu,int schimb, const char* angajat){                 
        
    this->nume = new char[strlen(numeAtribuit)+1];
    strcpy(this->nume, numeAtribuit);
    
    this->prenume = new char[strlen(prenumeAtribuit)+1];
    strcpy(this->prenume, prenumeAtribuit);
    
    this->varsta = varsta;
    
    this->salariu = salariu;
    
    this->schimb = schimb;
    
    this->vechime = 0;
    
    if(strcmp(angajat, "ospatar") == 0){
        this->ospatar = true;
        this->bucatar = false;
    }
    else{
        this->ospatar = false;
        this->bucatar = true;
    }
}


//constructor de copiere   

Angajat::Angajat(const Angajat &angajat){                                                                                                        
    this->nume = new char[strlen(angajat.nume)+1];
    strcpy(this->nume, angajat.nume);

    this->prenume = new char[strlen(angajat.prenume)+1];
    strcpy(this->prenume, angajat.prenume);

    this->varsta = angajat.varsta;
    this->salariu = angajat.salariu;
    this->schimb = angajat.schimb;
    this->ospatar = angajat.ospatar;
    this->bucatar = angajat.bucatar;
}

    //setteri

       void Angajat::setNume(const char *nume_set){

        if (this->nume != nullptr) {
            delete[] this->nume;
        }

        this->nume = new char[strlen(nume_set) + 1];
        strcpy(this->nume, nume_set);
        }

        void Angajat::setPrenume(const char *prenume_set){

            if (this->prenume != nullptr) {
                delete[] this->prenume;
            }

            this->prenume = new char[strlen(prenume_set) + 1];
            strcpy(this->prenume, prenume_set);
        }
        void Angajat::setVarsta(int varsta){
            this->varsta = varsta;
            this->vechime+= varsta;
        }
        void Angajat::setSalariu(int salariu){
            this->salariu = salariu;
        }
        void Angajat::setSchimb(int schimb){
            this->schimb = schimb;
        }
        void Angajat::setOspatar(bool ospatar){
            this->ospatar = ospatar;
        }
        void Angajat::setBucatar(bool bucatar){
            this->bucatar = bucatar;
        }
        void Angajat::setVechime(int vechime){
            this->vechime = vechime;
            this->varsta += vechime;
        }


    //getteri


        char* Angajat::getNume() const{
            return this->nume;
        }

        char* Angajat::getPrenume() const{
            return this->prenume;
        }
        int Angajat::getVarsta()const{
            return varsta;
        }
        int Angajat::getSalariu()const{
            return salariu;
        }
        int Angajat::getSchimb()const{
            return schimb;
        }
        bool Angajat::getOspatar()const{
            return ospatar;
        }
        bool Angajat::getBucatar()const{
            return bucatar;
        }
        int Angajat::getVechime()const{
            return vechime;
        }

        void Angajat::getAllAngajat()const{

            cout <<"------------------------------" << endl;
            cout << "Nume: " << nume << endl;
            cout << "Prenume: " << prenume << endl;
            cout << "Varsta: " << varsta << endl;
            cout << "Salariu: " << salariu << endl;
            cout << "Schimb: " << schimb << endl;
            cout << "Vechime: " << vechime << endl;
            if(ospatar){
                cout << "Angajatul este ospatar." << endl;
            }
            else if(bucatar){
                cout << "Angajatul este bucatar." << endl;
            }
            cout<< "------------------------------" << endl<<endl;
        }

        //functii
        
        void Angajat::promovareAngajat(){
            if (this->vechime >= 5) {
                if(this->ospatar){
                    this->salariu += 1000;
                }
                else if(this->bucatar){
                    this->salariu += 1500;
                }
            }
            else{
                cout << "Angajatul nu are vechime suficienta pentru a fi promovat." << endl;
            }
        }
        void Angajat::promovareAngajat(int schimbNou){                                  //functie supraincarcata pentru a promova angajatul si a-i schimba schimbul
            if (this->vechime >= 5) {
                if(schimbNou < 1 || schimbNou > 3) {
                    cout << "Schimbul nou trebuie sa fie intre 1 si 3." << endl;
                    return;
                }
                this->schimb = schimbNou;
                if(this->ospatar){
                    this->salariu += 1000;
                }
                else if(this->bucatar){
                    this->salariu += 1500;
                }
            }
            else{
                cout << "Angajatul nu are vechime suficienta pentru a fi promovat." << endl;
            }
        }

        void Angajat::pensionareAngajat(){
            if(this->vechime >= 10 || this->varsta>60){
                cout << "Angajatul " << this->nume << " " << this->prenume << " s-a pensionat." << endl;
                delete[] this->nume;
                delete[] this->prenume;
                this->nume = nullptr;
                this->prenume = nullptr;
                this->varsta = 0;
                this->salariu = 0;
                this->schimb = 0;
                this->vechime = 0;
                this->ospatar = false;
                this->bucatar = false;
        }
            }

        void Angajat::cresteVechimea() {
            this->varsta++;
            this->vechime++;
        }

        void Angajat::cresteVechimea(int ani) {             //functie supraincarcata pentru a creste vechimea cu un numar specificat de ani
            this->varsta += ani;
            this->vechime += ani;
        }

        void Angajat::preiaRezervare(const Rezervari &rezervareNoua){
            if(this->ospatar==true){
                this->rezervariPreluate.push_back(rezervareNoua);
                cout << "Ospatarul " << this->nume << " " << this -> prenume <<"a preluat rezervarea clientului: " << rezervareNoua.getNumeClient() << " " << rezervareNoua.getPrenumeClient() << endl;
            }
            else{
                cout<< "Angajatul nu este ospatar!"<<endl;
            }
        }

        void Angajat::reviewOspatar(int nota) {


    if (!this->ospatar) {
        cout << "Eroare: Angajatul " << this->nume << " este bucatar. Review-ul de servire nu se aplica." << endl;
        return;
    }

    cout << "Review pentru ospatarul " << this->nume << " " << this->prenume << ":" << endl;

    switch (nota) {
        case 5:
            cout << "Rating: ***** (Excelent)" << endl;
            this->salariu += 50;
            break;
        case 4:
            cout << "Rating: **** (Foarte Bine)" << endl;
            break;
        case 3:
            cout << "Rating: *** (Mediu)" << endl;
            break;
        case 2:
            cout << "Rating: ** (Slab)" << endl;
            break;
        case 1:
            cout << "Rating: * (Inacceptabil)" << endl;
            this->salariu -= 20;
            break;
        default:
            cout << "Nota introdusa (" << nota << ") este invalida. Te rugam sa introduci o nota de la 1 la 5." << endl;
            break;
    }
    cout << "------------------------------" << endl;
}   



    Angajat& Angajat::operator=(const Angajat &nou) {
    if (this == &nou) {
        return *this;
    }

    delete[] this->nume;
    delete[] this->prenume;

    this->nume = new char[strlen(nou.nume) + 1];
    strcpy(this->nume, nou.nume);

    this->prenume = new char[strlen(nou.prenume) + 1];
    strcpy(this->prenume, nou.prenume);

    this->varsta = nou.varsta;
    this->salariu = nou.salariu;
    this->schimb = nou.schimb;
    this->vechime = nou.vechime;
    this->ospatar = nou.ospatar;
    this->bucatar = nou.bucatar;
    
    this->rezervariPreluate = nou.rezervariPreluate;

    return *this;
}




        //destructor

        Angajat::~Angajat(){
            if(nume != nullptr){
                delete[] nume;
            }
            if(prenume != nullptr){
                delete[] prenume;
            }
        }