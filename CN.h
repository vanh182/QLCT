#pragma once
#ifndef _CN
#define _CN
#include"NLDXS.h"
class CN : public NLDXS
{
private:
	double dspclctb, dcc;
public:
	CN(string = "", string = "", string = "", double = 0, double = 0);
	double GetDSPCLCTB();
	double GetDCC();
	void SetDSPCLCTB(double);
	void SetDCC(double);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	string GetLoai();
};
#endif
