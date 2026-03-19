#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include "meniu.h"
using namespace std;

class Angajat{
    private:
        int varsta,salariu,schimb,vechime;
        char *nume, *prenume;
        bool ospatar , bucatar;
    public:
        Angajat(){
            varsta=0; salariu=0; schimb=0; vechime=0; nume = nullptr; prenume = nullptr; ospatar=false; bucatar=false;                       //constructor default
        }
        Angajat(const char *numeAtribuit,const char *prenumeAtribuit ,int varsta,int salariu,int schimb, const char* angajat){              //constructor cu parametrii
            
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
        Angajat(const Angajat &angajat){                                                                                                        //constructor de copiere
            
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

        void setNume(char *nume){
            this->nume = nume;
        }
        void setPrenume(char *prenume){
            this->prenume = prenume;
        }
        void setVarsta(int varsta){
            this->varsta = varsta;
        }
        void setSalariu(int salariu){
            this->salariu = salariu;
        }
        void setSchimb(int schimb){
            this->schimb = schimb;
        }
        void setOspatar(bool ospatar){
            this->ospatar = ospatar;
        }
        void setBucatar(bool bucatar){
            this->bucatar = bucatar;
        }
        void setVechime(int vechime){
            this->vechime = vechime;
        }


        //getteri

        char& getNume() const{
            return *nume;
        }
        char& getPrenume() const{
            return *prenume;
        }
        int getVarsta()const{
            return varsta;
        }
        int getSalariu()const{
            return salariu;
        }
        int getSchimb()const{
            return schimb;
        }
        bool getOspatar()const{
            return ospatar;
        }
        bool getBucatar()const{
            return bucatar;
        }
        int getVechime()const{
            return vechime;
        }
        void getAll()const{
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
        ~Angajat(){
            if(nume != nullptr){
                delete[] nume;
            }
            if(prenume != nullptr){
                delete[] prenume;
            }
        }
};





int main(){
    Angajat id1 = Angajat("Marcel", "Costica", 25, 3000, 1, "ospatar");
    // id1.getAll();
    cout<<id1.getVarsta();
}