#pragma once
#ifndef _NV
#define _NV
#include"NLDXS.h"
class NV : public NLDXS
{
private:
	double sosk;
public:
	NV(string = "", string = "", string = "", int= 0);
	int GetSoSK();
	void SetSoSK(int);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	string GetLoai();
};
#endif
