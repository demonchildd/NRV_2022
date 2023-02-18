#include "stdafx.h"
#include <stack>
#include "MFST.h"



#define max_word	1000
#define size_word	20

bool typeuint(char word[]) {
	FST::FST typeuint(word, 5,
		FST::NODE(1, FST::RELATION('u', 1)),
		FST::NODE(1, FST::RELATION('i', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('t', 4)),
		FST::NODE()
	);
	return FST::execute(typeuint);
}
bool typestr(char word[]) {
	FST::FST typestr(word, 4,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE()
	);
	return FST::execute(typestr);
}
bool typebool(char word[]) {
	FST::FST typestring(word, 5,
		FST::NODE(1, FST::RELATION('b', 1)),
		FST::NODE(1, FST::RELATION('o', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE()
	);
	return FST::execute(typestring);
}
bool typefunction(char word[]) {
	FST::FST typefunction(word, 5,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE()
	);
	return FST::execute(typefunction);
}
bool strnew(char word[]) {
	FST::FST strdeclare(word, 4,
		FST::NODE(1, FST::RELATION('n', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('w', 3)),
		FST::NODE()
	);
	return FST::execute(strdeclare);
}
bool streturn(char word[]) {
	FST::FST streturn(word, 4,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE()
	);
	return FST::execute(streturn);
}
bool strmain(char word[]) {
	FST::FST strmain(word, 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
	);
	return FST::execute(strmain);
}
bool strprint(char word[]) {
	FST::FST strprint(word, 6,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);
	return FST::execute(strprint);
}
bool expression(char word[]) {
	FST::FST expression(word, 2,
		FST::NODE(4,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1)),

		FST::NODE()
	);
	return FST::execute(expression);
}
bool leftbrace(char word[]) {
	FST::FST leftbrace(word, 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
	);
	return FST::execute(leftbrace);
}
bool rightbrace(char word[]) {
	FST::FST rightbrace(word, 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
	);
	return FST::execute(rightbrace);
}
bool leftthesis(char word[]) {
	FST::FST leftthesis(word, 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
	);
	return FST::execute(leftthesis);
}
bool rightthesis(char word[]) {
	FST::FST rightthesis(word, 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
	);
	return FST::execute(rightthesis);
}
bool semicolon(char word[]) {
	FST::FST semicolon(word, 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
	);
	return FST::execute(semicolon);
}
bool comma(char word[]) {
	FST::FST comma(word, 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
	);
	return FST::execute(comma);
}
bool left(char word[]) {
	FST::FST left(word, 5,
		FST::NODE(1, FST::RELATION('l', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('f', 3)),
		FST::NODE(1, FST::RELATION('t', 4)),
		FST::NODE()
	);
	return FST::execute(left);
}
bool right(char word[]) {
	FST::FST right(word, 6,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('i', 2)),
		FST::NODE(1, FST::RELATION('g', 3)),
		FST::NODE(1, FST::RELATION('h', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE()
	);
	return FST::execute(right);
}
bool ravno(char word[]) {

	FST::FST ravno(word, 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE()
	);
	return FST::execute(ravno);
}

bool cycle(char word[]) {

	FST::FST cycle(word, 6,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('y', 2)),
		FST::NODE(1, FST::RELATION('c', 3)),
		FST::NODE(1, FST::RELATION('l', 4)),
		FST::NODE(1, FST::RELATION('e', 5)),
		FST::NODE()
	);
	return FST::execute(cycle);
}
bool literaluint(char word[]) {

	FST::FST literaluint(word, 2,
		FST::NODE(20,
			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
			FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
			FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
			FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1)),
		FST::NODE()
	);
	return FST::execute(literaluint);
}

bool literaluint8(char word[]) {
	FST::FST literaluint8(word, 4,
		FST::NODE(1, FST::RELATION('8', 1)),
		FST::NODE(1, FST::RELATION('x', 2)),
		FST::NODE(20,
			FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2),
			FST::RELATION('3', 2), FST::RELATION('4', 2), FST::RELATION('5', 2),
			FST::RELATION('6', 2), FST::RELATION('7', 2),
			FST::RELATION('0', 3), FST::RELATION('1', 3),
			FST::RELATION('2', 3), FST::RELATION('3', 3), FST::RELATION('4', 3),
			FST::RELATION('5', 3), FST::RELATION('6', 3), FST::RELATION('7', 3)),
			
		FST::NODE()
	);
	return FST::execute(literaluint8);
}

bool literalstring(char word[]) {
	FST::FST literalstring(word, 3,
		FST::NODE(1, FST::RELATION('\'', 1)),
		FST::NODE(153, 
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), 
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1), 
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1), 
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), 
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), 
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1), 
			FST::RELATION('y', 1), FST::RELATION('z', 1), 
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), 
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), 
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), 
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), 
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), 
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), 
			FST::RELATION('Y', 1), FST::RELATION('Z', 1), 
			FST::RELATION('à', 1), FST::RELATION('á', 1), FST::RELATION('â', 1), FST::RELATION('ã', 1), 
			FST::RELATION('ä', 1), FST::RELATION('å', 1), FST::RELATION('¸', 1), FST::RELATION('æ', 1), 
			FST::RELATION('ç', 1), FST::RELATION('è', 1), FST::RELATION('é', 1), FST::RELATION('ê', 1), 
			FST::RELATION('ë', 1), FST::RELATION('ì', 1), FST::RELATION('í', 1), FST::RELATION('î', 1), 
			FST::RELATION('ï', 1), FST::RELATION('ð', 1), FST::RELATION('ñ', 1), FST::RELATION('ò', 1), 
			FST::RELATION('ó', 1), FST::RELATION('ô', 1), FST::RELATION('õ', 1), FST::RELATION('ö', 1), 
			FST::RELATION('÷', 1), FST::RELATION('ø', 1), FST::RELATION('ù', 1), FST::RELATION('ü', 1), 
			FST::RELATION('û', 1), FST::RELATION('ú', 1), FST::RELATION('ý', 1), FST::RELATION('þ', 1), 
			FST::RELATION('ÿ', 1), 
			FST::RELATION('À', 1), FST::RELATION('Á', 1), FST::RELATION('Â', 1), FST::RELATION('Ã', 1), 
			FST::RELATION('Ä', 1), FST::RELATION('Å', 1), FST::RELATION('¨', 1), FST::RELATION('Æ', 1), 
			FST::RELATION('Ç', 1), FST::RELATION('È', 1), FST::RELATION('É', 1), FST::RELATION('Ê', 1), 
			FST::RELATION('Ë', 1), FST::RELATION('Ì', 1), FST::RELATION('Í', 1), FST::RELATION('Î', 1), 
			FST::RELATION('Ï', 1), FST::RELATION('Ð', 1), FST::RELATION('Ñ', 1), FST::RELATION('Ò', 1), 
			FST::RELATION('Ó', 1), FST::RELATION('Ô', 1), FST::RELATION('Õ', 1), FST::RELATION('Ö', 1), 
			FST::RELATION('×', 1), FST::RELATION('Ø', 1), FST::RELATION('Ù', 1), FST::RELATION('Ü', 1), 
			FST::RELATION('Û', 1), FST::RELATION('Ú', 1), FST::RELATION('Ý', 1), FST::RELATION('Þ', 1), 
			FST::RELATION('ÿ', 1), 
			FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), 
			FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), 
			FST::RELATION('8', 1), FST::RELATION('9', 1), 
			FST::RELATION(' ', 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1), 
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1), 
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1), 
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1), 
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('&', 1), 
			FST::RELATION('>', 1), FST::RELATION('<', 1), FST::RELATION('[', 1), FST::RELATION(']', 1), 
			FST::RELATION('^', 1), 
			FST::RELATION('\'', 2)), 
		FST::NODE()
	);
	return FST::execute(literalstring);
}


bool literalbool1(char word[]) {

	FST::FST literalbool(word, 5,
		FST::NODE(1, FST::RELATION('t', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('u', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(literalbool);
}
bool literalbool2(char word[]) {

	FST::FST literalbool(word, 6,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('l', 3)),
		FST::NODE(1, FST::RELATION('s', 4)),
		FST::NODE(1, FST::RELATION('e', 5)),
		FST::NODE()
	);
	return FST::execute(literalbool);
}

bool idenf(char word[]) {

	FST::FST idenf(word, 2,
		FST::NODE(54,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
			FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
			FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
		FST::NODE()
	);
	return FST::execute(idenf);
}
bool Data_fi(char word[]) {
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('D', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}
bool Time_fi(char word[]) {
	FST::FST staticfi(word, 5,
		FST::NODE(1, FST::RELATION('T', 1)),
		FST::NODE(1, FST::RELATION('i', 2)),
		FST::NODE(1, FST::RELATION('m', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(staticfi);
}

namespace LexAnal
{
	
	void Synchronization(LexAnal::Lex& lex) {
		bool* is_changed = new bool[lex.idtab.size] { false };
		for (int i = 0; i < lex.lextab.size; i++)
		{
			if (lex.lextab.table[i].idxTI != -1 && !is_changed[lex.lextab.table[i].idxTI])
			{
				lex.idtab.table[lex.lextab.table[i].idxTI].idxfirstLE = i;
				is_changed[lex.lextab.table[i].idxTI] = true;
			}
		}
		delete[] is_changed;
	}

	Lex LexAnaliz(Parm::PARM parm, In::IN in)
	{
		Lex lex;
		LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
		IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);
		char** word = new char* [max_word];
		for (int i = 0; i < max_word; i++)
			word[i] = new char[size_word] {NULL};

		do
		{
			word = In::splitText(in.text, in.size);
		} while (word == NULL);

		stack<std::string> functions;
		int literalCounter = 1;
		int indexLex = 1;
		int position = 0;
		int is_cycle = 0;
		bool findDeclaration = false;
		bool findType = false;
		bool findFunc = false;
		bool findMain = false;
		bool findParm = false;
		bool findProc = false;
		int findFalse = 0;
		int idxFalse = 0;
		int mainCounter = 0;

		char* bufprefix = new char[10] { "" };
		char* L = new char[2] { "L" };
		char* bufL = new char[TI_STR_MAXSIZE];
		char* charclit = new char[10] { "" };
		char* nameLiteral = new char[10] { "" };
		int line = 1;

		IT::Entry entryIT = {};

		for (int i = 0; word[i] != NULL; i++)
		{
			bool findSameID = false;
			position += strlen(word[i]);
			if (strnew(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_NEW, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findDeclaration = true;
			}
			else if (typeuint(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_UINT, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::UINT;
			}
			else if (typebool(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BOOL, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::BOOL;
			}
			else if (typestr(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_STR, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findType = true;
				entryIT.iddatatype = IT::STR;
				strcpy(entryIT.value.vstr.str, "");
			}
			else if (typefunction(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_FUNCTION, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findFunc = true;
			}
			else if (streturn(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RETURN, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (strprint(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_PRINT, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (strmain(word[i]))
			{
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::F;
				entryIT.iddatatype = IT::UINT;
				IT::Add(idtab, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_MAIN, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				functions.push(word[i]);
				findMain = true;
				mainCounter++;
			}
			else if (Data_fi(word[i]) || Time_fi(word[i])) {
				if (int idx = IT::IsId(idtab, word[i]) == TI_NULLIDX) {
					entryIT.idtype = IT::F;
					entryIT.iddatatype = IT::STR;
					entryIT.idxfirstLE = indexLex;
					entryIT.params.count = 0;
					strcpy(entryIT.id, word[i]);
					IT::Add(idtab, entryIT);
					entryIT = {};
				}

				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
			}
			else if (cycle(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_CYCLE, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				is_cycle++;
			}
			else if (literaluint(word[i]))
			{
				int value = atoi((char*)word[i]);
				if (value > TI_UINT_MAXSIZE)
				{
					throw ERROR_THROW(313);
				}
				for (int k = 0; k < idtab.size; k++) {
					if (idtab.table[k].value.vuint == value &&
						idtab.table[k].idtype == IT::L &&
						idtab.table[k].iddatatype == IT::UINT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::UINT;
				entryIT.value.vuint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtab, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
			}
			else if (literaluint8(word[i])) {
				char* numBuf = new char;
				int j = 0;
				for (int k = 2; k < strlen(word[i]); k++, j++)
				{
					numBuf[j] = word[i][k];
				}
				numBuf[j] = '\0';
				int value = strtol(numBuf, NULL, 8);
				if (value > TI_UINT_MAXSIZE)
				{
					throw ERROR_THROW(313);
				}
				for (int k = 0; k < idtab.size; k++)
				{
					if (idtab.table[k].value.vuint == value &&
						idtab.table[k].idtype == IT::L &&
						idtab.table[k].iddatatype == IT::UINT)
					{
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						findSameID = true;
						break;
					}
				}

				if (findSameID) continue;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::UINT;
				entryIT.value.vuint = value;
				entryIT.idxfirstLE = indexLex;
				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				word[i] = strcat(bufL, charclit);
				strcpy(entryIT.id, word[i]);
				IT::Add(idtab, entryIT);
				entryIT = {};

				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
			}
			else if (literalbool1(word[i]) || literalbool2(word[i]))
			{
				bool value = true;
				if (literalbool2(word[i]))
				{
					value = false;
					findFalse++;
				}
				if (value == true)
				{
					for (int k = 0; k < idtab.size; k++) {
						if (idtab.table[k].value.vbool == value)
						{
							findSameID = true;
							LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
							LT::Add(lextab, entryLT);
							break;
						}
					}
				}
				if (findFalse == 1)
				{
					idxFalse = idtab.size;
				}
				if(findFalse != 1 && findFalse > 1) {

					findSameID = true;
					LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, idxFalse, line);
					LT::Add(lextab, entryLT);
					break;

				}
				if (findSameID) continue;

				entryIT.value.vbool = value;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::BOOL;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtab, entryIT);
				entryIT = {};

				/*int k = 0;
				for (k = 0; k < idtab.size; k++)
				{
					if (idtab.table[k].value.vbool = word[i])
						break;
				}*/
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, IT::IsId(idtab, nameLiteral), line);
				LT::Add(lextab, entryLT);
			}
			else if (literalstring(word[i]))
			{
				int length = strlen(word[i]);
				if (strlen(word[i]) == 2)
				{
					throw ERROR_THROW(321)
				}
				if (length - 2 > TI_STR_MAXSIZE)
				{
					throw ERROR_THROW(316);
				}
				for (int k = 0; k < length; k++)
					word[i][k] = word[i][k + 1];
				word[i][length - 2] = 0;

				for (int k = 0; k < idtab.size; k++) {
					if (!(strcmp(idtab.table[k].value.vstr.str, word[i])))
					{
						findSameID = true;
						LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
						LT::Add(lextab, entryLT);
						break;
					}
				}
				if (findSameID) continue;

				strcpy(entryIT.value.vstr.str, word[i]);
				entryIT.value.vstr.len = length - 2;
				entryIT.idtype = IT::L;
				entryIT.iddatatype = IT::STR;
				entryIT.idxfirstLE = indexLex;

				_itoa_s(literalCounter++, charclit, sizeof(char) * 10, 10);
				strcpy(bufL, L);
				nameLiteral = strcat(bufL, (char*)charclit);
				strcpy(entryIT.id, nameLiteral);
				IT::Add(idtab, entryIT);
				entryIT = {};

				int k = 0;
				for (k = 0; k < idtab.size; k++)
				{
					if (!(strcmp(idtab.table[k].value.vstr.str, word[i])))
						break;
				}
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LITERAL, k, line);
				LT::Add(lextab, entryLT);
			}
			else if (left(word[i]) || right(word[i]) || expression(word[i]))
			{
				if (left(word[i])) strcpy(word[i], "<<");
				if (right(word[i])) strcpy(word[i], ">>");
				strcpy(entryIT.id, word[i]);
				entryIT.idxfirstLE = indexLex;
				entryIT.idtype = IT::OP;
				if (IT::IsId(idtab, word[i]) == TI_NULLIDX)
					IT::Add(idtab, entryIT);
				entryIT = { };

				LT::Entry entryLT = WriteEntry(entryLT, LEX_OPERATOR, IT::IsId(idtab, word[i]), line);
				switch (word[i][0])
				{
				case '>':
					entryLT.priority = 2;
					entryLT.op = LT::operations::RIGHT;
					break;
				case '<':
					entryLT.priority = 2;
					entryLT.op = LT::operations::LEFT;
					break;
				case '+':
					entryLT.priority = 1;
					entryLT.op = LT::operations::OPLUS;
					break;
				case '-':
					entryLT.priority = 1;
					entryLT.op = LT::operations::OMINUS;
					break;
				case '*':
					entryLT.priority = 3;
					entryLT.op = LT::operations::OMUL;
					break;
				case '/':
					entryLT.priority = 3;
					entryLT.op = LT::operations::ODIV;
					break;
				
				}
				LT::Add(lextab, entryLT);

			}
			else if (idenf(word[i]))
			{
				if (strlen(word[i]) > ID_MAXSIZE)
				{
					throw ERROR_THROW(317);
				}
				if (findParm)
					entryIT.idtype = IT::P;
				else if (findFunc)
				{
					entryIT.idtype = IT::F;
					functions.push(word[i]);
				}
				else
				{
					entryIT.idtype = IT::V;
					int idx = IT::IsId(idtab, word[i]);
					if (idx != TI_NULLIDX) {
						LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, idx, line);
						LT::Add(lextab, entryLT);
						
						entryIT = { };
						continue;
					}
					if (idx == TI_NULLIDX && !findDeclaration && findType) throw ERROR_THROW(304);
					if (idx == TI_NULLIDX && findDeclaration && !findType) throw ERROR_THROW(306);
					
					
					if (entryIT.iddatatype == IT::UINT)
						entryIT.value.vuint = TI_INT_DEFAULT;
					else if (entryIT.iddatatype == IT::BOOL)
					{
						entryIT.value.vbool = false;
					}
					else if (entryIT.iddatatype == IT::STR)
					{
						entryIT.value.vstr.len = 0;
						memset(entryIT.value.vstr.str, TI_STR_DEFAULT, sizeof(char));
					}
				}
				int idx = IT::IsId(idtab, word[i]);
				if (idx != TI_NULLIDX && findParm) throw ERROR_THROW(308);
				entryIT.idxfirstLE = indexLex;
				if (entryIT.idtype != IT::F && !functions.empty())
				{
					strcpy(bufprefix, functions.top().c_str());
					bufprefix = strcat(bufprefix, "_");
					word[i] = strcat(bufprefix, word[i]);
				}
				strcpy(entryIT.id, word[i]);
				idx = IT::IsId(idtab, word[i]);
				
				if (idx != TI_NULLIDX && findDeclaration && findType) throw ERROR_THROW(308);
				if (findFunc && !findParm)
				{
					int c = i + 1;
					
			
					while (!leftbrace(word[c]))
					{
						if (typestr(word[c]) || typebool(word[c]) || typeuint(word[c])) 
						{
							if (typestr(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::STR;
								
							}
							if (typebool(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::BOOL;
								
							}
							if (typeuint(word[c]))
							{
								entryIT.params.type[entryIT.params.count] = IT::UINT;
								
							}
							entryIT.params.count++;
							if (entryIT.params.count > MAX_PARAMS)
							{
								throw ERROR_THROW(318)
							}
						}
						c++;
					}
				}
				if (idx != TI_NULLIDX && typefunction(word[i - 1])) throw ERROR_THROW(307);
				if (idx == TI_NULLIDX && !findFunc && !findParm) 
				{
					if (i > 1)
					{
						if (!(typestr(word[i - 1]) || typebool(word[i - 1]) || typeuint(word[i - 1])))
						{
							throw ERROR_THROW(305);
						}
					}
					else
						throw ERROR_THROW(305);
				}
				if (idx == TI_NULLIDX)
					IT::Add(idtab, entryIT);
				/*if (idx == TI_NULLIDX && !findDeclaration && !findType && !findFunc && !findParm) 
					throw ERROR_THROW(305);*/
				if (!findFunc && functions.empty()) throw ERROR_THROW(303);
				LT::Entry entryLT = WriteEntry(entryLT, LEX_ID, IT::IsId(idtab, word[i]), line);
				LT::Add(lextab, entryLT);
				entryIT = { };
			}
			else if (semicolon(word[i]))
			{
				/*if (findDeclaration && findFunc && findType)
					functions.pop();*/
				LT::Entry entryLT = WriteEntry(entryLT, LEX_SEMICOLON, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
				findDeclaration = findFunc = findType = findParm = false;
				entryIT = { };
			}
			else if (comma(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_COMMA, LT_TI_NULLIDX, line);
				
				LT::Add(lextab, entryLT);
			}
			else if (leftbrace(word[i]))
			{
				findType = findDeclaration = findFunc = findParm = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTBRACE, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (rightbrace(word[i]))
			{
				if (!functions.empty() && is_cycle == 0)
					functions.pop();
				else if (is_cycle != 0) is_cycle--;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_BRACELET, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (leftthesis(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_LEFTHESIS, LT_TI_NULLIDX, line);
				
				LT::Add(lextab, entryLT);
				if (findFunc)
					findParm = true;
			}
			else if (rightthesis(word[i]))
			{
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RIGHTHESIS, LT_TI_NULLIDX, line);
				
				findParm = false;
				LT::Add(lextab, entryLT);
			}
			else if (ravno(word[i]))
			{
				findDeclaration = findType = false;
				LT::Entry entryLT = WriteEntry(entryLT, LEX_RAV, LT_TI_NULLIDX, line);
				LT::Add(lextab, entryLT);
			}
			else if (word[i][0] == DIV)
			{
				line++;
				position = 0;
				indexLex++;
			}
			else
				throw ERROR_THROW(205);
		}


		if (lextab.size > LT_MAXSIZE) throw ERROR_THROW(201);
		if (idtab.size > TI_MAXSIZE) throw ERROR_THROW(203);
		if (!findMain) throw ERROR_THROW(302);
		if (mainCounter > 1) throw ERROR_THROW(301);

		lex.lextab = lextab;
		lex.idtab = idtab;

		return lex;
	
		
	}
}