// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNAttributeListH
#define IKNAttributeListH
//-------------------------------------------------------------------
#include "IKNAttribute.h"
//-------------------------------------------------------------------
// !!! �� ����������� - �� �������
/**
 *	@interface IKNAttributeList
 *	������ ��� <������� - ��������>.
 *	@note ������������, ��������, ��� ��������� ������� ����������.
 *	@note ������������ �������� �� �����������.
 */
class IKNAttributeList
{
public:
	/** ��� ������ ���������.
	 *	@return 0 - ��������������� ��������
	 *			1 - ���������� ��������������� ��������
	 *			2 - ������������� �������
	 */
	virtual int GetType() const = 0;

	/** �������� ���������� ���. */
	virtual unsigned GetCount() const = 0;

	/**
	 * ������ ���� <������� - ��������>.
	 * @param   iIndex - index of property in list(0-based) 
	 * @param   oAttrName - ��� ��������
	 * @param   oVal - �������� ��������
	 */
	virtual t_errno Get( unsigned iIndex, char* oAttrName, char* oVal ) const = 0;
	/**
	 * ������ ���� <������� - ��������>.
	 *	@param   iIndex - index of property in list(0-based) 
	 *	@param oValueNum - ����� �������� �� ������ ��������
     *	@return �������
	 */
	virtual IKNAttribute* Get( unsigned iIndex, int* oValNum ) const = 0;

	/** ��������� ������� ���� � ������. */
	virtual bool IsPair( char* oAttrName, char* oVal ) const = 0;
	virtual bool IsAttr( char* oAttrName ) const = 0;
	virtual bool IsAttr( IKNAttribute* iAttr ) const = 0;

	/** ����� ���� <������� - ��������> �� �������� ��������. */
	virtual IKNAttribute* FindAttr( char* iVal ) const = 0;
	/** ����� �������� ��������. */
	virtual bool Find( IKNAttribute* iAttr, char* oVal ) const = 0;

	/** ���������������� ����� ���� �������� � ������ �� ��������. */
	virtual int InitFind( IKNAttribute* iAttr ) = 0;
	virtual int InitFind( char* oAttrName ) = 0;
	
	virtual t_errno GetNext( char* oVal ) = 0;
//-------------------------------------------------------------------
	/** �������� ���� <������� - ��������>. */
	virtual t_errno Add( IKNAttribute* iAttr, char* iVal ) = 0;
	/** ������� ����. */
	virtual void Delete( IKNAttribute* iAttr, char* iVal ) = 0;
	/** ������� ��� ���� ��������. */
	virtual void Delete( IKNAttribute* iAttr ) = 0;
};

#endif
