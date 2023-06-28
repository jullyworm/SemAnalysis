// Copyright (c) 2005 by IIS. All rights reserved.
//===================================================================
// Usage notes: ������ ������������� �����, �������� � ��������.
//===================================================================
// july 2009                  Edited                L. Sidorova, IIS
//===================================================================
#ifndef KNMacrosH
#define KNMacrosH

#include <cstdio>
//#include "KNMacrosType.h"
//---------------------------------------------------------------------------
typedef unsigned char 	byte_t;
typedef unsigned int   	uint;
typedef byte_t t_errno; /**< error code */
typedef byte_t t_visible_type; /**< ��� ��������� �������. */
typedef byte_t t_covering_type; /**< ��� ������� �������� ������ ��������. */
typedef byte_t t_theme_type; /**< ��� ����: ����, ��� � �.�. */
typedef byte_t t_method_type; /**< ��� ������ */
//-------------------------------------------------------------------
/** ����� ��������� ����������. */
#define PATH_LENGTH         127
#define NAME_LENGTH         63
#define WORD_LENGTH         63
#define RULE_LENGTH			63
#define PHRASE_LENGTH       127
#define DESC_LENGTH  		1023
#define TEXT_LENGTH  		50000

const t_errno NO_ERRORS				= 0;
const t_errno ERRORS				= 1; /**< �� ����������������� ������. */
const t_errno INIT_ERROR			= 2;
const t_errno OPEN_FILE_ERROR		= 3;
const t_errno LOAD_FILE_ERROR		= 4;

const t_errno TYPE_NOT_CORRECT		= 5;
const t_errno OUT_OF_BOUND			= 6;
const t_errno STRING_LENGTH_ERROR	= 7;  /**< �� ������������� ����� ������ . */

const t_errno OPERATION_ERROR		= 8;
const t_errno FIND_OBJECT_ERROR		= 9;
const t_errno STRING_ERROR			= 10;


const t_errno VOC_IS_EMPTY          = 20;
const t_errno WORD_FINDER_ERROR		= 21;
const t_errno NOT_ACTIVE_OBJECT_ERROR = 22;

const t_errno OPEN_TABLES_ERROR		= 23;
const t_errno LOAD_THEMES_ERROR		= 24;
const t_errno LOAD_MORPH_ERROR		= 25;

const t_errno ACTIVATION_ERROR		= 26;

//const t_errno ACTIVATION_ERROR		= 27;


//typedef byte_t t_visible_type; /**< ��� ��������� �������. */

 /** ����������, ������������ ������ � ������� ������ �������� (������ �������). */
const t_visible_type VISIBLE_NON	= 0;
 /** �������������� ��������, ���� �� ������ ������ �������� (�����, ���� �� ������). */
const t_visible_type VISIBLE_OWN	= 1;
 /** ��������� ��������, ���������� �� �������� ������� ��������� (������ �����). */
const t_visible_type VISIBLE_ABS	= 2;

//typedef byte_t t_covering_type; /**< ��� ������� �������� ������ ��������. */

 /** ��������� ��������� ������ ������� (�������� ������� ������, ���� ��� �� VISIBLE_NON). */
const t_covering_type COVERING_NO	= 0;
 /** ������������� ��������� ������ ������� (�������� ������� ��������, ���� ��� �� VISIBLE_ABS). */
const t_covering_type COVERING_YES	= 1;
 /** ������������ ������ ��� �������� � ����������� 
  *  (��������� ���������, ����������� ��������� � �������������� �������). 
  */
const t_covering_type COVERING_PRIOR = 2;
 /** ������������� ��������� ������ ������� (��� �������� ������� �������� ������� VISIBLE_ABS). */
const t_covering_type COVERING_FULL	= 3;

//---------------------------------------------------------------------------
/** ��������� ������� ��� KNConcept (KNWord,KNPhrase). */
#define EXIST_MODE 		0  
#define STOP_MODE		1  
#define FIX_MODE		2  
#define EXPERT_MODE 	3  
#define DEL_MODE 		4
#define EDIT_MODE 		5  
#define NEW_MODE 		6  
#define PRED_MODE 		7  
//---------------------------------------------------------------------------
#define CONCEPT_TYPE        0
#define WORD_TYPE	        1
#define PHRASE_TYPE         2

/** ������� - ��� �� ���������� (������, ������ ���� �� ������). */
const t_theme_type THEME_TYPE_BASE			= 0;
/** ������� - ���� ��� �������������. */
const t_theme_type THEME_TYPE_STAT			= 1;
/** ������� - ����-������� �������������� (���� ��������� ��������������). */
const t_theme_type THEME_TYPE_STAT_HEAD		= 2;
/** ������� - ������� (��� ��������). */
const t_theme_type THEME_TYPE_ATTR			= 3;
/** ������� - �������� �������� (��� �������� ������� ���� �� ��������). */
const t_theme_type THEME_TYPE_ATTR_VAL		= 4;
/** ������� - ������������� �����. */
const t_theme_type THEME_TYPE_SEM			= 5;
/** ������� - ������� �� ���������, ���������� ��� ���������� �����. */
const t_theme_type THEME_TYPE_ATTR_INTVAL 	= 6;
/** ������� - ��� ������ ��������� (��������������� ��������). */
const t_theme_type THEME_TYPE_SIN 			= 7;


const t_method_type METHOD_CLASS_BASE = 0;
const t_method_type METHOD_CLASS_PARAL1 = 1;
const t_method_type METHOD_CLASS_PARAL2 = 2;
const t_method_type METHOD_CLASS_PARAL3 = 3;
const t_method_type METHOD_CLASS_PARAL_BASE = 4;

/** ����� ��������� ����������. */
#define PART_SPEECH_LENGTH  31
//-------------------------------------------------------------------
/** ��� ��������� �������. */
#define WORD_VOC        	1
#define STOP_WORD_VOC   	2

#define PHRASE_VOC      	3
#define STOP_PHRASE_VOC 	4

#define CONCEPT_VOC      	6
#define STOP_CONCEPT_VOC 	7

#define DEL_WORD_VOC	 	0
#define DEL_PHRASE_VOC      5
//-------------------------------------------------------------------
/** ������� ������ �������. */
#define TYPE_ORDINARY   0
#define TYPE_RENEWED    1
#define TYPE_NEW        2

/** ������ ��������� ������. */
#define FULL_UPDATE 			0
#define VOC_UPDATE				1
#define STATISTIC_UPDATE		2
#define MORPH_ANALISYS			3
#define CLASSIFICATION			4
#define CLASSIFICATION_UPDATE	5
#define STATISTIC_ANALISYS		7

#define WORK_ANALISYS			6
//#define WORK_STATISTIC			7
//#define WORK_CLASSIFICATION		8
//-------------------------------------------------------------------
/** �������������� ���-�� ������. */
/** ��� �������� */
#define COUNT_ALL	 			-1
/** ��� ����� (� ���������) */
#define COUNT_WORDS	 			0
/** ����� �� ������� �������� ���� */
#define COUNT_WORDS_TERMIN		1
/** ����� �� ����-������� */
#define COUNT_WORDS_STOP		2
/** ����� ����� */
#define COUNT_WORDS_NEW			10
/** ���-�� ��������������� ���� */
#define COUNT_WORDS_UNIC		6
/** ��� �� (� ���������) */
#define COUNT_PHRASES 			3
/** �� �� ������� �������� �� */
#define COUNT_PHRASES_TERMIN	4
/** �� �� ����-������� */
#define COUNT_PHRASES_STOP		5
/** ����� �� */
#define COUNT_PHRASES_NEW		11
/** ���-�� ��������������� �� */
#define COUNT_PHRASES_UNIC		7
//-------------------------------------------------------------------
/** ������ �������� �������� ���. */
// ���� ���������������� �� id + ��������
#define ID_NAME_MODE    false
// ���� ���������������� �� id, �������� ����������
#define ID_MODE         true
// ���� ���������������� �� �������, id ����������
//#define NAME_MODE     2
//-------------------------------------------------------------------
//�������� ����/�������� �� ���������
#define DEFULT_THEME "���������������"
//�������� ������� ������ �� �� ���������
#define EXPERT_RULE "�������"
//�������� ����� ���� ��� ������������ �������������� ������
#define UN_TYPE_NAME "Unknown"
//const char* UN_TYPE_NAME = "Unknown";
//const char UN_TYPE = '-';
//������ ��� ������������ �������������� ������
#define UN_TYPE '-'


//���-�� ������ ����� ������� ��� �������������� ���������� ����� � �������
#define PARAMETR_LENGTH_ROUND 3
//���-�� ��������, ������������ �������� ������������ ������� �������
#define PARAMETR_FREQUENCY 100000
//������������ ���-�� ���
#define MAX_COUNT_OF_THEME 500000
// ������� ���-�� ���
#define DEFOLTE_COUNT_OF_THEME 11
// ���� ��������
#define PROXIMITY 2
// ����� (����������� ��������) ������������� ������� � �������
#define TERM_THRESHOLD 30
// ����� (����������� ��������) �������� � ������� �� ����
#define THEME_THRESHOLD 200
// ������������ ���-�� ��������� � ���������
#define MAX_PARADIGM_COUNT 200

/** ��������� ��� ������������� */
/** ����� ������������� */
#define NECESSITY_THRESHOLD 2
/** ����� ������������� */
#define SUFFICIENCY_THRESHOLD 5

/** ��������� ��� WF. */
#define WF_PREDICTION	true
#define WF_USE_ALEX		false
#define WF_PHRASES		true
// ����� ���� �����������
#define LOG_FILE		"speed_error.log"
#define LEMRULES_LOG_FILE		"lemrules_error.log"
#define GRAMTAB_LOG_FILE		"gramtab_error.log"
#define RULE_FILE		"rules.ini"
#define LEX_FILE  		"gramtab.ini"
#define LEM_RULE_FILE	"lemrules.ini"
#define LOG_LOAD		"load_voc_error.log"


/// functions snprintf, snprintf_* are deprecated in windows and thus
/// has a prefix '_'. This macros detects OS and substitutes proper name.
#if (defined(__WINDOWS__) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(_WIN64)) && !defined(__CYGWIN__)
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

//---------------------------------------------------------------------------
#endif
