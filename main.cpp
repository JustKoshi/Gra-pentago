#include "Tgame.hpp"

int main() {
	char znak = '1';
	std::string nick;
	std::cout << "Podaj nickname (inny niz 'Komputer' zarezerwowany dla komputera):" << std::endl;
	std::cin >> nick;
	while (nick == "Komputer") {
		std::cout << "Przepraszam, za niedogodnosc. Wybierz inny nickname" << std::endl;
		std::cin >> nick;
	}
	std::cout << "Podaj znak gracza (inny niz 'K' zarezerwowany dla komputera):" << std::endl;
	std::cin >> znak;
	while (znak == 'K') {
		std::cout << "Przepraszam, za niedogodnosc. Wybierz inny znak" << std::endl;
		std::cin >> znak;
	}
	std::cout << "zacznijmy gre" << std::endl;
	TGame gra(nick, znak);
	gra.gameStart();
	char prtout = '0';
	if (gra.winner != "Komputer" && gra.is_draw() == false) {
		gra.create_ranking();
		std::cout << "Tworze ranking." << std::endl << "Jesli chcesz go wypisac wpisz 1 jesli nie to dowolny inny znak!" << std::endl;
		std::cin >> prtout;
		if (prtout == '1')
			gra.wypisz_ranking();
	}
	std::cout << "Chcesz zagrac jeszcze raz?!" << std::endl<<"Jesli tak wpisz 1 jesli nie dowolny inny znak!"<<std::endl;
	char wybor;
	std::cin >> wybor;
	while (wybor == '1') {
		std::cout << "Podaj nickname (inny niz 'Komputer' zarezerwowany dla komputera):" << std::endl;
		std::cin >> nick;
		while (nick == "Komputer") {
			std::cout << "Przepraszam, za niedogodnosc. Wybierz inny nickname" << std::endl;
			std::cin >> nick;
		}
		std::cout << "Podaj znak gracza (inny niz 'K' zarezerwowany dla komputera):" << std::endl;
		std::cin >> znak;
		while (znak == 'K') {
			std::cout << "Przepraszam, za niedogodnosc. Wybierz inny znak" << std::endl;
			std::cin >> znak;
		}
		std::cout << "zacznijmy gre" << std::endl;
		TGame gra(nick, znak);
		gra.gameStart();
		if(gra.winner != "Komputer" && gra.is_draw() == false) {
			gra.create_ranking();
			std::cout << "Tworze ranking." << std::endl << "Jesli chcesz go wypisac wpisz 1 jesli nie to dowolny inny znak!" << std::endl;
			std::cin >> prtout;
			if (prtout == '1')
				gra.wypisz_ranking();
		}
		std::cout << "Chcesz zagrac jeszcze raz?!" << std::endl << "Jesli tak wpisz 1 jesli nie dowolny inny znak!" << std::endl;
		std::cin >> wybor;
	}

	std::cout << "Dziekuje za rozgrywke!" << std::endl << "Gre stworzyl: Kacper Myszka" << std::endl;
}