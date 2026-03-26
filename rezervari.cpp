#include "rezervari.h"
#include <cstring>
#include <iostream>
using namespace std;


        //constructor default


        Rezervari::Rezervari(){
            nume_client = nullptr;
            prenume_client = nullptr;
            numar_persoane = 0;
            ora_rezervare = 0;
            confirmare = false;
        };

        //constructor cu parametrii


        Rezervari::Rezervari(const char *nume_client, const char *prenume_client, int numar_persoane, int ora_rezervare, bool confirmare){
            
            this->nume_client = new char[strlen(nume_client)+1];
            strcpy(this->nume_client, nume_client);

            this->prenume_client = new char[strlen(prenume_client)+1];
            strcpy(this->prenume_client, prenume_client);

            this->numar_persoane = numar_persoane;

            this->ora_rezervare = ora_rezervare;

            this->confirmare = confirmare;
            
            if (confirmare == true){
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    if(this->mese_disponibile[i][j]){
                        this->mese_disponibile[i][j] = false;
                        break;
                    }
                }
            }}
        };

        //constructor de copiere


        Rezervari::Rezervari(const Rezervari &rezervare){
            
            this->nume_client = new char[strlen(rezervare.nume_client)+1];
            strcpy(this->nume_client, rezervare.nume_client);

            this->prenume_client = new char[strlen(rezervare.prenume_client)+1];
            strcpy(this->prenume_client, rezervare.prenume_client);

            this->numar_persoane = rezervare.numar_persoane;

            this->ora_rezervare = rezervare.ora_rezervare;

            this->confirmare = rezervare.confirmare;

            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    this->mese_disponibile[i][j] = rezervare.mese_disponibile[i][j];
                }
            }
        };


        //setteri

        void Rezervari::setNumeClient(const char *nume_client){

            if (this->nume_client != nullptr) {
                delete[] this->nume_client;
            }

            this->nume_client = new char[strlen(nume_client) + 1];
            strcpy(this->nume_client, nume_client);
        };
        void Rezervari::setPrenumeClient(const char *prenume_client){

            if (this->prenume_client != nullptr) {
                delete[] this->prenume_client;
            }

            this->prenume_client = new char[strlen(prenume_client) + 1];
            strcpy(this->prenume_client, prenume_client);
        };
        void Rezervari::setNumarPersoane(int numar_persoane){
            this->numar_persoane = numar_persoane;
        };
        void Rezervari::setOraRezervare(int ora_rezervare){
            this->ora_rezervare = ora_rezervare;
        };
        void Rezervari::setMeseDisponibile(int numar_masa_rand, int numar_masa_coloana, bool disponibilitate){
            
            this->mese_disponibile[numar_masa_rand][numar_masa_coloana] = disponibilitate;

        };
        void Rezervari::setConfirmare(bool confirmare){
            this->confirmare = confirmare;
        };

        //getteri

        char* Rezervari::getNumeClient() const{
            return this->nume_client;
        };
        char* Rezervari::getPrenumeClient() const{
            return this->prenume_client;
        };
        int Rezervari::getNumarPersoane() const{
            return this->numar_persoane;
        };
        int Rezervari::getOraRezervare() const{
            return this->ora_rezervare;
        };
        bool Rezervari::getMeseDisponibile() const{
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    if(this->mese_disponibile[i][j]){
                        return true;
                    }
                }
            }
            return false;
        };

        bool Rezervari::getConfirmare() const{
            return this->confirmare;
        };


        void Rezervari::getAllRezervari() const{
            cout<< "------------------------------" << endl;
            cout << "Nume client: " << nume_client << endl;
            cout << "Prenume client: " << prenume_client << endl;
            cout << "Numar persoane: " << numar_persoane << endl;
            cout << "Ora rezervare: " << ora_rezervare << endl;
            cout<< "Confirmare: " << (confirmare ? "Da" : "Nu") << endl;
            cout<< "------------------------------" << endl<<endl;
            
        };
        
        //functii

        void Rezervari::inchidereZi(){
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    this->mese_disponibile[i][j] = true;
                }
            }
        };

        void Rezervari::eliberareMasa(int numar_masa_rand, int numar_masa_coloana){
            this->mese_disponibile[numar_masa_rand][numar_masa_coloana] = true;
        };


        //destructor

        Rezervari::~Rezervari(){
            if (nume_client != nullptr){
                 delete[] nume_client;
            }
            if (prenume_client != nullptr){
                delete[] prenume_client;
            }
        };