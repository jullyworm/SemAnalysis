// Copyright (c) 2014 by IIS. All rights reserved.
//===================================================================
// Usage notes: ����� ������������ - �������������� ������ ����������
//    -  ������� �������� ��� ����
//    -  ������� ����������� ��� ��
//    -  ���������� ������

// �� �������: ������� ��������� ����������
//	- ���������� ������� ����������� ��� �������� ������
//	- ���������� ���������� �������
//	- ������������� ������ (������������): ��������� ���������
//	- ����� ����-�������� ?? (�� �����, �.�. ������ �� � �������, � �������)
//	- ����� ��������������� �������� �� ������
//	- ����������� ���������� ���������� ������ ??
//===================================================================
// ������������ : 
//===================================================================
// ����������   :  KNResultList.h
//===================================================================
// May 2014                  Created               L. Sidorova, IIS
//===================================================================
#ifndef IKNEngineStatisticH
#define IKNEngineStatisticH
//-------------------------------------------------------------------
//#include "IKNResultList.h"
//#include "IKNTheme.h"
//-------------------------------------------------------------------
const int UNIVERSAL_WEIGHT = 5;
const uint UNIVERSAL_TOPIC = 1000; // !!! ������ �������������� ������

typedef byte_t t_metod; /**< Metod classification index */
const t_metod UNI_METOD = 0;

//-------------------------------------------------------------------
class IKNTheme;
class IKNResultList;

/** �������������� ���������� ������. */
class IKNEngineStatistic
{
public: // ���������� ������ ������������� ��� ����� �����.
//	virtual void ClearTopics() = 0;
	/** ���������� ������������� �����.
	 *	@note ������������ ����� �� ����������� ��� ������� � �� ������������ 
	 *		  � �������� ����������, ���� ������ ������� �� �������.
	 */
	virtual void SetUniversalTopic( IKNTheme* universal_topic ) = 0;
//	virtual bool IsUniversal( IKNConcept* ) = 0;
	/** ��������� ������ ��� ������ � ������������� �� �������������. */
	virtual uint CalculateTopics( IKNTheme* universal_topic, IKNResultList* res_list ) = 0;

	/** �������� ���-�� ����������� � ������ @see CalculateTopics �������. */
	virtual uint GetTopicCount() const = 0;
	/** �������� ����� � ������ ��� �������������. */
	virtual IKNTheme* GetTopic( uint id, float* oRel, float* oNorm_rel ) const = 0;
public:
	/** ������ ���� �������� �� ���� �������. 
	 *	@note � �������� ������� ����� ����������� ��������� ���������������, � ����� ������ ��
	 *		  ����������� � ��������� (�, ��������, ������������� ��������).
	 *	@note ��� ������� ����������� ���� ������� �� ����� � ��������� � ����.
	 *	@iMetod ������ ������ �������������.
	 *	@iParent ������� ��������������. ���� �������� ����� 0, �� ������������ ��� ��������.
	 */
	virtual void CalculateWeight( t_method_type iMetod, IKNTheme* iParent ) = 0;
	virtual void CalculateWeight( t_method_type iMetod ) = 0;
	virtual void CalculateWeight( const char* iMetodName, IKNTheme* iParent ) = 0;
	virtual void CalculateWeight( const char* iMetodName ) = 0;
};
// --------------------------------------------------------
#endif