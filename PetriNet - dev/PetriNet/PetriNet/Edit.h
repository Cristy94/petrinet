#ifndef __EDIT_H_
#define __EDIT_H_
#include "IEdit.h"

class Edit: IEdit
{
	void editNumberOfTokens(IElement *element, int numberOfTokens)
	{
		element->setNumberOfTokens(numberOfTokens);
	}
};

#endif
