#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Amostra.h"
#include <stdio.h>



Amostra::Amostra()
{
	Iniciar(0);
}


Amostra::~Amostra()
{
}

void Amostra::Iniciar(int ndados)
{
	dados = new float[ndados];
	for (int i = 0; i < ndados; i++)
		dados[i] = 0;
}

bool Amostra::Ler(const char * filename)
{
	FILE *ficheiro;
	ficheiro = fopen(filename,"r");
	if (ficheiro == NULL)
		return false;
	else {
		Iniciar(ndados);
		fscanf(ficheiro, "%d %d", &nclasses, &ndados);
		Iniciar(ndados);
		for (int i = 0; i < ndados; i++)
			fscanf(ficheiro,"%f",&dados[i]);

		return true;
	}

}

void Amostra::Print()
{
	for (int i = 0; i < ndados; i++)
		printf("%g ", dados[i]);
}

float Amostra::Mediana()
{
	Sort();
	float mediana;
	if (ndados % 2 == 0) {
		mediana = (dados[ndados / 2] + dados[(ndados / 2) + 1]) / 2;
	}
	else
		mediana = (dados[(ndados / 2)+1]);
	return mediana;

}

void Amostra::Sort()
{
	bool trocado = true;
	int aux, j = 0;
	while (trocado) {
		trocado = false;
		j++;
		for (int i = 0; i < ndados - j; i++) {
			if (dados[i] > dados[i + 1]){
				aux = dados[i];
				dados[i] = dados[i + 1];
				dados[i + 1] = aux;
				trocado = true;
			}
		}
	}

}
