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
                std::cout << "QUAL E O GENERO DO LIVRO: \n";
                std::getline(std::cin, livros[numero_livro].genero);
                std::cout << "ESSE LIVRO TEM QUANTAS QUANTIDADES: \n";
                std::cin >> livros[numero_livro].quantidade_dispo;
                std::cout << "ESSE LIVRO FOI PUBLICADO EM QUE ANO: \n";
                std::cin >> livros[numero_livro].ano_publicacao;
                std::cout << "QUAL E O ISBN DO LIVRO: \n";
                std::cin >> livros[numero_livro].ISBN;
                std::cout << "------ LOCALIZACAO -------\n";
                std::cout << "so pode ter dois livros na mesma localizacao\n ";
                std::cin.ignore();
                std::cout << "O LIVRO VAI SE ENCONTRAR EM QUAL CORREDOR? \n";
                std::getline(std::cin, livros[numero_livro].localizacao.corredor);
                for (char& c : livros[numero_livro].localizacao.corredor) {
                    c = toupper(c);
                }
                std::cout << "O LIVRO VAI SER ENCONTRADO EM QUAL COLUNA: \n";
                std::cin >> livros[numero_livro].localizacao.coluna;
                std::cout << "O LIVRO VAI SER ENCONTRADO EM QUAL LINHA: \n";
                std::cin >> livros[numero_livro].localizacao.linha;
                for (int i = 0; i < numero_livro; i++) {
                    for (int j = i + 1; j < numero_livro; j++) {
                        if (livros[i].localizacao.corredor == livros[j].localizacao.corredor &&
                            livros[i].localizacao.coluna == livros[j].localizacao.coluna &&
                            livros[i].localizacao.linha == livros[j].localizacao.linha) {
                            std::cout << "Os livros " << livros[i].nome_livro << " e " << livros[j].nome_livro
                                << " estao na mesma localizacao.\n";
                        }
                    }
                    break;
                }

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
                std::cout << "------------------------\n";
                std::cout << "------ LOCALIZAR -------\n";
                std::cout << "------------------------\n";
                std::cout << "1- TODOS OS LIVROS\n";
                std::cout << "2- POR NOME DO LIVRO\n";
                std::cout << "3- POR NOME DO AUTOR\n";
                std::cout << "4- POR EDITORA\n";
                std::cout << "5- POR GENERO\n";
                std::cout << "6- POR QUANTIDADE DISPONIVEL\n";
                std::cout << "7- ANO DE PUBLICACAO\n";
                std::cout << "8- PELO O ISBN\n";
                int local;
                std::cin >> local;
                std::cin.ignore(); 
                switch (local) {
                case 1: {
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        std::cout << "O nome do livro: " << livros[i].nome_livro << "\n";
                        std::cout << "O nome do autor(a): " << livros[i].nome_autor << "\n";
                        std::cout << "O nome da editora: " << livros[i].editora << "\n";
                        std::cout << "O genero: " << livros[i].genero << "\n";
                        std::cout << "A quantidade Dispodivel: " << livros[i].quantidade_dispo << "\n";
                        std::cout << "O ano publicado: " << livros[i].ano_publicacao << "\n";
                        std::cout << "O numero ISBN do livro: " << livros[i].ISBN << "\n";
                    }
                    break;
                }
                case 2: {
                    std::cout << "DIGITE O NOME DO LIVRO: \n";
                    string locale_nome_livro;
                    std::getline(std::cin, locale_nome_livro);
                    bool found = false;
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].nome_livro == locale_nome_livro) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "Livro nao encontrado.\n";
                    }
                    break;
                }
                case 3: {
                    std::cout << "DIGITE O NOME DO AUTOR(A): \n";
                    string locale_nome_autor;
                    std::getline(std::cin, locale_nome_autor);
                    bool found = false;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].nome_autor == locale_nome_autor) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;

                        }
                    }
                    if (!found) {
                        std::cout << "Autor nao encontrado.\n";
                    }
                    break;
                }
                case 4: {
                    std::cout << "DIGITE A EDITORA: \n";
                    string locale_editora;
                    std::getline(std::cin, locale_editora);
                    bool found = false;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].editora == locale_editora) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "Editora nao encontrada.\n";
                    }
                    break;
                }
                case 5: {
                    std::cout << "DIGITE O NOME DO GENERO: \n";
                    string locale_genero;
                    std::getline(std::cin, locale_genero);
                    bool found = false;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].genero == locale_genero) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "Genero nao encontrado.\n";
                    }
                    break;
                }
                case 6: {
                    std::cout << "DIGITE A QUANTIDADE: \n";
                    int locale_quantidade;
                    std::cin >> locale_quantidade;
                    bool found = false;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].quantidade_dispo == locale_quantidade) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "Quantidade nao encontrada.\n";
                    }
                    break;
                }
                case 7: {
                    std::cout << "DIGITE O ANO DA PUBLICACAO: \n";
                    int locale_ano;
                    std::cin >> locale_ano;
                    bool found = false;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].ano_publicacao == locale_ano) {
                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "Ano de publicacao nao encontrado.\n";
                    }
                    break;
                }
                case 8: {
                    std::cout << "DIGITE O NUMERO DO ISBN: \n";
                    long long locale_isbn;
                    std::cin >> locale_isbn;
                    std::cout << "O numero(s) de livro(s): " << numero_livro << "\n";
                    bool found = false;
                    for (int i = 0; i < numero_livro; i++) {
                        std::cout << "=================================================\n";
                        if (livros[i].ISBN == locale_isbn) {

                            std::cout << "O livro " << livros[i].nome_livro << " se encontra\n";
                            std::cout << "No corredor: " << livros[i].localizacao.corredor << " \n";
                            std::cout << "Na coluna: " << livros[i].localizacao.coluna << " \n";
                            std::cout << "Na linha: " << livros[i].localizacao.linha << " \n";
                            found = true;
                        }
                    }
                    if (!found) {
                        std::cout << "ISBN nao encontrado.\n";
                    }
                    break;
                }
                default:
                    std::cout << "Opcao invalida.\n";
                    break;
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
