#include <unistd.h>

#ifndef _CONSTANTS
    #define _CONSTANTS

    // Definindo macros para true e false caso não estejam definidas
    // usando #ifndef (if not defined).

    #ifndef true 
        #define true 1 
    #endif

    #ifndef false
        #define false	0
    #endif

    #ifndef VAGA_LIVRE
        #define VAGA_LIVRE	0
    #endif

    #ifndef SEM_VAGA 
        #define SEM_VAGA	-1 
    #endif

    #ifndef TIPO_INVALIDO
        #define TIPO_INVALIDO	-2
    #endif

    ///MAXIMOS VALORES PARA TAMANHO DOS VETORES
    #ifndef MAX_NUMERO_ALUNOS 
        #define MAX_NUMERO_ALUNOS 40
    #endif

    #ifndef MAX_CARACTERE_NOME 
        #define MAX_CARACTERE_NOME 40
    #endif

    #ifndef MAX_DISCIPLINAS 
        #define MAX_DISCIPLINAS 6
    #endif

    #ifndef MAX_CHAR_COD_DISCIPLINA 
        #define MAX_CHAR_COD_DISCIPLINA 6
    #endif

#endif
