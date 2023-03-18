#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 30
#define TAM_NOME 100

typedef struct cadastro
{
	int caixa;
	int ano;
	char isbn[14];
	int edicao;
	int quantidade;
	char titulo[30];
	char editora[30];
	char autor[30];
	char tipoObra[10];
} produto;

int i= 0;
int j= 0;

void cadastrarProduto(produto produtos[]);
void listarLivro(produto produtos[]);
int ler_arquivo(produto produtos[]);
void listarPorCaixa(produto produtos[]);
void listarRevista(produto produtos[]);

int main(){
	setlocale(LC_ALL, "portuguese");
	produto produtos[MAX]; 
	int op;
	char resp;
	system("cls");
	printf("***   20029196-5               ***\n");
	printf("***   isaque quadros amaral    ***\n");
	printf("***   Engenharia de Software   *** \n\n");
	do
	{
		printf("\n[ 1 ] - Registrar Obra "); //inicio do menu
		printf("\n[ 2 ] - Mostrar Livros ");
		printf("\n[ 3 ] - Mostrar Revistas ");
		printf("\n[ 4 ] - Mostrar Por Caixa ");
		printf("\n[ 5 ] - Sair ");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
				resp='s';
				while((resp=='S') || (resp=='s')){
					i++;
					system("cls");
					cadastrarProduto(produtos);
				
					printf("Deseja cadastrar nova obra [ s ] - para sim [ n ] - para nao: ");
					fflush(stdin);
					scanf("%c", &resp);
				}	
			break;

			case 2:
                listarLivro(produtos);
			break;

			case 3:
				listarRevista(produtos);
			break;

			case 4:
				listarPorCaixa(produtos);
			break; 
		
		case 5:
			system("cls");
			printf("\n\n\n _________Obrigado por sua visita!_________ \n");
			break;

		default:
			printf("Opcao invalida!");
			system("pause");
			break;
		}
	} while (op != 5);
	return 0;
}

void cadastrarProduto(produto produtos[MAX])
{
	FILE * arq;
	int i;
	arq = fopen("arquivo.txt", "a+");
	if (arq != NULL)
	{
			system("cls");
			printf("Informe o titulo da obra: ");
			fflush(stdin);
			gets(produtos[i].titulo);

			printf("Informe o nome do autor: ");
			fflush(stdin);
			gets(produtos[i].autor);

			printf("Informe a editora: ");
			fflush(stdin);
			gets(produtos[i].editora);

			printf("Informe a edicao: ");
			fflush(stdin);
			scanf("%d", &produtos[i].edicao);

			printf("Informe o ano: ");
			fflush(stdin);
			scanf("%d", &produtos[i].ano);

			printf("Informe o codigo isbn: ");
			fflush(stdin);
			gets(produtos[i].isbn);

			printf("Informe a quantidade: ");
			fflush(stdin);
			scanf("%d", &produtos[i].quantidade);

			printf("Em qual caixa a obra esta\n [1 caixa] [2 caixa] [3 caixa]: ");
			fflush(stdin);
			scanf("%d", &produtos[i].caixa);

			printf("Informe o tipo da obra (livro ou revista): ");
			fflush(stdin);
			gets(produtos[i].tipoObra);

			printf("\n\n \t|titulo: %s", produtos[i].titulo);
			printf("\n\n \t|autor: %s", produtos[i].autor);
			printf("\n\n \t|editora: %s", produtos[i].editora);
			printf("\n\n \t|edicao: %d", produtos[i].edicao);  
			printf("\n\n \t|ano: %d", produtos[i].ano);
			printf("\n\n \t|isbn: %s", produtos[i].isbn);  
			printf("\n\n \t|quantidade: %d", produtos[i].quantidade);
			printf("\n\n \t|caixa: %d", produtos[i].caixa);
			printf("\n\n \t|Tipo\n\n: %s", produtos[i].tipoObra);
	fwrite(&produtos[i], sizeof(produto), 1, arq);
	fclose(arq); 
  }
}

int ler_arquivo(produto produtos[MAX])
{
    FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			produto p;
			size_t r = fread(&p, sizeof(produto), 1, arq);
			if(r < 1)
				break;
			else
				produtos[indice++] = p;
		}
		fclose(arq); 
		return indice;
	}
	else
	{
		printf("\n Erro ao abrir o arquivo para leitura! \n");
		exit(1); 
    }
}

void listarLivro(produto produtos[MAX]){
	FILE *arq; 	
	arq = fopen ("arquivo.txt", "r");
	int len_vet = ler_arquivo(produtos);	
	fread(produtos, sizeof (struct cadastro), len_vet, arq); 	
	int j;
	for (j = 0; j < len_vet; j++) 
	{
		if(strcmp(produtos[j].tipoObra, "livro" ) == 0)
		{
			printf("    | TITULO: %s", produtos[j].titulo);
			printf("    | EDITORA: %s", produtos[j].editora);
			printf("    | AUTOR: %s", produtos[j].autor);
			printf("    | EDICAO: %d", produtos[j].edicao);
			printf("    | ANO: %d", produtos[j].ano);
			printf("    | ISBN: %s", produtos[j].isbn); 
			printf("    | QUANTIDADE: %d", produtos[j].quantidade);
			printf("    | CAIXA: %d", produtos[j].caixa);
			printf("    | TIPO: %s\n\n", produtos[j].tipoObra);
		}
	}
	fclose(arq); 
}
void listarRevista(produto produtos[MAX])
{
	FILE *arq; 	
	arq = fopen ("arquivo.txt", "r");
	int len_vet = ler_arquivo(produtos);	
	fread(produtos, sizeof (struct cadastro), len_vet, arq); 	
	int j;
	for (j = 0; j < len_vet; j++) 
	{
		if(strcmp(produtos[j].tipoObra, "revista" ) == 0)
		{
			printf("    | TITULO: %s", produtos[j].titulo);
			printf("    | EDITORA: %s", produtos[j].editora);
			printf("    | AUTOR: %s", produtos[j].autor);
			printf("    | EDICAO: %d", produtos[j].edicao);
			printf("    | ANO: %d", produtos[j].ano);
			printf("    | ISBN: %s", produtos[j].isbn); 
			printf("    | QUANTIDADE: %d", produtos[j].quantidade);
			printf("    | CAIXA: %d", produtos[j].caixa);
			printf("    | TIPO: %s\n\n", produtos[j].tipoObra);
		}
	}
	fclose(arq); 
}
void listarPorCaixa(produto produtos[MAX])
{
	FILE *arq; 	
	arq = fopen ("arquivo.txt", "r");
	int len_vet = ler_arquivo(produtos);	
	fread(produtos, sizeof (int), len_vet, arq); 	
	int j;
	int caixa;
	printf("Escolha a caixa [ 1 ] ou [ 2 ] ou [ 3 ]: ");
	scanf("%d", &caixa);
	for (j = 0; j < len_vet; j++) 
	{
		if(produtos[j].caixa == caixa)
		{
			printf("    | TITULO: %s", produtos[j].titulo);
			printf("    | EDITORA: %s", produtos[j].editora);
			printf("    | AUTOR: %s", produtos[j].autor);
			printf("    | EDICAO: %d", produtos[j].edicao);
			printf("    | ANO: %d", produtos[j].ano);
			printf("    | ISBN: %s", produtos[j].isbn); 
			printf("    | QUANTIDADE: %d", produtos[j].quantidade);
			printf("    | CAIXA: %d", produtos[j].caixa);
			printf("    | TIPO: %s\n\n", produtos[j].tipoObra);
		}
	}
	fclose(arq);
}