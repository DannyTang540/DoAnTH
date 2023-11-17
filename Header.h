#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>

using namespace std;
const int MAX = 100;
struct NgayGio {
    int ngay, thang, nam, gio, phut;
};
struct MonAn {
    char TenMon[50];
    double Gia;
};

struct KhachHang {
    char tenKH[50];
    char MaKh[10];
    char DiaChi[50];
    int SDT;
};
struct CTDonHang {
    char MaDon[10];
    MonAn mon[100];
    int SoLuong;
    float DonGia;
};
struct DonHang {
    char MaKH[10];
    char MaDon[10];
    NgayGio* ngaygio;//kieu du lieu ngay
    CTDonHang ctdonhang[50];//so luong ds
    char TrangThaiDon[20];
    KhachHang kh;
};
struct Node{
    KhachHang dataKH;
    DonHang dataDH;
    Node* link;
};

typedef struct Node* NodePtr;
void Menu();
void KhoiTao(NodePtr& ds);
int isEmpty(NodePtr ds);
void giaiPhong(NodePtr& ds);
NodePtr TaoNodeKH(KhachHang kh);
NodePtr TaoNodeDH(DonHang dh);
NodePtr ThemDonHang(NodePtr& ds,const DonHang& dh);
NodePtr ThemKhachHang(NodePtr& ds, KhachHang kh);
//bool strCmp(const char s1[],const char s2[]);
bool kiemTra_TrungMa(NodePtr& ds, char* ma);
//float tinhDonGia(NodePtr ds);
void nhapDSDonHang(NodePtr& ds);
void XuatDonHang(NodePtr ds);
//void nhapDSKhachHang(NodePtr& ds);
//void xuatKhachHang(NodePtr ds);
bool ghiFile(const char* tenFile, NodePtr&ds);
bool docFile(const char* tenFile, NodePtr& ds);
void nhapNgayGio(NodePtr& ds);
void xuatNgayGio(NodePtr ds);