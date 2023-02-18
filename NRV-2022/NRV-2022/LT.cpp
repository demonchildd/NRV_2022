#include "stdafx.h"

namespace LT
{
	LexTable Create(int size)			//������� ��
	{
		LexTable* tabl = new LexTable;
		if (size > LT_MAXSIZE)///4096
		{
			throw ERROR_THROW(113);		///�������� ���������� ����� � �� > 4096
		}
		tabl->maxsize = size;
		tabl->size = 0;
		tabl->table = new Entry[size];	///����� ������ ��
		return *tabl;
	}

	void Add(LexTable& lextable, Entry entry)	//�������� ������ � ��
	{
		if (lextable.size + 1 > lextable.maxsize)
		{
			throw ERROR_THROW(114);		///��������� ���������� ����� � ��
		}

		lextable.table[lextable.size] = entry;
		lextable.size += 1;
	}
	Entry GetEntry(LexTable& lextable, int n)	//�������� ������ �� �
	{
		return lextable.table[n];
	}

	Entry WriteEntry(Entry& entry, char lexema, int indx, int line) {
		entry.lexema = lexema;
		entry.idxTI = indx;
		entry.sn = line;
		return entry;
	}

	void Delete(LexTable& lextable)	//������� ��
	{
		delete[] lextable.table;
		//delete &lextable;
	}

	void ShowTable(LexTable lextable, std::ostream& stream_out) {
		int line = 2;
		stream_out << "\n\t\t������������� �������������\n";
		stream_out << "0001| ";
		for (int i = 0; i < lextable.size; i++) {
			if (lextable.table[i].lexema == ';') {
				stream_out << lextable.table[i].lexema << std::endl;
				if (i + 1 == lextable.size) break;
				line > 999 ? stream_out << line << "| " : line > 99 ? stream_out << "0" << line << "| " : line > 9 ? stream_out << "00" << line <<
					"| " : stream_out << "000" << line << "| ";
				line++;
			}
			else stream_out << lextable.table[i].lexema;
		}
	}
};