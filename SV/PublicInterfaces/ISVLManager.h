// Файл интерфейса для менеджера, создающего экземпляр
// семантического словарного компонента

#ifndef ISVLManagerH
#define ISVLManagerH

#include "ISemanticVoc.h"
//#include "IViewerSemanticVoc.h"

class ISVLManager {
public:
	// Уничтожает экземпляр компонента и освобождает память
	virtual void Release() = 0;
	// Создаёт единственный экземпляр семантического словарного
	// компонента
	virtual ISemanticVoc* GetSemanticVoc() = 0;
};

#endif
