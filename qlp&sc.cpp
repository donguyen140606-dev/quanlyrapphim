//Quan li phim va suat chieu
//1.them,xoa (ten phim, the loai, thoi luong)
//2.Tao lich danh sach chieu(sap xep phim vao cac phong, thoi gian chieu)
#include<iostream>
using namespace std;
class Film{
public:
    string tenPhim,theLoai,lichChieu,gioChieu;
    int thoiLuong,phong;
    void nhap();
    void xuat();
};
void Film::nhap(){
    cout<<"Nhap ten phim: ";
    getline(cin,tenPhim);
    cout<<"Nhap the loai: ";
    getline(cin,theLoai);
    cout<<"Nhap thoi luong: ";
    cin>>thoiLuong;
    cin.ignore();
    cout<<"Nhap lich chieu: ";
    getline(cin,lichChieu);
    cout<<"Nhap gio chieu: ";
    getline(cin,gioChieu);
    cout<<"Nhap phong chieu: ";
    cin>>phong;
    cin.ignore();
}
void Film::xuat(){
    cout<<"Ten phim: "<<tenPhim<<endl;
    cout<<"The loai: "<<theLoai<<endl;
    cout<<"Thoi luong: "<<thoiLuong<<endl;
    cout<<"Lich chieu: "<<lichChieu<<endl;
    cout<<"Gio chieu: "<<gioChieu<<endl;    
    cout<<"Phong chieu: "<<phong<<endl;
}
struct node{
    Film data;
    node *next;
};
class listFilm{
public:
    node *head,*tail;
    int size;
    listFilm();
    node* createNode(Film n); //tao node moi
    int length(); // kiem tra so luong phim
    void addFirst(Film n);  //them vao dau danh sach
    void addLast(Film n); //them vao cuoi danh sach
    void insertFilm(Film n,int pos); //chen phim vao vi tri pos
    void xoaDau();  //xoa phim o dau danh sach
    void xoaCuoi(); //xoa phim o cuoi danh sach
    void deleteFilm(int pos); //xoa phim o vi tri pos
    void showList(); //hien thi danh sach phim
};
listFilm::listFilm(){
    head = tail = NULL;
    size=0;
}
node* listFilm::createNode(Film n){
    node *p = new node();
    p->data = n;
    p->next = NULL;
    return p;
}
// Them phim vao dau danh sach
void listFilm::addFirst(Film n){
    node *p=createNode(n);
    if(p==NULL)
      return;
    else if(head==NULL){
        head=tail=p;
        size+=1;
    }
    else{
        p->next=head;
        head=p;
        size+=1;
    }
}
// Them phim vao cuoi danh sach
void listFilm::addLast(Film n){
    node *p=createNode(n);
    if(p==NULL){
       return;
    }
    else if(head==NULL){
        head=tail=NULL;
    }
    else{
        tail->next=p;
        tail=p;
        size+=1;
}
}
// Chen phim vao vi tri pos
void listFilm::insertFilm(Film n, int pos){
    node *p = createNode(n);
    if(p==NULL)
        return;
    else if(head==NULL){
        head=tail=p;
        size+=1;;
    }
    else if(pos==1)
        addFirst(n);
    else if(pos>size)
        addLast(n);
    else{
        int dem=0;
    node *i,*j;
    for(i=head;i!=NULL;i=i->next){
        dem++;
        if(dem==(pos-1)){
        break;
    }
}
    j=i->next; //j la node o vi tri pos
    i->next=p; //chen p vao sau i
    p->next=j; //noi p voi j
    size+=1;
    }
}
// Xoa phim o dau danh sach
void listFilm::xoaDau(){
    if(head==NULL){
        return;
    }
    else{
        node *p=head;
        head=head->next;
        delete p;
        size-=1;
    }
}
// Xoa phim o cuoi danh sach
void listFilm::xoaCuoi(){
    if(head==NULL)
       return;
    else if(head==tail){
        delete head;
        head=tail=NULL;
        size-=1;
    }
    else{
        for(node *i=head;i!=NULL;i=i->next){
            if(i->next==tail){
                delete tail;
                tail=i;
                tail->next=NULL;
                size-=1;
            }
        }
    }
}
// Xoa phim o vi tri pos
void listFilm::deleteFilm(int pos){
    if(head==NULL)
       return;
    else if(pos==1)
        xoaDau();
    else if(pos==size)
        xoaCuoi();
    else{
        int dem=0; 
        node *i,*j;
        for(i=head;i!=NULL;i=i->next){ 
            dem++;
            if(dem==(pos-1)) 
               break;
        }
        j=i->next; //j la node o vi tri pos
        i->next=j->next; //bo qua j
        delete j; //    xoa j
        size-=1;
    }
}
int listFilm::length(){
    return size;
}
void listFilm::showList(){
    for(node *i=head;i!=NULL;i=i->next){
        i->data.xuat();
        cout<<"-----------------"<<endl;
    }
}
int main(){
    Film f;
    listFilm l;
    f.nhap();
    l.insertFilm(f,1);
    f.nhap();
    l.insertFilm(f,2);
    f.nhap();
    l.insertFilm(f,3);
    f.nhap();
    l.insertFilm(f,4);
    l.deleteFilm(4);
    l.showList();
    cout<<"So luong phim :"<<l.length();
}
