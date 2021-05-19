#include <iostream>
#include <string>
#include <map>
#include <array>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;

// with big namespaces (multiple namespaces, like Hangman::Foo::Bar) we can
// give a "nickname" to it. E.g: namespace Foobar = Hangman::Foo::Bar

// static for vars makes it available only for this translation unit
static string palavra_secreta;
// map - key and value, similar to JSON
// we'll have char keys for the characters of each word
// we'll have bool values for each key (true if it has already been chosen and false otherwise)
static map<char, bool> chutou;
static array<char, 5> chutes_errados;

int main ()
{
    int guessesCount = 0;

    imprime_cabecalho();

    le_arquivo();
    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && guessesCount < 5)
    {
        guessesCount++;
        Hangman::imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(chutou, chutes_errados, palavra_secreta, guessesCount);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if (nao_acertou(palavra_secreta, chutou))
    {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else
    {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            adiciona_palavra();
        }
    }
    
    cin.get();
}