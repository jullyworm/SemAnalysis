// Copyright (c) 2017 by IIS. All rights reserved.
//===================================================================
// Usage notes: ������ ���������� �������.
//				������������ ��� ������� ���������� (vs. ������������) 
//				���������� ��� �������� ������� ��������� �������
//===================================================================
// ������������ :   IKNWord, IKNPhrase, KNConcept
//===================================================================
// ����������   :  
//===================================================================
// March 2017                  Created               L. Sidorova, IIS
//===================================================================
#ifndef IKNConceptParameterGroupH
#define IKNConceptParameterGroupH
//---------------------------------------------------------------------------
//#include "KNMacrosVoc.h"
#include "IKNConceptParameter.h"
//---------------------------------------------------------------------------
/** ������ ���������� �������. */
class IKNConceptParameterGroup //IKNConceptParameter
{
public:
	/** ����� ���-�� ��������� � ������. */
	virtual uint GetCount() const = 0;
	/** ����� ������������ ������������ ������. */
//	virtual IKNConceptParameterGroup* GetParentGroup() const = 0;
	/** ���������� ������������ ������. */
//	virtual void SetParentGroup(IKNConceptParameterGroup* iParent) = 0;

	/** ����� ������� ������ �� �������. */
	virtual IKNConceptParameter* GetParameter(uint) const = 0;

	/** ����� ���������. */
	virtual IKNConceptParameter* FindParameter(IKNTheme* iTh) const =0;
	/** ����� ���������. */
	virtual IKNConceptParameter* FindParameter(uint iTh_id) const =0;
	/** �������� ������� �������� � ������. */
	virtual bool IsElement(IKNConceptParameter* iPar) const =0;

	
	/** �������� ������� � ������. 
	 *	@return ���� ������� ��� ���������� ��� 0, �� OPERATION_ERROR
	 */
	virtual t_errno AddParameter(IKNConceptParameter*) = 0;	
	/** ������� ������� ������ �� �������. 
	 *	@note ������� ����������� �� ������, �� �� ���������.
	 */
	virtual void DeleteParameter(uint) = 0;
};

#endif
