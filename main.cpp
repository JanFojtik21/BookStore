#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class Book {
    public:
    std::string nazev_knihy;
    std::string autor_knihy;
    int id;
    unsigned int rok_vydani;
    int mnozstvi;

    // Konstruktorek vytvoren
    Book(std::string nazev, std::string autor, int _id, unsigned int rok, int _mnozstvi)
        : nazev_knihy(nazev), autor_knihy(autor), id(_id), rok_vydani(rok), mnozstvi(_mnozstvi) {}

    void upravKnihu(std::string novyNazev, std::string novy_autor, int _newid, unsigned int novy_rok_vydani, int nove_mnozstvi){
        nazev_knihy = novyNazev;
        autor_knihy = novy_autor;
        rok_vydani = novy_rok_vydani;
        mnozstvi = nove_mnozstvi;


    // dopln funkci pro hledani knihy pro me pls.
    }
     bool hledejKnihu(const std::string& searchNazev, const std::string& searchAutor)const {
        return (nazev_knihy == searchNazev && autor_knihy == searchAutor);

    }

};

int main() {
    std::vector<Book> books;  // Vytvoření vektoru pro ukládání knih

    std::string nazev_knihy;
    std::string autor_knihy;
    int id;
    unsigned int rok_vydani;
    int mnozstvi = 1;

    // Vyzva uzivateli k zadani informaci od uzivatele.
    std::cout << "Zadej nazev knihy: ";
    std::getline(std::cin, nazev_knihy);

    std::cout << "Zadej nazev autora: ";
    std::getline(std::cin, autor_knihy);

    std::cout << "Zadej rok: ";
    std::cin >> rok_vydani;
    std::cin.ignore();

    std::cout << "Zadej id: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Zadej mnozstvi: ";
    std::cin >> mnozstvi;

    // Přidání knihy do vektoru books
    books.push_back(Book(nazev_knihy, autor_knihy, id, rok_vydani, mnozstvi));

    // Otevření souboru pro zápis CSV a uložení záznamů
    std::ofstream file("knihy.csv"); // Otevřít soubor pro zápis

    if (file.is_open()) {
        for (const Book& book : books) {
            // Zapisovat hodnoty záznamu do souboru ve formátu CSV
            file << book.nazev_knihy << ","
                 << book.autor_knihy << ","
                 << book.id << ","
                 << book.rok_vydani << ","
                 << book.mnozstvi << "\n";
        }
        file.close();
        std::cout << std::endl << std::endl << "Kniha byla uspesne vlozena" << std::endl << std::endl;
    } else {
        std::cerr << "Nelze otevrit soubor pro zapis" << std::endl;
    }

    return 0;
}
