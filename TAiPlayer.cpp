#include "TAiPlayer.hpp"

TAiPlayer::TAiPlayer() {
	nickname = "Komputer";
	znak_gracza = 'K';
}

TPentagoBoard TAiPlayer::makeMove(TPentagoBoard plansza) {			//losuje ruchy dla komputera i je wykonuje ananogicznie do THumanPlayer ale zgodnie z zasadami gry
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int i, j = 0;
	i = (std::rand() % 6) + 1;
	j = (std::rand() % 6) + 1;
	ruch.set_j(j);
	ruch.set_i(i);
	int d = plansza.make_move(ruch, znak_gracza);
	while (d == 0)
	{
		j = (std::rand() % 6) + 1;
		ruch.set_j(j);
		i = (std::rand() % 6) + 1;
		ruch.set_i(i);
		d = plansza.make_move(ruch, znak_gracza);
	}
	std::cout << std::endl << "Komputer umiescil znak w kolumnie nr:" << j << " rzedzie nr: " << i << std::endl;
	return plansza;
}

TPentagoBoard TAiPlayer::rotate_quater(TPentagoBoard plansza) {					//losuje cwiartki i obrot dla komputera i je wykonuje ananogicznie do THumanPlayer ale zgodnie z zasadami gry
	int quater, rotate;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	quater = (std::rand() % 4) + 1;
	ruch.set_quater(quater);
	rotate = (std::rand() % 2) + 1;
	ruch.set_rotate(rotate);
	if (rotate == 1)
		plansza.rotate_quater_anticlockwise(quater);
	else
		plansza.rotate_quater_clockwise(quater);
	std::cout << "Komputer obrocil cwiartke nr: " << quater<<" w strone ";
	rotate == 1 ? std::cout << "anticlockwise" << std::endl : std::cout << "clockwise" << std::endl;
	return plansza;
}
