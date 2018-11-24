#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"Rectangulo.h"
#include"Janela.h"

#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {

		Janela janela;
		HWND janelaId;
		printf("Programa que utiliza outra janela para os resultados.\n");

		if (janela.Criar("Minha Janela")) {
			if ((janelaId = janela.ObterId()) != NULL) {
				Rectangulo r(242, 500, 892, 100, janelaId);
				printf("\nArea do rectangulo: %0.2f\n", r.obterArea());
				printf("\nPerimetro do rectangulo: %d\n", r.obterPerimetro());

				r.desenhar(janelaId, VERDE);
				MSG msg;
				while (GetMessage(&msg, 0, 0, 0)) {
					DispatchMessage(&msg);
					if (janela.Click()) {
						if (r.contem(Ponto(janela.ObterPonto().ObterX(),
							janela.ObterPonto().ObterY())) == true)
							r.desenhar(janelaId, VERDE);
						else
							r.desenhar(janelaId, VERMELHO);
					}

				}
			}
		}
	
	
}