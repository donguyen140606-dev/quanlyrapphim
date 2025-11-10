#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================== CONSTANTS ==================
const double LUONG_THEO_GIO = 30000.0;
const int GIO_MOT_CA = 6;

// ================== FORWARD DECLARATIONS ==================
void clearScreen();
void pause();
bool isValidSeat(string seat);

// ================== CLASS NHAN VIEN ==================
class NhanVien {
public:
    string hoTen, gioiTinh, viTriWork;
    int caLam, ID;
    double tongLuong;
    
    void nhap();
    void tinhLuong();
    void xuat();
};

// Định nghĩa hàm NhanVien bên ngoài class
void NhanVien::nhap() {
    cin.ignore();
    cout << "\nNhap Ho Ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Vi tri lam viec: ";
    getline(cin, viTriWork);
    
    // Nhập ID với validation
    do {
        cout << "So ID (so nguyen duong): ";
        cin >> ID;
        if (cin.fail() || ID <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "ID khong hop le! Vui long nhap lai.\n";
        } else {
            break;
        }
    } while (true);
    
    // Nhập số ca làm với validation
    do {
        cout << "Ca lam viec trong thang: ";
        cin >> caLam;
        if (cin.fail() || caLam < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "So ca khong hop le! Vui long nhap lai.\n";
        } else {
            break;
        }
    } while (true);
    
    tinhLuong();
}

void NhanVien::tinhLuong() {
    int soGioLam = caLam * GIO_MOT_CA;
    tongLuong = soGioLam * LUONG_THEO_GIO;
}

void NhanVien::xuat() {
    cout << "========================================" << endl;
    cout << "Ho Ten          : " << hoTen << endl;
    cout << "Gioi Tinh       : " << gioiTinh << endl;
    cout << "Vi tri          : " << viTriWork << endl;
    cout << "ID              : " << ID << endl;
    cout << "So ca lam       : " << caLam << endl;
    cout << "Tong luong      : " << fixed << setprecision(0) << tongLuong << " VND" << endl;
    cout << "========================================" << endl;
}

// ================== DANH SACH NHAN VIEN ==================
struct NodeNV {
    NhanVien data;
    NodeNV* next;
};

class ListNhanVien {
public:
    NodeNV* head;
    NodeNV* tail;
    
    ListNhanVien();
    NodeNV* createNode(NhanVien v);
    bool kiemTraIDTonTai(int id);
    void addNV(NhanVien v);
    void deleteNV(int id);
    void editNV(int id);
    void show();
    double tinhTongLuong();
};

// Định nghĩa hàm ListNhanVien bên ngoài class
ListNhanVien::ListNhanVien() { 
    head = tail = NULL; 
}

NodeNV* ListNhanVien::createNode(NhanVien v) {
    NodeNV* p = new NodeNV();
    p->data = v;
    p->next = NULL;
    return p;
}

bool ListNhanVien::kiemTraIDTonTai(int id) {
    for (NodeNV* i = head; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            return true;
        }
    }
    return false;
}

void ListNhanVien::addNV(NhanVien v) {
    // Kiểm tra ID trùng
    if (kiemTraIDTonTai(v.ID)) {
        cout << "\n ID " << v.ID << " da ton tai! Vui long nhap ID khac.\n";
        return;
    }
    
    v.tinhLuong();
    NodeNV* p = createNode(v);
    if (head == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    cout << " Da them nhan vien thanh cong!\n";
}

void ListNhanVien::deleteNV(int id) {
    if (head == NULL) {
        cout << "\nKhong co nhan vien nao" << endl;
        return;
    }
    
    if (head->data.ID == id) {
        NodeNV* p = head;
        head = head->next;
        delete p;
        cout << "\nDa xoa nhan vien thanh cong" << endl;
        return;
    }
    
    NodeNV* j = head;
    for (NodeNV* i = head->next; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            j->next = i->next;
            if (i == tail) tail = j;
            delete i;
            cout << "\nDa xoa nhan vien thanh cong" << endl;
            return;
        }
        j = i;
    }
    cout << "\nKhong tim thay ID" << endl;
}

void ListNhanVien::editNV(int id) {
    for (NodeNV* i = head; i != NULL; i = i->next) {
        if (i->data.ID == id) {
            cout << "Da tim thay nhan vien:" << endl;
            i->data.xuat();
            cout << "\n----Nhap lai thong tin----:" << endl;
            i->data.nhap();
            cout << "Cap nhat thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

void ListNhanVien::show() {
    if (!head) {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    cout << "\n========= DANH SACH NHAN VIEN =========" << endl;
    for (NodeNV* i = head; i != NULL; i = i->next) {
        i->data.xuat();
    }
}

double ListNhanVien::tinhTongLuong() {
    double tong = 0;
    for (NodeNV* i = head; i != NULL; i = i->next) {
        tong += i->data.tongLuong;
    }
    return tong;
}

// ================== CLASS PHIM ==================
class Film {
public:
    string tenPhim, theLoai;
    int thoiLuong, phong;
    string suatChieu[6];
    double giaVe[6];

    Film();
    void nhap();
    void xuat();
};

// Định nghĩa hàm Film bên ngoài class
Film::Film() {
    tenPhim = theLoai = "";
    thoiLuong = phong = 0;
    for (int i = 0; i < 6; i++) {
        suatChieu[i] = "";
        giaVe[i] = 70000;
    }
}

void Film::nhap() {
    cout << "Nhap ten phim: ";
    getline(cin, tenPhim);
    cout << "Nhap the loai: ";
    getline(cin, theLoai);
    cout << "Nhap thoi luong (phut): ";
    cin >> thoiLuong;
    cout << "Nhap phong chieu: ";
    cin >> phong;
    cin.ignore();
    
    cout << "Nhap 6 suat chieu:\n";
    for (int i = 0; i < 6; i++) {
        cout << "  Suat " << i + 1 << ": ";
        getline(cin, suatChieu[i]);
        cout << "  Gia ve suat " << i + 1 << " (VND): ";
        cin >> giaVe[i];
        cin.ignore();
    }
}

void Film::xuat() {
    cout << "\n========================================\n";
    cout << "TEN PHIM    : " << tenPhim << endl;
    cout << "THE LOAI    : " << theLoai << endl;
    cout << "THOI LUONG  : " << thoiLuong << " phut" << endl;
    cout << "PHONG       : " << phong << endl;
    cout << "========================================\n";
}

// ================== DANH SACH PHIM ==================
struct NodeFilm {
    Film data;
    NodeFilm* next;
};

class ListFilm {
public:
    NodeFilm* head;
    NodeFilm* tail;
    int size;

    ListFilm();
    NodeFilm* createNode(Film n);
    void addLast(Film n);
    void deleteFilm(int pos);
    void showList();
    int length();
    Film* getFilmAt(int pos);
};

// Định nghĩa hàm ListFilm bên ngoài class
ListFilm::ListFilm() {
    head = tail = NULL;
    size = 0;
}

NodeFilm* ListFilm::createNode(Film n) {
    NodeFilm* p = new NodeFilm();
    p->data = n;
    p->next = NULL;
    return p;
}

void ListFilm::addLast(Film n) {
    NodeFilm* p = createNode(n);
    if (!head) head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
    size++;
}

void ListFilm::deleteFilm(int pos) {
    if (!head || pos < 1 || pos > size) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    
    if (pos == 1) {
        NodeFilm* p = head;
        head = head->next;
        delete p;
        size--;
        if (!head) tail = NULL;
        cout << "Da xoa phim!" << endl;
        return;
    }
    
    int dem = 1;
    NodeFilm* i = head;
    while (i && dem < pos - 1) {
        i = i->next;
        dem++;
    }
    
    if (i && i->next) {
        NodeFilm* j = i->next;
        i->next = j->next;
        if (j == tail) tail = i;
        delete j;
        size--;
        cout << "Da xoa phim!" << endl;
    }
}

void ListFilm::showList() {
    if (!head) {
        cout << "Danh sach phim trong!\n";
        return;
    }
    cout << "\n" << setw(5) << "STT" << setw(20) << "TEN PHIM" 
         << setw(23) << "THE LOAI" << setw(30) << "PHONG\n";
    cout << string(85, '-') << endl;
    int stt = 1;
    for (NodeFilm* i = head; i != NULL; i = i->next) {
        cout << setw(3) << stt++ 
             << setw(15) << i->data.tenPhim
             << setw(23) << i->data.theLoai 
             << setw(32) << i->data.phong << endl;
    }
}

int ListFilm::length() { 
    return size; 
}

Film* ListFilm::getFilmAt(int pos) {
    if (pos < 1 || pos > size) return NULL;
    int dem = 1;
    for (NodeFilm* i = head; i != NULL; i = i->next) {
        if (dem == pos) return &i->data;
        dem++;
    }
    return NULL;
}

// ================== STRUCT KHACH HANG ==================
struct KhachHang {
    string hoTen;
    string soDienThoai;

    void nhap();
};

void KhachHang::nhap() {
    cout << "\n----- THONG TIN KHACH HANG -----\n";
    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "So dien thoai: ";
    getline(cin, soDienThoai);
}

// ================== STRUCT GHE ==================
struct Ghe {
    string maGhe;
    string loaiGhe;
    double giaGhe;
    KhachHang khachHang;
    Ghe* next;
};

// Các hàm xử lý ghế
bool daChon(Ghe* head, string ghe) {
    for (Ghe* p = head; p; p = p->next)
        if (p->maGhe == ghe) return true;
    return false;
}

void themGhe(Ghe*& head, string ghe, string loai, double gia, KhachHang kh) {
    Ghe* p = new Ghe;
    p->maGhe = ghe;
    p->loaiGhe = loai;
    p->giaGhe = gia;
    p->khachHang = kh;
    p->next = head;
    head = p;
}

bool huyGhe(Ghe*& head, string ghe) {
    if (!head) return false;
    if (head->maGhe == ghe) {
        Ghe* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    for (Ghe* p = head; p->next; p = p->next) {
        if (p->next->maGhe == ghe) {
            Ghe* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            return true;
        }
    }
    return false;
}

double tinhTongTien(Ghe* head) {
    double tong = 0;
    for (Ghe* p = head; p; p = p->next)
        tong += p->giaGhe;
    return tong;
}

int demSoVe(Ghe* head) {
    int count = 0;
    for (Ghe* p = head; p; p = p->next) count++;
    return count;
}

string getLoaiGhe(string maGhe) {
    char hang = maGhe[0];
    if (hang == 'C' || hang == 'F') return "VIP";
    if (hang == 'G' || hang == 'H') return "Couple";
    return "Thuong";
}

double getGiaGhe(string loai, double giaVeCoBan) {
    if (loai == "VIP") return giaVeCoBan * 1.5;
    if (loai == "Couple") return giaVeCoBan * 2.0;
    return giaVeCoBan;
}

void inSoDo(Ghe* danhSachGhe) {
    cout << "\n========== SO DO GHE ==========\n";
    cout << "[ ] = Trong | [X] = Da dat\n";
    cout << "A-B: Thuong | C-F: VIP | G-H: Couple\n\n";
    cout << "    ";
    for (int i = 1; i <= 8; i++) cout << i << "   ";
    cout << endl;

    for (int i = 0; i < 8; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 1; j <= 8; j++) {
            string ma = "";
            ma += char('A' + i);
            ma += to_string(j);
            cout << (daChon(danhSachGhe, ma) ? "[X] " : "[ ] ");
        }
        cout << endl;
    }
}

void hienThiGheDaChon(Ghe* head) {
    if (!head) {
        cout << "\nChua co ghe nao duoc dat.\n";
        return;
    }
    cout << "\n===== DANH SACH GHE DA DAT =====\n";
    cout << setw(10) << "Ma Ghe" << setw(15) << "Loai" 
         << setw(15) << "Gia (VND)" << endl;
    cout << string(40, '-') << endl;
    
    for (Ghe* p = head; p; p = p->next) {
        cout << setw(10) << p->maGhe 
             << setw(15) << p->loaiGhe
             << setw(15) << fixed << setprecision(0) << p->giaGhe << endl;
    }
    cout << string(40, '-') << endl;
    cout << "TONG TIEN: " << tinhTongTien(head) << " VND\n";
}

void inHoaDon(Ghe* head, Film* phim, int suatChieu) {
    if (!head) return;
    
    cout << "\n";
    cout << "========================================\n";
    cout << "         HOA DON BAN VE XEM PHIM       \n";
    cout << "========================================\n";
    cout << "Phim: " << phim->tenPhim << endl;
    cout << "Suat chieu: " << phim->suatChieu[suatChieu] << endl;
    cout << "Phong: " << phim->phong << endl;
    cout << "----------------------------------------\n";
    
    if (head) {
        cout << "Khach hang: " << head->khachHang.hoTen << endl;
        cout << "SDT: " << head->khachHang.soDienThoai << endl;
    }
    
    cout << "----------------------------------------\n";
    cout << setw(10) << "Ghe" << setw(15) << "Loai" 
         << setw(15) << "Gia\n";
    cout << string(40, '-') << endl;
    
    for (Ghe* p = head; p; p = p->next) {
        cout << setw(10) << p->maGhe 
             << setw(15) << p->loaiGhe
             << setw(15) << fixed << setprecision(0) << p->giaGhe << endl;
    }
    
    cout << "========================================\n";
    cout << "TONG TIEN: " << tinhTongTien(head) << " VND\n";
    cout << "========================================\n";
    cout << "   Cam on! Chuc xem phim vui ve!\n";
    cout << "========================================\n";
}

void chonGhe(Ghe*& danhSachGhe, double giaVeCoBan) {
    int luaChon;
    string ghe;
    KhachHang kh;
    bool daNhapKH = false;

    while (true) {
        cout << "\n";
        inSoDo(danhSachGhe);
        hienThiGheDaChon(danhSachGhe);
        
        cout << "\n===== MENU DAT GHE =====\n";
        cout << "1. Chon ghe\n";
        cout << "2. Huy ghe\n";
        cout << "3. Xac nhan va thanh toan\n";
        cout << "0. Quay lai\n";
        cout << "========================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        
        if (luaChon == 1) {
            if (!daNhapKH) {
                kh.nhap();
                daNhapKH = true;
            }
            
            cout << "Nhap ma ghe (vd: A1): ";
            cin >> ghe;
            
            if (!daChon(danhSachGhe, ghe)) {
                string loai = getLoaiGhe(ghe);
                double gia = getGiaGhe(loai, giaVeCoBan);
                themGhe(danhSachGhe, ghe, loai, gia, kh);
                cout << "Da chon ghe " << ghe << " (" << loai << ") - " 
                     << gia << " VND\n";
            } else {
                cout << "Ghe da duoc chon!\n";
            }
            
        } else if (luaChon == 2) {
            cout << "Nhap ma ghe can huy: ";
            cin >> ghe;
            if (huyGhe(danhSachGhe, ghe))
                cout << "Da huy ghe " << ghe << endl;
            else
                cout << "Ghe nay chua duoc chon!\n";
            
        } else if (luaChon == 3) {
            if (!danhSachGhe) {
                cout << "Ban chua chon ghe nao!\n";
            } else {
                cout << "\nXac nhan thanh toan " << tinhTongTien(danhSachGhe) 
                     << " VND? (y/n): ";
                char xacNhan;
                cin >> xacNhan;
                if (xacNhan == 'y' || xacNhan == 'Y') {
                    cout << "Thanh toan thanh cong!\n";
                    cout << "\nNhan Enter de xem hoa don...";
                    cin.ignore();
                    cin.get();
                    return;
                }
            }
        } else if (luaChon == 0) {
            break;
        }
    }
}

// ================== CLASS QUAN LY DOANH THU ==================
class QuanLyDoanhThu {
public:
    double tongDoanhThuVe;
    int tongSoVe;
    double tongChiPhiNhanVien;
    double loiNhuan;
    
    QuanLyDoanhThu();
    void tinhToanDoanhThu(Ghe* ghePhim[50][6], int soPhim);
    void tinhToanChiPhi(ListNhanVien& dsNV);
    void tinhLoiNhuan();
    void xuatBaoCao();
};

// Định nghĩa hàm QuanLyDoanhThu bên ngoài class
QuanLyDoanhThu::QuanLyDoanhThu() {
    tongDoanhThuVe = 0;
    tongSoVe = 0;
    tongChiPhiNhanVien = 0;
    loiNhuan = 0;
}

void QuanLyDoanhThu::tinhToanDoanhThu(Ghe* ghePhim[50][6], int soPhim) {
    tongDoanhThuVe = 0;
    tongSoVe = 0;
    
    for (int i = 0; i < soPhim; i++) {
        for (int j = 0; j < 6; j++) {
            if (ghePhim[i][j]) {
                tongDoanhThuVe += tinhTongTien(ghePhim[i][j]);
                tongSoVe += demSoVe(ghePhim[i][j]);
            }
        }
    }
}

void QuanLyDoanhThu::tinhToanChiPhi(ListNhanVien& dsNV) {
    tongChiPhiNhanVien = dsNV.tinhTongLuong();
}

void QuanLyDoanhThu::tinhLoiNhuan() {
    loiNhuan = tongDoanhThuVe - tongChiPhiNhanVien;
}

void QuanLyDoanhThu::xuatBaoCao() {
    cout << "\n";
    cout << "============================================\n";
    cout << "        BAO CAO DOANH THU RAP PHIM         \n";
    cout << "============================================\n";
    cout << fixed << setprecision(0);
    cout << "\n**DOANH THU BAN VE**\n";
    cout << "Tong so ve da ban: " << tongSoVe << " ve\n";
    cout << "Doanh thu tu ban ve: " << tongDoanhThuVe << " VND\n";
    
    cout << "\n**CHI PHI NHAN SU**\n";
    cout << "Tong luong nhan vien: " << tongChiPhiNhanVien << " VND\n";
    
    cout << "\n**LOI NHUAN**\n";
    cout << "Loi nhuan = " << loiNhuan << " VND\n";
    
    if (loiNhuan > 0) {
        cout << "\n=> Rap dang SINH LOI\n";
    } else if (loiNhuan < 0) {
        cout << "\n=> Rap dang LO\n";
    } else {
        cout << "\n=> Rap HOA VON\n";
    }
    cout << "============================================\n";
}

// ================== UTILITY FUNCTIONS ==================
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "\nNhan Enter de tiep tuc...";
    cin.ignore();
    cin.get();
}

bool isValidSeat(string seat) {
    if (seat.length() < 2 || seat.length() > 3) return false;
    char hang = seat[0];
    if (hang < 'A' || hang > 'H') return false;
    string cot = seat.substr(1);
    try {
        int sotCot = stoi(cot);
        return sotCot >= 1 && sotCot <= 8;
    } catch(...) {
        return false;
    }
}

// ================== MAIN FUNCTION ==================
int main() {
    ListFilm danhSachPhim;
    ListNhanVien danhSachNV;
    QuanLyDoanhThu doanhThu;
    Ghe* ghePhim[50][6] = { NULL };
    int luaChon;

    do {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "   HE THONG QUAN LY RAP CHIEU PHIM     \n";
        cout << "========================================\n";
        cout << "1. Quan ly phim\n";
        cout << "2. Dat ve xem phim\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Bao cao doanh thu\n";
        cout << "0. Thoat\n";
        cout << "========================================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        if (luaChon == 1) {
            // QUAN LY PHIM
            int subChoice;
            do {
                cout << "\n===== QUAN LY PHIM =====\n";
                cout << "1. Them phim moi\n";
                cout << "2. Xoa phim\n";
                cout << "3. Xem danh sach phim\n";
                cout << "0. Quay lai\n";
                cout << "========================\n";
                cout << "Nhap lua chon: ";
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    Film f;
                    f.nhap();
                    danhSachPhim.addLast(f);
                    cout << "Da them phim thanh cong!\n";
                } 
                else if (subChoice == 2) {
                    danhSachPhim.showList();
                    int pos;
                    cout << "Nhap vi tri phim can xoa: ";
                    cin >> pos;
                    danhSachPhim.deleteFilm(pos);
                } 
                else if (subChoice == 3) {
                    danhSachPhim.showList();
                    cout << "\nTong so phim: " << danhSachPhim.size << endl;
                }
            } while (subChoice != 0);
        }
        else if (luaChon == 2) {
            // DAT VE
            if (danhSachPhim.size == 0) {
                cout << "Khong co phim nao!\n";
                continue;
            }

            danhSachPhim.showList();
            int posPhim;
            cout << "\nNhap so thu tu phim: ";
            cin >> posPhim;
            
            Film* phim = danhSachPhim.getFilmAt(posPhim);
            if (!phim) {
                cout << "Khong hop le!\n";
                continue;
            }

            phim->xuat();
            
            cout << "\n===== CAC SUAT CHIEU =====\n";
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << ". " << phim->suatChieu[i] 
                     << " - " << phim->giaVe[i] << " VND\n";
            }

            int chonSuat;
            cout << "\nChon suat chieu (1-6): ";
            cin >> chonSuat;
            
            while (chonSuat < 1 || chonSuat > 6) {
            cout << "Khong hop le! Vui long nhap lai (1-6): ";
            cin >> chonSuat;
            }

            chonGhe(ghePhim[posPhim][chonSuat - 1], phim->giaVe[chonSuat - 1]);
            
            if (ghePhim[posPhim][chonSuat - 1]) {
                inHoaDon(ghePhim[posPhim][chonSuat - 1], phim, chonSuat - 1);
            }
        }
        else if (luaChon == 3) {
            // QUAN LY NHAN VIEN
            int nvChoice;
            do {
                cout << "\n===== QUAN LY NHAN VIEN =====\n";
                cout << "1. Them nhan vien\n";
                cout << "2. Xoa nhan vien\n";
                cout << "3. Sua thong tin nhan vien\n";
                cout << "4. Xem danh sach nhan vien\n";
                cout << "0. Quay lai\n";
                cout << "==============================\n";
                cout << "Nhap lua chon: ";
                cin >> nvChoice;

                if (nvChoice == 1) {
                    int n;
                    cout << "\nNhap so nhan vien can them: ";
                    cin >> n;
                    
                    int demThanhCong = 0;
                    for (int i = 0; i < n; i++) {
                        cout << "\n--- NHAN VIEN THU " << (i + 1) << " ---";
                        NhanVien nv;
                        nv.nhap();
                        
                        // Thêm vào danh sách (có kiểm tra trùng ID)
                        if (!danhSachNV.kiemTraIDTonTai(nv.ID)) {
                            danhSachNV.addNV(nv);
                            demThanhCong++;
                        } else {
                            cout << "\n❌ ID " << nv.ID << " da ton tai! Bo qua nhan vien nay.\n";
                            cout << "Ban co muon nhap lai? (y/n): ";
                            char choice;
                            cin >> choice;
                            if (choice == 'y' || choice == 'Y') {
                                i--;  // Lặp lại vòng này
                            }
                        }
                    }
                    
                    cout << "\n✅ Da them thanh cong " << demThanhCong << "/" << n << " nhan vien!\n";
                    pause();
                }
                else if (nvChoice == 2) {
                    int id;
                    cout << "\nNhap ID can xoa: ";
                    cin >> id;
                    danhSachNV.deleteNV(id);
                    pause();
                }
                else if (nvChoice == 3) {
                    int id;
                    cout << "\nNhap ID can sua: ";
                    cin >> id;
                    danhSachNV.editNV(id);
                    pause();
                }
                else if (nvChoice == 4) {
                    danhSachNV.show();
                    pause();
                }
            } while (nvChoice != 0);
        }
        else if (luaChon == 4) {
            // BAO CAO DOANH THU
            doanhThu.tinhToanDoanhThu(ghePhim, danhSachPhim.size);
            doanhThu.tinhToanChiPhi(danhSachNV);
            doanhThu.tinhLoiNhuan();
            doanhThu.xuatBaoCao();
            pause();
        }
    } while (luaChon != 0);

    cout << "\nCam on da su dung he thong!\n";
    return 0;
}