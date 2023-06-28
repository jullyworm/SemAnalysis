// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNEngineH
#define IKNEngineH
//-------------------------------------------------------------------
#include "KNMacros.h"
#include "IKNTextIndex.h"
#include "IKNResultList.h"
#include "IKNParsedText.h"
//-------------------------------------------------------------------
class IKNEngineStatistic;
/**
 * @interface IKNEngine
 * ����������� ������ ��������� � �������������� �������.
 *
 * @note ������ ��� ������ ��������������� � �������� �������������
 * a. ������ � WordFinder dll
 * b. �������������� ���������� ������� �� ������
 * c. �������������� ������������� ������
 * d. ����� ����-�������� � ����-���������������
 * 
 * ��������� WFEngine (WF_C.dll):
 *		- ������������ (��/���)
 *		- ����� ����������� ������� (��/���, ���� �� �������)
 *		- ������ �� (��/���)
 *
 * ��������� TomatEngine (TomatAPI.dll):
 *		- ������ �� (��/���)
 *		- ���� �� ����� �������� (����� �������)
 *		- ��� ���������� �����
 *		- ��� ����������������� �������
 *
 * ����� ��������� ������:
 *	0 - ���������� ������� + ������� ����������
 *	1 - ���������� �������
 *	2 - ���������� ����������
 *	3 -	��������������� ������
 *	4 -	������������� 
 *	5 -	������������� + ������� ���������� � �������
 *
 * ��� �������� (������� ���������� �� �����) ���������� �������������� 
 * ���������� �������� ���� IKNThemeList::SetTextTheme (AddTextTheme)
 *
 * ��� ������������� ����� ���������� ��������� ��������������:
 *      - ����� ������������� (����������� ������� ��� ��������� � ����)
 *      - ����� ������������� (����������� ������� ��� ��������� � ����)
 *
 * �� ��������� ��� ��������� ������ � KNMacros.h
 */
class IKNEngine
{
public:
	virtual IKNParsedText* GetParsedText() const = 0;
	virtual IKNEngineStatistic* GetEngineStatistic() = 0;

	/**
	 * Run morpho-analyze of text.
     * @note ����� ������ ���������� ��������� TEXT_LENGTH.
	 * @param len - ������������ ��������, ��������� ����� ������������� ������
	 *		  len = 0 - ��������� ���� ����� 
	 * @param  iMode - mode of text analisys
	 *		   iMode = 0 - learning (add new termins to vocabulary)
	 *		   iMode = 1 - learning without statistic (add new termins to vocabulary)
	 *		   iMode = 2 - relearning with statistic (only termin in vocabulary)
	 *		   iMode = 3 - morphological analysis
	 *		   iMode = 4 - classificaion text
	 *		   iMode = 5 - classificaion with statistic update (only termin in vocabulary)
	 *		   iMode = 6 - classification by expert rule (topic find)
	 *		   iMode = 7 - statistic analysis
	 */
	virtual t_errno Run( char* text, int iMode, uint* len  ) = 0;

	/** ����� ���������� ������������ ������� (���������� � ������ ���������� ����������). */
	virtual uint GetTextCount() const = 0;
	/** ����� ���������� ��������� �� ���� ������������ ������� (���������� � ������ ���������� ����������). */
	virtual uint GetAllWordCount(bool with_omonims = false) const = 0;
	
	/**
	 * Find and transfer all stop concept.
	 * ����� ����-�������� � ������� � ����-�������.
     * @note ��������: ���� ������ �� ����������� �� ���� ����� � ��� �������,
     * 		 �������������� ������������� �������� ������ - 1, �� ��� ����-������.
     * 		 ������� ����������������� ������ PROXIMITY, ��� ������ ������ � ��������� 
     * 		 �������� (1/PROXIMITY, PROXIMITY).
     * �����������:
     * 		- ���� ������ ���� ���������� ��������� - THEME_THRESHOLD
     * 		- ������������� ������� � ������� - �� ����� TERM_THRESHOLD
     * !! �������� �� ������ ������ �������, �.�. �� ����������� �������� ��� !!
     * !! ��� ��-�� ����� ������ ����������� !!
	 * @return count of new stop concept
	 *   -1 -- if error
	 */
	virtual int FindStopConcepts() = 0;

	/** �������� ������ � ������� ����������. */
	virtual IKNTextIndex* GetTextIndex() const = 0;

	/** �������� ������ � ������ ���������� � ���������� ������� ��������. */
	virtual IKNResultList* GetResultList() const = 0;

	virtual void Clear() = 0;	/**< ������� ����������� ���������� ������. */
//	virtual void Close() = 0;	/**< ��������� �������������� ������ (� ������� ��� engine). */

	/** ���������� ������ ��� �������������.
	 * @param   iNecessity - threshold of Necessity
	 * @param   iSufficiency - threshold of sufficiency
	 */
	virtual void SetThreshold(unsigned iNecessity, unsigned iSufficiency) = 0;
	/** ���������� ������ ��� ������ ����-��������. */
	virtual void SetStopThreshold( float iMin, float iMax ) = 0;

	/** ���������� ��������� ������ ������ �� WF (WF_C.dll)
	 * @param isPredict - ������������ ������������ (��/���)
	 * @param isWFPhrase - ������������ ������ �� ������� WF (��/���)
	 * @param iVocPath - ���� �� ������� �����
	 *		  iVocPath=0 - ���� ����� �� ���������
	 */
	virtual void SetWFParametrs(bool isPredict, bool isWFPhrase, char* iVocPath = 0) = 0;

	/** �������� ����� �� ����� � ������ � ���������� � ������� �������.
	  * �������������� ��������������� ����� � ��������.
      *		- ���� ����� ������� � del �������, ��� ����������� � �������.
	  * ������������ ��������� ����������� (������������).
	  * @return ����� ��� ��������� �����.
	  */
	virtual IKNWord* CreateWord( char* iNorm, byte_t iMorh ) = 0;
	/** �������� ����� �� �������� (� ���� ��������).
	  * �������������� ��������������� ����� � ��������, ��� ����
      *	���������, ��� ���� ������ ���� �� ������, �� ��������� ��� ������������.
	  * ������������ ��������� ����������� (������������).
	  * @return ������ ����� (��������� ����� �����).
	  */
	virtual IKNWord* CreateWords( char* iNorm ) = 0;
	/**
	 * ������������ �������� ��-� �� ���������� ������������� �������.
	 * @param p - �� � �������� ���������� ������
	 * @param part_count - ���-�� ������������ 
	 * @param text - ������ � ���������� ����� (����������� - ������)
	 * @return ���������� �������������� �� (0 - ���� �� ������� ������� ��)
	 */
	virtual int CreatePhraseParts( IKNPhrase* p, unsigned part_count, char* text ) = 0;

	/** �������������� ����������� �������� ������ ��� ����������� �����������.
	 * @param is_bit_para = true ����� ����������� 1 ��������
	 * 		  is_bit_para = false ����� ����������� 2 ���������
	 */
	virtual void ConvertTextType( bool is_bit_para ) = 0;

	/* �� ��������� ������� �������� ������ � ������ �������(�������� �����). */
//	uint GetPositionIndex( uint text_pos) const;
	/* �� ������� �������� ��������� ������� (�� ������ � ����� ���.�������� � ������). */
//	uint GetTextIndex( uint id_pos, uint* oEndText ) const;
};
// --------------------------------------------------------
#endif
