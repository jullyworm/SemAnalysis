// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Usage notes: ���������� �������� ������� ����������� �� �����������.
// ������� type ���������� ��� ������� ������� + ��� ������� ��������� 
//===================================================================
// ������������ :   IKNWord, IKNPhrase, KNConcept
//===================================================================
// Sep 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNParadigmH
#define IKNParadigmH
//---------------------------------------------------------------------------
#include "KNMacros.h"
//#include "KNMacrosType.h"
#include "IKNMorphProperties.h"
//---------------------------------------------------------------------------
/** ��������� - ������ ��������� �����.
 *  � ������� ��������� ������������� ����� ����.��������.
 *	���� � ����� ���� ��������� �� ��� ���� ���������+��������� - ����� ����.��������
 */
class IKNParadigm
{
public:
    /** ���������� ���������. */
	virtual unsigned GetCount() const = 0;
    /** ���������� ���� � ���������� (������������� � GetCount()). */
	virtual unsigned GetCountPref() const = 0;
//    /** ����� �� ������� ����� ����� � ����������� (��� ���� �� ����������� �����). */
//	virtual bool IsPrefixInclude() const = 0;
    /** �������� ��������� (��� ���������). */
	virtual const char * GetFlex( unsigned iIndex ) const = 0;
    /** �������� ��������� ��� ����� � ����������. */
	virtual const char * GetFlexPref( uint iIndexPref ) const = 0;
    /** �������� ���������. */
	virtual const char * GetPref( uint iIndexPref ) const = 0;
    virtual t_errno GetFlexPref( uint iIndexPref, char* oFlex, char* oPref ) const = 0;

// ������ � ����������
    /** �������� ���������� ������� ����. ��������� ��������� iIndex.
	 *	@note ������ ��������� ����� ����� ��������� ����� ��������� (���� ������ ������ ����)
	 *		  ������: "���(�)" ����� �� ������ 2 �����: (��,���), (��,��) 
	 *	@note ����� ������ ����� ��� ���� � � ��� ��������� GetCount+GetCountPref
	 */
	virtual uint GetGroupCount( uint iIndex ) = 0;
    /** �������� ����� ����. ��������� � �������� iIndexGroup, ���������������
     *	���������� � ���������� iIndex � ���� ������ (����� PHRASE_LENGTH).
     */
	virtual t_errno GetGroupAsString( uint iIndex, uint iIndexGroup, char* oProp ) = 0;

    /** �������� iIndexGroup-����� ����. ��������� � iIndex-��������� */
	virtual IKNMorphProperties* GetGroup( uint iIndex, uint iIndexGroup ) = 0;

// ����� ����� �� ���������
    /** ������� ������ ����� ��� ������������ ���������� ����. ��������� � ����� ������ ���������. */
	virtual IKNMorphProperties* CreateGroup() = 0;
    /** � ������ ���� ���-�� �������� ������ �������� �� ������������� ���������.
     *	!!?? ���� ������ ������.
     */
	virtual uint GetIndexByProperties() = 0;
};

#endif
