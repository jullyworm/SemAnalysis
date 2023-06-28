// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNResultListH
#define IKNResultListH
//---------------------------------------------------------------------------
#include "IKNMorphProperties.h"
//#include "IKNWordShell.h"
#include "IKNPhraseShell.h"
//-------------------------------------------------------------------
/**
 *	@interface IKNResultList
 *	������ ��������� �������.
 */
class IKNResultList
{
public:
	/** �������� ���������� ��������� ��������� ��������.
     * @param iType - ��� ��������� ��������
     *		iType = -1 - ��� ��������
     *		iType = 0  - ��� ����� (� ���������)
     *		iType = 1  - ����� �� ������� �������� ����
     *		iType = 2  - ����� �� ����-�������
     *		iType = 3  - ��� �� (� ���������)
     *		iType = 4  - �� �� ������� �������� ��
     *		iType = 5  - �� �� ����-�������
     *		iType = 6  - ���-�� ��������������� ����
     *		iType = 7  - ���-�� ��������������� ��
     *		iType = 10  - ����� �����
     *		iType = 11  - ����� ��
     */
	virtual int GetCount( int iType = -1 ) = 0;

	virtual void InitWordsList() = 0;
	/** ����� ��������� �����, ��������� � ������. */
	virtual IKNWordShell* GetNextWordShell() const = 0;

	/** ������ �� �� �������. */
	virtual IKNPhraseShell* GetPhraseShell( unsigned iPhraseIndex ) const = 0;

/** ��� �������������� ��������� shell-� ��������� � ��������� ���������� � ����������� ����������.
 * � ������ ���� ��������� �������� ��� ����� MORPH_ANALISYS � WORK_ANALISYS
 */
	virtual void InitStatisticWords() = 0;
	/** ����� ��������� �����, ��������� � ������.
	 * @param   oCount - count word in text
	 */
	virtual IKNWord* GetStatisticWord( uint* oCount ) const = 0;

	virtual void InitStatisticPhrases() = 0;
	/** ����� ��������� �����, ��������� � ������.
	 * @param   oCount - count phrse in text
	 */
	virtual IKNPhrase* GetStatisticPhrase( uint* oCount ) const = 0;

};

#endif
