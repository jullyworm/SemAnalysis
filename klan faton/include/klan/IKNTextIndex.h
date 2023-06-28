// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
//===================================================================
// Nov                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNTextIndexH
#define IKNTextIndexH

//#include "KNMacros.h"
#include "KNMacros.h"
//---------------------------------------------------------------------------
/** 
 * @interface IKNTextIndex
 * ������ ������ (���������), ����������� ��� ��� �������������.
 * @note ������ ������ - ��� ������������� �������.
 *		 �� ������ ���� ����� �������� ��������� ���������:
 *      - �������� ��������
 *      - �������� �� ��������
 *      - ����������� �������� ��������
 *      - �������� �� ���� ��������������
 */
class IKNTextIndex
{
public:
	/** ���������� ��������. */
	virtual unsigned GetCount() const = 0;
	/** ���������� ��������� �������� � ������. */
	virtual unsigned GetTerminCount() const = 0;

	/**
	 * Get element of text profile 
	 * @param   iThemeIndex - index of theme in based list (0-based) 
	 * @param   oFirst - �������� �������� (projection of proximity)
	 * @param   oSecond - �������� �� �������� (projection of non-proximity)
	 * @param   oThird - ����������� �������� �������� (averaged projection of proximity)
	 * @param   isResult - �������� �� ���� ��������������
	 */
	virtual t_errno GetProfile( unsigned iThemeIndex, unsigned * oThemeId, float *oFirst, 
				float *oSecond, float *oThird, bool *isResult ) const = 0;
};
//---------------------------------------------------------------------------
#endif
