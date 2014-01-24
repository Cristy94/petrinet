#ifndef __TOKEN_H_
#define __TOKEN_H_

class Token
{
	bool isActive;

public:
	bool getState()
	{
		return isActive;
	}

    void deactivate(){
        isActive = 0;
    }

    void activate(){
        isActive = 1;
    }
};

#endif