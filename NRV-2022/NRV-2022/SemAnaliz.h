#pragma once
#include "stdafx.h"
#include "Log.h"
#include "LexAnaliz.h"

namespace Semantic {
	bool Parse(LexAnal::Lex lex, Log::LOG log);
}