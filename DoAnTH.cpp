#include"Header.h"
void Menu() {
    NodePtr ds;
    KhoiTao(ds);
    KhachHang kh;
    DonHang dh;
    int choice;
    do {
        cout << "------ MENU ------" << endl;
        //cout << "1. Them khach hang" << endl;
        cout << "2. Them don hang" << endl;
        cout << "3. Xuat danh sach don hang" << endl;
       // cout << "4. Xuat danh sach khach hang" << endl;
        cout << "5. Sap xep khach hang theo ten" << endl;
        cout << "6. Sap xep don hang theo ma don" << endl;
        cout << "7. Sap xep don hang theo ngay" << endl;
        cout << "8. Tim khach hang theo ten" << endl;
        cout << "9.Tim khach hang theo ma" << endl;
        cout << "10.Tim Khach hang theo so dien thoai" << endl;
        cout << "11. Tim don hang theo ma don hang" << endl;
        cout << "12. Tim don hang theo ma khach hang" << endl;
        cout << "13. Tim don hang theo ten khach hang" << endl;
        cout << "14. Ghi file" << endl;
        cout << "15. Doc file" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            //nhapDSKhachHang(ds);
            break;
        case 2:
            nhapDSDonHang(ds);
            break;
        case 3:
            XuatDonHang(ds);
            break;
        case 4:
            //xuatKhachHang(ds);
            break;
        case 14:
            ghiFile("danhsach.dat", ds);
            break;
        case 15:
            docFile("danhsach.dat", ds);
            break;
        case 16:
            nhapNgayGio(ds);
            break;
        case 17:
            xuatNgayGio(ds);
            break;
        default:
            break;
        }
    } while (choice != 0);
    giaiPhong(ds);
}

void KhoiTao(NodePtr& ds) {
    ds = NULL;
}
int isEmpty(NodePtr ds) {
    return ds == NULL ? 1 : 0;
}
void giaiPhong(NodePtr& ds) {
    NodePtr p = ds;
    while (p!=NULL)
    {
        ds = ds->link;
        delete p;
        p = ds;
    }
}
NodePtr TaoNodeKH(KhachHang kh) {
    NodePtr p = new Node;
    p->dataKH = kh;
    p->link = NULL;
    return p;
}

NodePtr TaoNodeDH(DonHang dh) {
    NodePtr p = new Node;
    p->dataDH = dh;
    p->link = NULL;
    return p;
}
NodePtr ThemDonHang(NodePtr& ds,const DonHang& dh) {
    NodePtr p = TaoNodeDH(dh);
    if (p != NULL) {
        p->link = ds;
        ds = p;
    }
    return p;
}
NodePtr ThemKhachHang(NodePtr& ds, KhachHang kh) {
    NodePtr p = TaoNodeKH(kh);
    p->link = ds;
    ds = p;
    return p;
}
//bool strCmp(const char s1[], const char s2[]) {
//    int i = 0;
//    while (s1[i] != '\0' || s2[i] != '\0') {
//        if (s1[i] != s2[i]) {
//            return false;
//        }
//        i++;
//    }
//    return true;
//}

bool kiemTra_TrungMa(NodePtr& ds,char* ma) {
    NodePtr p = ds;
    while (p!=NULL)
    {
        if (strcmp(p->dataDH.MaDon, ma)==0)
            return true;
        p = p->link;
    }
    return false;
}
//float tinhDonGia(DonHang dh) {
//    float tong = dh.ctdonhang.SoLuong * dh.ctdonhang.mon->Gia;
//    return tong;
//}
//void nhapDSDonHang(NodePtr& ds) {
//    DonHang dh;
//    KhoiTao(ds);
//    cin.ignore();
//    do {
//        cout << "\nNhap ma don hang (NHAP 0 DE THOAT): ";
//        cin.getline(dh.MaDon, 10);
//        if (strcmp(dh.MaDon, "0") == 0)
//            break;
//        while (kiemTra_TrungMa(ds, dh.MaDon)) {
//            cout << "\nMa don da ton tai!!!";
//            cout << "\nNhap lai ma don hang: ";
//            cin.getline(dh.MaDon, 10);
//        }
//        cout << "\nNhap ma khach hang: ";
//        cin.getline(dh.MaKH, 10); do
//        {   
//            NodePtr newNode = new Node;
//            cout << "\nNhap thoi gian: ";
//            cin >> newNode->dataDH.NgayGio.tm_year >> newNode->dataDH.NgayGio.tm_mon >> newNode->dataDH.NgayGio.tm_mday >> newNode->dataDH.NgayGio.tm_hour >> newNode->dataDH.NgayGio.tm_min;
//            //cin >> ds->dataDH.NgayGio.tm_year >> ds->dataDH.NgayGio.tm_mon >> ds->dataDH.NgayGio.tm_mday >> ds->dataDH.NgayGio.tm_hour >> ds->dataDH.NgayGio.tm_min;
//            giaiPhong(newNode);
//        } while (true);
//        
//        
//        cout << "\nNhap trang thai don: "; 
//        cin.getline(dh.TrangThaiDon, 20);
//        cout << "\nNhap chi tiet don hang (Nhap 0 de thoat)";
//        cout << "\nNhap ten mon an: ";
//        cin.getline(dh.ctdonhang->mon->TenMon, 50);
//        cout << "\nNhap gia tien mon an: ";
//        cin >> dh.ctdonhang->mon->Gia;
//        cout << "\nNhap so luong mon an: ";
//        cin >>  dh.ctdonhang->SoLuong;
//        cout << "\nNhap Don gia: ";
//        cin >> dh.ctdonhang->DonGia;
//        cin.ignore();
//       
//        ThemDonHang(ds, dh);
//        /*nhapDSKhachHang(ds);*/
//    } while (1);
//}
void nhapDSDonHang(NodePtr& ds) {
    DonHang dh;
    KhoiTao(ds);
    cin.ignore();
    do {
        cout << "\nNhap ma don hang (NHAP 0 DE THOAT): ";
        cin.getline(dh.MaDon, 10);
        if (strcmp(dh.MaDon, "0") == 0)
            break;
        while (kiemTra_TrungMa(ds, dh.MaDon)) {
            cout << "\nMa don da ton tai!!!";
            cout << "\nNhap lai ma don hang: ";
            cin.getline(dh.MaDon, 10);
        }
        cout << "\nNhap ma khach hang: ";
        cin.getline(dh.MaKH, 10);
        NodePtr ds = new Node;
        ds->link = nullptr;
        cout << "\nNhap thoi gian (DD/MM/YYYY HH:mm): ";
        //cin >> ds->dataDH.ngaygio.ngay >> ds->dataDH.ngaygio.thang >> ds->dataDH.ngaygio.nam >> ds->dataDH.ngaygio.gio >> ds->dataDH.ngaygio.phut;
        cout << "\nNhap trang thai don: ";
        cin.getline(dh.TrangThaiDon, 20);
        cout << "\nNhap chi tiet don hang (Nhap 0 de thoat)";
        cout << "\nNhap ten mon an: ";
        cin.getline(dh.ctdonhang->mon->TenMon, 50);
        cout << "\nNhap gia tien mon an: ";
        cin >> dh.ctdonhang->mon->Gia;
        cout << "\nNhap so luong mon an: ";
        cin >> dh.ctdonhang->SoLuong;
        cout << "\nNhap Don gia: ";
        cin >> dh.ctdonhang->DonGia;
        cin.ignore();
        ThemDonHang(ds, dh);
    } while (true);
}
void XuatDonHang(NodePtr ds) {
    NodePtr p = ds;
    cout << "Ma don hang | Ma khach hang | Thoi gian | Trang thai don | Ten mon an | Gia | So luong | Don gia" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    while (p != NULL) {
        cout << setw(11) << p->dataDH.MaDon << " | ";
        cout << setw(14) << p->dataDH.MaKH << " | ";
        //cout << setw(9) << ds->dataDH.ngaygio.ngay << ds->dataDH.ngaygio.thang << ds->dataDH.ngaygio.nam << ds->dataDH.ngaygio.gio << ds->dataDH.ngaygio.phut << " | ";
        cout << setw(14) << p->dataDH.TrangThaiDon << " | ";
        cout << setw(11) << ds->dataDH.ctdonhang->mon->TenMon << " | ";
        cout << setw(4) << ds->dataDH.ctdonhang->mon->Gia << " | ";
        cout << setw(8) << ds->dataDH.ctdonhang->SoLuong << " | ";
        cout << setw(7) << ds->dataDH.ctdonhang->DonGia << endl;

        p = p->link;
    }
}
//void nhap(NodePtr& ds) {
//    DonHang dh;
//    KhoiTao(ds);
//    cout << "\nNhap ma: ";
//    cin.getline(dh.MaDon, 10);
//    cin.ignore();
//    if (strcmp(dh.MaDon,"0")==0) {
//        cout << dh.MaDon;
//    }
//    cout << "\nNhap ma khach hang: ";
//    cin.getline(dh.MaKH, 10);
//    cout << "\nNhap thoi gian: ";
//    cin.getline(dh.NgayGio, 20);
//    cout << "\nNhap trang thai don: ";
//    cin.getline(dh.TrangThaiDon, 20);
//    cout << "\nNhap chi tiet don hang (Nhap 0 de thoat)";
//    cout << "\nNhap ten mon an: ";
//    cin.getline(dh.ctdonhang.mon->TenMon, 50);
//    /*if(strCmp(dh.ctdonhang.mon->TenMon,"0") == 0)
//        break;*/
//    cout << "\nNhap gia tien mon an: ";
//    cin >> dh.ctdonhang.mon->Gia;
//    cout << "\nNhap so luong mon an: ";
//    cin >> dh.ctdonhang.SoLuong;
//    cout << "\nNhap don gia: ";
//    cin >> dh.ctdonhang.DonGia;
//    cin.ignore();
//    ThemDonHang(ds, dh);
//}
//    void nhapDSKhachHang(NodePtr & ds); {
//        KhachHang kh;
//        //KhoiTao(ds);
//        cin.ignore();
//        cout << "\nThong tin khach hang";
//        cout << "\nMa khach hang: " << ds->dataDH.MaKH;
//        //cin.getline(kh.MaKh, 10);
//       /* while (kiemTra_TrungMa(ds, kh.MaKh)) {
//            cout << "\nMa khach hang da ton tai!!!";
//            cout << "\nNhap lai ma khach hang: ";
//            cin.getline(kh.MaKh, 10);
//        }*/
//        cout << "\nNhap ten khach hang: ";
//        cin.getline(kh.tenKH, 50);
//        cout << "\nNhap dia chi: ";
//        cin.getline(kh.DiaChi, 50);
//        cout << "\nNhap so dien thoai: ";
//        cin >> kh.SDT;
//        ThemKhachHang(ds, kh); 
//    }
//}
//void xuatKhachHang(NodePtr ds){
//    cout << "Ma khach hang: " << ds->dataKH.MaKh << endl;
//    cout << "Ten khach hang: "<<ds->dataKH.tenKH<< endl;
//    cout << "Dia chi: "<<ds->dataKH.DiaChi << endl;
//    cout << "So dien thoai: " << ds->dataKH.SDT << endl;
//    cout << "---------------------------------------" << endl;
//}
bool ghiFile(const char* tenFile, NodePtr& ds) {
    FILE* file;
    errno_t file_out;
    file_out = fopen_s(&file, tenFile, "wb");
    if (file_out !=0) {
        cout << "\nLoi mo file\n";
        return false;
    }
    NodePtr p = ds;
    while (p != NULL)
    {
        size_t result = fwrite(&p->dataDH, sizeof(DonHang), 1, file);
        if (result!=1)
        {
            cout << "\nLoi ghi file";
            fclose(file);
            return false;
        }
        p = p->link;
    }
    fclose(file);
    return true;
}
bool docFile(const char* tenFile,NodePtr& ds){
    FILE* file;
    errno_t file_in;
    file_in = fopen_s(&file, tenFile, "rb");
    if (file == NULL) {
        cout << "\nLoi mo file\n";
        return false;
    }
    KhoiTao(ds);
    DonHang dh;
    while (fread(&dh, sizeof(DonHang), 1, file) == 1) {
        NodePtr p = new Node;
        p->dataDH = dh;
        p->link = NULL;
        if (ds == NULL)
            ds = p;
        else {
            NodePtr current = ds;
            while (current->link != nullptr)
                current = current->link;
            current->link = p;
        }
    }
    fclose(file);
    return true;
}
void nhapNgayGio(NodePtr& ds) {
    cout << "\nNhap ngay gio:";
    if (ds != NULL) {
        NgayGio* ngay = new NgayGio;
        cin >> ngay->gio >> ngay->phut;
        ds->dataDH.ngaygio = ngay;
        ds = ds->link;
    }

}

void xuatNgayGio(NodePtr ds) {
    NodePtr p = ds;
    cout << "\nNgay gio:" << ds->dataDH.ngaygio->gio << ":" << ds->dataDH.ngaygio->phut;
}