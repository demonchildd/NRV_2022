#include "Generation.h"

using namespace std;

namespace Gen {
	Generator::Generator(LT::LexTable plexT, IT::IdTable pidT, const char* pout)
	{
		lexT = plexT;
		idT = pidT;
		out = ofstream(pout);

		Head();
		Const();
		Data();
		Code();
	}

	void Generator::Head() {
		out << ".586\n";
		out << ".model flat, stdcall\n";
		out << "includelib libucrt.lib\n";
		out << "includelib kernel32.lib\n";
		out << "includelib ../Debug/StaticLib.lib\n";
		out << "ExitProcess PROTO :DWORD\n\n";
		out << "OutputInt PROTO : DWORD\n";
		out << "OutputStr PROTO : DWORD\n";
		out << "EXTRN Date: proc\n";
		out << "EXTRN Time: proc\n";

		
		out << "\n.stack 4096\n\n";
	}

	void Generator::Const() {
		out << ".CONST\n";
		out << "\toverflownum BYTE \"Выход за пределы значения\", 0\n";
		out << "\tneguint BYTE \"Отрицательное число\", 0\n";
		out << "\tzerodel BYTE \"Деление на ноль\", 0\n";
		for (int i = 0; i < idT.size; i++)
		{
			if (idT.table[i].idtype == IT::L)
			{
				out << "\t" << idT.table[i].id;
				if (idT.table[i].iddatatype == IT::STR)
					out << " BYTE \"" << idT.table[i].value.vstr.str << "\", 0";
				if (idT.table[i].iddatatype == IT::UINT)
					out << " DWORD " << idT.table[i].value.vuint;
				if (idT.table[i].iddatatype == IT::BOOL)
					out << " DWORD " << idT.table[i].value.vbool;
				out << "\n";
			}
		}
	}

	void Generator::Data() {
		out << "\n.data\n";
		out << "\tcount DWORD 0\n";
		for (int i = 0; i < lexT.size; i++) {
			if (lexT.table[i].lexema == LEX_NEW) {
				if (idT.table[lexT.table[i + 2].idxTI].idtype == IT::V) {
					out << "\t" << idT.table[lexT.table[i + 2].idxTI].id;
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::STR)
						out << " DWORD ?\n";
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::UINT)
						out << " DWORD 0\n";
					if (idT.table[lexT.table[i + 2].idxTI].iddatatype == IT::BOOL)
						out << " DWORD 0\n";
				}
			}
		}
	}

	void Generator::Code() {
		stack<char*> stk;
		int num_of_ret = 0,
			num_of_cycles = 100,
			countParm = 0;
		int cycleCounter = 0;
		char* cycle = new char[6] { "CYCLE" };
		char* bufCycle = new char[TI_STR_MAXSIZE];
		char* in = new char[10] { "" };
		string func_name = string();
		bool flag_func = false,
			flag_ret = false,
			flag_body = false,
			flag_callfunc = false,
			flag_cycle = false;
		int result_position;

		out << "\n.code\n\n";
		for (int i = 0; i < lexT.size; i++) {
			switch (lexT.table[i].lexema) {
			case LEX_FUNCTION:
				func_name = idT.table[lexT.table[i + 1].idxTI].id;
				while (lexT.table[i].lexema != LEX_RIGHTHESIS) {
					if (lexT.table[i].lexema == LEX_ID &&
						idT.table[lexT.table[i].idxTI].idtype == IT::F) {
						out << (char*)idT.table[lexT.table[i].idxTI].id << " PROC ";
					}

					if (lexT.table[i].lexema == LEX_ID && idT.table[lexT.table[i].idxTI].idtype == IT::P) {
						out << idT.table[lexT.table[i].idxTI].id << " : ";
						out << "DWORD";
					}

					if (lexT.table[i].lexema == LEX_COMMA)
						out << ", ";

					i++;
				}
				flag_func = true;
				out << "\n";
				break;

			case LEX_MAIN:
				flag_body = true;
				out << "main PROC\n";
				break;
			case LEX_RAV:
				result_position = i - 1;
				while (lexT.table[i].lexema != LEX_SEMICOLON) {
					switch (lexT.table[i].lexema) {
					case LEX_ID:
					case LEX_LITERAL:
						if (idT.table[lexT.table[i].idxTI].idtype == IT::F)
							flag_callfunc = true;
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::UINT) {
							out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
							stk.push(idT.table[lexT.table[i].idxTI].id);
							break;
						}
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::BOOL) {
							out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
							stk.push(idT.table[lexT.table[i].idxTI].id);
							break;
						}
						if (idT.table[lexT.table[i].idxTI].iddatatype == IT::STR) {
							char* s;
							if (idT.table[lexT.table[i].idxTI].idtype == IT::L) {
								out << "\tpush offset " << idT.table[lexT.table[i].idxTI].id << "\n";
								s = new char[8] { "offset " };
							}
							else {
								out << "\tpush " << idT.table[lexT.table[i].idxTI].id << "\n";
								s = new char[1] { "" };
							}

							int len1 = strlen((char*)s);
							int len2 = strlen((char*)idT.table[lexT.table[i].idxTI].id);
							char* result = (char*)malloc(len1 + len2 + 1);
							memcpy(result, s, len1);
							memcpy(result + len1, (char*)idT.table[lexT.table[i].idxTI].id, len2 + 1);
							stk.push(result);
							break;
						}

					case LEX_OPERATOR:
						switch (lexT.table[i].op) {
						case LT::OMUL:
							out << "\tpop eax\n\tpop ebx\n";
							out << "\tmul ebx\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							break;
						case LT::OPLUS:
							out << "\tpop eax\n\tpop ebx\n";
							out << "\tadd eax, ebx\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							break;
						case LT::OMINUS:
							out << "\tpop ebx\n\tpop eax\n";
							out << "\tsub eax, ebx\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							break;
						case LT::ODIV:
							out << "\tpop ebx\n\tpop eax\n";
							out << "\cmp ebx, 0\nje DELZERO\n";
							out << "\tcdq\n\tidiv ebx\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							break;
						case LT::LEFT:
							_itoa_s(cycleCounter++, in, sizeof(char) * 10, 10);
							strcpy(bufCycle, cycle);
							bufCycle = strcat(bufCycle, in);
							out << "\tpop ecx\n";
							out << bufCycle << ":\n";
							out << "\tpop eax\n";
							out << "\tshl eax, 1\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							out << "\tloop " << bufCycle << "\n";
							break;
						case LT::RIGHT:
							_itoa_s(cycleCounter++, in, sizeof(char) * 10, 10);
							strcpy(bufCycle, cycle);
							bufCycle = strcat(bufCycle, in);
							out << "\tpop ecx\n";
							out << bufCycle << ":\n";
							out << "\tpop eax\n";
							out << "\tshr eax, 1\n";
							out << "\tcmp eax, 255\njg OVERFLOW\n\tcmp eax, 0\njl NEGNUM\n";
							out << "\tpush eax\n";
							out << "\tloop " << bufCycle << "\n";
							break;

						}
						break;

					case '@':
						countParm = (char)lexT.table[i + 1].lexema - '0';

						for (int j = 1; j <= countParm; j++)
							out << "\tpop edx\n";

						for (int j = 1; j <= countParm; j++) {
							out << "\tpush " << stk.top() << "\n";
							stk.pop();
						}
						out << "\tcall " << idT.table[lexT.table[i].idxTI].id << "\n\tpush eax\n";
						flag_callfunc = false;
						break;
					}

					i++;
				}
				
				out << "\tpop " << idT.table[lexT.table[result_position].idxTI].id << "\n";
				break;
			
			case LEX_RETURN:
				out << "\tpush ";
				if (idT.table[lexT.table[i + 1].idxTI].idtype == IT::L)
				{
					if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::UINT)
					{
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
					else if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::BOOL)
					{
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
					else if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::STR)
					{
						out << "offset ";
						out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
					}
				}
				else
					out << idT.table[lexT.table[i + 1].idxTI].id << "\n";
				if (flag_func) {
					out << "\tjmp local" << num_of_ret << "\n";
					flag_ret = true;
				}
				break;
			case LEX_BRACELET:
				if (flag_body && !flag_func && !flag_cycle) {
					out << "OutAsm:\n";
					out << "\tpush 0\n\tcall ExitProcess\n";
					out << "OVERFLOW:\n\tpush offset overflownum\n\tcall OutputStr\n";
					out << "\tpush 0\n\tcall ExitProcess\n";
					out << "NEGNUM:\n\tpush offset neguint\n\tcall OutputStr\n";
					out << "DELZERO:\n\tpush offset zerodel\n\tcall OutputStr\n";
					out << "\tpush 0\n\tcall ExitProcess\n";
					out << "main ENDP\nend main";
				}
				if (flag_func && !flag_cycle) {
					if (flag_ret) {
						out << "local" << num_of_ret++ << ":\n";
						out << "\tpop eax\n\tret\n";
						out << "OVERFLOW:\n\tpush offset overflownum\n\tcall OutputStr\n";
						out << "\tpush 0\n\tcall ExitProcess\n";
						out << "NEGNUM:\n\tpush offset neguint\n\tcall OutputStr\n";
						out << "DELZERO:\n\tpush offset zerodel\n\tcall OutputStr\n";
						out << "\tpush 0\n\tcall ExitProcess\n";
						flag_ret = false;
					}
					out << func_name << " ENDP\n\n";
					flag_func = false;
				}
				if (flag_cycle) {
					out << "\tdec count\n\tmov ecx, count\n";
					out << "loop CYCLE" << num_of_cycles++ << endl;
					
					flag_cycle = false;
				}
				break;
			case LEX_CYCLE:
				
				flag_cycle = true;
				out << "\tpush " << idT.table[lexT.table[i + 2].idxTI].id << endl;
				out << "\tpop count\n";
				out << "\tadd count, 1\n";
				out << "\tmov ecx, count\n";
				out << "CYCLE" << num_of_cycles << ":\n";
				i = i + 3;

				break;
			

			case LEX_PRINT:
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::UINT)
					out << "\tpush " << idT.table[lexT.table[i + 1].idxTI].id << "\n\tcall OutputInt\n";
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::BOOL)
					out << "\tpush " << idT.table[lexT.table[i + 1].idxTI].id << "\n\tcall OutputInt\n";
				if (idT.table[lexT.table[i + 1].idxTI].iddatatype == IT::STR) {
					if (idT.table[lexT.table[i + 1].idxTI].idtype == IT::L)
						out << "\tpush offset ";
					else
						out << "\tpush ";
					out << idT.table[lexT.table[i + 1].idxTI].id << "\n\tcall OutputStr\n";
				}
				break;
			
			}
		}
	}
}