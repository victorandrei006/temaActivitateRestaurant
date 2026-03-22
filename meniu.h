#ifndef MENIU_H
#define MENIU_H
class Meniu{
    private:
        char *nume_produs;
        double pret;
        bool disponibilitate ,vegan,alergeni;
    public:
        Meniu();
        Meniu(const char *nume_produs, double pret, bool disponibilitate, bool vegan, bool alergeni);
        Meniu(const Meniu &meniu);
        void setNumeProdus(char *nume_produs);
        void setPret(double pret);
        void setDisponibilitate(bool disponibilitate);
        void setVegan(bool vegan);
        void setAlergeni(bool alergeni);
        char* getNumeProdus() const;
        double getPret() const;
        bool getDisponibilitate() const;
        bool getVegan() const;
        bool getAlergeni() const;
        void getAllMeniu() const;
        ~Meniu();
};
#endif