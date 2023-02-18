#pragma once
#include "stdafx.h"
#include "LexAnaliz.h"
#include "Error.h"

namespace Polish
{
	void startPolish(LexAnal::Lex& lex);
	bool PolishNotation(int i, LexAnal::Lex& lex);
}