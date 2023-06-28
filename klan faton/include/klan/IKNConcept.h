// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Usage notes: ���������� �������� ������� ����������� �� �����������.
// ������� type ���������� ��� ������� ������� + ��� ������� ��������� 
//===================================================================
// ������������ :   IKNWord, IKNPhrase, KNConcept
//===================================================================
// ����������   :  
//===================================================================
// Sep 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNConceptH
#define IKNConceptH
//---------------------------------------------------------------------------
//#include "KNMacrosVoc.h"
#include "KNMacros.h"
//#include "IKNTheme.h"
#include "IKNConceptParameterGroup.h"
//---------------------------------------------------------------------------
/** ������� ������ ��� ���� ��������� ������� (����, ���������������) */
class IKNConcept
{
public:
	/** �������� (���������� �����) �������.
	 *    @param oNorm is a name of attribute.
	 */
//	virtual t_errno GetNorm( char* oNorm ) = 0;
	virtual const char* GetNorm( ) = 0;

    /** ���������� ����� �������: CONCEPT_TYPE, WORD_TYPE, PHRASE_TYPE */
	virtual int GetType() const = 0;

    /** ������ �������� ���������/��������� (false/true). */
	virtual bool IsExpert() const = 0;
    /** ������ �������� �������/����-�������� (false/true). */
	virtual bool IsStop() const = 0;
    /** ������ �������� ����������/��������� (false/true). */
	virtual bool IsDelete() const = 0;
    /** ������ ��� �������������/��� ����������� (false/true). */
//	virtual bool IsName() const = 0;
    /** �������� �����������/���� (false/true). */
	virtual bool IsSameExist() const = 0;
    /** ������ �� ���������/��������� (false/true). */
	virtual bool IsEdit() const = 0;
    /** ������ ������/����� (false/true). */
	virtual bool IsNew() const = 0;
    /** ������ ������������/���������� (false/true). */
	virtual bool IsFix() const = 0;
    /** ������ ������������ ��/���. */
	virtual bool IsPrediction() const = 0;

    /** ����� ������ ����������. */
	virtual void SetTypical() = 0;
//-------------------------------------------------------------------
	/** ����� ������������� �������. */
	virtual uint GetCount() const = 0;
	/** ����� ���-�� �������, � ������� ���������� ������. */
	virtual uint GetTextCount() const = 0;
	/** ������� �������. */	                               	
	virtual float GetTF() const = 0;
	/** ��������� ������� �������. ��������� ���-�� ����������, � �������
	 *	���������� ������ � ������ ���-�� ������������ ����������.
	 */
	virtual float GetDF() const = 0;
	/** �������� ��������� ������� �������. **/
	virtual float GetIDF() const = 0;
	virtual float GetTF_IDF() const = 0;
	/** ����� ����������� ������� ������� (������� �� ���� �����). */
	virtual float GetFrequency() const = 0;
//-------------------------------------------------------------------
    /** ���������� ���������� ����� ������������ ����.
     *  @param iExpertNorm - ���������� �����, ���������� � ��������� (%).
     *  @param iTheme_id - ������ ����
     *  @param iThemeName - ��� ����
     */
	virtual t_errno SetExpertNorm( char* iThemeName, int iExpertNorm ) = 0;
	virtual t_errno SetExpertNormById( uint iTheme_id, int iExpertNorm ) = 0;

	/** �������� ��������. */
	virtual IKNConceptParameter* AddParameter( IKNTheme* iT, int iExpertNorm = 1 ) = 0;
//	virtual IKNConceptParameter* AddParameter( uint iTheme_id, int iExpertNorm = 1 ) = 0;
	
	/** ������� ���������� �� ����, �� �� �����. */
	virtual void DeleteThemeStatistic( char* iThemeName ) = 0;
	/** ������� ���������� �� ����, �� �� �������. */
	virtual void DeleteThemeStatisticById( uint iTheme_id ) = 0;

	/** ������� ���������� �� ���� � �������� iid. */
//	virtual void DeleteT( unsigned iid ) = 0;
	/** �������� ����-������ ������� (�� ���������������). */
	virtual t_errno Transfer() = 0;
//-------------------------------------------------------------------

	/** ���������� �������� �� ����������� �� ������.
	 *	@return ���-�� ���, � ������� ���������� ������ (���-�� ���������).
	 */
	virtual uint InitStatistic() const = 0;

	/** ����� �������� ������� � ��� ����������.
	 *	���������� ������������ ������� InitStatistic(),
	 *	������� ��������� �������� �� ������ ������ ��������� ������� �������.
	 *
	 *    @param oTheme_id is a index of theme.
	 *    @param oCount is a count of term in theme.
	 *    @param oTextCount is a count of text of theme.
	 *    @param oExpertNorm is a expert norm.
	 */
	 /// {
//	virtual t_errno GetStatistic( uint* oTheme_id, uint* oCount,
//				uint* oTextCount, int* oExpertNorm ) = 0;
	virtual IKNConceptParameter* GetStatistic() const = 0;
	/** ���������� ������������� �������� ��������� ��� ������� �������.
	 *	@note �� ����������� ��� ������������ ���������� THEME_TYPE_STAT � THEME_TYPE_STAT_HEAD
	 */
	virtual void SetParameterValue(IKNConceptParameter* iPar, const char* iVal) = 0;

	/** ������� ����� ������. */
	virtual IKNConceptParameterGroup* CreateGroup(IKNConceptParameter* iElem) = 0;
	/** ����� ���������� �����. */
	virtual uint GetCountGroup() const = 0;
	/** ����� ������ �� �������. */
	virtual IKNConceptParameterGroup* GetGroup(uint i) = 0;
	/** ������� ������. */
	virtual void DeleteGroup(uint i) = 0;
	/** ��������, ������ �� ������� � �����-���� ������. 
	 *	@note ������� ����� ������� � ��������� �����
	 *	@note ������ ����� �������� �� ������ �������� 
	 *		  (����������, ����� ���� ��� ������ ���������� ���� ������� � �����-���� ������)
	 */
	virtual bool InGroup(IKNConceptParameter* iElem) const = 0;

	
	virtual t_errno GetShortStatistic( uint* oTheme_id ) const = 0;
	/** ����� �������������� ���������� ������� �� ������ ���������.
	 *	���������� ������������ ������� InitStatistic().
	 *    @param oDirectNorm ��� ������� � ����.
	 *    @param oRelativeNorm ������������� ������� ������� � ����.
	 */
//	virtual t_errno GetFullStatistic( char* oThemeName, uint* oCount, uint* oTextCount,
//				int* oExpertNorm, float* oDirectNorm, float* oRelativeNorm ) = 0;
	virtual IKNConceptParameter* GetFullStatistic( float* oDirectNorm, float* oRelativeNorm ) const = 0;
	 /// }
	
	/** ����� ���������� �� ����.
	 *	����� ����� ��������� ��������� ���������� (����� ���� ��� ���� �������)
	 *	������� ����� GetStatistic, GetFullStatistic ��� GetTStatistic
	 *    @param oTheme_id is a index of theme.
	 *    @param oExpertNorm is a expert norm.
	 */
	 /// {
//	virtual bool FindTStatistic( uint iTheme_id ) = 0;
	virtual IKNConceptParameter* FindTStatistic( uint iTheme_id ) const = 0;
//	virtual bool FindThemeStatistic( char* oThemeName ) = 0;
	virtual IKNConceptParameter* FindThemeStatistic( char* iThemeName ) const = 0;
//	virtual t_errno GetTStatistic( IKNTheme* iTheme, uint* oCount, uint* oTextCount,
//				int* oExpertNorm, float* oDirectNorm, float* oRelativeNorm ) = 0;
	virtual IKNConceptParameter* GetTStatistic( IKNTheme* iTheme, float* oDirectNorm, float* oRelativeNorm ) const = 0;
	/// }

	/// { ��������� ������� ���� ��� �� �����������/��������� � �������
	/** ����� ���������� �� ������� ����. ������� ����������� ���� � �������� iTheme_id. */
	virtual bool FindTStatChild( uint iTheme_id ) const = 0;
	/** ����� ���������� �� ������� ����. ������� ��������� ���� � �������� iTheme_id. */
	virtual bool FindTStatParent( uint iTheme_id ) const = 0;
	 /// }

	/** ������� ���������� ��������. */
	virtual void ClearStatisticClassify() =0;

	/**
	 * Get count of addition statistics of active concept
	 * @return count of plus statistics
	 * 		- 1 if error
	 */
//	virtual int GetCountPlusStatistics(); //FindActiveThemesPlus

	/**
	 * Get addition concept statistics, corresponding i-theme
	 * @return code of error
	 */
/*	virtual int GetPlusStatistics( unsigned iThemeIndex, char* oThemeName,
                    int* oCountTextsWithWord, int* oCountWordsInTheme,
                    int* oExpertNorm, float* oDirectNorm, float* oRelativeNorm );
//*/
//-------------------------------------------------------------------
};

#endif
