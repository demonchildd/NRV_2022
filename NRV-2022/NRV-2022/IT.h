#pragma once
#include "LT.h"
#define ID_MAXSIZE 10				//���� ���-�� �������� � �����.
#define TI_MAXSIZE 4096				//���� ���-�� ����� � ��
#define TI_INT_DEFAULT 0x00000000	//����. �� ����� ��� integer
#define TI_STR_DEFAULT 0x00			//����. �� ����� ��� string
#define TI_NULLIDX 0xffffffff		//��� ��������� ��
#define TI_STR_MAXSIZE 255			//������������ ������ ������
#define TI_UINT_MAXSIZE 255
#define MAX_PARAMS 5

namespace IT	//������� ���������������
{
	enum IDDATATYPE { UINT = 1, BOOL = 2, STR = 3 };		///���� ������ ���������������: integer, string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5 };	///���� ���������������: ����������, �������, ��������, �������
	
	struct Entry	//������ ��
	{
		int idxfirstLE;			///������ ������ ������ � ������� ������
		char id[ID_MAXSIZE * 2 + 1];	///�������������(������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE iddatatype;	///��� ������
		IDTYPE idtype;			///��� ��������������
		struct
		{
			int count;
			IDDATATYPE type[MAX_PARAMS];
		}params;
		struct		// 
		{
			unsigned int vuint = 0;					// �������� unsigned integer
			bool vbool;
			struct
			{
				int len;						// ���������� �������� � string
				char str[TI_STR_MAXSIZE - 1]{};	// ������� string
			}vstr;								// �������� string
		}value;		// �������� ��������������							
	};

	struct IdTable	//��������� ��
	{
		int maxsize;	///������� �� < TI_MAXSIZE
		int size;		///������� ������ �� < maxsize
		Entry* table;	///������ ����� ��
	};

	IdTable Create(				//������� ������� ���������������
		int size				///������� ������� ��������������� < TI_MAXSIZE
	);

	void Add(				//�������� ������ � ������� ���������������
		IdTable& idtable,		/// �������� ������� ���������������
		Entry entry				///������ ������� ���������������
	);

	Entry GetEntry(IdTable& idtable, int n);	//�����. ��. �� ������ ������

	int IsId(					//�������: ����� ������(���� ����), TI_NULLIDX(���� ���)
		IdTable& idtable,		///�������� ������� ���������������
		char id[ID_MAXSIZE]		///�������������
	);

	void Delete(IdTable& idtable);		//������� ������� �����. (���������� �����)

	void ShowTable(
		IdTable idt,
		std::ostream& stream_out
	);
};