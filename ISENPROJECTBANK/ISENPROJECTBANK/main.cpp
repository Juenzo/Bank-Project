#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <windows.data.json.h>

#include "ISENPROJECTBANK.h"

using namespace std;


int main() {
    int Reveniraumenuprincipal;
    clock_t prv = clock();
    int compteur = 0;
    do {

        cout << "\nBIENVENUE DANS LE PROGRAMME DE GESTION DE COMPTE\n\n";
        cout << "\nOperations possibles:\n";//Menu du programme
        cout << "\t1- Creer un nouveau compte\n\t2- Acceder a son compte\n\t3- Effectuer un versement\n";
        cout << "\t4- Effectuer un retrait\n\t5- Fermer son compte\n\t6- Epargne\n\t7- Effectuer un virement\n\t0- Pour quitter le programme\n\n";
        cout << "faite votre choix  :  ";
        int choix;
        cin >> choix;
        cin.ignore();

        //Nom des fichiers
        string const FichierCompte("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\FichierCompte.txt");
        string const FichierCompteISEN("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\ISENBANK.txt");
        string const FichierCompteJUNIA("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\JUNIABANK.txt");
        string const FichierNumeroCOmpte(
            "C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\FichierNumeroCompte.txt");
        string const FichierNumeroCompteEpargne(
            "C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\FichierNumeroCompteEpargne.txt");
        string const FichierCompteEpargne(
            "C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\FichierCompteEpargne.txt");

        //Déclaration de l'objet Client
        Client Personne;



        switch (choix) {
        case 0://QUITTER LE PROGRAMME
        {
            break;
        }
        case 1://Création Nouveau compte
        {


            int reponse = 0;
            cout << "Operation possible :\n\t1- Creer un compte Epargne\n\t2- Creer un compte Courant\n";
            cout << "faite votre choix  :  ";
            int choixCompte;
            cin >> choixCompte;
            cin.ignore();


            switch (choixCompte) {
            case 0: // Quitter le logiciel
                break;
            case 1: // Creation Compte Epargne



                do {
                    system("cls");
                    cout << "\n******** CREATION D'UN NOUVEAU COMPTE EPARGNE **********\n";
                    //Nom des variables de remplissage
                    string codeCompte, codeConfirmation, nomClient, prenom, ContactCLient;
                    int NumeroCompte, NumeroBank;
                    cout << "\nChoisissez votre banque (1 = ISENBank , 2 = JUNIABank)  :  ";
                    cin >> NumeroBank;
                    string const FichierBank;
                    cin.ignore();
                    switch (NumeroBank) {
                    case 1: {
                        NumeroBank = 1;
                        string const FichierBank("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\ISENBANK.txt");
                    }
                          break;
                    case 2: {
                        NumeroBank = 2;
                        string const FichierBank("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\JUNIABANK.txt");
                    }
                          break;
                    default: {
                        NumeroBank = 1;
                    }
                    }

                    cout << "\nEntrez votre nom  :  ";
                    cin >> nomClient;
                    cout << "\nEntrez votre prenom  :  ";
                    cin >> prenom;
                    cin.ignore();
                    cout << "\nEntrez votre numero de telephone   :  ";
                    getline(cin, ContactCLient);
                    cout << "\nEntrez votre code secret  :  ";
                    cin >> codeCompte;
                    cout << "\nConfirmez votre code secret  :  ";
                    cin >> codeConfirmation;
                    while (codeCompte != codeConfirmation) {
                        cout << "\nErreur, Confirmez votre code secret  :  ";
                        cin >> codeConfirmation;
                    }
                    cout << "\nEntrez le montant a verser sur votre compte des l'ouverture  :  ";
                    unsigned int montant;
                    cin >> montant;

                    std::string DayToday;
                    DayToday = DateDuJour();
                    NumeroCompte = NumCompte(FichierNumeroCompteEpargne);

                    cout << "\nCompte a ete cree le  " << DayToday << " .\nVotre numero de compte est :"
                        << NumeroCompte << endl;
                    cout
                        << "Vous devrez connaitre ce numero et votre mot de passe pour pouvoir vous connectez a votre compte\n\n\n";

                    Personne.NouveauCompte(FichierCompteEpargne, NumeroCompte, codeConfirmation, nomClient,
                        prenom,
                        ContactCLient, DayToday, montant, NumeroBank);
                    cout << "\nVous pouvez passer a une verification ....";

                    cout << "\n\nVoulez-vous creer un nouveau compte ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                    cin >> reponse;
                } while (reponse == 1);
                //Déclaration compte Epargne

                system("pause");
                system("cls");
                cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
                cout << "0-pour fermer      1-menu principal\nReponse : ";
                cin >> Reveniraumenuprincipal;
                if (Reveniraumenuprincipal == 1) {
                    system("cls");
                }
                break;
            case 2: // Creation Compte Courant
                do {
                    system("cls");
                    cout << "\n******** CREATION D'UN NOUVEAU COMPTE **********\n";
                    //Nom des variables de remplissage
                    string codeCompte, codeConfirmation, nomClient, prenom, ContactCLient;
                    int NumeroCompte, NumeroBank;
                    cout << "\nChoisissez votre banque (1 = ISENBank , 2 = JUNIABank)  :  ";
                    cin >> NumeroBank;
                    string const FichierBank;
                    cin.ignore();
                    switch (NumeroBank) {
                    case 1: {
                        NumeroBank = 1;
                    }
                          break;
                    case 2: {
                        NumeroBank = 2;
                    }
                          break;
                    default: {
                        NumeroBank = 1;
                    }
                    }
                    cout << "\nEntrez votre nom  :  ";
                    cin >> nomClient;
                    cout << "\nEntrez votre prenom  :  ";
                    cin >> prenom;
                    cin.ignore();
                    cout << "\nEntrez votre numero de telephone :  ";
                    getline(cin, ContactCLient);
                    cout << "\nEntrez votre code secret  :  ";
                    cin >> codeCompte;
                    cout << "\nConfirmez votre code secret  :  ";
                    cin >> codeConfirmation;
                    while (codeCompte != codeConfirmation) {
                        cout << "\nErreur, Confirmez votre code secret  :  ";
                        cin >> codeConfirmation;
                    }
                    cout << "\nEntrez le montant a verser sur votre compte des l'ouverture  :  ";
                    unsigned int montant;
                    cin >> montant;

                    std::string DayToday;
                    DayToday = DateDuJour();
                    NumeroCompte = NumCompte(FichierNumeroCOmpte);

                    cout << "\nCompte a ete cree le  " << DayToday << " .\nVotre numero de compte est :"
                        << NumeroCompte << endl;
                    cout
                        << "Vous devrez connaitre ce numero et votre mot de passe pour pouvoir vous connectez a votre compte\n\n\n";
                    if (NumeroBank == 1) {
                        Personne.NouveauCompte(FichierCompteISEN , NumeroCompte, codeConfirmation, nomClient, prenom,
                            ContactCLient, DayToday, montant, NumeroBank);
                    }
                    else {
                        Personne.NouveauCompte(FichierCompteJUNIA, NumeroCompte, codeConfirmation, nomClient, prenom,
                            ContactCLient, DayToday, montant, NumeroBank);
                    }
                    Personne.NouveauCompte(FichierCompte, NumeroCompte, codeConfirmation, nomClient, prenom,
                        ContactCLient, DayToday, montant, NumeroBank);
                    cout << "\nVous pouvez passer a une verification ....";

                    cout << "\n\nVoulez-vous creer un nouveau compte ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                    cin >> reponse;
                } while (reponse == 1);
                //Déclaration compte bancaire

                system("pause");
                system("cls");
                cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
                cout << "0-pour fermer      1-menu principal\nReponse : ";
                cin >> Reveniraumenuprincipal;
                if (Reveniraumenuprincipal == 1) {
                    system("cls");
                }
                break;
            default: {
                cout << "Aucun choix effectue !!!!";
            }
            }
        }
        case 2: //Accès au compte
        {
            system("pause");
            int reponse = 0;
            do {
                system("cls");
                cout << "\n\n***** ACCES A SON COMPTE *******  \n\n";
                cout << "Entrer votre numero de compte : ";
                unsigned int Numero;
                cin >> Numero;
                cout << "\nEntrez votre code secret  :  ";
                std::string mdp;
                cin >> mdp;
                cout << endl;
                //Déclaration compte bancaire
                system("pause");
                system("cls");

                Personne.SoldeClient(FichierCompte, Numero, mdp);
                cout << "\n\nVerification effectuee!!!!!\n\n";

                cout << "\n\nVoulez-vous consulter un autre compte ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                cin >> reponse;
            } while (reponse == 1);
            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1) {
                system("cls");
            }

            break;
        }
        case 3://EFFECTUER UN VERSEMENT
        {
            system("pause");
            int reponse = 0;
            do {
                system("cls");
                cout << "\n***** EFFECTUER UN VERSEMENT *******  \n\n";

                cout << "Entrer votre numero de compte : ";
                unsigned int Numero;
                cin >> Numero;
                cout << "Entrer le montant a verser sur votre compte : ";
                unsigned int vers;
                cin >> vers;
                cout << "\nEntrez votre code secret  :  ";
                std::string mdp;
                cin >> mdp;
                cout << endl;
                //Déclaration compte bancaire
                system("pause");
                system("cls");
                Personne.Versement(FichierCompte, Numero, mdp, vers);

                cout << "\n\nVoulez-vous effectuer un autre versement ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                cin >> reponse;
            } while (reponse == 1);

            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1) {
                system("cls");
            }

            break;
        }
        case 4://EFFECTUER UN RETRAIT
        {
            system("pause");
            int reponse = 0;
            do {
                system("cls");
                cout << "\n***** EFFECTUER UN RETRAIT *******  \n\n";

                cout << "Entrer votre numero de compte : ";
                unsigned int Numero;
                cin >> Numero;
                cout << "Entrer le montant a retirer sur votre compte : ";
                unsigned int retrait;
                cin >> retrait;
                cout << "\nEntrez votre code secret  :  ";
                std::string mdp;
                cin >> mdp;
                cout << endl;
                //Déclaration compte bancaire
                system("pause");
                system("cls");
                Personne.Retrait(FichierCompte, Numero, mdp, retrait);

                cout << "\n\nVoulez-vous effectuer un autre retrait ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                cin >> reponse;

            } while (reponse == 1);

            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1) {
                system("cls");
            }

            break;
        }
        case 5://FERMER SON COMPTE
        {

            system("pause");
            int reponse = 0;
            do {
                system("cls");
                cout << "\n***** FERMER SON COMPTE POUR TOUJOURS *******  \n\n";

                cout << "Entrer votre numero de compte : ";
                unsigned int Numero;
                cin >> Numero;

                cout << "\nEntrez votre code secret  :  ";
                std::string mdp;
                cin >> mdp;
                cout << endl;
                //Déclaration compte bancaire
                system("pause");
                system("cls");
                Personne.FermetureCompte(FichierCompte, Numero, mdp);

                cout << "\n\nVoulez-vous fermeture un autre compte ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                cin >> reponse;

            } while (reponse == 1);
            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1) {
                system("cls");
            }

            break;
        }
        case 6://EPARGNE
        {
            system("pause");
            cout << "\n***** EPARGNE EN COURS *******  \n\n";
            compteur = 0;
            while (compteur != 1000000) {
                clock_t now = clock();
                if ((now - prv) / CLOCKS_PER_SEC >= 1) {
                    prv = now;
                    compteur++;
                    Personne.AjoutEpargne("C:\\Users\\julie\\source\\repos\\bank-project\\bank-project\\FichierCompteEpargne.txt");
                }
            }
            continue;
            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1) {
                system("cls");
            }

            break;
        }
        case 7:// Faire un virement
        {
            system("pause");
            int reponse = 0;
            do
            {
                system("cls");
                cout << "\n***** EFFECTUER UN VIREMENT *******  \n\n";

                int NumeroBank;
                cout << "\nindiquez votre banque (1 = ISENBank , 2 = JUNIABank)  :  ";
                cin >> NumeroBank;
                string const FichierBank;
                cin.ignore();
                switch (NumeroBank) {
                case 1: {
                    NumeroBank = 1;
                }
                      break;
                case 2: {
                    NumeroBank = 2;
                }
                      break;
                default: {
                    NumeroBank = 1;
                }
                }
                cout << "Entrer votre numero de compte : ";
                unsigned int Numero;
                cin >> Numero;
                int NumeroBank2;
                cout << "\nindiquez la banque du destinataire (1 = ISENBank , 2 = JUNIABank)  :  ";
                cin >> NumeroBank2;
                string const FichierBank2;
                cin.ignore();
                switch (NumeroBank2) {
                case 1: {
                    NumeroBank2 = 1;
                }
                      break;
                case 2: {
                    NumeroBank2 = 2;
                }
                      break;
                default: {
                    NumeroBank2 = 1;
                }
                }
                cout << "Entrer le numero de compte du destinaraire : ";
                unsigned int Numero2;
                cin >> Numero2;
                cout << "Entrer le montant a verser sur le compte choisit : ";
                unsigned int vers;
                cin >> vers;
                cout << "\nEntrez votre code secret  :  ";
                std::string mdp;
                cin >> mdp;
                cout << endl;
                //Déclaration compte bancaire
                system("pause");
                system("cls");
                Personne.Retrait(FichierCompte, Numero, mdp, vers);
                Personne.Versement3(FichierCompte, Numero2, vers);
                //Personne.transactionCompte(FichierCompte, Numero, Numero2, mdp, vers);
                if (NumeroBank == 1) {
                    Personne.Retrait(FichierCompteISEN, Numero, mdp, vers);
                }
                else if (NumeroBank == 2) {
                    Personne.Retrait(FichierCompteJUNIA, Numero, mdp, vers);
                }
                if (NumeroBank2 == 1) {
                    Personne.Versement3(FichierCompteISEN, Numero2, vers);
                }
                else if (NumeroBank2 == 2) {
                    Personne.Versement3(FichierCompteJUNIA, Numero2, vers);
                }

                cout << "\n\nVoulez-vous effectuer un autre virement ?\nTaper \t 1-oui \t 0-non\nReponse : ";
                cin >> reponse;
            } while (reponse == 1);

            cout << "\n\nVoulez-vous revenir au Menu Principal?\n\n";
            cout << "0-pour fermer      1-menu principal\nReponse : ";
            cin >> Reveniraumenuprincipal;
            if (Reveniraumenuprincipal == 1)
            {
                system("cls");
            }

            break;
        }
        default: {
            cout << "Aucun choix effectue !!!!";
        }
        }

    } while (Reveniraumenuprincipal == 1);

    return 0;//Ajouter choix quitter le programme
    //Pour le cas 1 tant que repose==1 ou 0 répéter
}
