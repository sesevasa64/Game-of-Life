//---------------------------------------------------------------------------

#ifndef managerH
#define managerH
#include <System.hpp>
#include "colony.h"

class Manager {
public:
	static Colony load_colony(AnsiString& file_name);
	static void save_colony(Colony& colony, AnsiString& file_name);
};

//---------------------------------------------------------------------------
#endif
