#include "todolist.h"
#include "Attività.h"
#include <iostream>
#include <limits>   // Per std::numeric_limits
  // Per std::unique_ptr
#include <string>
#include <vector>
// Funzione helper per pulire il buffer di input
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int main() {
    ToDoList miaLista;
    int scelta;
    std::string descrizione;
    std::string tipoAttivitaInput;
    int livelloDifficolta;
    do {
        std::cout << "\n--- MENU TO-DO LIST ---" << std::endl;
        std::cout << "1. Aggiungi Attività" << std::endl;
        std::cout << "2. Visualizza Tutte le Attività" << std::endl;
        std::cout << "3. Marca Attività come Completata/Non Completata" << std::endl;
        std::cout << "4. Visualizza Attività Completate" << std::endl;
        std::cout << "5. Visualizza Attività di Lavoro" << std::endl;
        std::cout << "6. Visualizza Attività Ricreative (Hobby)" << std::endl;
        std::cout << "0. Esci" << std::endl;
        std::cout << "Scegli un'opzione: ";
        std::cin >> scelta;
        if (std::cin.fail()) {
            std::cout << "Input non valido. Inserisci un numero." << std::endl;
            std::cin.clear(); // Resetta lo stato di errore
            clearInputBuffer(); // Pulisci il buffer di input
            continue; // Torna all'inizio del ciclo
        }
        clearInputBuffer(); // Pulisci il buffer dopo aver letto il numero
        switch (scelta) {
            case 1: {
                std::cout << "Descrizione dell'attività: ";
                std::getline(std::cin, descrizione);
                std::cout << "Livello di difficoltà (1-10): ";
                std::cin >> livelloDifficolta;
                if (std::cin.fail() || livelloDifficolta < 1 || livelloDifficolta > 10) {
                    std::cout << "Input non valido per il livello di difficoltà. Impostato a 5." << std::endl;
                    livelloDifficolta = 5;
                }
                clearInputBuffer();
                std::cout << "È urgente? (s/n): ";
                char urg_char;
                std::cin >> urg_char;
                bool  urgente = (urg_char == 's' || urg_char == 'S');
                clearInputBuffer();
                std::cout << "Tipo di attività (Lavorativa/Ricreativa): ";
                std::getline(std::cin, tipoAttivitaInput);
                std::unique_ptr<Attivita> nuovaAttivita;
                if (tipoAttivitaInput == "Lavorativa" || tipoAttivitaInput == "lavorativa") {
                    std::cout << "Nome del progetto: ";
                    std::string nomeProgetto;
                    std::getline(std::cin, nomeProgetto);
                    nuovaAttivita = std::make_unique<AttivitaLavorativa>(urgente, livelloDifficolta, descrizione, false, nomeProgetto);
                } else if (tipoAttivitaInput == "Ricreativa" || tipoAttivitaInput == "ricreativa") {
                    std::cout << "Tipo di hobby: ";
                    std::string tipoHobby;
                    std::getline(std::cin, tipoHobby);
                    nuovaAttivita = std::make_unique<AttivitaRicreativa>(urgente, livelloDifficolta, descrizione, false, tipoHobby);
                } else {
                    std::cout << "Tipo di attività non riconosciuto. Aggiunto come Attività generica." << std::endl;
                    std::cout << "Errore: Impossibile creare attività di tipo generico. Si prega di scegliere 'Lavorativa' o 'Ricreativa'." << std::endl;
                    break; // Esci dal case per evitare di aggiungere un puntatore nullo
                }
                try {
                    miaLista.AggiungiAttivita(std::move(nuovaAttivita));
                    std::cout << "Attività aggiunta con successo!" << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Errore nell'aggiungere l'attività: " << e.what() << std::endl;
                }
                break;
            }
            case 2:
                miaLista.StampaAttivita();
                break;
            case 3: {
                std::cout << "Descrizione dell'attività da modificare: ";
                std::getline(std::cin, descrizione);
                std::cout << "Contrassegnare come completata? (s/n): ";
                char comp_char;
                std::cin >> comp_char;
                bool completata = (comp_char == 's' || comp_char == 'S');
                clearInputBuffer();
                miaLista.SetAttivitaCompletata(descrizione, completata);
                std::cout << "Stato attività aggiornato (o attività non trovata)." << std::endl;
                break;
            }
            case 4: {
                std::vector<const Attivita*> completate = miaLista.GetListaCompletate();
                if (completate.empty()) {
                    std::cout << "Nessuna attività completata." << std::endl;
                } else {
                    std::cout << "\n--- Attività Completate ---" << std::endl;
                    for (const auto& attivita : completate) {
                        std::cout << "Tipo: " << attivita->GetTipoAttivita()
                                  << ", Descrizione: " << attivita->GetDescrizione()
                                  << ", Urgente: " << (attivita->GetUrgente() ? "Sì" : "No") << std::endl;
                    }
                    std::cout << "--------------------------" << std::endl;
                }
                break;
            }
            case 5: {
                std::vector<const Attivita*> lavoro = miaLista.GetListaLavoro();
                if (lavoro.empty()) {
                    std::cout << "Nessuna attività di lavoro." << std::endl;
                } else {
                    std::cout << "\n--- Attività di Lavoro ---" << std::endl;
                    for (const auto& attivita : lavoro) {
                        std::cout << "Tipo: " << attivita->GetTipoAttivita()
                                  << ", Descrizione: " << attivita->GetDescrizione()
                                  << ", Urgente: " << (attivita->GetUrgente() ? "Sì" : "No") << std::endl;
                    }
                    std::cout << "-------------------------" << std::endl;
                }
                break;
            }
            case 6: {
                std::vector<const Attivita*> hobby = miaLista.GetListaHobby();
                if (hobby.empty()) {
                    std::cout << "Nessuna attività ricreativa (hobby)." << std::endl;
                } else {
                    std::cout << "\n--- Attività Ricreative (Hobby) ---" << std::endl;
                    for (const auto& attivita : hobby) {
                        std::cout << "Tipo: " << attivita->GetTipoAttivita()
                                  << ", Descrizione: " << attivita->GetDescrizione()
                                  << ", Urgente: " << (attivita->GetUrgente() ? "Sì" : "No") << std::endl;
                    }
                    std::cout << "---------------------------------" << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Uscita dal programma. Arrivederci!" << std::endl;
                break;
            default:
                std::cout << "Scelta non valida. Riprova." << std::endl;
                break;
        }
    } while (scelta != 0);
    return 0;
}
