#pragma once
class Amostra
{
	int nclasses, ndados;
	float* dados;
public:
	Amostra();
	~Amostra();
	void Iniciar(int ndados);
	bool Ler(const char* filename);
	void Print();
	float Mediana();
	float Media();
	float Stddev();
	void Sort();
};

