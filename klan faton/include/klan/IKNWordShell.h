// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNWordShellH
#define IKNWordShellH
//---------------------------------------------------------------------------
#include "IKNMorphProperties.h"
#include "IKNWord.h"
//-------------------------------------------------------------------
/**
 *	@interface IKNWordShell
 *	����� �������, ��������� � ������, � ������� ���������, ��������������� 
 *	����������� ��� ������������� � ������.
 *	@note 	����� ��������� ��� ������� � ������, ���������� � 
 *			����. �������� ������ ���������� (�� �����������)
 */
class IKNWordShell
{
public:
	/** �������� ��������� ������, ��������������� �����, ���������� � ������. */
	virtual IKNWord* GetWord() const = 0;
	/** �������� ������ ����� � ������. */
	virtual uint GetPosId() const = 0;
	/** �������� ������� ����� � ������. */
	virtual uint GetTextPos( uint* end_pos ) const = 0;

	virtual const char* GetForm() const = 0;

	/** �������� ��������������� ��������� �����, ���������� � ������.
	 *	@note ��������� �������� ����� ������� � ������� �������� �����������.
	 *	@note ����� ������ ������������ PHRASE_LENGTH
	 */
//	virtual t_errno PropertyEFormat( char* oProperty ) = 0;

	/** �������� ��������������� ��������� �����, ���������� � ������.
	 *	@note ��������� �������� ����� ������� � ������� �������� �����������.
	 *	@note ����� ������ ������������ PHRASE_LENGTH
	 */
//	virtual char* PropertyEFormat() = 0;

	/** �������� ��������������� ��������� �����, ���������� � ������.
	 *	@note ��������� �������� ����� ������� �� ���������� �������.
	 */
	virtual t_errno GetPropertyAsString( char* oProperty ) = 0;

	/** �������� ���������� ����� ��������� (��������������� ��������). */
	virtual uint GetPropertyGroupCount() = 0;

	/** �������� ������ ���������. */
	virtual IKNMorphProperties* GetPropertyGroup( uint iGroupIndex ) = 0;
};

#endif
