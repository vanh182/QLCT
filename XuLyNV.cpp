#include"NV.h"
NV::NV(string ms, string ht, string bp, int sk) : NLDXS(ms,ht,bp), sosk(sk){}
int NV::GetSoSK() {
	return sosk;
}
void NV::SetSoSK(int sk) {
	while (sk < 0)
	{
		cout << "Nhap so sang kien: ";
		cin >> sk;
	}
	sosk = sk;
}
void NV::Nhap() {
	NLDXS::Nhap();
	do
	{
		cout << "Nhap so sang kien: ";
		cin >> this->sosk;
	} while (sosk < 0);
}
void NV::Xuat() {
	NLDXS::Xuat();
	cout << "\tLoai: NV\tSoSK: " << sosk << "\tTien thuong: " << TinhTienThuong() << endl;
}
long NV::TinhTienThuong() {
	long thuong = sosk * 5000000;
	if (sosk >= 5)
		thuong = thuong * 1.3;
	return thuong;
}
string NV::GetLoai() {
	return "NV";
}