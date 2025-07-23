#include "Attività.h"
Attivita::Attivita(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_)
    : urgente(urgente_), livelloDifficolta(livelloDifficolta_), descrizione(std::move(descrizione_)), completata(completata_) {}
bool Attivita::operator==(const Attivita& other) const {
    return (urgente == other.urgente &&
            livelloDifficolta == other.livelloDifficolta &&
            descrizione == other.descrizione &&
            completata == other.completata);
}
bool Attivita::GetUrgente() const {
    return urgente;
}
void Attivita::SetUrgente(bool urgente_) {
    urgente = urgente_;
}
int Attivita::GetLivelloDifficolta() const {
    return livelloDifficolta;
}
void Attivita::SetLivelloDifficolta(const int& livelloDifficolta_) {
    livelloDifficolta = livelloDifficolta_;
}
std::string Attivita::GetDescrizione() const {
    return descrizione;
}
void Attivita::SetDescrizione(const std::string& descrizione_) {
    descrizione = descrizione_;
}
bool Attivita::GetCompletata() const {
    return completata;
}
void Attivita::SetCompletata(bool completata_) { // Modificato per accettare un bool
    completata = completata_;
}
AttivitaRicreativa::AttivitaRicreativa(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_, std::string tipoHobby_)
    : Attivita(urgente_, livelloDifficolta_, std::move(descrizione_), completata_), tipoHobby(std::move(tipoHobby_)) {
    this->tipoAttivita = "Ricreativa";
}
std::string AttivitaRicreativa::GetTipoHobby() const {
    return tipoHobby;
}
void AttivitaRicreativa::SetTipoHobby(const std::string& tipoHobby_) {
    tipoHobby = tipoHobby_;
}
std::string AttivitaRicreativa::GetTipoAttivita() const {
    return tipoAttivita;
}
void AttivitaRicreativa::SetTipoAttivita(const std::string& tipo_){ // Corretto nome e firma (const std::string&)
    tipoAttivita = tipo_;
}
AttivitaLavorativa::AttivitaLavorativa(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_, std::string nomeProgetto_)
    : Attivita(urgente_, livelloDifficolta_, std::move(descrizione_), completata_), nomeProgetto(std::move(nomeProgetto_)) {
    this->tipoAttivita = "Lavorativa";
}
std::string AttivitaLavorativa::GetNomeProgetto() const { // Corretto il nome del metodo
    return nomeProgetto;
}
void AttivitaLavorativa::SetNomeProgetto(const std::string& nomeProgetto_) {
    nomeProgetto = nomeProgetto_;
}
std::string AttivitaLavorativa::GetTipoAttivita() const{
    return tipoAttivita;
}
void AttivitaLavorativa::SetTipoAttivita(const std::string& tipo_){
    tipoAttivita = tipo_;
}

