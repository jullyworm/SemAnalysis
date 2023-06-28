// Файл интерфейса для класса унарной модели управления

#ifndef IUnCaseFrameH
#define IUnCaseFrameH

#include "ISemanticFeature.h"

class IUnCaseFrame
{
public:
	// Возвращает уникальный идентификатор актанта
	virtual int GetID() const = 0;
	// Предоставляет доступ к коньюнкции семантических признаков по индексу
	virtual ISemanticFeature* GetSemanticFeature(int Index) const = 0;
	// Удаляет конъюнкцию семантических признаков
	virtual void DeleteSemanticFeature(int Index) = 0;
	// Создаёт новый объект конъюнкции семантических признаков
	virtual ISemanticFeature* CreateSemanticFeature() = 0;
	// Возвращает колличество конъюнкций семантических признаков
	virtual int GetSemanticFeatureCount() const = 0;
	// Работа с именем
	virtual const char* GetName() const = 0;
	virtual void SetName(char* sNewName) = 0;
};

#endif