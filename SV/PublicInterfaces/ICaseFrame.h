// Файл интерфейса для класса модели управления

#ifndef ICaseFrameH
#define ICaseFrameH

#include "IAktant.h"

class ICaseFrame {
public:
	// Возвращает уникальный идентификатор модели управления
	virtual int GetID() const = 0;
	// Предоставляет доступ к актанту по его индексу
	virtual IAktant* GetAktant(int Index) const = 0;
	// Удаляет актант
	virtual void DeleteAktant(int Index) = 0;
	// Создаёт новый объект актанта
	virtual IAktant* CreateAktant() = 0;
	// Возвращает колличество актантов данной модели управления
	virtual int GetAktantCount() const = 0;
	// Работа с именем модели управления
	virtual const char* GetName() const = 0;
	virtual void SetName(char* sNewName) = 0;
};

#endif
