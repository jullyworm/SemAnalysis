// Copyright (c) 2009 by IIS. All rights reserved.
//===================================================================
// July 2009                  Created               L. Sidorova, IIS
//===================================================================
#ifndef IKNPhraseShellH
#define IKNPhraseShellH
//---------------------------------------------------------------------------
#include "IKNPhrase.h"
#include "IKNWordShell.h"
//-------------------------------------------------------------------
/**
 *	@interface IKNWordShell
 *	����� �������, ��������� � ������, �� ������� ���������, ��������������� 
 *	����������� ��� ������������� � ������.
 *	@note 	����� ��������� ��� ������� � ������, ���������� � 
 *			����. �������� ������ ���������� (�� �����������)
 */
class IKNPhraseShell
{
public:
	/** �������� ������� ����� � ����� � �� ��������� ��������. */
	virtual IKNWordShell* GetMainWord() =0;
	/** �������� ��������� ������������� (�����),���������� � ������. */
	virtual IKNPhrase* GetPhrase() const = 0;

	/** �������� ��������� ������ ����� � ������. */
	virtual uint GetPosId() const = 0;
	virtual uint GetPosEndId() const = 0;
	/** �������� ���������� ���� � ������. */
//	virtual uint GetNum() const = 0;

	/** �������� ��������� � �������� ������� ����� � ������. */
	virtual uint GetTextPos( uint* end_pos ) const = 0;
	/** �������� ����� ����� � ������. */
//	virtual char* GetForm() const = 0;
	virtual t_errno GetForm( char* oForm ) const = 0;

	/** �������� ���������� ����� ��������� (��������������� ��������). */
	virtual IKNWordShell* GetPartShell( unsigned iPartId ) const = 0;
};

#endif
