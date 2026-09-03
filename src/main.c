#include <stdio.h>
#include "../headers/utilidades.h"
#include "../headers/relatorio.h"
#include "../headers/escola.h"

#define TAM_LISTA_ALUNOS 3

int main(){
	individuo listaAlunos[TAM_LISTA_ALUNOS];

	int sair = 0;
	int qtdAlunos = 0;
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
			case 0: {
				sair = 1;
				break;
			}

			case 1: {
				puts("Digite o nome:\n");
				input_string(listaAlunos[qtdAlunos].nome, 100);

				do{
					puts("Digite gênero (M - Masculino | F - Feminino):");
					scanf_limpo_simples("%c", &listaAlunos[qtdAlunos].genero);

					if(listaAlunos[qtdAlunos].genero == 'm' || listaAlunos[qtdAlunos].genero == 'p')
						listaAlunos[qtdAlunos].genero -= 32;

				} while(listaAlunos[qtdAlunos].genero != 'M' && listaAlunos[qtdAlunos].genero != 'F');

				puts("Digite a data de nascimento (DiaMêsAno | DDMMAA):\n");
				scanf_limpo_simples("%d", &listaAlunos[qtdAlunos].nascimento);

				puts("Digite o CPF:\n");
				scanf_limpo_simples("%d", &listaAlunos[qtdAlunos].cpf);

				//falta o resto, salvei por que tive que sair
				qtdAlunos++;
				break;
			}
				
			case 2: {
				printf("Lista Alunos\n");
				listar_individuos(listaAlunos, TAM_LISTA_ALUNOS);
				break;
			}

			case 3: {
				printf("Atualizar");
				break;
			}

			case 4: {
				printf("Deletar");
				break;
			}

			default: { 
				printf("Opção Inválida");
			}
		}
	}
}
