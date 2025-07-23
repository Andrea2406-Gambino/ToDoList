#include "todolist.h"
#include <iostream>
#include <stdexcept>
void ToDoList::StampaAttivita() const {
    std::cout << "--- Lista delle Attività ---" << std::endl;
    if (lista.empty()) {
        std::cout << "Nessuna attività nella lista." << std::endl;
        return;
    }
    for (const auto& attivita_ptr : lista) {
        // Usiamo il puntatore per chiamare i metodi polimorfici
        std::cout << "Tipo: " << attivita_ptr->GetTipoAttivita()
                  << ", Descrizione: " << attivita_ptr->GetDescrizione()
                  << ", Urgente: " << (attivita_ptr->GetUrgente() ? "Sì" : "No")
                  << ", Completata: " << (attivita_ptr->GetCompletata() ? "Sì" : "No") << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}
void ToDoList::AggiungiAttivita(std::unique_ptr<Attivita> attivita) {
    if (attivita) {
        lista.push_back(std::move(attivita));
    } else {
        throw std::invalid_argument("Attività nulla: impossibile aggiungere alla lista.");
    }
}
std::vector<const Attivita*> ToDoList::GetListaCompletate() const {
    std::vector<const Attivita*> attivitaCompletate;
    for (const auto& attivita_ptr : lista) {
        if (attivita_ptr->GetCompletata()) {
            attivitaCompletate.push_back(attivita_ptr.get());
        }
    }
    return attivitaCompletate;
}
std::vector<const Attivita*> ToDoList::GetListaLavoro() const {
    std::vector<const Attivita*> attivitaLavoro;
    for (const auto& attivita_ptr : lista) {
        if (attivita_ptr->GetTipoAttivita() == "Lavorativa") {
            attivitaLavoro.push_back(attivita_ptr.get());
        }
    }
    return attivitaLavoro;
}
void ToDoList::SetAttivitaCompletata(const std::string& descrizione, bool completata) {
    for (const auto& attivita_ptr : lista) { // Ora l'accesso a 'lista' è consentito qui (nel membro della classe)
        if (attivita_ptr->GetDescrizione() == descrizione) {
            attivita_ptr->SetCompletata(completata); // Chiamata al setter
            return; // Trovato e modificato, esci
        }
    }
}
std::vector<const Attivita*> ToDoList::GetListaHobby() const {
    std::vector<const Attivita*> attivitaHobby;
    for (const auto& attivita_ptr : lista) {
        if (attivita_ptr->GetTipoAttivita() == "Ricreativa") {
            attivitaHobby.push_back(attivita_ptr.get());
        }
    }
    return attivitaHobby;
}
