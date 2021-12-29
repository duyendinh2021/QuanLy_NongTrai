#pragma once
#include<iostream>
#include<string>
using namespace std;
class GiaSuc
{
protected:
	string MaSo;
	float CanNang;
	int Tuoi;
public:
	GiaSuc() {
		this->MaSo = "";
		this->CanNang = 0;
		this->Tuoi = 0;
	}
	GiaSuc(string maso, float cannang, int tuoi) {
		this->MaSo = maso;
		this->CanNang = cannang;
		this->Tuoi = tuoi;
	}
	~GiaSuc(){}
	virtual void nhap() {
		cin.ignore(1);
		cout << "\nNhap Vao Ma So Gia Suc:";
		getline(cin, this->MaSo);
		cout << "\nNhap Vao Can Nang:";
		cin >> this->CanNang;
		cout << "\nNhap Vao Tuoi Gia Suc:";
		cin >> this->Tuoi;
	}
	string getMaSo() {
		return this->MaSo;
	}
	int getTuoi() {
		return this->Tuoi;
	}
	virtual void xuat() {
		cout << "\nMa Gia Suc :"<< this->MaSo;
		cout << "\nCan Nang Gia Suc:" << this->CanNang;
		cout << "\nTuoi Gia Suc:" << this->Tuoi;
	}
	virtual float tinhLuongSua() = 0;
};

