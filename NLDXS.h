#pragma once
#ifndef _NLDXS
#define _NLDXS
#include <iostream>
#include <string>
using namespace std;
//Lop truu tuong (Abstract class)
class NLDXS
{
protected:
	string maso, hoten, bophan;
public:
	NLDXS(string = "", string = "", string = "");
	string GetMaSo();
	string GetHoTen();
	string GetBoPhan();
	void SetHoTen(string);
	void SetBoPhan(string);
	//cac ham ao
	virtual int GetSoKHCL();
	virtual double GetDSPCLCTB();
	virtual double GetDCC();
	virtual int GetSoSK();
	virtual void SetSoKHCL(int);
	virtual void SetDSPCLCTB(double);
	virtual void SetDCC(double);
	virtual void SetSoSK(int);
	virtual void Nhap();
	virtual void Xuat();
	//Ham ao thuan tuy
	virtual string GetLoai() = 0;
	virtual long TinhTienThuong() = 0;
};
#endif