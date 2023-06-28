// Copyright (c) 2004 by RRIAI. All rights reserved.
//===================================================================
// Nov 2005                  Created               L. Sidorova, RRIAI
//===================================================================
#ifndef IKNThemeListH
#define IKNThemeListH
//---------------------------------------------------------------------------
#include "IKNTheme.h"
//---------------------------------------------------------------------------
/** 
 * @interface IKNThemeList
 * �������� ���.
 */
class IKNThemeList {
public:
	/** Get Themes count. */
	virtual unsigned GetCount() const = 0;
	/** Get theme. */
	virtual IKNTheme* GetTheme( unsigned iIndex ) const = 0;

	/** Find theme by name. */
	virtual IKNTheme* FindTheme( char* iThemeName ) const = 0;
	/** Find theme by own id. */
	virtual IKNTheme* FindTheme( unsigned iId ) const = 0;
    /** ����� ���� �� �� ��������, ���� ���� ���, �� �������. */
	virtual IKNTheme* FindAddTheme( char *iThemeName ) = 0;

	/** Create theme (���������� ������ ���� ������������� �������������).
	 * @params iName - name of new theme
	 * @params iParent - parent of new theme
	 */
	virtual IKNTheme* CreateTheme( char* iName, IKNTheme* iParent=0 ) = 0;
	/** Delete theme. */
	virtual void DeleteTheme( IKNTheme* iTheme ) = 0;

	/** ������� ������ ����������� ��� (11 ���). */
	virtual void CreateDefult() = 0;

	/** ��������� ���� �� ���������� �����. */
    virtual bool LoadAsText(const char* file_name) = 0;
	/** ��������� ���� � ��������� ����. */
    virtual bool SaveAsText(const char* file_name) const = 0;

//-------------------------------------------------------------------
	/** �������� ������ �������� ��� (��� ��������). */
    virtual void ClearActive() = 0;
	/** Set text theme (��� ��������). */
	virtual t_errno SetTextTheme( IKNTheme* iTheme ) = 0;

	/**
	 * Add theme to list of text themes (��� ��������).
     * @note ���� ������ ������ ������������� ��������� ���, �� ���
     *		 ����������� � ������ ��� ��� ��������
	 */
	virtual t_errno AddTextTheme( IKNTheme* iTheme ) = 0;

	/** Get themes max Id. */
	virtual unsigned GetMaxId() const = 0;

//-------------------------------------------------------------------
// � IKNManager !!
	/**
	 * C��������� �������� ��� � ����, ��������� �������������.
	 * @note ��������� ���������� �� �������.
	 * @param iName - ��� ����� (����������� ������ ������������)
	 */
//	virtual t_errno Save( char* iFileName ) const = 0;

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
//	virtual t_errno Load(char* iFileName, bool iMode) = 0;
};
//---------------------------------------------------------------------------
#endif
