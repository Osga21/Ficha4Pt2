#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "Rectangulo.h"
#include "Janela.h"
#include "Hist.h"
#include "Amostra.h"
#include "Ponto.h"
#include "math.h"

#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {
	

		char filename[] = { "test.txt" };
		Amostra dados;
		dados.Ler(filename);
	
		printf("Mediana amostra: %g\nMedia amostra:%g \nDesvio amostra:%g", dados.Mediana(), dados.Media(), dados.Stddev());
		
		Janela janela;
		HWND janelaId;


		Hist h(dados.Classes(), dados.ObterClasses());
		h.SetCorBins(RGB(18, 210, 193));
		if (janela.Criar("Minha Janela")) {
			if ((janelaId = janela.ObterId()) != NULL) {
				h.Desenhar(&janela);
				MSG msg;
				while (GetMessage(&msg, 0, 0, 0)) {
					DispatchMessage(&msg);
				}
				printf("O programa terminou\n");
			}
		}
	
}