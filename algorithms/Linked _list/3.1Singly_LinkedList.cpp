// Danh sách liên kết
/*
	- Danh sách liên kết là danh sách mà mỗi phần tử trong danh sách là 1 Node trong Node có 2 thành phần
	  + Data : chứa dữ liệu
	  + Con trỏ : liên kết giữa các Node với nhau
	- Danh sách liên kết các Node không cần nằm liên tiếp nhau trong bộ nhớ máy tính nhưng có thể liên kết
	với nhau bằng con trỏ
	- Danh sách liên kết
		- Ưu điểm: + Việc thêm và xóa đơn giản chỉ cần thay đổi mối liên kết giữa các node với nhau
				   + Không cần biết trước số lượng phần tử
				   + Các phần tử không cần nằm liên tiếp nhau trong bộ nhớ máy tính. Vì vậy khắc phục được
					 tình trạng phân mảnh bộ nhớ
		- Nhược điểm: + Có thể truy xuất đến từng phần tử của mảng thông qua toán tử chỉ số mà nó phải duyệt
						tuần tự thông qua các phần tử
					  + Tốn bộ nhớ (do vừa lưu thông tin data và phải lưu thêm con trỏ nữa)
*/

// Danh sách liên kết đơn
/*  
	- Danh sách liên kết đơn là cấu trúc dữ liệu tuyến tính luôn có 1 chiều đi từ trái qua phải
	- Danh sách liên kết được quản lý bời 2 node pHead(node đầu), pTail(node cuối)
*/

#include<iostream>
#include<math.h>
#include<string>
using namespace std;

// Khai báo cấu trúc 1 Node
struct node
{
	int data; // dữ liệu chứa trong 1 node
	struct node* pNext; // con trỏ dùng để liên kết giữa các node với nhau
};
typedef struct node NODE; // thay thế tên node thành NODE để khi khai báo không phải thêm từ struct 
                          // (VD: struct node x -> NODE x)

// Kháo báo cấu trúc danh sách liên kết đơn
struct list
{
	NODE* pHead; // node đàu danh sách
	NODE* pTail; // node cuối danh sách
};
typedef struct list LIST; // thay thế struct list thành LIST

/* 1.CÁC THAO TÁC KHỞI TẠO */
// 1.1) Init (khởi tạo danh sách, ban đầu chưa có phần tử)
void Init(LIST& l)
{
	l.pHead = NULL; // chưa quản lý node nào lên trỏ tới null
	l.pTail = NULL;
}
// 1.2) Khởi tạo 1 NODE
NODE* InitNODE(int x) // vì 1 NODE là 1 con trỏ lên kiểu trả về cũng là 1 con trỏ
{
	NODE* p = new NODE; // cấp phát vùng nhớ cho NODE p
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat !" << endl;
		return NULL;
	}
	p->data = x; // truyền giá trị x vào cho data
	p->pNext = NULL; // chưa biết node liên kết tiếp theo lên gán bằng NULL
	return p; // trả về NODE p vừa mới khởi tạo
}

/* 2.BỔ SUNG 1 PHẦN TỬ MỚI VÀO DANH SÁCH */
// 2.1) InsertFirst (thêm NODE vào đầu danh sách)
void InsertFirst(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // NODE đầu là NODE cuối và là p
	}
	else
	{
		p->pNext = l.pHead; // cho con trỏ của NODE cần thêm là NODE p liên kết đến NODE đầu pHead
		l.pHead = p; // cập nhật lại pHead chính là NODE p
	}
}
// 2.2) InsertLast (thêm NODE vào cuối danh sách)
void InsertLast(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // NODE đầu là NODE cuối và là p
	}
	else
	{
		l.pTail->pNext = p; // cho con trỏ của pTail liên kết với node p
		l.pTail = p; // cập nhật lại p chính là NODE pTail
	}
}
// 2.3) InsertAfter (them node p sau node q)
void InsertAfter(LIST& l, NODE* p)
{
	int x; cout << "(+) Nhap gia tri node q: "; cin >> x;
	NODE* q = InitNODE(x);
	// Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q => bài toán trở thành thêm vào cuối
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		InsertLast(l, p);
	}
	else
	{
		// duyệt từ đầu danh sách đến cuối danh sách để tìm node q
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (q->data == k->data) // nếu node q có tồn tại thì
			{         
				// khởi tạo node h mới để thêm vào sau node q (để tránh trường hợp tồn tại 2 node q)
				NODE* h = InitNODE(p->data); 
				// node g là node trung gian giữ mối liên kết đến node sau node q => cho node g trỏ đến node nằm sau node q
				NODE* g = k->pNext; 
				h->pNext = g; // B1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node h đến  
				k->pNext = h; // B2: Tạo mối liên kết tử node q đến node h <=> chính là node k đến node h
			} 
		}
	}
}
// 2.4) InsertAfter (them node p truoc node q)
void InsertBefore(LIST& l, NODE* p)
{
	int x;
	cout << "(+) Nhap gia tri node q: "; cin >> x;
	NODE* q = InitNODE(x); // khởi tạo 1 node q
	// Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q => bài toán trở thành thêm vào cuối
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		InsertLast(l, p);
	}
	else 
	{
		NODE* g = new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sach
		// duyệt từ đầu danh sách đến cuối danh sách để tìm node q
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			// nếu node q có tồn tại thì
			if (q->data == k->data)
			{
				NODE* h = InitNODE(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h 
				h->pNext = k; // B1: Tao moi lien ket ty node h tro den node k <=> cung chinh la node tro deh node q
				g->pNext = h; // B2: Tao moi lien ket ty node g tro den node h <=> chinh la node k den node h
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
// 2.5) InsertPosition (thêm node p vào vị trí bất kì trong danh sách liên kết)
void InsertPosition(LIST &l, NODE *p, int pos, int n)
{
	if (l.pHead == NULL || pos == 1) // nếu danh sách đang rỗng hoặc vị trí cần thêm ở đầu thì thêm node p vào đầu
		InsertFirst(l, p);
	else if (pos == n + 1) // nếu vị trí = số lượng phần tử + 1 thì thêm vào cuối
		InsertLast(l, p);
	else // vị trí nằm trong đoạn [2,n]
	{
		int count = 0; // xác định vị trí cần thêm
		NODE* g = new NODE;
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí cần thêm node p vào
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			count++;
			if (count == pos)
			{
				NODE* h = InitNODE(p->data);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}

/* 3. LOẠI BỎ 1 PHẦN TỬ RA KHỎI DANH SÁCH LIÊN KẾT ĐƠN*/
// 3.1) DeleteFirst (Xóa phần tử đầu danh sách)
void DeleteFirst(LIST &l)
{
	if (l.pHead == NULL) // nếu danh sách rỗng
		return; // kết thúc luôn
	else
	{
		NODE* p = l.pHead; // node p là node sẽ xóa
		l.pHead = l.pHead->pNext; // cập nhật lại l.pHead là phần tử kế tiếp
		delete p;
	}
}
// 3.2) DeleteLast (Xóa node p cuối danh sách)
void DeleteLast(LIST &l)
{
	if (l.pHead == NULL) // nếu danh sách rỗng
		return; // kết thúc luôn
	else if (l.pHead->pNext == NULL) // nếu danh sách có 1 phần tử
	{
		DeleteFirst(l);
		return;
	}
	else
	{
		// duyệt từ đầu danh sách đến phần tử kế cuối 
		for (NODE* k = l.pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == l.pTail) // phát hiện phần tử kế cuối
			{
				delete l.pTail; // xóa phần tử cuối
				k->pNext = NULL; // cho con trỏ của node kế cuối trỏ đến vùng nhớ null
				l.pTail = k; // cập nhật lại l.pTail
				return;
			}
		}
		NODE* p = l.pHead; // node p là node sẽ xóa
		l.pHead = l.pHead->pNext; // cập nhật lại l.pHead là phần tử kế tiếp
		delete p;
	}
}
// 3.3) DeleteAfter (Xóa node nằm sau node q trong danh sách)
void DeleteAfter(LIST &l, NODE *q)
{
	int count = 0; // đếm số lần xuất hiện của node q
	// duyệt từ đầu danh sách đến phần tử cuối để tìm node q
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data) // phát hiện node q
		{
			count++;
			NODE* g = k->pNext; // node g chính là node nằm sau node k (nằm sau node q)
			k->pNext = g->pNext; // cập nhật mối liên kết giữ node k (node q) với node sau node g
			delete g; // xóa node nằm sau node q
		}
	}
	if (count == 0)
		cout << "(!) Khong co node can xoa trong danh sach !!!" << endl;
}
// 3.4) DeleteBefore (Xóa node nằm trước node q trong danh sách)
void DeleteBefore(LIST& l, NODE *q)
{
	int count = 0; // đếm số lần xuất hiện của node q
	// duyệt từ đầu danh sách đến phần tử cuối để tìm node q
	NODE* h = NULL;
	for (NODE* k = l.pHead; k->pNext != NULL;)
	{
		if (k->pNext->data == q->data && k == l.pHead) // nếu node là phần tử thứ 2 trong danh sách thì sẽ dùng xóa đầu
		{	
			count++;
			l.pHead = l.pHead->pNext;
			delete k;
			k = l.pHead;
		}
		else if (k->pNext->data == q->data)
		{
			count++;
			h->pNext = k->pNext;
			delete k;
			k = h;
			h = k;
			k = k->pNext;
		}
		else
		{
			h = k;
			k = k->pNext;
		}
	}
	if (count == 0)
		cout << "(!) Khong co node can xoa trong danh sach !!!" << endl;
}
// 3.5) DeleteNode (Xóa node bất kì trong danh sach)
void DeleteNode(LIST &l, int x)
{
	int count = 0; // đếm số lần xuất hiện của node q
	if (l.pHead == NULL) // nếu danh sách rỗng thì không làm gì
		return;
	else if (l.pHead->data == x) // nếu node cần xóa nằm đầu danh sách
	{
		DeleteFirst(l);
		return;
	}
	else if (l.pTail->data == x) // nếu node cần xóa nằm cuoi danh sách
	{
		DeleteLast(l);
		return;
	}
	else
	{
		NODE* g = new NODE; // node g là node trỏ đến node nằm trước node cần xóa
		// duyệt từ đầu danh sách liên kết
		for (NODE* k = l.pHead; k != NULL;)
		{
			if (k->data == x) 
			{
				NODE* h = k;     // node h để giữ liên kết với node k và sẽ giải phóng nó sau khi di chuyển k tiến lên 
				g->pNext = h->pNext; // nối node 
				k = k->pNext;    // di chuyển k tiến lên 
				delete h;        // giải phóng node h cũng chính là node mà ta cần xoá 
			}
			else 
			{
				g = k;
				k = k->pNext;
			}
		}
	}
	if (count == 0)
		cout << "(!) Khong co node can xoa trong danh sach !!!" << endl;
}

/* 4. CÁC THAO TÁC KHÁC*/
// 4.1) Search (tìm kiếm phần tử max trong danh sách)
int searchMax(LIST l)
{
	int max = l.pHead->data; // giả sử node đầu là max
	for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext) // duyệt từ phần tử thứ 2
	{
		if (max < k->data)
			max = k->data; // cập nhật lại giá trị max
	}
	return max;
}

// Hàm xuất danh sách liên kết đơn
void output(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << ", ";
	}
	cout << endl << endl;
}

void Menu(LIST& l)
{
	int options;
	do
	{
		cout << "\t____________________________MENU_________________________________" << endl
			 << "\t|1. Them node vao danh sach va xuat danh sach                    |" << endl
			 << "\t|2. Them node p vao sau node q danh sach lien ket don            |" << endl
			 << "\t|3. Them node p vao truoc node q danh sach lien ket don          |" << endl
			 << "\t|4. Them node p vao vi tri bat ki trong danh sach                |" << endl
			 << "\t|5. Xoa node p dau danh sach                                     |" << endl
			 << "\t|6. Xoa node p cuoi danh sach                                    |" << endl
		 	 << "\t|7. Xoa node nam sau node q trong danh sach                      |" << endl
			 << "\t|8. Xoa node nam truoc node q trong danh sach                    |" << endl
			 << "\t|9. Xoa node p bat ki trong danh sach                            |" << endl
			 << "\t|10. Tim gia tri lon nhat trong danh sach lien ket don           |" << endl
			 << "\t|11. Sap xep cac phan tu trong danh sach bang Selection Sort     |" << endl
			 << "\t|0. Thoat !!!                                                    |" << endl
			 << "\t|________________________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
			case 1:
			{
				int n; cout << "(+) Nhap so luong node can them: "; cin >> n;
				for (int i = 1; i <= n; i++)
				{
					int x;
					cout << "Nhap gia tri node thu " << i << " la: "; cin >> x;
					NODE* p = InitNODE(x); // khởi tạo 1 cái node số nguyên
					InsertFirst(l, p); // 2.1) thêm node p vào đầu
					//InsertLast(l, p); // 2.2) thêm node p vào cuối
				}
				cout << "=> Danh sach lien ket don la : "; output(l);
				break;
			}
			case 2: // 2.3)
			{
				int x; cout << "(+) Nhap gia tri node p can them: "; cin >> x;
				NODE* p = InitNODE(x);
				InsertAfter(l, p);
				cout << "2.3) => Danh sach lien ket don sau khi them node p sau node q la: "; output(l);
				break;
			}
			case 3: // 2.4)
			{
				int x; cout << "(+) Nhap gia tri node p can them: "; cin >> x;
				NODE* p = InitNODE(x);
				InsertBefore(l, p);
				cout << "2.4) => Danh sach lien ket don sau khi them node p truoc node q la : "; output(l);
				break;
			}
			case 4: // 2.5)
			{
				int n = 0;
				// vòng lặp lấy số lượng node trong danh sách
				for (NODE* k = l.pHead; k != NULL; k = k->pNext)
				{
					n++;
				}
				// khởi tạo giá trị cho node p
				int x; cout << "(+) Nhap gia tri node p can them: "; cin >> x;
				NODE* p = InitNODE(x);
				// nhập vị trí cần thêm cho node p
				int pos;
				do
				{
					cout << "(+) Nhap vi tri can them node: "; cin >> pos;
					if (pos < 1 || pos > n + 1)
					{
						cout << "(+) Nhap lai vi tri phai nam trong doan [1," << n + 1 << "]: ";
					}
				} while (pos < 1 || pos > n + 1);
				InsertPosition(l, p, pos, n);
				cout << "=> Danh sach lien ket don sau khi them node p vao vi tri " << pos << " la : "; output(l);
				break;
			}
			case 5: // 3.1
			{
				DeleteFirst(l);
				cout << "=> Danh sach lien ket don sau khi xoa node dau danh sach la : "; output(l);
				break;
			}
			case 6: // 3.2
			{
				DeleteLast(l);
				cout << "=> Danh sach lien ket don sau khi xoa node cuoi danh sach la : "; output(l);
				break;
			}
			case 7: // 3.3
			{
				int x; cout << "(+) Nhap node q = "; cin >> x;
				NODE* q = InitNODE(x);
				DeleteAfter(l, q);
				cout << "=> Danh sach lien ket don sau khi xoa node sau node " << x << " la : "; output(l);
				break;
			}
			case 8: // 3.4
			{
				int x; cout << "(+) Nhap node q = "; cin >> x;
				NODE* q = InitNODE(x);
				DeleteBefore(l, q);
				cout << "=> Danh sach lien ket don sau khi xoa node truoc node " << x << " la : "; output(l);
				break;
			}
			case 9: // 3.5
			{
				int x; cout << "(+) Nhap node can xoa: "; cin >> x;
				DeleteNode(l, x);
				cout << "=> Danh sach lien ket don sau khi xoa node " << x << " trong danh sach la : "; output(l);
				break;
			}
			case 10:
			{
				cout << "4.1) => Gia tri lon nhat trong danh sach la: " << searchMax(l) << endl;
				break;
			}
			case 11:
			{
				
				break;
			}
			case 0:
			{
				cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
				break;
			}
			default:
				cout << "\t(!) Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
				cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
				if (options == 0)
					cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
				break;
		}
	} while (options != 10);
}

int main()
{
	LIST l;
	Init(l); // luôn luôn gọi hàm khởi tạo danh sách liên kết đơn trước khi thao tác với danh sách
	Menu(l);
	return 0;
}