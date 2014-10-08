#pragma once

#include "windows.h"

class PacMan
{
public:
	PacMan(int x, int y);
	void Update();
	void Draw(HDC hdc);
	void Load(HDC windowDC);
	void SetVX(int v)
	{
		if(_vx >= 0 && v < 0)
		{
			_direction = Left;
		}
		if(_vx <= 0 && v > 0)
		{
			_direction = Right;
		}
		_vx = v;
	}
	void SetVY(int v)
	{
		if(_vy >= 0 && v < 0)
		{
			_direction = Up;
		}
		if(_vy <= 0 && v > 0)
		{
			_direction = Down;
		}
		_vy = v;
	}
private:
	int _x;
	int _y;
	int _vx;
	int _vy;
	HBITMAP _frames[5];
	HBITMAP _masks[5];
	HDC _memoryHDC;
	HDC _maskHDC;
	int _counter;
	unsigned _imageIndex;
	enum Direction
	{
		Left, Up, Right, Down
	};

	Direction _direction;


};

