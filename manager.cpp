#include <fstream>
#include "manager.h"
using namespace std;

void Manager::load_colony(Colony *colony, QString file_name) {
	vec2i p;
    colony->eraseAll();
    ifstream file(file_name.toStdString());
	while (file >> p.x >> p.y) {
        colony->create(p);
	}
}

void Manager::save_colony(Colony *colony, QString file_name) {
    ofstream file(file_name.toStdString());
    for (const_cell_it it = colony->begin(); it != colony->end(); it++) {
        file << it->x << ' ' << it->y << endl;
	}
}

