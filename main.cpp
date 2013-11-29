#include <iostream>

using namespace std;

//Prototipi
void tfr(double, double, double);
void input();

//Variabili e costanti
double sal_stip, deb_tfr, indice;
bool flag = 0;
const double RETR = 13.5;

int main(){

    do{
        //Richiamo la procedura per l inserimento dei dati.
        input();
        //richiamo la procedura per il calcolo del tfr, passandogli 3 parametri per valore.
        tfr(sal_stip, deb_tfr, indice);

        if(flag == 0){
            cout<<"Vuoi calcolare un altro TFR? (1 = si 0 = no) \n--->";
            cin>> flag;
        }
    }while(flag != 0);

    return 0;
}

//Calcolo tfr e output
void tfr(double SL, double Deb_tfr, double Ind_ISTAT){
    if(SL == 0 or Deb_tfr == 0 or Ind_ISTAT == 0){
        cout<<"Errore. Impossibile effetturare il calcolo.Inserire tutti i dati in modo corretto.\n";
        flag = 1;
    }
    else{
    flag = 0;
        double tfr_annuo = 0;//Quota commisurata alle retribuzioni dell' anno
        double coef = 0; //Coefficiente di rivalutazione
        double rival_lord = 0;//rivalutazione al lordo della ritenuta
        double TFR_lordo = 0; //Calcolo TFR LORDO
        double rec_contrib = 0; //Recupero contributivo


        double TFR_netto = 0;//TFR NETTO dell' esercizio
        double rit_da_vers = 0;//Debiti per ritenute da versare
        double deb_tfr = 0;

        tfr_annuo = (SL / RETR);//Quota commisurata alle retribuzioni dell' anno
        cout<<"Quota commisurata alle retribuzioni dell' anno ("<<SL<<"/"<<RETR<<") = "<< tfr_annuo<<endl;
        coef = (1.50 + (0.75*(Ind_ISTAT - 100))); //Coefficiente di rivalutazione
        cout<<"Coefficiente di rivalutazione (1.50+(0.75 * ("<<Ind_ISTAT<<" -100)) = "<< coef<< endl;
        rival_lord = (Deb_tfr * coef)/100;//rivalutazione al lordo della ritenuta
        cout<<"Rivalutazione al lordo della ritenuta ("<<Deb_tfr<<"* "<<coef<<") = "<<rival_lord<<endl;
        TFR_lordo = tfr_annuo + rival_lord; //Calcolo TFR LORDO
        cout<<"TFR LORDO "<<tfr_annuo<<"+"<<rival_lord<<" = " <<TFR_lordo<<endl;
        rec_contrib = ((SL * 0.50)/100); //Recupero contributivo
        cout<<"Recupero contributivo (("<<SL<<" * 0.50)/100) = "<<rec_contrib<<endl;


        TFR_netto = TFR_lordo - rec_contrib;//TFR NETTO dell' esercizio
        rit_da_vers = (rival_lord * 11)/100;//Debiti per ritenute da versare
        deb_tfr = TFR_netto - rit_da_vers;

        //Output, stampo a schermo la registrazione in PD
        cout<<"---------------------------------------------------------------------\n";
        cout<<"TFR  VEN ---> DARE  "<<TFR_netto<<"\n";
        cout<<"Debiti per ritenute da versare  VFP ---> AVERE  "<<rit_da_vers<<"\n";
        cout<<"Debiti per TFR  VFP ---> AVERE  "<<deb_tfr<<"\n";

    }
}

//Procedura per l' input
void input(){
    cout<<"Inserisci Salari e Stipendi \n--->";
    cin>>sal_stip;

    cout<<"Inserisci i Debiti per TFR \n--->";
    cin>>deb_tfr;

    cout<<"Inserisci l' Indice ISTAT \n--->";
    cin>>indice;
}
