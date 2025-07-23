#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
#include "Attività.h"
class ToDoList {
public:
    ~ToDoList() = default;
    void StampaAttivita() const;
    void AggiungiAttivita(std::unique_ptr<Attivita> attivita);
    void SetAttivitaCompletata(const std::string& descrizione, bool completata);
    std::vector<const Attivita*> GetListaCompletate() const;
    std::vector<const Attivita*> GetListaLavoro() const;
    std::vector<const Attivita*> GetListaHobby() const;
private:
    std::vector<std::unique_ptr<Attivita>> lista;
};
#endif //TODOLIST_TODOLIST_H