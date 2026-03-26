#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include "meniu.h"
#include "angajati.h"
#include "rezervari.h"
using namespace std;

// void treceUnAn(vector<Angajat> listaAngajati) {
//     cout << "\n A mai trecut un an la restaurant! " << endl;                     //functie prietena care preiea angajatii dintr-un vector si le creste tuturor vechimea, si ii pensioneaza automat pe cei care au ajuns la vechimea necesara.(nu functioneaza momentan)
    
//     for (int i = 0; i < listaAngajati.size(); i++) {
//         if (listaAngajati[i].getNume() != nullptr) {
            
//             listaAngajati[i].cresteVechimea();
            
//             listaAngajati[i].pensionareAngajat();
//         }
//     }
// }

int main(){
    
    
    Angajat angajat1("Popescu", "Ion", 30, 3000, 1, "ospatar");                                  //construim obiectele angajat1,angajat2 si angajat3(pe angajat3 ii copiem constructia angajatului1,o modificam dupa cu setteri)
    Angajat angajat2("Ionescu", "Maria", 25, 3500, 2, "bucatar");
    Angajat angajat3(angajat1);

    angajat3.setNume("Georgescu");
    angajat3.setBucatar(true);
    angajat3.setOspatar(false);
    angajat3.setSalariu(4000);
    angajat2.setPrenume("Elena");
    angajat3.setSchimb(3);
    angajat1.setVechime(6);

    angajat1.promovareAngajat();
    angajat2.setVarsta(30);
    angajat1.cresteVechimea(4);
    angajat1.getAllAngajat();
    angajat2.getAllAngajat();
    angajat3.getAllAngajat();
    angajat1.pensionareAngajat();


    Meniu meniu1("Ciorba de burta", 25.5, true, false, true);
    Meniu meniu2("Salata de vinete", 15.0, true, true, false);
    Meniu meniu3(meniu2);
    meniu3.setNumeProdus("Salata de rosii");
    meniu1.setDisponibilitate(false);
    meniu3.setPret(12.0);
    meniu3.setDisponibilitate(false);
    meniu1.getAllMeniu();
    meniu2.getAllMeniu();
    meniu3.getAllMeniu();
    // cout<< meniu3.getNumeProdus()<< "\n";



    // vector<Angajat*> echipa={&angajat1, &angajat2};



    Rezervari rezervare1("Vasilescu", "Andrei", 4, 19, true);
    Rezervari rezervare2("Marinescu", "Ioana", 2, 20, false);
    Rezervari rezervare3(rezervare1);

    cout<<"------------------------------"<<endl;
    cout<< rezervare3.getNumeClient()<< "\n";
    cout<< rezervare3.getPrenumeClient()<< "\n";
    cout<< rezervare3.getNumarPersoane()<< "\n";
    cout<< rezervare3.getOraRezervare()<< "\n";
    cout<< rezervare3.getConfirmare()<< "\n";
    cout<<"------------------------------"<<endl<<endl;


    rezervare3.setNumeClient("Dumitrescu");
    rezervare3.setPrenumeClient("Alex");
    rezervare3.setNumarPersoane(3);
    rezervare3.setOraRezervare(21);
    rezervare3.setConfirmare(true);
    rezervare3.getAllRezervari();
    rezervare1.getAllRezervari();
    rezervare2.getAllRezervari();
    rezervare1.eliberareMasa(2, 3);
    
    
    
    
    // for (int i = 0; i < 10; i++) {
    //     treceUnAn(echipa);
    // }


    // cout<< angajat1.getNume()<< "\n";
    // cout<< angajat1.getPrenume()<< "\n";
    // cout<< angajat1.getVarsta()<< "\n";
    // cout<< angajat1.getSalariu()<< "\n";
    // angajat1.setVechime(10);
    // angajat1.pensionareAngajat();
    // cout<< meniu1.getNumeProdus()<< "\n";
    // cout<< meniu1.getPret()<< "\n";
    // cout<< meniu1.getDisponibilitate()<< "\n";
    // cout<< meniu1.getVegan()<< "\n";
    // cout<< meniu1.getAlergeni()<< "\n";
    // cout<< rezervare1.getNumeClient()<< "\n";
    // cout<< rezervare1.getPrenumeClient()<< "\n";
    // cout<< rezervare1.getNumarPersoane()<< "\n";
    // cout<< rezervare1.getOraRezervare()<< "\n";
    // cout<< rezervare1.getConfirmare()<< "\n";
    return 0;
}