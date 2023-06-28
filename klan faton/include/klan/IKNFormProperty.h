// Copyright (c) 2010 by IIS. All rights reserved.
//===================================================================
// Usage notes: �������� ����� �����.
//===================================================================
// ������������ :   IKNParadigm
//===================================================================
// Dec 2010                  Created               L. Sidorova, IIS
//===================================================================
#ifndef IKNFormPropertyH
#define IKNFormPropertyH
//---------------------------------------------------------------------------
#include "KNMacros.h"
//#include "KNMacrosType.h"
#include "IKNMorphProperties.h"
//---------------------------------------------------------------------------
/** � ��������� ����� ����� ���������: ���������, ��������� 
 *	����������� ������ ����.��������� �����.
 */
class IKNFormProperty
{
public:
    /** �������� ���������. */
	virtual const char * GetFlex() const = 0;
    /** �������� ���������. */
	virtual const char *  GetPrefix() const = 0;
    /** ��������� ������� ���������. */
	virtual bool IsPrefix() const = 0;

// ������ � ����������
    /** �������� ���������� ������� ����. ��������� �����. */
	virtual uint GetGroupCount() = 0;
    /** �������� ����� ����. ��������� � �������� iIndexGroup, ���������������
     *	���������� � ���������� iIndex � ���� ������ (����� PHRASE_LENGTH).
     */
	virtual t_errno GetGroupAsString( uint iIndexGroup, char* oProp ) = 0;
//	virtual t_errno GetAsString( char* oProp ) = 0;

    /** �������� iIndexGroup-����� ����. ��������� � iIndex-��������� */
	virtual IKNMorphProperties* GetGroup( uint iIndexGroup ) = 0;
};

#endif
