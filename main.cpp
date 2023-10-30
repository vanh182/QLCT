#include "CONGTY.h"
void main()
{
	CONGTY ct;
	int chon;
	do
	{
		cout << "**********************CT QUAN LY NGUOI LAO DONG XUAT SAC CUA CONG TY**********************\n";
		cout << "*            1. Nhap d/s NLDXS                                                           *\n";
		cout << "*            2. Xuat d/s NLDXS                                                           *\n";
		cout << "*            3. Liet ke d/s CQ co tu 8 ban KHCL duoc chon tro len                        *\n";
		cout << "*            4. Dem CN co DCC toi da                                                     *\n";
		cout << "*            5. Tinh tong tien thuong cua NV co 5 SKKN tro len                           *\n";
		cout << "*            6. Tinh DSPCLCTB cua CN co DCC duoi 50                                      *\n";
		cout << "*            7. Kiem tra CQ chua co KHCL duoc chon                                       *\n";
		cout << "*            8. Tim NV co SKKN nhieu nhat                                                *\n";
		cout << "*            9. Sap xep d/s NLDXS tang dan theo ma so                                    *\n";
		cout << "*            10. Tim NLDXS thuoc Bo phan                                                 *\n";
		cout << "*            11. Cap nhat thong tin NLDXS co ma so tuy y                                 *\n";
		cout << "*            12. Them NLDXS moi tai vi tri bat ky                                        *\n";
		cout << "*            13. Xoa NLDXS co ma so tuy y                                                *\n";
		cout << "*            14. Xoa d/s NLDXS                                                           *\n";
		cout << "*            15. Tao file                                                                *\n";
		cout << "*            16. Doc file                                                                *\n";
		cout << "*            17. Doc file va luu d/s NLDXS                                               *\n";
		cout << "*            18. Luu file d/s NLDXS                                                      *\n";
		cout << "*            0. Thoat CT                                                                 *\n";
		cout << "******************************************************************************************\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
			if (ct.GetSL() > 0)
				ct.~CONGTY();
			cout << "Dang thoat CT...";
			break;
		case 1:
			if (ct.GetSL() > 0)
				ct.~CONGTY();
			ct.Nhap();
			break;
		case 2:
			if (ct.GetSL() > 0)
				ct.Xuat();
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 3:
			if (ct.GetSL() > 0)
				ct.LietKeCQCoTu8KHCL();
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 4:
			if (ct.GetSL() > 0)
			{
				int dem = ct.DemCNCODCCToiDa();
				if (dem > 0)
					cout << "Co " << dem << " CN co DCC toi da\n";
				else
					cout << "Khong co CN co DCC toi da\n";
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 5:
			if (ct.GetSL() > 0)
			{
				int tongtien = ct.TinhTongTienThuongNVCo5SKKNTroLen();
				if (tongtien > 0)
					cout << "Tong tien thuong cap cho NV co 5 SKKN tro len la " << tongtien << endl;
				else
					cout << "Khong co NV co 5 SKKN tro len\n";
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 6:
			if (ct.GetSL() > 0)
			{
				double dspclctb = ct.TinhDSPCLCTBCuaCNCODCCDuoi50();
				if (dspclctb == 0)
					cout << "Khong co CN co DCC duoi 50\n";
				else
					cout << "DSPCLCTB cua CN co DCC duoi 50 la " << dspclctb << endl;
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 7:
			if (ct.GetSL() > 0)
			{
				if (ct.KiemTraCQChuaCoKHCL())
					cout << "Cong ty co CQ chua co KHCL duoc chon\n";
				else
					cout << "Cong ty khong co CQ chua co KHCL duoc chon\n";
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 8:
			if (ct.GetSL() > 0)
				ct.TimNVCoSKKNNhieuNhat();
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 9:
			if (ct.GetSL() > 0)
			{
				ct.SapXepMaSoTangDan();
				ct.Xuat();
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 10:
			if (ct.GetSL() > 0)
			{
				string bp;
				cin.ignore();
				cout << "Nhap Bo phan can tim: ";
				getline(cin, bp);
				ct.TimNLDXSThuocBoPhan(bp);
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 11:
			if (ct.GetSL() > 0)
			{
				string ms;
				cin.ignore();
				cout << "Nhap ma so: ";
				getline(cin, ms);
				ct.CapNhatThongTinTheoMaSo(ms);
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 12:
		{
			NLDXS* pnld;
			int vt = 1;
			pnld = ct.Nhap1();
			if (ct.GetSL() > 0)
			{
				do
				{
					cout << "Nhap vi tri muon them NLDXS tu 1 den " << ct.GetSL() + 1 << ": ";
					cin >> vt;
				} while (vt<1 || vt>ct.GetSL() + 1);
			}
			ct.Them(pnld, vt);
			cout << "D/s NLDXS sau khi them NLDXS tai vi tri thu " << vt << " la:\n";
			ct.Xuat();
			break;
		}
		case 13:
			if (ct.GetSL() > 0)
			{
				string ms;
				cout << "Nhap ma so NLDXS muon xoa: ";
				cin >> ms;
				int kq = ct.Xoa(ms);
				if (kq != -1)
				{
					if (ct.GetSL() > 0)
					{
						cout << "D/s NLDXS sau khi xoa NLDXS co ma so " << ms << " la:\n";
						ct.Xuat();
					}
					else
						cout << "D/s NLDXS rong\n";
				}
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 14:
			if (ct.GetSL() > 0)
			{
				ct.~CONGTY();
				cout << "Da xoa toan bo d/s NLDXS\n";
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 15:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			ct.GhiFile(tenfile);
			break;
		}
		case 16:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			ct.DocFile(tenfile);
			break;
		}
		case 17:
		{
			if (ct.GetSL() > 0)
				ct.~CONGTY();
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			ct.DocFileNLDXS(tenfile);
			break;
		}
		case 18:
			if (ct.GetSL() > 0)
			{
				string tenfile;
				cin.ignore();
				cout << "Nhap ten file: ";
				getline(cin, tenfile);
				ct.GhiFileNLDXS(tenfile);
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		default: 
			cout << "Ban chon sai. Moi chon lai.\n";
			break;
	}
	} while (chon != 0);
}