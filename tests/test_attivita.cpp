#include <gtest/gtest.h>
#include "Attività.h"
// Test costruttore e getter per AttivitaLavorativa
TEST(AttivitaTest, AttivitaLavorativa_CostruzioneEGetter) {
    AttivitaLavorativa att(true, 3, "Progetto CLion", false, "ProgettoX");
    EXPECT_TRUE(att.GetUrgente());
    EXPECT_EQ(att.GetLivelloDifficolta(), 3);
    EXPECT_EQ(att.GetDescrizione(), "Progetto CLion");
    EXPECT_FALSE(att.GetCompletata());
    EXPECT_EQ(att.GetNomeProgetto(), "ProgettoX");
    EXPECT_EQ(att.GetTipoAttivita(), "Lavorativa");
}
// Test costruttore e getter per AttivitaRicreativa
TEST(AttivitaTest, AttivitaRicreativa_CostruzioneEGetter) {
    AttivitaRicreativa att(false, 1, "Giochi", true, "Videogiochi");
    EXPECT_FALSE(att.GetUrgente());
    EXPECT_EQ(att.GetLivelloDifficolta(), 1);
    EXPECT_EQ(att.GetDescrizione(), "Giochi");
    EXPECT_TRUE(att.GetCompletata());
    EXPECT_EQ(att.GetTipoHobby(), "Videogiochi");
    EXPECT_EQ(att.GetTipoAttivita(), "Ricreativa");
}
// Test operator==
TEST(AttivitaTest, OperatorEquals) {
    AttivitaLavorativa att1(true, 2, "Test", false, "Proj");
    AttivitaLavorativa att2(true, 2, "Test", false, "Proj");
    AttivitaLavorativa att3(false, 2, "Test", false, "Proj");
    EXPECT_TRUE(att1 == att2);
    EXPECT_FALSE(att1 == att3);
}