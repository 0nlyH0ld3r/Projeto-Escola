#include <stdio.h>
#include <string.h>
#include "base_projeto.h"

int main(){
	struct Individuo listaAlunos[3];

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

		scanf("%d", &opcao);

		switch (opcao){
			case 0: {
				sair = 1;
				break;
			}

			case 1: {
				puts("Digite o nome:\n");
				input_string(listaAlunos[qtdAlunos].nome, 100);

				scanf("%c", &listaAlunos[qtdAlunos].genero);

				do {
					puts("Digite gênero (M - Masculino | F - Feminino):");
					scanf("%c", &listaAlunos[qtdAlunos].genero);

					if(listaAlunos[qtdAlunos].genero == 'm' || listaAlunos[qtdAlunos].genero == 'm')
						listaAlunos[qtdAlunos].genero -= 32;

				} while(listaAlunos[qtdAlunos].genero != 'M' && listaAlunos[qtdAlunos].genero != 'F');

				puts("Digite a data de nascimento (DiaMêsAno | DDMMAA):\n");
				scanf("%d", &listaAlunos[qtdAlunos].nascimento);

				puts("Digite o CPF:\n");
				scanf("%d", &listaAlunos[qtdAlunos].cpf);

				//falta o resto, salvei por que tive que sair
				qtdAlunos++;
				break;
			}
				
			case 2: {
				printf("Lista Alunos\n");

				for (int i = 0; i < qtdAlunos; i++)
					printf("");

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
