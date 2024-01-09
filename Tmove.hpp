#pragma once

class Tmove{ //klasa przechwuje ruchy uzytkownika
	int i; //ktory rzad ruchu ruchu 1-6
	int j; //ktora kolumna ruchu 1-6
	int quater; //ktora cwiartke obrocic 1-4
	int rotate; //w ktora strone obrocic 1-2
public:
	Tmove();
	Tmove(int new_i, int n_j, int n_quater, int n_rotate); //konstruktor ruchu z argumetnami
	void set_i(int poziom);
	void set_j(int pion);
	void set_quater(int n_quater);
	void set_rotate(int n_rotate); //odpowiednie settery
	int get_i();
	int get_j();
	int get_quater();
	int get_rotate(); //odpowiednie gettery
};