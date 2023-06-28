// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNAttributeH
#define IKNAttributeH
//-------------------------------------------------------------------
#include "KNMacros.h"
//-------------------------------------------------------------------
// !!! �� ����������� - �� �������
/**
 *	@interface IKNAttribute
 *	�������� ���������� ��������, ��������� �������.
 *  @note ������������ ��� �������� ��������������� ���������. 
 */
class IKNAttribute
{
public:
    /** ��� ��������.
     *	@return 0 - ��������������� �������
     *			1 - ������������� �������
     */
//	virtual int GetType() const = 0;
	/** �������� ��������. */
	virtual t_errno GetName( char* oName ) const = 0;
	/** ����� ��������. */
//	virtual t_errno GetMask( char* oMask ) = 0;
    /** ���������� �������� ��������. */
	virtual unsigned GetCount() const = 0;
	/** �������� ��������. */
	virtual t_errno GetValue( unsigned iIndex, char* oVal ) const = 0;
	/** �������� ��������. */
	virtual bool IsValue( char* iVal ) const = 0;
	/** ������ ������� �������� ��������. */
	virtual int GetValueIndex( char* iVal ) const = 0;
//----------------------------------------------------------
	/** ���������� �������� ��������. */
	virtual t_errno AddValue( char* iVal ) = 0;
	/** �������� �������� ��������. */
	virtual void DeleteValue( char* iVal ) = 0;
	/** �������� �������� ��������. */
	virtual t_errno EditName( char* iNewName ) = 0;
};

#endif
