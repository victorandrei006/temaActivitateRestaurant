#include "angajati.h"
#include <cstring>
#include <iostream>
using namespace std;

Angajat::Angajat(){
    varsta=0; salariu=0; schimb=0; vechime=0; nume = nullptr; prenume = nullptr; ospatar=false; bucatar=false;                       //constructor default
}
Angajat::Angajat(const char *numeAtribuit,const char *prenumeAtribuit ,int varsta,int salariu,int schimb, const char* angajat){              //constructor cu parametrii    
        
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
Angajat::Angajat(const Angajat &angajat){                                                                                                        //constructor de copiere   
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

       void Angajat::setNume(char *nume){
            this->nume = nume;
        }
        void Angajat::setPrenume(char *prenume){
            this->prenume = prenume;
        }
        void Angajat::setVarsta(int varsta){
            this->varsta = varsta;
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
        }
        char& Angajat::getNume() const{
            return *nume;
        }
        char& Angajat::getPrenume() const{
            return *prenume;
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
        void Angajat::getAll()const{
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
        }
        Angajat::~Angajat(){
            if(nume != nullptr){
                delete[] nume;
            }
            if(prenume != nullptr){
                delete[] prenume;
            }
        }