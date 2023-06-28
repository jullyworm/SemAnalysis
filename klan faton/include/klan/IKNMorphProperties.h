// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNMorphPropertiesH
#define IKNMorphPropertiesH
//---------------------------------------------------------------------------
#include "IKNMorphAttribute.h"
//---------------------------------------------------------------------------
/**
 *	@interface IKNMorphProperties
 *	������ ��������������� ���������.
 *	@note ������� �������������� �����: ��� �������� - �������� ��������
 */
class IKNMorphProperties
{
public:
	/** �������� ���������� ��������� ��������� ��������. */
	virtual unsigned GetCount() const = 0;

	/**
	 * ������ ���������������� ��������.
	 * @param   iIndex - index of property in list(0-based)
	 * @param   oName - ��� ���������������� ��������
	 * @param   oVal - �������� ���������������� ��������
	 */
	virtual t_errno GetProperty( unsigned iIndex, char* oName, char* oVal ) const = 0;
	virtual const char* GetPropertyName( unsigned iIndex ) const = 0;
	virtual const char* GetPropertyValue( unsigned iIndex ) const = 0;
//	virtual t_errno GetProperty( unsigned iIndex, IKNMorphAttribute* oAttrType, char* oVal ) = 0;

	/** ������ ���������������� ��������.
	 *	@param oValNum - ����� �������� ���������������� ��������
     *	@return ��������������� ������� (�� ��������������� �������) 
	 */
	virtual IKNMorphAttribute* GetPropertyType( unsigned iIndex, unsigned* oValNum ) const = 0;

	/** ���������� ���������������� ��������.
	 *	@param oValueNum - ����� �������� ���������������� ��������
     *	@return ��������������� ������� (�� ��������������� �������) 
	 */
	virtual t_errno AddProperty( IKNMorphAttribute* iAttrType, unsigned iValNum ) = 0;
	virtual t_errno AddProperty( IKNMorphAttribute* iAttrType, char* iVal ) = 0;
};

#endif
