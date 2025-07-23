cmake_minimum_required(VERSION 3.14)
project(ToDoList)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Aggiungi la cartella googletest
add_subdirectory(googletest)

# Sorgenti principali
set(SOURCE_FILES
        src/Attività.cpp
        src/todolist.cpp
)
# Libreria con il codice principale
add_library(todolist_lib ${SOURCE_FILES})
target_include_directories(todolist_lib PUBLIC src)
# Eseguibile principale (se vuoi)
add_executable(ToDoList
        src/main.cpp # se ce l'hai, altrimenti rimuovi questa parte
)
target_link_libraries(ToDoList todolist_lib)
# Eseguibile dei test
add_executable(tests
        tests/test_attivita.cpp
        tests/test_todolist.cpp
)
target_link_libraries(tests
        todolist_lib
        gtest_main
)
# Abilita testing
enable_testing()
add_test(NAME tests COMMAND tests)
