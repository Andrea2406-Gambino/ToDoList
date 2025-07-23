#ifndef TODOLIST_ATTIVITA_H
#define TODOLIST_ATTIVITA_H
#include <string>
class Attivita {
public:
    explicit Attivita(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_);
    virtual ~Attivita() = default;
    bool operator==(const Attivita& other) const;
    virtual std::string GetTipoAttivita() const = 0;
    virtual void SetTipoAttivita(const std::string& tipo_) = 0;
    bool GetUrgente() const;
    void SetUrgente(bool urgente_);
    int GetLivelloDifficolta() const;
    void SetLivelloDifficolta(const int& livelloDifficolta_);
    std::string GetDescrizione() const;
    void SetDescrizione(const std::string& descrizione);
    bool GetCompletata() const;
    void SetCompletata(bool completata_);
protected:
    bool urgente;
    int livelloDifficolta;
    std::string descrizione;
    bool completata;
    std::string tipoAttivita;
};
class AttivitaLavorativa : public Attivita {
public:
    explicit AttivitaLavorativa(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_, std::string nomeProgetto_);

    std::string GetNomeProgetto() const;
    void SetNomeProgetto(const std::string& nomeProgetto_);

    std::string GetTipoAttivita() const override;
    void SetTipoAttivita(const std::string& tipo_) override; // Usare const std::string&
private: // Specificatore di accesso esplicito
    std::string nomeProgetto;
};
class AttivitaRicreativa : public Attivita {
public:
    explicit AttivitaRicreativa(bool urgente_, int livelloDifficolta_, std::string descrizione_, bool completata_, std::string tipoHobby_);
    std::string GetTipoHobby() const;
    void SetTipoHobby(const std::string& tipoHobby_);
    std::string GetTipoAttivita() const override;
    void SetTipoAttivita(const std::string& tipo_) override;
private:
    std::string tipoHobby;
};
#endif //TODOLIST_ATTIVITA_H
