#include "stdafx.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[��������� ������] ������������ ��� ������"),
		ERROR_ENTRY(1, "[��������� ������] ��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "[�������� ������] �������� -in ������ ���� �����"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "[�������� ������] ��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "[�������� ������] ������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "[�������� ������] ������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112, "[�������� ������] ������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY_NODEF(113), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "[����������� ������] ����������� ������ � �������� ����� (-in)"),
		ERROR_ENTRY(201, "[����������� ������] ������ ������� ������ ��������"),
		ERROR_ENTRY_NODEF(202),
		ERROR_ENTRY(203, "[����������� ������] ������ ������� ��������������� ��������"),
		ERROR_ENTRY_NODEF(204),
		ERROR_ENTRY(205, "[����������� ������] ����������� ������������������ ��������"),
		ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY_NODEF(300),
		ERROR_ENTRY(301, "[������������� ������] ������� ����� ����� ����� ����� � main"),
		ERROR_ENTRY(302, "[������������� ������] �� ������� ����� ����� � main"),
		ERROR_ENTRY(303, "[������������� ������] ���������� ���������� ����������"),
		ERROR_ENTRY(304, "[������������� ������] ���������� ���������� ��� ��������� ����� new"),
		ERROR_ENTRY(305, "[������������� ������] ������������� �������������"),
		ERROR_ENTRY(306, "[������������� ������] ��������� ���������� ��� �������� ����"),
		ERROR_ENTRY(307, "[������������� ������] ������� ����������� ������������ �������"),
		ERROR_ENTRY(308, "[������������� ������] ��������� ���������� ��������������"),
		ERROR_ENTRY(309, "[������������� ������] ������������ ����� ������������ ���������� �������"),
		ERROR_ENTRY(310, "[������������� ������] �������������� �������������� ����������"),
		ERROR_ENTRY(311, "[������������� ������] ������������ �������� � �����"),
		ERROR_ENTRY(312, "[������������� ������] ������������� ����� ������"),
		ERROR_ENTRY(313, "[������������� ������] �������� uint ���������"),
		ERROR_ENTRY(314, "[������������� ������] ������� ���������� �������� ��� ������"),
		ERROR_ENTRY(315, "[������������� ������] �������������� ���������� ������������ ���������� �������"),
		ERROR_ENTRY(316, "[������������� ������] ����� ������ ���������"),
		ERROR_ENTRY(317, "[������������� ������] ����� �������������� ���������"),
		ERROR_ENTRY(318, "[������������� ������] ��������� ����� ���������� �������"),
		ERROR_ENTRY(319, "[������������� ������] ������� �� ����"),
		ERROR_ENTRY(320, "[������������� ������] ������������� ��������"),
		ERROR_ENTRY(321, "[������������� ������] ������������� ������� ������"),
		ERROR_ENTRY_NODEF(322), ERROR_ENTRY_NODEF(323), ERROR_ENTRY_NODEF(324), ERROR_ENTRY_NODEF(325),
		ERROR_ENTRY_NODEF(326), ERROR_ENTRY_NODEF(327), ERROR_ENTRY_NODEF(328), ERROR_ENTRY_NODEF(329),
		ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
		ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400),
		ERROR_ENTRY_NODEF10(500), ERROR_ENTRY_NODEF10(510), ERROR_ENTRY_NODEF10(520), ERROR_ENTRY_NODEF10(530), ERROR_ENTRY_NODEF10(540),
		ERROR_ENTRY_NODEF10(550), ERROR_ENTRY_NODEF10(560), ERROR_ENTRY_NODEF10(570), ERROR_ENTRY_NODEF10(580), ERROR_ENTRY_NODEF10(590),
		ERROR_ENTRY(600, "[�������������� ������] �������� ��������� ���������"),
		ERROR_ENTRY(601, "[�������������� ������] ��� ���������� main"),
		ERROR_ENTRY(602, "[�������������� ������] ������ � ���������� �������"),
		ERROR_ENTRY(603, "[�������������� ������] ����������� ���� �������"),
		ERROR_ENTRY(604, "[�������������� ������] ������������ ���������"),
		ERROR_ENTRY_NODEF(605),
		ERROR_ENTRY(606, "[�������������� ������] �������� ����������� � ���� �������"),
		ERROR_ENTRY(607, "[�������������� ������] ������ � �����"),
		ERROR_ENTRY(608, "[�������������� ������] ������ � ������ �������"),
		ERROR_ENTRY_NODEF(609),
		ERROR_ENTRY(610, "[�������������� ������] ������ � ������ ���������� ��� ������ �������"),
		ERROR_ENTRY(611, "[�������������� ������] ��������� ���������� � log �����"),
		ERROR_ENTRY_NODEF(612),
		ERROR_ENTRY_NODEF(614), ERROR_ENTRY_NODEF(615), ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617), ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900) 
	};

	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			return errors[id];
		}
		else
		{
			return errors[0];			//������������ ��� ������
		}
	}

	ERROR geterrorin(int id = -1, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return errors[id];
		}
		else
		{
			return errors[0];			//������������ ��� ������
		}
	}
}