#include <gtest/gtest.h>
#include "todolist.h"
#include "Attività.h"
TEST(ToDoListTest, AggiungiEStampa) {
    ToDoList todo;
    auto att1 = std::make_unique<AttivitaLavorativa>(true, 2, "Scrivere codice", false, "Progetto1");
    auto att2 = std::make_unique<AttivitaRicreativa>(false, 1, "Giocare a scacchi", true, "Hobby");
    todo.AggiungiAttivita(std::move(att1));
    todo.AggiungiAttivita(std::move(att2));
    auto completate = todo.GetListaCompletate();
    EXPECT_EQ(completate.size(), 1);
    EXPECT_EQ(completate.at(0)->GetDescrizione(), "Giocare a scacchi");
    auto lavoro = todo.GetListaLavoro();
    EXPECT_EQ(lavoro.size(), 1);
    EXPECT_EQ(lavoro.at(0)->GetDescrizione(), "Scrivere codice");
    auto hobby = todo.GetListaHobby();
    EXPECT_EQ(hobby.size(), 1);
    EXPECT_EQ(hobby.at(0)->GetDescrizione(), "Giocare a scacchi");
    todo.SetAttivitaCompletata("Scrivere codice", true);
    completate = todo.GetListaCompletate();
    EXPECT_EQ(completate.size(), 2);
}
TEST(ToDoListTest, SetAttivitaCompletata_NonEsiste) {
    ToDoList todo;
    EXPECT_NO_THROW(todo.SetAttivitaCompletata("Non esiste", true));
}