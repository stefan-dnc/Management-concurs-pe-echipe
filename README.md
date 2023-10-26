# Management concurs pe echipe

Acest proiect reprezintă o aplicație simplă de management a unui concurs organizat pe echipe, implementată în limbajul de programare `C++`. Scopul principal al acestei aplicații este să faciliteze înregistrarea și gestionarea participanților și echipelor în cadrul unui concurs, oferind funcționalități de bază pentru organizarea și desfășurarea competiției.

## Utilizare

Se recomandă utilizarea `C++23` pentru a asigura rularea corectă a programului. Este posibil ca versiunile anterioare de `C++` să corespundă standardelor `C++23` utilizate însă nu sunt recomandate.

## Funcționalități

- înregistrarea participanților
- crearea echipelor
- gestionarea echipelor
- înregistrarea rezultatelor
- generarea clasamentului

## Clase

`class Student {}`:

- reține numele studentului
- include constructor de inițializare, copiere, operator `=` de copiere, destructor, operator `<<` pentru afișare

`class Team {}`

- retine studenții, numărul studenților dintr-o echipă și punctajul echipei
- funcție `void addStudent(const Student &s) {}` pentru adăugarea unui student în echipa respectivă dacă echipa nu este deja plină
- funcție `void addPunctaj(const int p) {}` pentru adăugarea de punctaj pentru echipa respectivă
- funcție `int getPunctaj() {}` care returnează punctajul echipei pentru formarea clasamentului
- include constructor de inițializare, copiere, operator `=` de copiere, destructor, operator `<<` pentru afișare

`class Concurs {}`

- reține echipele și numărul lor
- funcție `void addTeam(const Team &team) {}` pentru adăugarea unei echipe în concurs
- funcție `void showTeam(const int i) {}` pentru afișarea unei echipe din concurs
- funcție `void addPunctajComp(const int i, const int p) {}` pentru apelarea funcției de adăugare a punctajului echipei alese
- funcție `void addStudentToTeam(const int i, const Student &s) {}` pentru adăugarea unui student în echipa aleasă din concurs
- funcție `void afiseazaTeam(const int i) {}` pentru afișarea unei echipe din concurs
- funcție `void afiseazaClasament() {}` pentru afișarea clasamentului în ordine descrescătoare punctajelor obținute
- funcție `void reseteazaPunctaje() {}` pentru resetarea punctajelor în cazul unor erori de introducere a datelor sau pentru începerea unei noi runde din concurs
- include constructor de inițializare, copiere, operator `=` de copiere, destructor, operator `<<` pentru afișare

## Meniuri publice

Meniu principal

```
Meniu:
1. Meniu echipa
2. Meniu student
3. Meniu concurs
0. Exit
```

Meniu echipe

```
Meniu echipe:
1. Adauga echipa
2. Afiseaza echipele
0. Exit
```

Meniu studenti

```
Meniu studenti:
1. Adauga student
2. Afiseaza studentii
0. Exit
```
