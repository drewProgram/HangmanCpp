#include <iostream>

// Fun��es inline s�o usadas para que o compilador decida se faz sentido executar em uma linha ou n�o

// inline functions are declared in the header file, cuz they'll just be imported directly to a 
// translation unit
inline void imprime_cabecalho()
{
    std::cout << "*********************" << std::endl;
    std::cout << "*** JOGO DA FORCA ***" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
}