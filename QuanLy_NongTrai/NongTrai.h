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
		this->dsGiaSuc = NULL;
	}
	NongTrai(string ten, int soluong) {
		this->Ten = ten;
		this->SoLuong = soluong;
		this->dsGiaSuc = new GiaSuc * [this->SoLuong];
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
			cin >> loai;
			if (loai == 1)
			{
				GS = new Bo();
			}
			else if (loai == 2)
			{
				GS = new De();
			}
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
	float tinhTongLuongSuade() {
		float allSuaDe = 0;
		for (int i = 0; i < this->SoLuong; i++) {
			string loai = typeid(*dsGiaSuc[i]).name();
			if (loai == "class De")
				allSuaDe = allSuaDe + dsGiaSuc[i]->tinhLuongSua();
		}
		return allSuaDe;
	}
};

