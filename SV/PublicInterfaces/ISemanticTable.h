// Файл интерфейса для класса таблицы семантических аттрибутов

#ifndef ISemanticTableH
#define ISemanticTableH

#include "ISemanticAttr.h"

class ISemanticTable {
public:
	// Возвращает колличество семантических аттрибутов в таблице
	virtual int GetSemanticAttrCount() const = 0;
	// Создаёт новый семантический аттрибут в таблице,
	// возвращает индекс созданной;
	// если аттрибут с указанным значением уже существует в таблице,
	// то возвращает его индекс, не создавая нового
	virtual int CreateNewSemanticAttr(char* sSemanticAttrValue) = 0;
	// Удаляет семантическийй аттрибут из таблицы,
	// возвращает код при ошибке
	// 0 - операция прошла успешно
	// 1 - значение аттрибута хранится во внешнем словаре
	// 2 - аттрибут используется в словарной статье
	virtual short DeleteSemanticAttr(int Index) = 0;
	// Возвращает семантический аттрибут по его индексу
	virtual ISemanticAttr* GetSemanticAttr(int Index) const = 0;
	// Ищет семантический аттрибут по его значению,
	// возвращает индекс, ищет через сравнение строк
	virtual int FindSemanticAttr(const char* sSemanticAttrValue) const = 0;
	// Изменяет значение аттрибута, возвращает код при ошибке
	// 0 - операция прошла успешно
	// 1 - значение аттрибута хранится во внешнем словаре
	// 3 - такой атрибут уже есть в таблице
	// (значение остаётся прежним)
	virtual short SetSemanticAttrValue(int Index, char* sNewSemanticAttrValue) = 0;
};

#endif
