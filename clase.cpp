#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include "meniu.h"
#include "angajati.h"
#include "rezervari.h"
using namespace std;

void treceUnAn(vector<Angajat>& listaAngajati) {
    cout << "\n A mai trecut un an la restaurant! " << endl;
    
    for (int i = 0; i < listaAngajati.size(); i++) {
        if (listaAngajati[i].getNume() != nullptr) {
            
            listaAngajati[i].cresteVechimea();
            
            listaAngajati[i].pensionareAngajat();
        }
    }
}

int main(){
    

    Angajat angajat1("Popescu", "Ion", 30, 3000, 1, "ospatar");
    Angajat angajat2("Ionescu", "Maria", 25, 3500, 2, "bucatar");
    Meniu meniu1("Ciorba de burta", 25.5, true, false, true);
    Rezervari rezervare1("Vasilescu", "Andrei", 4, 19, true);
    cout<< angajat1.getNume()<< "\n";
    cout<< angajat1.getPrenume()<< "\n";
    cout<< angajat1.getVarsta()<< "\n";
    cout<< angajat1.getSalariu()<< "\n";
    angajat1.setVechime(10);
    angajat1.pensionareAngajat();
    cout<< meniu1.getNumeProdus()<< "\n";
    cout<< meniu1.getPret()<< "\n";
    cout<< meniu1.getDisponibilitate()<< "\n";
    cout<< meniu1.getVegan()<< "\n";
    cout<< meniu1.getAlergeni()<< "\n";
    cout<< rezervare1.getNumeClient()<< "\n";
    cout<< rezervare1.getPrenumeClient()<< "\n";
    cout<< rezervare1.getNumarPersoane()<< "\n";
    cout<< rezervare1.getOraRezervare()<< "\n";
    cout<< rezervare1.getConfirmare()<< "\n";
    return 0;
}