# Projeto escola

## Estrutura atual da codebase
    |--makefile
    |--.gitignore
    
    |--src
    |    base_projeto.c
    |    menu.c
    
    |--headers
    |    base_projeto.h
    |-- build 
    |    builds locais
    
## Arquitetura Proposta
### Estrutura proposta
    projetoEscola/
    │
    ├── Makefile
    │
    ├── src/
    │   ├──  main.c             -> importa constants.h inicia o programa; cria o objeto escola;chama o menu;termina;
    │   ├──  menu.c             -> seleciona a operação e termina;
    │   ├──  escola.c           -> implementa as operações solicitadas pelo menu
    │   ├──  relatorios.c       -> cria relatórios com os dados armazenados na escola
    │   └──  utilidades.c       -> funções pequenas e úteis como limpar buffer do scanf ou remover caractere do fgets
    ├── headers/
    │   ├──  constants.h        -> todas as structs, constantes e modelos ficam aqui; 
    │   ├──  menu.h
    │   ├──  escola.h
    │   ├──  relatorios.h
    │   └──  utilitarios.h
    └── build/
        └──  app
### Lógica Proposta   

    main
     │
     ▼
    menu -> utilidades
     │
     ├──────────────► escola -> utilidades
     │                    │
     │                    └──► retorna ao menu
     │
     ├──────────────► relatorios -> utilidades
     │                    │
     │                    └──► retorna ao menu
     │
     └──────────────► sair
                          │
                          ▼
                         main
                          │
                          ▼
                         fim
    
## Alunos
 - Bruno Vinicius
 - Igor Lisboa Ramos
 - João Abreu
 - Vitor Chagas
