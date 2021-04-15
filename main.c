/*
 * Aluna: Ana Carolina Jaolino
 * DRE: 117230950
 * Escola Politécnica
 * Universidade Federal do Rio de Janeiro - UFRJ
 * Engenharia de Computacao e Informacao
 */
 
//#define MAX_SIZE    22000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {
    int MAX_SIZE = *argv[0]; 
	int nIndice, nIndiceLinha, nIndiceColuna;
	double matriz [MAX_SIZE][MAX_SIZE], vetor [MAX_SIZE], resultado [MAX_SIZE];
	clock_t inicio, fim;
	double tempoExec;

    	srand(time(NULL));

    	/*Variando o tamanho da matriz e do vetor, mantando n <= nMax*/
	for (nIndice = 1; nIndice <= MAX_SIZE; (nIndice = nIndice * 3))
	{
        	/*Inicializando randomicamente matriz e vetor, de acordo com o tamanho n*/
		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
        		for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
            		{
                		matriz[nIndiceLinha][nIndiceColuna] = (double)rand();
            		}
            		vetor[nIndiceLinha] = (double)rand();
            		resultado[nIndiceLinha] = 0;
        	}

        	/*Realizando o produto (i externo ; j interno)*/
        	inicio = clock();
	    	for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
            		for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
            		{
                		resultado[nIndiceLinha] = resultado[nIndiceLinha] + (matriz[nIndiceLinha][nIndiceColuna] * vetor[nIndiceLinha]);
            		}
        	}
        	fim = clock();
        	tempoExec = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

		
        	/*Zerando o vetor resultado*/
		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
        	{
            		resultado[nIndiceLinha] = 0;
        	}

    
        	/*Realizando o produto (j externo ; i interno)*/
        	inicio = clock();
	    	for (nIndiceColuna = 0; nIndiceColuna < nIndice; nIndiceColuna++)
        	{
            		for (nIndiceLinha = 0; nIndiceLinha < nIndice; nIndiceLinha++)
            		{
                		resultado[nIndiceLinha] = resultado[nIndiceLinha] + (matriz[nIndiceLinha][nIndiceColuna] * vetor[nIndiceLinha]);
            		}
        	}
        	fim = clock();
        	tempoExec = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

	}
	
    	printf("%f\n",tempoExec);

	return 0;
}
