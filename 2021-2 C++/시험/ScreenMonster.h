//-----------------------------------------------------------------------------
// ScreenMonster.h
//
// 특수기 - n개의 랜덤한 알파벳 문자를 화면에 출력한다
//-----------------------------------------------------------------------------

#pragma once

#include "Monster.h"

class ScreenMonster : public Monster {
	int n;							

public:
	ScreenMonster( int n ) : n{ n }
	{

	}

	virtual void special() override;
};

