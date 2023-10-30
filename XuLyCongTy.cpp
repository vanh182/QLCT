#include"CONGTY.h"
#include"CQ.h"
#include"CN.h"
#include"NV.h"
CONGTY::CONGTY() {
	pnldxs = NULL;
	sl = 0;
}
CONGTY::~CONGTY() {
	for (int i = 0; i < sl; i++)
		delete pnldxs[i];
	delete[]pnldxs;
	pnldxs = NULL;
	sl = 0;
}
int CONGTY::GetSL() {
	return sl;
}
void CONGTY::Nhap() {
	int loai; //loai NLDXS
	do
	{
		cout << "Nhap so luong NLDXS: ";
		cin >> sl;
	} while (sl < 1);
	pnldxs = new NLDXS * [sl];
	for (int i = 0; i < sl; i++)
	{
		cout << "----------------------------------------\n";
		cout << "Nhap thong tin NLDXS thu " << i + 1 << ":\n";
		do
		{
			cout << "Nhap loai (1: CQ, 2: CN, 3: NV): ";
			cin >> loai;
		} while (loai < 1 || loai>3);
		if (loai == 1)
			pnldxs[i] = new CQ;
		else if (loai == 2)
			pnldxs[i] = new CN;
		else
			pnldxs[i] = new NV;
		pnldxs[i]->Nhap();
		for (int j = 0; j < i; j++) //kiem tra ms bi trung
		{
			if (pnldxs[i]->GetMaSo() == pnldxs[j]->GetMaSo())
			{
				cout << "Ma so "<<pnldxs[i]->GetMaSo() << " bi trung.\n";
				Xoa(pnldxs[i]->GetMaSo());
			}
		}
	}
}
NLDXS* CONGTY::Nhap1() {
	int loai; //loai NLDXS
	NLDXS* pnld;
	do
	{
		cout << "Nhap loai (1: CQ, 2: CN, 3: NV): ";
		cin >> loai;
	} while (loai < 1 || loai>3);
	if (loai == 1)
		pnld = new CQ;
	else if (loai == 2)
		pnld = new CN;
	else
		pnld = new NV;
	pnld->Nhap();
	return pnld;
}
void CONGTY::Xuat() {
	for (int i = 0; i < sl; i++)
		pnldxs[i]->Xuat();
}
void CONGTY::LietKeCQCoTu8KHCL() {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "CQ" && pnldxs[i]->GetSoKHCL() >= 8)
		{
			pnldxs[i]->Xuat();
			dem++;
		}
	if (dem == 0)
		cout << "Khong co CQ nao co tu 8 ke hoach chien luoc duoc chon tro len\n";
}
int CONGTY::DemCNCODCCToiDa() {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "CN" && pnldxs[i]->GetDCC() == 100)
			dem++;
	return dem;
}
long CONGTY::TinhTongTienThuongNVCo5SKKNTroLen() {
	long sum = 0;
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "NV" && pnldxs[i]->GetSoSK() >= 5)
			sum += pnldxs[i]->TinhTienThuong();
	return sum;
}
double CONGTY::TinhDSPCLCTBCuaCNCODCCDuoi50() {
	double tongdspclctb = 0;
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "CN" && pnldxs[i]->GetDCC() < 50)
		{
			tongdspclctb += pnldxs[i]->GetDCC();
			dem++;
		}
	return dem > 0 ? tongdspclctb / dem : 0;
}
bool CONGTY::KiemTraCQChuaCoKHCL() {
	bool kt = false; //Gia su khong co CQ chua co KHCL
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "CQ" && pnldxs[i]->GetSoKHCL() == 0) // CQ thu i nay chua co KHCL duoc chon
		{
			kt = true; //ghi nhan CQ chua co KHCL duoc chon
			break;
		}
	return kt;
}
void CONGTY::TimNVCoSKKNNhieuNhat() {
	int skmax = -1, vt = -1; //khong co NV
	//tim NV dau tien (neu co)
	for (int i = 0; i < sl; i++)
		if (pnldxs[i]->GetLoai() == "NV") //co NV
		{
			vt = i; //ghi nhan vt NV dau tien
			skmax = pnldxs[i]->GetSoSK(); // ghi nhan so SKKN cua NV dau tien la skmax
			break;
		}
	if (vt != -1) //neu co NV dau tien
	{
		//tim so SKKN max
		for (int i = vt + 1; i < sl; i++)
			if (pnldxs[i]->GetLoai() == "NV" && pnldxs[i]->GetSoSK() > skmax)
				skmax = pnldxs[i]->GetSoSK();//ghi nhan so SKKN cua NV nhieu hon=> skmax
		//liet ke d/s cac NV co so SKKN max
		for (int i = 0; i < sl; i++)
			if (pnldxs[i]->GetLoai() == "NV" && pnldxs[i]->GetSoSK() == skmax)
				pnldxs[i]->Xuat();
	}
	else //khong co NV
		cout << "Cong ty khong co NV";
}
string CONGTY::DoiChuoiInHoa(string str) {
	//doi tung ky tu cua chuoi str thanh ky tu IN HOA
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}
string CONGTY::DoiChuoiInThuong(string str) {
	//doi tung ky tu cua chuoi str thanh ky tu in thuong
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}
void CONGTY::SapXepMaSoTangDan() {
	for (int i = 0; i < sl - 1; i++)
		for (int j = i + 1; j < sl; j++)
			if (DoiChuoiInHoa(pnldxs[i]->GetMaSo()) > DoiChuoiInHoa(pnldxs[j]->GetMaSo()))
			{
				NLDXS* ptam = pnldxs[i];
				pnldxs[i] = pnldxs[j];
				pnldxs[j] = ptam;
			}
}
void CONGTY::TimNLDXSThuocBoPhan(string bp) {
	int dem = 0;
	for (int i=0; i<sl ; i++)
		if (DoiChuoiInHoa(pnldxs[i]->GetBoPhan()) == DoiChuoiInHoa(bp))
		{
			pnldxs[i]->Xuat();
			dem++;
		}
	if (dem == 0)
		cout << "Khong co NLDXS thuoc Bo Phan " << bp << endl;
}
void CONGTY::CapNhatThongTinTheoMaSo(string ms) {
	int timthay = -1; //chua tim thay NLDXS co ma so ms
	for (int i=0; i<sl; i++)
		if (DoiChuoiInHoa(pnldxs[i]->GetMaSo()) == DoiChuoiInHoa(ms))
		{
			timthay = 1; //da tim thay NLDXS co ma so ms
			string ht, bp;
			cin.ignore();
			cout << "Nhap ho ten: ";
			getline(cin, ht);
			pnldxs[i]->SetHoTen(ht); //cap nhat ho ten
			cout << "Nhap bo phan: ";
			getline(cin, bp);
			pnldxs[i]->SetBoPhan(bp); //cap nhat bo phan
			if (pnldxs[i]->GetLoai() == "CQ") //neu NLDXS dang xet la CQ
			{
				int khcl;
				cout << "Nhap so ke hoach chien luoc: ";
				cin >> khcl;
				pnldxs[i]->SetSoKHCL(khcl); //cap nhat so khcl
			}
			else if (pnldxs[i]->GetLoai() == "CN") //neu NLDXS dang xet la CN
			{
				double spclctb, cc;
				cout << "Nhap DSPCLCTB: ";
				cin >> spclctb;
				pnldxs[i]->SetDSPCLCTB(spclctb); //Cap nhat DSPCLCTB
				cout << "Nhap DCC: ";
				cin >> cc;
				pnldxs[i]->SetDCC(cc); //cap nhat DCC
			}
			else //nld dang xet la NV
			{
				int sk;
				cout << "Nhap so SKKN: ";
				cin >> sk;
				pnldxs[i]->SetSoSK(sk); //cap nhat so SKKN
			}
			cout << "Da cap nhat thong tin NLD co ma so la " << ms << endl;
			Xuat(); // Xuat lai d/s NLDXS sau khi da cap nhat
			break;
		}
	if (timthay == -1)
		cout << "Khong tim thay NLDXS co ma so la " << ms << endl;
}
void CONGTY::Them(NLDXS* pnld, int vt) {
	NLDXS** pnew = new NLDXS * [sl + 1];
	for (int i = 0; i <vt - 1; i++)
		pnew[i] = pnldxs[i];
	pnew[vt - 1] = pnld;
	for (int i = vt; i < sl + 1; i++)
		pnew[i] = pnldxs[i - 1];
	delete[]pnldxs;
	pnldxs = pnew;
	sl++;
}
int CONGTY::Xoa(string ms) {
	int vt = -1; //chua tim thay NLDXS co ma so ms
	for (int i=0; i<sl; i++)
		if (DoiChuoiInHoa(pnldxs[i]->GetMaSo()) == DoiChuoiInHoa(ms))
		{
			vt = i;
			break;
		}
	if (vt != -1)
	{
		NLDXS** pnew = new NLDXS * [sl - 1];
		for (int i = 0; i < vt; i++)
			pnew[i] = pnldxs[i];
		for (int i = vt; i < sl - 1; i++)
			pnew[i] = pnldxs[i + 1];
		delete[]pnldxs;
		pnldxs = pnew;
		sl--;
	}
	else
		cout << "Khong tim thay NLDXS co ma so " << ms << endl;
	return vt;
}
void CONGTY::GhiFile(string tenfile) {
	string nd;
	ofstream outputFile(tenfile);
	if (!outputFile.fail())
	{
		cout << "Ban nhap noi dung file (ket thuc bang dau ~):\n";
		while (1)
		{
			getline(cin, nd);
			if (nd.back() != '~')
				outputFile << nd << endl;
			else
			{
				nd.back() = '\0';
				outputFile << nd;
				break;
			}
		}
		outputFile.close();
		cout << "Da ghi file thanh cong\n";
	}
	else
		cout << "Loi tao file\n";
}
void CONGTY::DocFile(string tenfile) {
	string nd;
	ifstream inputFile(tenfile);
	if (!inputFile.fail())
	{
		while (getline(inputFile, nd))
			cout << nd << endl;
		inputFile.close();
		cout << "Da doc file thanh cong\n";
	}
	else
		cout << "Loi doc file\n";
}
void CONGTY::GhiFileNLDXS(string tenfile) {
	ofstream outputFile(tenfile);
	if (!outputFile.fail())
	{
		outputFile << sl << endl;
		string l;
		for (int i = 0; i < sl; i++)
		{
			l = pnldxs[i]->GetLoai();
			outputFile << pnldxs[i]->GetMaSo() << endl << pnldxs[i]->GetHoTen() << endl 
				<< pnldxs[i]->GetBoPhan() << endl << l << endl;
			if (l == "CQ")
				outputFile << pnldxs[i]->GetSoKHCL() << endl;
			else if (l == "CN")
				outputFile << pnldxs[i]->GetDSPCLCTB() << endl << pnldxs[i]->GetDCC() << endl;
			else
				outputFile << pnldxs[i]->GetSoSK() << endl;
			outputFile << pnldxs[i]->TinhTienThuong() << endl;
		}
		outputFile.close();
		cout << "Da ghi file thanh cong\n";
	}
	else
		cout << "Loi ghi file\n";
}
void CONGTY::DocFileNLDXS(string tenfile) {
	ifstream inputFile(tenfile);
	if (!inputFile.fail())
	{
		inputFile >> sl;
		if (sl > 0)
		{
			pnldxs = new NLDXS * [sl];
			string ms, ht, bp, l;
			int khcl, sk;
			double spclctb, cc;
			long tt;
			for (int i = 0; i < sl; i++)
				//while (!inputFile.eof())
			{
				inputFile.ignore();
				getline(inputFile, ms);
				getline(inputFile, ht);
				getline(inputFile, bp);
				getline(inputFile, l);
				if (DoiChuoiInHoa(l) == "CQ")
				{
					inputFile >> khcl;
					pnldxs[i] = new CQ(ms, ht, bp, khcl);
				}
				else if (DoiChuoiInHoa(l) == "CN")
				{
					inputFile >> spclctb;
					inputFile >> cc;
					pnldxs[i] = new CN(ms, ht, bp, spclctb, cc);
				}
				else
				{
					inputFile >> sk;
					pnldxs[i] = new NV(ms, ht, bp, sk);
				}
				inputFile >> tt;
			}
			cout << "Da doc file va luu d/s NLDXS thanh cong\n";
		}
		else
			cout << "So luong NLDXS phai > 0\n";
		inputFile.close();
	}
	else
		cout << "Loi doc file\n";
}
