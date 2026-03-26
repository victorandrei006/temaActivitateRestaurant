#include "meniu.h"
#include <cstring>
#include <iostream>
using namespace std;



Meniu::Meniu(){
    nume_produs = nullptr;
    pret = 0;
    disponibilitate = false;                                                                                    //constructor default(implementat)
    vegan = false;
    alergeni = false;
}





Meniu::Meniu(const char *nume_produs, double pret, bool disponibilitate, bool vegan, bool alergeni){
    this->nume_produs = new char[strlen(nume_produs)+1];
    strcpy(this->nume_produs, nume_produs);
    this->pret = pret;                                                                                          //constructor cu parametrii
    this->disponibilitate = disponibilitate;
    this->vegan = vegan;
    this->alergeni = alergeni;
}




Meniu::Meniu(const Meniu &meniu){
    this->nume_produs = new char[strlen(meniu.nume_produs)+1];
    strcpy(this->nume_produs, meniu.nume_produs);
    this->pret = meniu.pret;
    this->disponibilitate = meniu.disponibilitate;                                                                  //constructor de copiere
    this->vegan = meniu.vegan;
    this->alergeni = meniu.alergeni;
}





            //setteri

void Meniu::setNumeProdus(const char *nume_produs_set){

    if (this->nume_produs != nullptr) {
        delete[] this->nume_produs;
    }

    this->nume_produs = new char[strlen(nume_produs_set) + 1];
    strcpy(this->nume_produs, nume_produs_set);

}
void Meniu::setPret(double pret){
    this->pret = pret;
}
void Meniu::setDisponibilitate(bool disponibilitate){
    this->disponibilitate = disponibilitate;
}
void Meniu::setVegan(bool vegan){
    this->vegan = vegan;
}
void Meniu::setAlergeni(bool alergeni){ 
    this->alergeni = alergeni;
}




            //getteri

char* Meniu::getNumeProdus() const{
    return this->nume_produs;
}
double Meniu::getPret() const{
    return pret;
}
bool Meniu::getDisponibilitate() const{
    return disponibilitate;
}
bool Meniu::getVegan() const{
    return vegan;
}
bool Meniu::getAlergeni() const{
    return alergeni;
}
void Meniu::getAllMeniu() const{
    cout<< "------------------------------" << endl;
    cout << "Nume produs: " << nume_produs << endl;
    cout << "Pret: " << pret << endl;
    if(disponibilitate){
        cout << "Produsul este disponibil." << endl;
    }
    else{
        cout << "Produsul nu este disponibil." << endl;
    }
    if(vegan){
        cout << "Produsul este vegan." << endl;
    }
    else{
        cout << "Produsul nu este vegan." << endl;
    }
    if(alergeni){
        cout << "Produsul contine alergeni." << endl;
    }
    else{
        cout << "Produsul nu contine alergeni." << endl;
    }
    cout<< "------------------------------" << endl<<endl;
}



Meniu::~Meniu(){
    if(nume_produs != nullptr){                                                                 //destructor(dezaloc memoria utilizata daca pointerul nu este null)
        delete[] nume_produs;
    }
}