
#include "stdafx.h"
#include "resource.h"
#include "pm.h"

extern HINSTANCE hInst;

PacMan::PacMan(int x, int y): _x(x), _y(y), _vx(0), _vy(0), _counter(0), _imageIndex(0), _direction(Left)
{

}

void PacMan::Load(HDC windowDC)
{
	_frames[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRAME0));
	_frames[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRAME_LEFT));
	_frames[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRAME_UP));
	_frames[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRAME_RIGHT));
	_frames[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRAME_DOWN));

	_masks[0] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MASK0));
	_masks[1] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MASK_LEFT));
	_masks[2] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MASK_UP));
	_masks[3] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MASK_RIGHT));
	_masks[4] = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MASK_DOWN));


	_memoryHDC = CreateCompatibleDC(windowDC);
	_maskHDC = CreateCompatibleDC(windowDC);
}

void PacMan::Update()
{
	++_counter;
	if(_counter == 5)
	{
		_counter = 0;
		_imageIndex = _imageIndex ? 0 : (1 + _direction);
	}
	_x += _vx;
	_y += _vy;
}

void PacMan::Draw(HDC hdc)
{
	SelectObject(_memoryHDC, _frames[_imageIndex]);
	SelectObject(_maskHDC, _masks[_imageIndex]);

	BitBlt(hdc, _x, _y, 28, 28, _maskHDC, 0, 0, SRCAND);
	BitBlt(hdc, _x, _y, 28, 28, _memoryHDC, 0, 0, SRCPAINT);

}

