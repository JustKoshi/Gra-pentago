#pragma once
#define M 6
#include <iostream>
#include <cstdio>
#include "Tmove.hpp"

class TPentagoBoard {
protected:	
	char board[M][M];					//plansza do gry
public:
	TPentagoBoard();					//konstruktor domyslny inicjalizujacy tab zerami
	TPentagoBoard(TPentagoBoard&mk);		//konstruktor kopiujacy
	void wypisz();							//wypisuje aktualny stan tablicy
	void rotate_quater_clockwise(int quater); //rotacja cwiartki clockwise
	void rotate_quater_anticlockwise(int quater); //rotacja cwiartki anticlockwise
	bool czy_wygrana(char znak_gracza);		//sprawdza czy uzytkownik wygral
	int make_move(Tmove ruch, char znak_gracza); //zwraca 1 jak ruch prawidlowy 0 jak nieprawidlowy 2 jak przed obrotem nastapila wygrana
	bool is_full();								 //sprawdza czy tablica jest pelna jestli tak zwraca true
};


