#include "Tmove.hpp"
#include <iostream>
Tmove::Tmove() { 
	i = 0;
	j = 0;
	quater = 1;
	rotate = 2;
}

Tmove::Tmove(int new_i, int new_j, int new_quater, int new_rotate) { 
	i = new_i;
	j = new_j;
	quater = new_quater;
	rotate = new_rotate;
}

void Tmove::set_j(int pion) {
	if (pion < 1 || pion>6) {
		std::cout << std::endl << "Blednie podana wspolrzedna y, ustawiam wartosc domyslna = 0" << std::endl;
		i = 0;
	}
	else
		j = pion - 1;
}

void Tmove::set_i(int poziom){ 
	if (poziom < 1 || poziom>6) {
		std::cout << std::endl << "Blednie podana wspolrzedna x, ustawiam wartosc domyslna = 0" << std::endl;
		i = 0;
	}
	else
		i = poziom-1;
}

int Tmove::get_j() { return j; } 
int Tmove::get_i() { return i; }
int Tmove::get_rotate() { return rotate; } 
int Tmove::get_quater() { return quater; } 


void Tmove::set_quater(int n_quater) {
	if (n_quater < 1 || n_quater>4) {
		std::cout << std::endl << "Blednie podana cwiartka, ustawiam wartosc domyslna = 1" << std::endl;
		quater =1;
	}
}

void Tmove::set_rotate(int n_rotate) {
	if (n_rotate < 1 || n_rotate>2) {
		std::cout << std::endl << "Blednie podany kierunek rotacji, ustawiam wartosc domyslna = 2" << std::endl;
		rotate = 2;
	}
}



