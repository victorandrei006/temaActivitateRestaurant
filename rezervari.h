#ifndef REZERVARI_H
#define REZERVARI_H

class Rezervari{
    private:
        char *nume_client, *prenume_client;
        int numar_persoane, ora_rezervare;
        bool confirmare,mese_disponibile[5][5];
        
    public:
        Rezervari();
        Rezervari(const char *nume_client, const char *prenume_client, int numar_persoane, int ora_rezervare, bool confirmare);
        Rezervari(const Rezervari &rezervare);
        void setNumeClient(const char *nume_client);
        void setPrenumeClient(const char *prenume_client);
        void setNumarPersoane(int numar_persoane);
        void setOraRezervare(int ora_rezervare);
        void setMeseDisponibile(int numar_masa_rand, int numar_masa_coloana, bool disponibilitate);
        void setConfirmare(bool confirmare);
        char* getNumeClient() const;
        char* getPrenumeClient() const;
        int getNumarPersoane() const;
        int getOraRezervare() const;
        bool getMeseDisponibile() const;
        bool getNrMeseDisponibile() const;
        bool getConfirmare() const;
        void getAllRezervari() const;
        void incepereZi();
        void eliberareMasa(int numar_masa_rand, int numar_masa_coloana);
        ~Rezervari();
};





#endif