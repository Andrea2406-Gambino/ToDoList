ToDoList
Definizione Generale
ToDoList è un'applicazione sviluppata in C++ per la gestione organizzata delle attività. Permette agli utenti di tenere traccia dei propri impegni, distinguendo tra quelli di natura lavorativa e quelli ricreativi. L'applicazione mira a fornire uno strumento semplice ma efficace per monitorare lo stato delle attività, la loro urgenza e il livello di difficoltà.

Funzionalità
Gestione Completa delle Attività: Aggiunta, visualizzazione e marcatura delle attività come completate.
Classificazione Dettagliata: Le attività possono essere distinte in categorie specifiche (lavorative, ricreative) e ulteriormente caratterizzate da urgenza e livello di difficoltà.
Filtri e Visualizzazioni: Possibilità di stampare tutte le attività o di filtrare l'elenco per visualizzare solo quelle completate, lavorative o ricreative.
Affidabilità tramite Test: Il codice è supportato da test unitari robusti, sviluppati con Google Test, per garantire la sua correttezza e stabilità.
Struttura del Progetto
Il progetto è organizzato in modo modulare per facilitare la gestione e lo sviluppo: 
ToDoList/
├── .idea/                      # Cartella di configurazione di CLion (ignorata da Git)
├── cmake-build-debug/          # Cartella di build generata da CMake (ignorata da Git)
├── googletest/                 # Libreria Google Test (scaricata da GitHub)
├── src/                        # Contiene il codice sorgente principale dell'applicazione
│   ├── Attività.h
│   ├── Attività.cpp
│   ├── todolist.h
│   ├── todolist.cpp
│   └── main.cpp                # (Se presente, l'eseguibile principale del programma)
├── tests/                      # Contiene i test unitari
│   ├── test_attivita.cpp
│   ├── test_todolist.cpp
├── CMakeLists.txt              # File di configurazione del progetto per CMake
├── .gitignore                  # Specifica i file e le cartelle da ignorare da Git
└── README.md                   # Questo file
Ecco una versione aggiornata del file README.md che riflette le tue richieste, con una definizione generale, le funzionalità, lo schema delle cartelle e una spiegazione sommaria delle classi.

ToDoList
Definizione Generale
ToDoList è un'applicazione sviluppata in C++ per la gestione organizzata delle attività. Permette agli utenti di tenere traccia dei propri impegni, distinguendo tra quelli di natura lavorativa e quelli ricreativi. L'applicazione mira a fornire uno strumento semplice ma efficace per monitorare lo stato delle attività, la loro urgenza e il livello di difficoltà.

Funzionalità
Gestione Completa delle Attività: Aggiunta, visualizzazione e marcatura delle attività come completate.

Classificazione Dettagliata: Le attività possono essere distinte in categorie specifiche (lavorative, ricreative) e ulteriormente caratterizzate da urgenza e livello di difficoltà.

Filtri e Visualizzazioni: Possibilità di stampare tutte le attività o di filtrare l'elenco per visualizzare solo quelle completate, lavorative o ricreative.

Affidabilità tramite Test: Il codice è supportato da test unitari robusti, sviluppati con Google Test, per garantire la sua correttezza e stabilità.

Struttura del Progetto
Il progetto è organizzato in modo modulare per facilitare la gestione e lo sviluppo.

ToDoList/
├── .idea/                      # Cartella di configurazione di CLion (ignorata da Git)
├── cmake-build-debug/          # Cartella di build generata da CMake (ignorata da Git)
├── googletest/                 # Libreria Google Test (scaricata da GitHub)
├── src/                        # Contiene il codice sorgente principale dell'applicazione
│   ├── Attività.h
│   ├── Attività.cpp
│   ├── todolist.h
│   ├── todolist.cpp
│   └── main.cpp                # (Se presente, l'eseguibile principale del programma)
├── tests/                      # Contiene i test unitari
│   ├── test_attivita.cpp
│   ├── test_todolist.cpp
├── CMakeLists.txt              # File di configurazione del progetto per CMake
├── .gitignore                  # Specifica i file e le cartelle da ignorare da Git
└── README.md                   # Questo file
Panoramica delle Classi
Il cuore dell'applicazione è basato su un design orientato agli oggetti con le seguenti classi principali:
Attivita (src/Attività.h, src/Attività.cpp):
Questa è la classe base che definisce le proprietà e i comportamenti comuni a tutte le attività, come descrizione, urgenza e stato di completamento. È astratta, il che significa che non si possono creare direttamente oggetti Attivita, ma serve da modello per tipi più specifici.
AttivitaLavorativa (src/Attività.h, src/Attività.cpp):
È una specializzazione di Attivita, progettata per rappresentare compiti legati al lavoro o a progetti specifici. Aggiunge un attributo per il nome del progetto.
AttivitaRicreativa (src/Attività.h, src/Attività.cpp):
Un'altra specializzazione di Attivita, pensata per attività di svago o hobby. Include un attributo per specificare il tipo di hobby.
ToDoList (src/todolist.h, src/todolist.cpp):
Questa classe agisce come un contenitore per tutte le attività. Gestisce l'aggiunta, la modifica dello stato (completata) e la visualizzazione delle attività. È il punto centrale per interagire con l'intera collezione di attività.
