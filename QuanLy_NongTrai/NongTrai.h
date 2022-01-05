#pragma once
#include"Bo.h"
#include"De.h"
class NongTrai
{
private:
	string Ten;
	int SoLuong;
	GiaSuc** dsGiaSuc;
public:
	NongTrai() {
		this->Ten = "";
		this->SoLuong = 0;
		this->dsGiaSuc = new GiaSuc * [this->SoLuong];
	}
	NongTrai(string ten, int soluong) {
		this->Ten = ten;
		this->SoLuong = soluong;
		/*this->dsGiaSuc = new GiaSuc * [this->SoLuong];*/
	}
	~NongTrai(){}
	void nhap() {
		cout << "\nNhap Ten Nong Trai:";
		getline(cin, this->Ten);
		cout << "\nNhap So Luong Gia Suc:";
		cin >> this->SoLuong;
		this->dsGiaSuc = new GiaSuc * [this->SoLuong];
		cout << "\nNhap Danh Sach Gia Suc:";
		int loai;
		GiaSuc* GS = NULL;
		for (int i = 0; i < this->SoLuong; i++)
		{
			cout << "\nNhap Loai Gia Suc 1:Bo - 2:De\n";
			do
			{
			cin >> loai;
			switch (loai)
			{
			case 1:
				GS = new Bo();
				break;
			case 2:
				GS = new De();
				break;
			default:
				cout << "\nChon Loai Gia Suc 1:Bo - 2:De\n";
				cout << "\nBan chon sai: vui long chon lai 1->2 ok...";
			}
			} while (loai != 1 && loai !=2);
			//if (loai == 1)
			//{
			//	GS = new Bo();
			//}
			//else if (loai == 2)
			//{
			//	GS = new De();
			//}
			GS->nhap();
			this->dsGiaSuc[i] = GS;
		}
	}
	void xuat() {
		cout << "\nTen Nong Trai:" << this->Ten;
		cout << "\nSo Luong Gia Suc:" << this->SoLuong;
		cout << "\nDanh Sach Gia suc: \n";
		for (int i = 0; i < this->SoLuong; i++)
		{
			this->dsGiaSuc[i]->xuat();
		}
	}
	float tinhTongLuongSuaBo() {
		float allSuaBo = 0;
		for (int i = 0; i < this->SoLuong; i++) {
			string loai = typeid(*dsGiaSuc[i]).name();
			if (loai == "class Bo")
				allSuaBo = allSuaBo + dsGiaSuc[i]->tinhLuongSua();
		}
		return allSuaBo;
	}
	float tinhTongLuongSua() {
		float allSua = 0;
		for (int i = 0; i < this->SoLuong; i++)
		{
			allSua = allSua + dsGiaSuc[i]->tinhLuongSua();
		}
		return allSua;
	}
	float tinhTongLuongSuade() {
		float allSuaDe = 0;
		for (int i = 0; i < this->SoLuong; i++) {
			string loai = typeid(*dsGiaSuc[i]).name();
			if (loai == "class De")
				allSuaDe = allSuaDe + dsGiaSuc[i]->tinhLuongSua();
		}
		return allSuaDe;
	}
	bool timTheoMS(GiaSuc*& gs) {
		string temp;
		cout << "\nNhap vo ma so Gia Suc Muon tim:";
		cin.ignore(1);
		getline(cin, temp);
		for (int i = 0; i < this->SoLuong; i++)
		{
			if (temp.compare(dsGiaSuc[i]->getMaSo()) == 0) {
				gs = dsGiaSuc[i];
				return true;
			}
		}
		return false;
	}
	/*NongTrai timMaSoGiaSuc() {
		NongTrai kq;
		string maSoCanTim;
		cout << "\nNhap vao ma so Gia Suc Can tim:";
		cin.ignore(1);
		getline(cin, maSoCanTim);
		for (int i = 0; i < this->SoLuong; i++)
		{
			if (maSoCanTim.compare(dsGiaSuc[i]->getMaSo()) == 0)
			{
				kq.dsGiaSuc[kq.SoLuong++] = this->dsGiaSuc[i];
			}
		}
		return kq;
	}*/
	NongTrai timTheoTuoi() {
		NongTrai kq;
		int temp = 0;
		cout << "\nNhap vao so tuoi muon:";
		int temTuoi;
		cin.ignore(1);
		cin >> temTuoi;
		for (int i = 0; i < this->SoLuong; i++)
		{
			if (this->dsGiaSuc[i]->getTuoi() == temTuoi) {
				kq.dsGiaSuc[temp++] = this->dsGiaSuc[i];
			}
		}
		kq.SoLuong = temp;
		return kq;
	}
	float timLuongSuaMax() {
		float LuongSuaMax = 0;
		for (int i = 0; i < this->SoLuong; i++)
		{
			if (dsGiaSuc[i]->tinhLuongSua() > LuongSuaMax) {
				LuongSuaMax = dsGiaSuc[i]->tinhLuongSua();
			}
		}
		return LuongSuaMax;
	}
	NongTrai TimGiaSucCoLuongSuaMax() {
		NongTrai kq;
		int temp = 0;
		float SuaMax = timLuongSuaMax();
		for ( int i = 0; i <this->SoLuong; i++)
		{
			if (this->dsGiaSuc[i]->tinhLuongSua() == SuaMax)
			{
				kq.dsGiaSuc[temp++] = this->dsGiaSuc[i];
			}
		}
		kq.SoLuong = temp;
		return kq;
	}
	NongTrai sapXepTheoLuongSua() {
		NongTrai temp;
		temp = *this;
		for (int i = 0; i < temp.SoLuong - 1; i++)
		{
			for (int j=  i + 1;j < temp.SoLuong; j++) {
				if (temp.dsGiaSuc[i]->tinhLuongSua() > temp.dsGiaSuc[j]->tinhLuongSua())
				{
					swap(temp.dsGiaSuc[i], temp.dsGiaSuc[j]);
				}
			}
		}
		return temp;
	}
	NongTrai sapXepTheoTuoi() {
		NongTrai temp;
		temp = *this;
		for (int i = 0; i < temp.SoLuong - 1; i++)
		{
			for (int j = i + 1; j < temp.SoLuong; j++) {
				if (temp.dsGiaSuc[i]->getTuoi() < temp.dsGiaSuc[j]->getTuoi())
				{
					swap(temp.dsGiaSuc[i], temp.dsGiaSuc[j]);
				}
			}
		}
		return temp;
	}
};

