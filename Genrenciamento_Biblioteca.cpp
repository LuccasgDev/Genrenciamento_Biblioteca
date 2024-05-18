#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

struct localiza_livro {
    string corredor;
    int coluna;
    int linha;
};

struct adicionar_livro {
    string nome_livro;
    string nome_autor;
    string editora;
    string genero;
    int quantidade_dispo;
    int ano_publicacao;
    long long ISBN; //  Número Padrão Internacional de Livro é um identificador único para livros
    localiza_livro localizacao;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    int numero_livro = 0;
    char continuar;
    adicionar_livro livros[999];

    do {
        std::cout << "-------------------------\n";
        std::cout << "------ BIBLIOTECA -------\n";
        std::cout << "-------------------------\n";
        std::cout << "1- ADICIONAR\n";
        std::cout << "2- REMOVER\n";
        std::cout << "3- LOCALIZAR\n";
        std::cout << "4- SAIR\n";
        std::cout << "Informe uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
        case 1: {
            do {
                system("cls");
                std::cout << "------------------------\n";
                std::cout << "------ ADICIONAR -------\n";
                std::cout << "------------------------\n";
                std::cin.ignore();
                std::cout << "NOME DO LIVRO: \n";
                std::getline(std::cin, livros[numero_livro].nome_livro);
                std::cout << "NOME DO AUTOR(A) DO LIVRO: \n";
                std::getline(std::cin, livros[numero_livro].nome_autor);
                std::cout << "QUAL E A EDITORA: \n ";
                std::getline(std::cin, livros[numero_livro].editora);
                std::cout << "QUAL É O GENERO DO LIVRO: \n";
                std::getline(std::cin, livros[numero_livro].genero);
                std::cout << "ESSE LIVRO TEM QUANTAS QUANTIDADES: \n";
                std::cin >> livros[numero_livro].quantidade_dispo;
                std::cout << "ESSE LIVRO FOI PUBLICADO EM QUE ANO: \n";
                std::cin >> livros[numero_livro].ano_publicacao;
                std::cout << "QUAL É O ISBN DO LIVRO: \n";
                std::cin >> livros[numero_livro].ISBN;
                std::cout << "------ LOCALIZACAO -------\n";
                std::cin.ignore();
                std::cout << "O LIVRO VAI SE ENCONTRAR EM QUAL CORREDOR? \n";
                std::getline(std::cin, livros[numero_livro].localizacao.corredor);
                std::cout << "O LIVRO VAI SER ENCONTRADO EM QUAL COLUNA: \n";
                std::cin >> livros[numero_livro].localizacao.coluna;
                std::cout << "O LIVRO VAI SER ENCONTRADO EM QUAL LINHA: \n";
                std::cin >> livros[numero_livro].localizacao.linha;

                numero_livro++;

                std::cout << "Deseja adicionar outro livro? (S/N): ";
                std::cin >> continuar;
                system("cls");
            } while (toupper(continuar) == 'S');
            break;
        }
        case 2: {
            do {
                system("cls");
                std::cout << "----------------------\n";
                std::cout << "------ REMOVER -------\n";
                std::cout << "----------------------\n";
                std::cout << "DIGITE O NUMERO DO ISBN PARA REMOVER O LIVRO: ";
                long long remove_livro;
                std::cin >> remove_livro;
                bool found = false;
                for (int i = 0; i < numero_livro; i++) {
                    if (livros[i].ISBN == remove_livro) {
                        std::cout << "O livro " << livros[i].nome_livro << " foi removido\n";
                        livros[i] = livros[numero_livro - 1];
                        numero_livro--;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Livro nao encontrado.\n";
                }
                std::cout << "Deseja remover outro livro? (S/N): ";
                std::cin >> continuar;
                system("cls");
            } while (toupper(continuar) == 'S');
            break;
        }
        case 3: {
            do {
                system("cls");
                system("cls");
                std::cout << "------------------------\n";
                std::cout << "------ LOCALIZAR -------\n";
                std::cout << "------------------------\n";
                std::cout << "Voce pode localizar pelo o ISBN do livro\n";
                std::cout << "Informe o ISBN: ";
                long long locale_livro;
                std::cin >> locale_livro;
                bool found = false;
                for (int i = 0; i < numero_livro; i++) {
                    if (livros[i].ISBN == locale_livro) {
                        std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                        std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                        std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                        std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Livro nao encontrado.\n";
                }
                std::cout << "Deseja localizar outro livro? (S/N): ";
                std::cin >> continuar;
                system("cls");
            } while (toupper(continuar) == 'S');
            break;
        }
        case 4: {
            system("cls");
            std::cout << "---------------------\n";
            std::cout << "------ SAINDO -------\n";
            std::cout << "---------------------\n";
            break;
        }
        default:
            std::cout << "DIGITE A OPCAO CORRETA\n";
            break;
        }
    } while (opcao != 4);
    std::cout << "-- ATE MAIS -- ";
    return 0;
}