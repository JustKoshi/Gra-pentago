#include "THumanPlayer.hpp"

THumanPlayer::THumanPlayer() {
	nickname = "Gracz";
	znak_gracza = '1';
}

THumanPlayer::THumanPlayer(std::string nick, char znak) {
	nickname = nick;
	znak_gracza = znak;
}

std::string THumanPlayer::get_name() {
	return nickname;
}

char THumanPlayer::get_znak() {
	return znak_gracza;
}

void THumanPlayer::set_nickname(std::string nick) {
	nickname = nick;
}

void THumanPlayer::set_znak(char znak) {
	znak_gracza = znak;
}

TPentagoBoard THumanPlayer::makeMove(TPentagoBoard plansza) { //metoda odpowiada za pobranie ruchu od gracza. Pobiera plansze, umieszcza ruch gracza. Zwraca plansze.
	int i, j = 0;
	std::cout << "Podaj kolumne w ktorej chcesz umiescic znak (1-6)" << std::endl;
	std::cin >> j;
	while (j < 1 || j >6) {
		std::cout << "Podana kolunna wykracza za zakres. Popraw." << std::endl;
		std::cin >> j;
	}
	std::cout << "Podaj rzad ktorym chcesz umiescic znak (1-6)" << std::endl;
	std::cin >> i;
	while (i < 1 || i >6) {
		std::cout << "Podany rzad wykracza za zakres. Popraw." << std::endl;
		std::cin >> i;
	}
	ruch.set_j(j);
	ruch.set_i(i);
	int d = plansza.make_move(ruch, znak_gracza);
	while (d == 0) 
	{
		std::cout << "Nieprawidlowy ruch. Pole zajete" << std::endl;
		std::cout << "Podaj kolumne w ktorej chcesz umiescic znak (1-6)" << std::endl;
		std::cin >> j;
		while (j < 1 || j >6) {
			std::cout << "Podana kolunna wykracza za zakres. Popraw." << std::endl;
			std::cin >> j;
		}
		ruch.set_j(j);
		std::cout << "Podaj rzad w ktorym chcesz umiescic znak (1-6)" << std::endl;
		std::cin >> i;
		while (i < 1 || i >6) {
			std::cout << "Podany rzad wykracza za zakres. Popraw." << std::endl;
			std::cin >> i;
		}
		ruch.set_i(i);
		d = plansza.make_move(ruch, znak_gracza);
	}
	return plansza;
}

TPentagoBoard THumanPlayer::rotate_quater(TPentagoBoard plansza) { //metoda odpowiadajaca za pobranie od uzytkowika cwiartki i obrocenie przyjetej planszy, zwrocenie stanu planszy po odwroceniu
	int quater, rotate;
	std::cout << "Podaj cwiartke do obrocenia (1-4)" << std::endl;
	std::cin >> quater;
	while (quater < 1 || quater >4) {
		std::cout << "Blednie podana cwiartka. Popraw." << std::endl;
		std::cin >> quater;
	}
	ruch.set_quater(quater);
	std::cout << "Podaj strone do obrocenia (1-anticlockwise; 2-clockwise)" << std::endl;
	std::cin >> rotate;
	while (rotate <1 || rotate > 2) {
		std::cout << "Blednie podany kierunek obrotu. Popraw." << std::endl;
		std::cin >> rotate;
	}
	ruch.set_rotate(rotate);
	if (rotate == 1)
		plansza.rotate_quater_anticlockwise(quater);
	else
		plansza.rotate_quater_clockwise(quater);

	return plansza;
}
