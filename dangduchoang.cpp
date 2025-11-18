//Quan li phim va suat chieu
//1.them,xoa (ten phim, the loai, thoi luong)
//2.Tao lich danh sach chieu(sap xep phim vao cac phong, thoi gian chieu)
#include<iostream>
#include<iomanip>
using namespace std;
class Film{
public:
    string tenPhim,theLoai;
    int thoiLuong,phong;
    string suatChieu[6];
    double giaVe[6];
    Film();
    void nhap();
    void xuat();
};
Film::Film() {
    tenPhim = theLoai = "";
    thoiLuong = phong = 0;
    for (int i = 0; i < 6; i++) {
        suatChieu[i] = "";
        giaVe[i] = 70000;
    }
}
void Film::nhap(){
    cout<<"Nhap ten phim: ";
    getline(cin,tenPhim);
    cout<<"Nhap the loai: ";
    getline(cin,theLoai);
    cout<<"Nhap thoi luong: ";
    cin>>thoiLuong;
    cin.ignore();
    cout<<"Nhap phong chieu: ";
    cin>>phong;
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
void Film::xuat(){
    cout<<"Ten phim: "<<tenPhim<<endl;
    cout<<"The loai: "<<theLoai<<endl;
    cout<<"Thoi luong: "<<thoiLuong<<endl;
    cout<<"Phong chieu: "<<phong<<endl;
}
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
        if (!head) {
        tail = NULL;
        cout << "Da xoa phim!" << endl;
        return;
        }
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
void ListFilm::showList(){
    if (!head){
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
int main() {
    ListFilm l;
    Film f;
    int n;
    cout<<"Nhap so luong phim: "<<endl;
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++) {
        cout <<"Nhap phim thu: "<<i+1<<endl;
        f.nhap();
        l.addLast(f);
    }
    cout <<"\nDanh sach phim vua nhap:\n";
    l.showList();
    int pos;
    cout <<"\nNhap vi tri phim muon xoa:\n";
    cin >> pos;
    l.deleteFilm(pos);
    cout << "\nDanh sach phim sau khi xoa:\n";
    l.showList();
    cout << "\nSo luong phim hien tai: " << l.length() << endl
    return 0;
}



