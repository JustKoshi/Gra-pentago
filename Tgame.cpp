#include "Tgame.hpp"
#include <fstream>



TGame::TGame() {
	end = false;
	draw = false;
	player = THumanPlayer("gracz", 'G');
	ai = new TAiPlayer();
	board = TPentagoBoard();

}

TGame::TGame(std::string nick, char znak) {
	end = false;
	draw = false;
	player = THumanPlayer(nick, znak);
	ai = new TAiPlayer();
	board = TPentagoBoard();

}

bool TGame::is_draw() { return draw; }

void TGame::gameStart() { //przeprowadzenie gry
	char znak = player.get_znak();
	char znak_ai = ai->get_znak();
	board.wypisz();
	std::cout <<std::endl <<"Gracz zaczyna!" << std::endl;
	while (!end) {
		board = player.makeMove(board);
		board.wypisz();
		end = board.czy_wygrana(znak);
		if (end) {
			winner = player.get_name();
			break;
		}
		draw = board.is_full();
		if (draw) {
			end = true;
			break;
		}
		board = player.rotate_quater(board);
		board.wypisz();
		end = board.czy_wygrana(znak);
		if (end) {
			winner = player.get_name();
			break;
		}
		std::cout << "Tura komputera: " << std::endl;
		board = ai->makeMove(board);
		board.wypisz();
		end = board.czy_wygrana(znak_ai);
		if (end) {
			winner = ai->get_name();
			break;
		}
		draw = board.is_full();
		if (draw) {
			end = true;
			break;
		}
		board = ai->rotate_quater(board);
		board.wypisz();
		end = board.czy_wygrana(znak_ai);
		if (end) {
			winner = ai->get_name();
			break;
		}
		std::cout << "Tura gracza: " << std::endl;
	}
	if (draw) {
		std::cout << "Remis!" << std::endl;
	}
	else {
		std::cout << "Wygral gracz:"<<winner<<"!" << std::endl;
	}


}

TPlayer_Wins::TPlayer_Wins() {
	w_name = "";
	wins = 0;
}
TPlayer_Wins::TPlayer_Wins(std::string & playerName, int playerWins) {
	w_name = playerName;
	wins = playerWins;
}

void TGame::create_ranking(){

	
	std::ifstream file("ranking.txt"); // Sprawdzanie istnienia pliku z rankingiem
	if (!file.is_open()) {
		
		std::ofstream newFile("ranking.txt"); // Jeœli plik nie istnieje, tworzymy go
		newFile.close();
	}
	else {
		std::string nick;
		int wins;
		while (file >> nick >> wins && ile_graczy < MAX_P) { 	//odczyt z pliku
			ranking[ile_graczy] = TPlayer_Wins(nick, wins); 
			ile_graczy++;
		}
		file.close();
	}

	bool playerInRanking = false;
	for (int i = 0; i < ile_graczy; i++) {
		if (ranking[i].w_name == winner) {
			ranking[i].wins++; // Zwiêkszanie liczby wygranych, jeœli gracz ju¿ istnieje
			playerInRanking = true;
			break;
		}
	}
	if (!playerInRanking && ile_graczy < MAX_P) { //gracza nie ma w rankingu, dodajemy go z 1 wygrana
		ranking[ile_graczy] = TPlayer_Wins(winner, 1);
		ile_graczy++;
	}

	int i = 0, j = 1; 
	int temp = 0;
	for (i = 0; i < ile_graczy - 1; i++) {  //sortowanie rankingu algortymem bubble sort
		for (j = 0; j < ile_graczy - i - 1; j++) {
			if (ranking[j].wins < ranking[j + 1].wins) {
				temp = ranking[j].wins;
				ranking[j].wins = ranking[j + 1].wins;
				ranking[j + 1].wins = temp;
			}

		}
	}
	std::ofstream outputFile("ranking.txt"); 
	if (outputFile.is_open()) { //zapis do pliku
		for (int i = 0; i < ile_graczy; i++) {
			outputFile << ranking[i].w_name << " " << ranking[i].wins << std::endl;
		}
		outputFile.close();
	}
	else {
		std::cout << "Nie mo¿na zapisaæ rankingu do pliku." << std::endl;
	}

}

void TGame::clear_ranking() {
	ile_graczy = 0;
}

void TGame::wypisz_ranking() {
	clear_ranking();
	bool czy_pusty = false;
	std::ifstream file("ranking.txt"); // Sprawdzanie istnienia pliku z rankingiem
	if (file.is_open()) {
		if (file.peek() == std::ifstream::traits_type::eof()) { //sprawdzenie czy plik z rankingiem jest pusty
			std::cout << "Plik z rankingiem jest pusty." << std::endl;
		}
		else {
			std::string nick;
			int wins;
			while (file >> nick >> wins) { 	// odczyt z pliku
				ranking[ile_graczy] = TPlayer_Wins(nick, wins);
				ile_graczy++;
			}
			
			std::cout << "Ranking graczy:\n";
			for (int i = 0; i < ile_graczy; i++) {
				std::cout << ranking[i].w_name << " - Wygrane: " << ranking[i].wins << std::endl; //wypisanie rankingu
			}
		}
		file.close();
	}
	else
		std::cout << "Nie udana proba otworzenia pliku z rankingiem" << std::endl;
	
}
