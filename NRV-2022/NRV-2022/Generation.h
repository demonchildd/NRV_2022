#pragma once
#include "stdafx.h"
#include "Parm.h"
#include "LT.h"
#include "IT.h"

namespace Gen {
	struct Generator {
		LT::LexTable lexT;
		IT::IdTable idT;
		std::ofstream out;

		Generator(LT::LexTable plexT, IT::IdTable pidT, const char* pout);

		void Head();
		void Const();
		void Data();
		void Code();
	};
}