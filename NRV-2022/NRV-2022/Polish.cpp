#include "Polish.h"

using namespace std;

namespace Polish
{
	bool PolishNotation(int i, LexAnal::Lex& lex)
	{
		stack<LT::Entry> stack;	// В стек будем заносить операции
		queue<LT::Entry> queue;	// В очередь будем заносить операнды

		LT::Entry placeholder_symbol;
		placeholder_symbol.idxTI = -1;
		placeholder_symbol.lexema = ' ';
		placeholder_symbol.sn = lex.lextab.table[i].sn;

		LT::Entry function_symbol;				// Лексема, обозначающая конец функции
		function_symbol.idxTI = LT_TI_NULLIDX;	// Признак начала и окончания функции
		function_symbol.lexema = '@';
		function_symbol.sn = lex.lextab.table[i].sn;
		int idx;

		int lexem_counter = 0;
		int parm_counter = 0;			// Количество параметров в функции
		int lexem_position = i;			// Запоминаем номер лексемы перед преобразованием
		char* buf = new char[i];

		bool findFunc = false;

		for (i; lex.lextab.table[i].lexema != LEX_SEMICOLON; i++, lexem_counter++)
		{
			switch (lex.lextab.table[i].lexema)
			{
			case LEX_ID:
			case LEX_LITERAL:
				if (lex.idtab.table[lex.lextab.table[i].idxTI].idtype == IT::F)
				{
					findFunc = true;
					idx = lex.lextab.table[i].idxTI;
				}
				else
				{
					if (findFunc)
						parm_counter++;
					queue.push(lex.lextab.table[i]);
				}
				continue;
			case LEX_LEFTHESIS:
				stack.push(lex.lextab.table[i]);
				continue;
			case LEX_RIGHTHESIS:
				while (stack.top().lexema != LEX_LEFTHESIS)
				{
					queue.push(stack.top());
					stack.pop();
					if (stack.empty())
						return false;
				}

				if (!findFunc)
					stack.pop();
				else {
					function_symbol.idxTI = idx;
					idx = LT_TI_NULLIDX;
					lex.lextab.table[i] = function_symbol;
					queue.push(lex.lextab.table[i]);
					_itoa_s(parm_counter, buf, 2, 10);
					stack.top().lexema = buf[0];
					stack.top().idxTI = LT_TI_NULLIDX;
					stack.top().sn = function_symbol.sn;
					queue.push(stack.top());
					stack.pop();
					parm_counter = 0;
					findFunc = false;
				}
				continue;
			case LEX_OPERATOR:
				while (!stack.empty() && lex.lextab.table[i].priority <= stack.top().priority)
				{
					queue.push(stack.top());
					stack.pop();
				}
				stack.push(lex.lextab.table[i]);
				continue;
			}
			
		}
		while (!stack.empty())
		{
			if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTHESIS)
				return false;

			queue.push(stack.top());
			stack.pop();
		}

		while (lexem_counter != 0)
		{
			if (!queue.empty())
			{
				lex.lextab.table[lexem_position++] = queue.front();
				queue.pop();
			}
			else
				lex.lextab.table[lexem_position++] = placeholder_symbol;

			lexem_counter--;
		}

		for (int i = 0; i < lexem_position; i++)
		{
			if (lex.lextab.table[i].lexema == LEX_OPERATOR || lex.lextab.table[i].lexema == LEX_LITERAL)
				lex.idtab.table[lex.lextab.table[i].idxTI].idxfirstLE = i;
		}
		return true;
	}


	void startPolish(LexAnal::Lex& lex)
	{
		for (int i = 0; i < lex.lextab.size; i++)
		{
			if (lex.lextab.table[i].lexema ==  '=')
			{
				PolishNotation(i + 1, lex);
			}
		}
	}
}