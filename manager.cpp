#include <fstream>
#include "manager.h"
using namespace std;

Colony Manager::load_colony(QString file_name) {
	vec2i p;
	Colony colony;
    ifstream file(file_name.toStdString());
	while (file >> p.x >> p.y) {
		colony.create(p);
	}
	return colony;
}

void Manager::save_colony(Colony& colony, QString file_name) {
    ofstream file(file_name.toStdString());
	for (const_cell_it it = colony.begin(); it != colony.end(); it++) {
		file << it->first.x << ' ' << it->first.y << endl;
	}
}
