#pragma once
#ifndef _CQ
#define _CQ
#include "NLDXS.h"
class CQ: public NLDXS
{
private:
	int sokhcl;
public:
	CQ(string = "", string = "", string = "", int = 0);
	int GetSoKHCL();
	void SetSoKHCL(int);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	string GetLoai();
};
#endif
