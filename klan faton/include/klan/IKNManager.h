// Copyright (c) 2010 by IIS. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, IIS
//===================================================================
#ifndef IKNManagerH
#define IKNManagerH
//---------------------------------------------------------------------------
#include "IKNWordVoc.h"
#include "IKNPhraseVoc.h"
#include "IKNMorphTable.h"
#include "IKNThemeList.h"
#include "IKNResultList.h"
#include "IKNTextIndex.h"
#include "IKNEngine.h"
#include "IKNSynRelation.h"
//---------------------------------------------------------------------------
/**
 * @mainpage
 * <HR>
 * @section intro ����� ����������� � ������� API
 * - ��� �������� ���������� ��� ������ API, ������������ ��� ������.
 * - ��� ���������� ���������� ��� ������ API, ������������ ���������, ���������� 0.
 * - ��� ������� ���������� � ����.
 * - ����������� API ������ ������ delete.
 * - ������� ��������� IKNManager ��������� ������� Release(), ��������� ���������� �� ���������.
 */

/** 
 * @interface IKNManager
 * �������� ������ �������� �������������� ������� API.
 * ��������� � ������� ������������ ���������� ������� DLL-���������� GenerateAPIManager().
 */
class IKNManager {
public:
	/** UnInitialize. Close Vocabulary. */
	virtual void Release() = 0;

	/** ������� ����� ������.
	 *	@note �� ��������� ��������� ������ ��������
	 */
	virtual t_errno Create( bool is_themes_create = false ) = 0;
    /** ������� ��������, ������ � ��. */
	virtual t_errno Clear() = 0;
    /** ������� del-��������. */
	virtual void ClearDel() = 0;

	/** ���������� ���� � ��� ����� �������. */
	virtual t_errno SetPath(const char* iFileName) = 0;
	/** Load Vocabulary. */
	virtual t_errno Load() = 0;
	/** Save Vocabulary. */
	virtual t_errno Save() = 0;
	/** ����������� ��������.
	 * @note ���� ���������������� �� ��������, ����� �����������.
	 * 		 ��������������� ������� ������ ��������� (������ �� ��������)
	 *		 ��� ���� �� ���������������.
	 */
	virtual t_errno JoinVoc(const char* iFile/*, byte_t iMode*/) = 0;

	/** Save Vocabulary as Text. */
	virtual t_errno SaveAsText(const char* iFileName) = 0;
	/** Load Vocabulary from Text.
	 * @note format as function SaveAsText.
	 * @note ��������� �������� ���� �� �������� ������� �� ���������� ����� (��������, del �����)
	 */
	virtual t_errno LoadFromText(const char* iFileName) = 0;

	/** Save morphology table and morph rules for Lemmatizer. */
// � IKNMorphTable (����� ����� �����������).
	virtual t_errno SaveMorphTables(const char* iMorphFile, const char* iRulesFile) = 0;

	/**
	 * C��������� �������� ��� � ����, ��������� �������������.
	 * @note ��������� ���������� �� �������.
	 * @param iName - ��� ����� (����������� ������ ������������)
	 */
	virtual t_errno SaveThemes( const char* iFileName ) const = 0;

	/**
	 * �������� �������� ��� �� ����� � ������ ������� �������� �������.
	 * @note �������������� �������� ������������� ����� ��������
	 * 		 �� �������� � ��������� ������������� ������ iMode.
	 * 		 ��� ��������������� �������� ��� ��������� ������.
	 *
	 * @param iName - ��� ����� (����������� ������ ������������)
	 * @param iMode - ����� ������ ��������
	 *		iMode = false - ���� ���������������� �� id + ��������
	 *		iMode = true - ���� ���������������� �� id, �������� ����������
	 */
	virtual t_errno LoadThemes(const char* iFileName, bool iMode) = 0;

	/**
	 * Check Vocabulary empty
	 * @return true - if vocabulary empty / false - else
	 */
	virtual bool IsEmpty() const = 0;

//===================================================================
	/** �������� ������ � �������.
	 *	@param voc_type - ��� �������
	 */
//    virtual IConceptVec* GetConceptVoc( int voc_type ) const = 0;
	/** �������� ������ � ������� ���� �� ��� ����.
	 *	@param voc_type - ��� �������
	 */
	virtual IKNWordVoc* GetWordVoc( int voc_type ) const = 0;
	/** �������� ������ � ������� ��������������� (��) �� ��� ����.
	 *	@param voc_type - ��� �������
	 */
	virtual IKNPhraseVoc* GetPhraseVoc( int voc_type ) const = 0;

	/// get synonymy relation between vocabulary terms
	virtual IKNSynRelation* GetSynonymy(void) = 0;


	/** �������� ������ � ������� ��������������� �������. */
	virtual IKNMorphTable* GetMorphTable()  const = 0;

	/** �������� ������ � �������� ���. */
	virtual IKNThemeList* GetThemesTable() const = 0;

	/** �������� ������ � ������ �������� � �������������. */
	virtual IKNEngine* GetEngine()  const = 0;

//===================================================================
//*********************** SPESHIAL FUNCTIONS ************************
//===================================================================
	/** ��������� ������� ���� �����/����������� ��������� �������� �� �������. */
	virtual void ClearNews() = 0;

//!! ��������� � StatisticEngine
	/** ��������� �������������� �������� �� ������������. */
	virtual void TransformCategoryTerms() = 0;

//!! ��������� � StatisticEngine
	/** ������� ���������� ��������. */
	virtual void ClearStatisticClassify() =0;
	
	/** ������������� ������ ��, ���������� ����� w. */
	virtual IKNPhrase* InitRelation( IKNWord* w ) = 0;
	/** ������ ���������� �������� �� ������ ��. */
	virtual IKNPhrase* GetRelation() = 0;

// !!������!!
//===================================================================
//************************* VALUES TABLE ****************************
//===================================================================
	/** Get Rules count	 */
	virtual uint GetRulesCount() const = 0; 

	/** Get rule name. ������������ ����� ������ NAME_LENGTH. */
	virtual t_errno GetRule(unsigned iIndex, char* oRule) const = 0; 
	virtual const char* GetRule(unsigned iIndex) const = 0; 

	/** Get Part of Speech count */
	virtual uint GetPSCount() const = 0; 

	/** Get Part of Speech. ������������ ����� ������ PART_SPEECH_LENGTH. */
	virtual t_errno GetPS(unsigned iIndex, char* oPS) const = 0; 
	virtual const char* GetPS(unsigned iIndex) const = 0; 

};
//---------------------------------------------------------------------------
#endif

