#include <stdio.h>
#include "../headers/utilidades.h"
#include "../headers/relatorio.h"
#include "../headers/escola.h"

#define TAM_LISTA_ALUNOS 5
#define TAM_LISTA_DISCIPLINAS 3

int main(){
	individuo lista_individuos[TAM_LISTA_ALUNOS];
	disciplina lista_disciplinas[TAM_LISTA_DISCIPLINAS];

	int sair = 0;
	int opcao;
	while(!sair){ //sair == 0
		printf("Digite a opção: \n\n");
		printf("\t0 - Sair \n");
		printf("\t1 - Inserir \n");
		printf("\t2 - Listar \n");
		printf("\t3 - Atualizar \n");
		printf("\t4 - Deletar \n");

		scanf_limpo_simples("%d", &opcao);

		switch (opcao){
		case 0:
			sair = 1;
			break;
		

		case 1: // Cadastrar
			break;

		case 2: // Listar
			switch (opcao) {
			case 1:
				listar_individuos(lista_individuos, TAM_LISTA_ALUNOS);
				break;
			case 2:
				listar_disciplinas(lista_disciplinas, TAM_LISTA_DISCIPLINAS);
				break;
			}

			break;

		case 3: // Atualizar
			printf("Atualizar");
			break;

		case 4: // Deletar
			printf("Deletar");
			break;

		default: 
			puts("Opção Inválida");
		}
	}
}
