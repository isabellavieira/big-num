/*--------------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
      
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Março / 2012                                        */
/*--------------------------------------------------------------------------*/


#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"
#include "big_num.h"
#include "funcoes_extras.h"

/*--------------------------------------------------------------------------*/
/* Função principal.                                                        */
/*--------------------------------------------------------------------------*/

int main(int argc, char *argv[]){
	
	FILE *entrada;
	FILE *saida;
	char *arquivo_entrada;

	lista resultado_final, resultado_par, resultado_impar;
	lista linha_impar, linha_par;
	lista auxiliar_par, auxiliar_impar;

	Apontador aux_resultado,aux_par,aux_impar;
	
	int n, m, resultado, cont = 1;
	
	arquivo_entrada = argv[1];
	
	//Abrindo o arquivo de entrada para leitura
	entrada = fopen(arquivo_entrada,"r");
	
	saida = fopen ("saida.out","w");
	
	//No caso do arquivo não existir ou não ter permissao para ler.
	if (entrada == NULL) {
		
		printf("Parâmetro incorreto! Informe o nome de arquivo válido.\n");
		
		return;
		
	}	
	
	
	criar (&linha_impar);
	criar(&linha_par);
	criar (&resultado_par);
	criar (&resultado_impar);
	criar (&resultado_final);
	
	inserir (0, &linha_par);
	inserir (0,&linha_impar);
	
	/* ler a primeira linha do arquivo de entrada */
	fscanf (entrada, "%d %d", &n, &m);
	

	if (n == 0 && m==0) {
		fprintf (saida, "Não há valores a serem calculados!\n");
	}	

	while (n != 0 && m != 0) {
	
		if (cont % 2 == 0)  {
			
			criar (&resultado_par);
			
			criar (&auxiliar_par);
			
			combinacao (n,m,&resultado_par);
			
			somar (&resultado_par, &linha_par, &auxiliar_par);
			
			criar (&linha_par);
			
			aux_par = auxiliar_par.ultimo;
			
			while (aux_par->chave != 111) {
				
				inserir (aux_par->chave,&linha_par);
				aux_par = aux_par->prev;
				
			}
			
			destruir (&auxiliar_par);
			
		} else    {    
			
			criar (&resultado_impar);
			
			criar (&auxiliar_impar);
				
			combinacao (n,m,&resultado_impar); 
						
			somar (&resultado_impar, &linha_impar, &auxiliar_impar);
			
			criar (&linha_impar);
			
			aux_impar = auxiliar_impar.ultimo;
			
			while (aux_impar->chave != 111) {
				
				inserir (aux_impar->chave,&linha_impar);
				aux_impar = aux_impar->prev;
				
			}
			
			destruir (&auxiliar_impar);
		}	
			
		cont++;
		
		/* ler a próxima linha do arquivo de entrada */
		fscanf (entrada, "%d %d", &n, &m);
		
	}//while
	
	
	subtrair (&linha_impar, &linha_par, &resultado_final);
	
	imprimir (resultado_final, saida);
	

	fclose (entrada);
	
	fclose (saida);
}
