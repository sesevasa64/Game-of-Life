//---------------------------------------------------------------------------


#pragma hdrstop
#include <fstream>
#include "manager.h"
using namespace std;

Colony Manager::load_colony(AnsiString& file_name) {
	vec2i p;
	Colony colony;
	ifstream file(file_name.c_str());
	while (file >> p.x >> p.y) {
		colony.create(p, clRed);
	}
	return colony;
}
void Manager::save_colony(Colony& colony, AnsiString& file_name) {
	ofstream file(file_name.c_str());
	for (const_cell_it it = colony.begin(); it != colony.end(); it++) {
		file << it->first.x << ' ' << it->first.y << endl;
	}
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
