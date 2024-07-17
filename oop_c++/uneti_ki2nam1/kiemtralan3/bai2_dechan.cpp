// Nguyen Huu Hoang - 2113100320 - de chan
 #include<iostream>
 #include<fstream>
 using namespace std;
 
void nhapMang(int a[],int &n) 
{
	cout<<"NHAP SO LIEU "<<n<<" PHAN TU" << endl;
	for (int i=0; i<n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i]; 
	} 
	cout << endl; 
}
void ghiFile(char b[], int a[], int n)
{
	fstream f(b,ios::out);
	cout << "Ghi tep thanh cong !" << endl;
	for(int i=0; i<n; i++)
		f << a[i] << "   ";	 
	f.close();	
} 
void docFile(int a[],int n)
{
	int b; 
	ifstream f("input.txt",ios::in);
	if(!f) 
	{
		cout << "Khong ton tai file input.txt !" << endl; 
	} 
	cout << "Doc file input.txt" << endl; 
	for(int i=0; i<n; i++)
	{
		f >> b;
		cout << b << "   "; 
	}
	f.close(); 
} 
float tbPhanTuLe(int a[], int n)
{
	float S = 0; 
	for(int i=0; i<n; i++)
		S += a[i];	
	return S/n; 
}
bool kiemTraSNT(int n)
{
	int count = 0; 
	for(int i=1;i<=n;i++)
	{
		if(n % i == 0)
			count++;
	}
	if(count == 2)
		return 1;
	return 0;			 
}
void soNguyenTo(int a[],int n)
{
	int count = 0; 
	cout<<"CAC SO NGUYEN TO TRONG MANG CO "<<n<<" PHAN TU" << endl;
	for(int i=0; i<n; i++)
	{
		if(kiemTraSNT(a[i]))
			count++;
	}
	cout << "Co "<<count<<" so nguyen to trong mang" << endl;
	for(int i=0; i<n; i++)
	{
		if(kiemTraSNT(a[i]))
			cout << a[i] << "   ";
	}
	fstream f("output.txt",ios::out);
	f << "Co " << count <<" so nguyen to trong mang";
	for(int i=0; i<n; i++)
	{
		if(kiemTraSNT(a[i]))
			f << a[i] << "   ";
	}
	f.close();				 
} 
int main()
{
	cout << "Nhap so luong phan tu cua mang: ";
	int n;
	cin >> n;
	int a[n];
	nhapMang(a,n); 
	ghiFile("input.txt",a,n); 
	docFile(a,n); 
	cout << endl;
	cout << "Trung binh cua "<<n<<" phan tu co trong mang la: "<<tbPhanTuLe(a,n)<<endl; 
	soNguyenTo(a,n);
	cout << endl; 
	return 0;
}
