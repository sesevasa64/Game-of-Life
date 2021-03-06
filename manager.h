#ifndef managerH
#define managerH
#include <QString>
#include "colony.h"

class Manager {
public:
    static Colony load_colony(QString file_name);
    static void save_colony(Colony& colony, QString file_name);
};

#endif
