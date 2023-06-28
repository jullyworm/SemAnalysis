// Файл интерфейса для класса актанта

#ifndef IAktantH
#define IAktantH

#include "IUnCaseFrame.h"
//#include "ISemanticFeature.h"

class IAktant: public IUnCaseFrame {
public:
	//Возвращает ID родительской модели управления
	virtual int GetIDParentCaseFrame() const = 0;
};

#endif
