#include <iostream>

class Student
{
private:
    std::string name;

public:
    Student(){};
    Student(std::string name) : name(name)
    {
    }

    ~Student()
    {
        std::cout << "Obiectul Student a fost distrus." << std::endl;
    }

    Student(const Student &other) : name(other.name) {}

    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            name = other.name;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &s)
    {
        os << s.name;
        return os;
    };
};

class Team
{
private:
    Student students[4];
    int numStudents;
    int punctaj;

public:
    Team() : students(), numStudents(0), punctaj(0) {}

    ~Team()
    {
        std::cout << "Obiectul Team a fost distrus." << std::endl;
    }

    Team(const Team &other) : students(), numStudents(other.numStudents)
    {
        for (int i = 0; i < numStudents; ++i)
        {
            students[i] = other.students[i];
        }
    }

    void addStudent(const Student &s)
    {
        if (numStudents < 4)
        {
            students[numStudents] = s;
            ++numStudents;
        }
        else
        {
            std::cout << "Echipa este deja plina." << std::endl;
        }
    }

    void addPunctaj(const int p)
    {
        punctaj += p;
    }

    int getPunctaj()
    {
        return punctaj;
    }

    Team &operator=(const Team &other)
    {
        if (this != &other)
        {
            numStudents = other.numStudents;
            for (int i = 0; i < numStudents; ++i)
            {
                students[i] = other.students[i];
            }
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Team &t)
    {
        for (int i = 0; i < t.numStudents; ++i)
        {
            os << "• " << t.students[i] << std::endl;
        }
        return os;
    }
};

class Concurs
{
private:
    Team teams[10];
    int numTeams;

public:
    Concurs() : numTeams(0) {}

    ~Concurs()
    {
        std::cout << "Obiectul Concurs a fost distrus." << std::endl;
    }

    Concurs(const Concurs &other) : numTeams(other.numTeams)
    {
        for (int i = 0; i < numTeams; ++i)
        {
            teams[i] = other.teams[i];
        }
    }

    Concurs &operator=(const Concurs &other)
    {
        if (this != &other)
        {
            numTeams = other.numTeams;
            for (int i = 0; i < numTeams; ++i)
            {
                teams[i] = other.teams[i];
            }
        }
        return *this;
    }

    void addTeam(const Team &team)
    {
        if (numTeams < 10)
        {
            teams[numTeams++] = team;
        }
        else
        {
            std::cout << "Numarul maxim de echipe a fost atins." << std::endl;
        }
    }

    void showTeam(const int i)
    {
        std::cout << "Studentii din echipa " << i << ":\n";
        std::cout << teams[i - 1] << std::endl;
        std::cout << "Punctaj: " << teams[i - 1].getPunctaj() << "\n\n";
    }

    void addPunctajComp(const int i, const int p)
    {
        teams[i - 1].addPunctaj(p);
    }

    void addStudentToTeam(const int i, const Student &s)
    {
        if (i > 0 && i <= numTeams)
        {
            teams[i - 1].addStudent(s);
        }
        else
        {
            std::cout << "Numarul echipei este invalid. Este necesar un numar intre 1 si 10" << std::endl;
        }
    }

    void afiseazaTeam(const int i)
    {
        std::cout << teams[i - 1];
    }

    void afiseazaClasament()
    {
        int *punctaje = new int[numTeams];
        int *echipe = new int[numTeams];
        for (int i = 0; i < numTeams; ++i)
        {
            punctaje[i] = teams[i].getPunctaj();
            echipe[i] = i;
        }

        for (int i = 0; i < numTeams; ++i)
        {
            for (int j = 0; j < numTeams; ++j)
            {
                if (punctaje[i] > punctaje[j])
                {
                    std::swap(punctaje[i], punctaje[j]);
                    std::swap(echipe[i], echipe[j]);
                }
            }
        }

        for (int i = 0; i < numTeams; ++i)
        {
            std::cout << "Echipa " << i + 1 << ":\n";
            std::cout << teams[echipe[i]];
            std::cout << "Punctaj: " << teams[echipe[i]].getPunctaj() << "\n\n";
        }
    }

    void reseteazaPunctaje()
    {
        for (int i = 0; i < numTeams; ++i)
        {
            teams[i].addPunctaj(-teams[i].getPunctaj());
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Concurs &c)
    {
        for (int i = 0; i < c.numTeams; ++i)
        {
            os << "Studentii din echipa " << i + 1 << ":\n";
            os << c.teams[i] << std::endl;
        }
        return os;
    }
};

int main()
{
    Student s1("Ion");
    Student s2("Gheorghe");
    Student s3("Vasile");
    Student s4("Mihai");
    Student s5("Andrei");
    Student s6("Marius");
    Student s7("Cristi");
    Student s8("Alex");
    Student s9("Vlad");
    Student s10("Ionut");
    Student s11("Alexandra");
    Student s12("Cristi");
    Student s13("Alex");
    Student s14("Amalia");
    Student s15("Irina");
    Student s16("Bogdan");

    Team t1;
    t1.addStudent(s1);
    t1.addStudent(s2);
    t1.addStudent(s3);
    t1.addStudent(s4);

    Team t2;
    t2.addStudent(s5);
    t2.addStudent(s6);
    t2.addStudent(s7);
    t2.addStudent(s8);

    Team t3;
    t3.addStudent(s9);
    t3.addStudent(s10);
    t3.addStudent(s11);
    t3.addStudent(s12);

    Team t4;
    t4.addStudent(s13);
    t4.addStudent(s14);
    t4.addStudent(s15);
    t4.addStudent(s16);

    Concurs c;
    c.addTeam(t1);
    c.addTeam(t2);
    c.addTeam(t3);
    c.addTeam(t4);

    // MENIU

    std::cout << "Meniu:\n";
    std::cout << "1. Meniu echipe\n";
    std::cout << "2. Meniu studenti\n";
    std::cout << "3. Meniu concurs\n";
    std::cout << "0. Exit\n";

    int optiune;
    std::cout << "Optiune: ";
    std::cin >> optiune;
    std::cout << "\n\n";

    while (optiune != 0)
    {
        switch (optiune)
        {
        case 1:
        {
            std::cout << "\n\n\n";
            std::cout << "Meniu echipe:\n";
            std::cout << "1. Adauga echipa\n";
            std::cout << "2. Afiseaza echipele\n";
            std::cout << "0. Exit\n";

            int optiune2;
            std::cout << "Optiune: ";
            std::cin >> optiune2;
            std::cout << "\n\n";

            while (optiune2 != 0)
            {
                switch (optiune2)
                {
                case 1:
                {
                    Team t;
                    c.addTeam(t);
                    break;
                }
                case 2:
                {
                    std::cout << c << std::endl;
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    std::cout << "Optiune invalida." << std::endl;
                    break;
                }
                }

                std::cout << "Meniu echipe:\n";
                std::cout << "1. Adauga echipa\n";
                std::cout << "2. Afiseaza echipele\n";
                std::cout << "0. Exit\n";
                std::cout << "Optiune: ";
                std::cin >> optiune2;
                std::cout << "\n\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "\n\n\n";
            std::cout << "Meniu studenti:\n";
            std::cout << "1. Adauga student\n";
            std::cout << "2. Afiseaza studentii\n";
            std::cout << "0. Exit\n";

            int optiune2;
            std::cout << "Optiune: ";
            std::cin >> optiune2;
            std::cout << "\n\n";

            while (optiune2 != 0)
            {
                switch (optiune2)
                {
                case 1:
                {
                    std::string name;
                    std::cout << "Nume student: ";
                    std::cin >> name;
                    Student s(name);
                    std::cout << "Echipa: ";
                    int echipa;
                    std::cin >> echipa;
                    c.addStudentToTeam(echipa, s);
                    break;
                }
                case 2:
                {
                    std::cout << "Echipa: ";
                    int echipa;
                    std::cin >> echipa;
                    c.afiseazaTeam(echipa);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    std::cout << "Optiune invalida." << std::endl;
                    break;
                }
                }

                std::cout << "\n\n\n";
                std::cout << "Meniu studenti:\n";
                std::cout << "1. Adauga student\n";
                std::cout << "2. Afiseaza studentii\n";
                std::cout << "0. Exit\n";
                std::cin >> optiune2;
                std::cout << "\n\n";
            }
            break;
        }
        case 3:
        {
            std::cout << "\n\n\n";
            std::cout << "Meniu concurs:\n";
            std::cout << "1. Adauga punctaj\n";
            std::cout << "2. Afiseaza clasament\n";
            std::cout << "3. Reseteaza punctaje\n";
            std::cout << "0. Exit\n";

            int optiune2;
            std::cout << "Optiune: ";
            std::cin >> optiune2;
            std::cout << "\n\n";

            while (optiune2 != 0)
            {
                switch (optiune2)
                {
                case 1:
                {
                    std::cout << "Echipa: ";
                    int echipa;
                    std::cin >> echipa;
                    std::cout << "Punctaj: ";
                    int punctaj;
                    std::cin >> punctaj;
                    c.addPunctajComp(echipa, punctaj);
                    break;
                }
                case 2:
                {
                    c.afiseazaClasament();
                    break;
                }
                case 3:
                {
                    c.reseteazaPunctaje();
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    std::cout << "Optiune invalida." << std::endl;
                    break;
                }
                }

                std::cout << "\n\n\n";
                std::cout << "Meniu concurs:\n";
                std::cout << "1. Adauga punctaj\n";
                std::cout << "2. Afiseaza clasament\n";
                std::cout << "3. Reseteaza punctaje\n";
                std::cout << "0. Exit\n";
                std::cin >> optiune2;
                std::cout << "\n\n";
            }
            break;
        }
        case 0:
        {
            std::cout << "Shutting down..." << std::endl;
            break;
        }
        default:
        {
            std::cout << "Optiune invalida." << std::endl;
            break;
        }
        }
        std::cout << "Meniu:\n";
        std::cout << "1. Meniu echipe\n";
        std::cout << "2. Meniu studenti\n";
        std::cout << "3. Meniu concurs\n";
        std::cout << "0. Exit\n";

        std::cout << "Optiune: ";
        std::cin >> optiune;
        std::cout << "\n\n";
    }

    return 0;
}