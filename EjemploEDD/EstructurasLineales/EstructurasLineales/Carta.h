#pragma once
class Carta
{
private: 
	int numero = 0;
	char color = 'R';
	char simbolo = 'A';

public:
	int getNumero();
	void setNumero(int _numero);

	char getColor();
	void setColor(char _color);

	char getSimbolo();
	void setSimbolo(char _simbolo);

};

