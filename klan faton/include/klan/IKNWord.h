// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Usage notes: ���������� �������� ������� ����������� �� �����������.
// ������� type ���������� ��� ������� ������� + ��� ������� ��������� 
//===================================================================
//===================================================================
// ����������   :   IKNParadigm
//===================================================================
// Sep 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNWordH
#define IKNWordH
//---------------------------------------------------------------------------
#include "IKNConcept.h"
#include "IKNParadigm.h"
#include "KNMacros.h"
#include "IKNParadigmUpdater.h"
//#include "KNMacrosType.h"
//---------------------------------------------------------------------------
/**
 * @interface IKNWord
 * ������ ������� ���� �����. ����� ����� ��������������� ��������� �
 * ��������� - ������ ��������� �����.
 */
class IKNWord : virtual public IKNConcept
{
public:
	/** �������� ������ �����. */
	virtual t_errno GetStem( char* oStem ) const = 0;
	/** �������� ������������� ���������������� ������ �����. */
	virtual byte_t GetMorph() const = 0;
	/** �������� ����� ����.
	 *	@note � ������ ������������ ����������� ���� *
	 */
	virtual t_errno GetPartSpeech( char* oPart ) const = 0;
	/** �������� ������ ����� ���� (��� ����� ������������). */
	virtual const char* GetPartSpeech() const = 0;
	/** �������� ������ ����. ��������� ������� � ���� ������ (����� PHRASE_LENGTH). */
	virtual t_errno GetLex( char* oProp ) const = 0;
	/** ������ ���������� ����������� ���������� �����. */
	virtual unsigned GetLexCount() const = 0;
	/** ������ ����������� ���������� ����� ��-���������.
	 *	@param oAttrName - ��� ���������
	 *	@param oAttrValue - �������� ���������
	 */
	virtual t_errno GetLexElement( unsigned iIndex, char* oAttrName, char* oAttrValue ) const = 0;
	/** �������� ����������� �������.
	 *	@param oValNum - ����� �������� ���������������� ��������
     *	@return ��������������� ������� (�� ��������������� �������) 
	 */
	virtual IKNMorphAttribute* GetAttr( unsigned iIndex, unsigned* oValNum ) const = 0;
	
	/** �������� ��������� �� ��������� �����. */
	virtual IKNParadigm* GetParadigm() const = 0;
//-------------------------------------------------------------------
	/** ����� �����, ���������� ���������� � ����� ����� (�����������).
	 *	@note this - ������� �����, iAddWord - ��������������, ���������.
	 *	@note this->IsDel = true, �� �������� �� ����������, iAddWord ���������
	 *	@note this->IsStop = true, �� ���������� � ����� ������������, iAddWord ���������
	 *	@note ���������� ������� �� ������ ���������� �� ����������� ������ 1
	 */
	virtual t_errno MixWords(IKNWord* iAddWord, bool is_paradigm = false) = 0;
	/** ��������/�������������� ��������� �����.
	 *	@note ��������� ����� ��������� (� ����� ������������ �������� ������),
	 *		����� ������� UpdateParadigm ������ ��������� ���������, � ����� ��������
	 *	@note ����� CreateParadigm ������� ������ ���������, ModifyParadigm �������� ������
	 */
	virtual IKNParadigmUpdater* CreateParadigm() const = 0;
	virtual IKNParadigmUpdater* ModifyParadigm() const = 0;
	virtual t_errno UpdateParadigm( IKNParadigmUpdater* ) = 0;

	/**
	 * Edit word.
	 */
//	virtual int KNEditNorm( char* iNormForm );
//	virtual int KNEditWordBase( char* iBase );
//	virtual int KNEditMorphType( char iType );
	
};
//-------------------------------------------------------------------
#endif
