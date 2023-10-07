#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef char string[100];

typedef struct
{
	string nama;
	float berat;
}Barang;

typedef struct
{
	string nama, telp, tanggal;
	int noRek, PIN;
	double saldo;
	Barang B[3];
}Nasabah;

void initData (Nasabah N[]);
int cekKosong (Nasabah N[]);
int angkaRandom (int max, int min);
int cariTelepon (Nasabah N[], string noTelp);
int cariRekening (Nasabah N[], int noRek);
void tampilData (Nasabah N[]);
void tampilDataSearch (Nasabah N[], int indeks);
void hapusRekening (Nasabah N[], int indeks);
int cekKosongBarang (Nasabah N[], int indeks);
int cariBarang (Nasabah N[], int indeks, string barang);
void hapusBarang (Nasabah N[], int indeks, int subIndeks);
double hitungTarikSaldo (Nasabah N[], int indeks, double tarik);
double hitungSetorSaldo (Nasabah N[], int indeks, double tarik);

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	Nasabah N[5];
	int menu, subMenu, indeks, subIndeks, noRek, pin;
	string noTelp, barang;
	double tarik;
	
	initData(N);
	
	do
	{
		system("cls");
		printf("\n\t\t ===[ BANK CENTRAL ATMA ]===");
		printf("\n\t [1] Buka Rekening");
		printf("\n\t [2] Info Rekening");
		printf("\n\t [3] Update Rekening");
		printf("\n\t [4] Tutup Rekening");
		printf("\n\t [5] Input Barang");
		printf("\n\t [6] Ambil Barang");
		printf("\n\t ===================================");
		printf("\n\t [7] Tarik Saldo");
		printf("\n\t [8] Setor Tunai");
		printf("\n\t ===================================");
		printf("\n\t [0] Exit");
		printf("\n\n\t >>> "); scanf("%d", &menu);
		
		system("cls");
		switch(menu)
		{
			case 1:
				if(cekKosong(N) != -1)
				{
					indeks = cekKosong(N);
					printf("\n\t\t Nasabah ke %d \n", indeks+1);
					do
					{
						printf("\n\t Masukan Nama Nasabah \t\t: "); fflush(stdin); gets(N[indeks].nama);
						if(strlen(N[indeks].nama) == 0 || strcmp(N[indeks].nama, "-") == 0)
						{
							printf("\n\t\t [!] Nama Tidak Boleh Kosong \n");
						}
						else
						{
							break;
						}
					}while(true);
					
					do
					{
						printf("\n\t Masukkan Nomor Telepon Nasabah : "); fflush(stdin); gets(noTelp);
						if(strlen(noTelp) < 10 || strlen(noTelp) > 13)
						{
							printf("\n\t\t [!] Nomor Telepon Harus 10-13 Digit \n");
						}
						else if(cariTelepon (N, noTelp) != -1)
						{
							printf("\n\t\t [!] Nomor Telepon sudah pernah diinput sebelumnya");
						}
						else
						{
							strcpy(N[indeks].telp, noTelp);
						}
					}while(strcmp(N[indeks].telp, "-") == 0);
					
					do
					{
						printf("\n\t Masukkan Tanggal Lahir Nasabah : "); fflush(stdin); gets(N[indeks].tanggal);
						if(strlen(N[indeks].tanggal) == 0 || strcmp(N[indeks].tanggal, "-") == 0)
						{
							printf("\n\t\t [!] Tanggal Lahir Tidak Boleh Kosong \n");
						}
						else
						{
							break;
						}
					}while(true);
					
					do
					{
						noRek = angkaRandom (9999, 1000);
					}while(cariRekening (N, noRek) != -1);
					N[indeks].noRek = noRek;
					printf("\n\t No. Rekening Anda \t\t: %d", N[indeks].noRek); 
					
					do
					{
						printf("\n\t Masukkan PIN \t\t\t: "); scanf("%d", &N[indeks].PIN);
						if(N[indeks].PIN < 1000 || N[indeks].PIN > 9999)
						{
							printf("\n\t\t [!] PIN harus 4 digit \n");
						}
						else
						{
							break;
						}
					}while(true);
					
					do
					{
						printf("\n\t Masukkan Saldo \t\t: "); scanf("%lf", &N[indeks].saldo);
						if(N[indeks].saldo < 100000)
						{
							printf("\n\t\t [!] Minimal Input Saldo Rp 100.000");
						}
						else
						{
							break;
						}
					}while(true);
					
					printf("\n\t\t [!] Input Berhasil [!]");
				}
				else
				{
					printf("\n\t\t [!] Data Penuh");
				}
			break;
			
			case 2:
				if(cekKosong(N) != 0)
				{
					do
					{
						system("cls");
						printf("\n\t ===[ Tampil Rekening ]===");
						printf("\n\t [1] Seluruh");
						printf("\n\t [2] Salah Satu");
						printf("\n\t =========================");
						printf("\n\t [0] Main Menu");
						printf("\n\n\t >>> "); scanf("%d", &subMenu);
						
						switch(subMenu)
						{
							case 1:
								tampilData(N);
							break;
							
							case 2:
								printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
								if(cariRekening (N, noRek) != -1)
								{
									indeks = cariRekening (N, noRek);
									tampilDataSearch (N, indeks);
								}
								else
								{
									printf("\n\t\t [!] Data Tidak Ditemukan");
								}
							break;
							
							case 0:
								printf("\n\t\t Kembali ke Main Menu");
							break;
							
							default:
								printf("\n\t\t [!] Menu tidak tersedia");
							break;
						}getch();
					}while(subMenu != 0);
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 3:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							do
							{
								printf("\n\t Masukan Nama Nasabah \t\t: "); fflush(stdin); gets(N[indeks].nama);
								if(strlen(N[indeks].nama) == 0 || strcmp(N[indeks].nama, "-") == 0)
								{
									printf("\n\t\t [!] Nama Tidak Boleh Kosong \n");
								}
								else
								{
									break;
								}
							}while(true);
							
							do
							{
								printf("\n\t Masukkan Nomor Telepon Nasabah : "); fflush(stdin); gets(noTelp);
								if(strlen(noTelp) < 10 || strlen(noTelp) > 13)
								{
									printf("\n\t\t [!] Nomor Telepon Harus 10-13 Digit \n");
								}
								else if(cariTelepon (N, noTelp) != -1)
								{
									printf("\n\t\t [!] Nomor Telepon sudah pernah diinput sebelumnya");
								}
								else
								{
									strcpy(N[indeks].telp, noTelp);
								}
							}while(strcmp(N[indeks].telp, "-") == 0);
							
							do
							{
								printf("\n\t Masukkan Tanggal Lahir Nasabah : "); fflush(stdin); gets(N[indeks].tanggal);
								if(strlen(N[indeks].tanggal) == 0 || strcmp(N[indeks].tanggal, "-") == 0)
								{
									printf("\n\t\t [!] Tanggal Lahir Tidak Boleh Kosong \n");
								}
								else
								{
									break;
								}
							}while(true);
							
							printf("\n\t No. Rekening Anda \t\t: %d", N[indeks].noRek); 
							
							do
							{
								printf("\n\t Masukkan PIN \t\t\t: "); scanf("%d", &N[indeks].PIN);
								if(N[indeks].PIN < 1000 || N[indeks].PIN > 9999)
								{
									printf("\n\t\t [!] PIN harus 4 digit \n");
								}
								else
								{
									break;
								}
							}while(true);
							
							do
							{
								printf("\n\t Masukkan Saldo \t\t: "); scanf("%lf", &N[indeks].saldo);
								if(N[indeks].saldo < 100000)
								{
									printf("\n\t\t [!] Minimal Input Saldo Rp 100.000");
								}
								else
								{
									break;
								}
							}while(true);
							
							printf("\n\t\t [!] Update Data Berhasil")
						}
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 4:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							hapusRekening (N, indeks);
							printf("\n\t\t [!] Berhasil Menghapus Data Nasabah");
						}	
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 5:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							if(cekKosongBarang (N, indeks) != -1)
							{
								subIndeks = cekKosongBarang (N, indeks);
								printf("\n\t\t Barang ke %d", subIndeks+1);
								do
								{
									printf("\n\t Masukkan Nama Barang \t: "); fflush(stdin); gets(N[indeks].B[subIndeks].nama);
									if(strlen(N[indeks].B[subIndeks].nama) == 0 || strcmp(N[indeks].B[subIndeks].nama, "-") == 0)
									{
										printf("\n\t\t Nama Tidak Boleh Kosong");
									}
									else
									{
										break;
									}
								}while(true);
								
								do
								{
									printf("\n\t Masukkan Berat Barang \t: "); scanf("%f", &N[indeks].B[subIndeks].berat);
									if(N[indeks].B[subIndeks].berat <= 0)
									{
										printf("\n\t\t Berat Tidak Boleh <= 0");
									}
									else
									{
										break;
									}
								}while(true);
								
								printf("\n\t\t [!] Input Berhasil");
							}
							else
							{
								printf("\n\t\t [!] Data Penuh");
							}
						}	
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 6:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							if(cekKosongBarang (N, indeks) != 0)
							{
								tampilDataSearch (N, indeks);
								printf("\n\n\t Masukkan Nama Barang : "); fflush(stdin); gets(barang);
								if(cariBarang (N, indeks, barang) != -1)
								{
									subIndeks = cariBarang (N, indeks, barang);
									hapusBarang (N, indeks, subIndeks);
									printf("\n\t\t [!] Berhasil Mengambil Barang");
								}
								else
								{
									printf("\n\t\t [!] Data tidak ditemukan");
								}
							}
							else
							{
								printf("\n\t\t [!] Data Kosong");
							}
						}
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 7:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							do
							{
								printf("\n\t\t Saldo Anda : Rp %.2lf", N[indeks].saldo);
								printf("\n\\t\t Masukkan Nominal yang ingin anda tarik : "); scanf("%lf", &tarik);
								if(tarik < 100000)
								{
									printf("\n\t\t [!] Tidak Bisa Mengambil Uang < Rp 100.000 \n");
								}
								else if(tarik > N[indeks].saldo)
								{
									printf("\n\t\t [!] Saldo Anda tidak mencukupi \n");
								}
								else
								{
									printf("\n\t\t Silakan Ambil Uang Anda ^-^");
									N[indeks].saldo = hitungTarikSaldo (N, indeks, tarik);
									printf("\n\t\t Sisa Saldo Anda : %.2lf", N[indeks].saldo);
									break;
								}
							}while(tarik < 100000 || tarik > N[indeks].saldo);	
						}
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 8:
				if(cekKosong(N) != 0)
				{
					printf("\n\t Masukan Nomor Rekening : "); scanf("%d", &noRek);
					printf("\n\t Masukan PIN : "); scanf("%d", &pin);
					if(cariRekening (N, noRek) != -1)
					{
						indeks = cariRekening (N, noRek);
						if(N[indeks].PIN != pin)
						{
							printf("\n\t\t [!] No. Rekening atau Pin Salah");
						}
						else
						{
							do
							{
								printf("\n\t\t Saldo Anda : Rp %.2lf", N[indeks].saldo);
								printf("\n\t\t Masukkan Nominal yang ingin Anda setor : "); scanf("%lf", &tarik);
								if(tarik < 100000)
								{
									printf("\n\t\t [!] Nominal Tidak Boleh < Rp 100.000");
								}
								else
								{
									N[indeks].saldo = hitungSetorSaldo (N, indeks, tarik);
									printf("\n\t\t Saldo Rekening Anda sekarang : Rp %.2lf", N[indeks].saldo);
									break;
								}
							}while(true);
						}
					}
					else
					{
						printf("\n\t\t [!] No. Rekening atau Pin Salah");
					}
				}
				else
				{
					printf("\n\t\t [!] Data Kosong");
				}
			break;
			
			case 0:
				printf("\n\t\t Cindy Valencia - 220711593 - A");
			break;
			
			default:
				printf("\n\t\t [!] Menu tidak tersedia");
			break;
		}getch();
		
	}while(menu != 0);
	return 0;
}

void initData (Nasabah N[])
{
	int i, j;
	for(i=0; i<5; i++)
	{
		strcpy(N[i].nama, "-");
		strcpy(N[i].telp, "-");
		strcpy(N[i].tanggal, "-");
		N[i].PIN = 0;
		N[i].noRek = 0;
		N[i].saldo = 0;
		for(j=0; j<3; j++)
		{
			N[i].B[j].berat = 0;
			strcpy(N[i].B[j].nama, "-");
		}
	}
}

int cekKosong (Nasabah N[])
{
	int i;
	for(i=0; i<5; i++)
	{
		if(N[i].noRek == 0)
		{
			return i;
		}
	}
	return -1;
}

int cariTelepon (Nasabah N[], string noTelp)
{
	int i;
	for(i=0; i<5; i++)
	{
		if(strcmp(N[i].telp, noTelp) == 0)
		{
			return i;
		}
	}
	return -1;
}

int cariRekening (Nasabah N[], int noRek)
{
	int i;
	for(i=0; i<5; i++)
	{
		if(N[i].noRek == noRek)
		{
			return i;
		}
	}
	return -1;
}

int angkaRandom (int max, int min)
{
	return rand() % (max - min+1) + min;
}

void tampilData (Nasabah N[])
{
	int i, j;
	for(i=0; i<5; i++)
	{
		if(N[i].noRek != 0)
		{
			printf("\n\t ======================================");
			printf("\n\t\t\t Nasabah %d", i+1);
			printf("\n\t ======================================");
			printf("\n\t Nasabah \t: %s", N[i].nama);
			printf("\n\t No. Telepon \t: %s", N[i].telp);
			printf("\n\t Tanggal Lahir \t: %s \n", N[i].tanggal);
			printf("\n\t Nomor Rekening : %d", N[i].noRek);
			printf("\n\t PIN \t\t: %d", N[i].PIN);
			printf("\n\t Saldo \t\t: Rp %.2lf", N[i].saldo);
			printf("\n");
			
			for(j=0; j<3; j++)
			{
				if(N[i].B[j].berat != 0)
				{
					printf("\n\t\t == [Barang Nasabah %d] ==", j+1);
					printf("\n\t\t Nama \t: %s", N[i].B[j].nama);
					printf("\n\t\t Berat \t: %.2f", N[i].B[j].berat);
				}	
			}
		}
	}
}

void tampilDataSearch (Nasabah N[], int indeks)
{
	int j;
	printf("\n\t ========== [Rekening Anda] ========== \n");
	printf("\n\t Nasabah \t: %s", N[indeks].nama);
	printf("\n\t No. Telepon \t: %s", N[indeks].telp);
	printf("\n\t Tanggal Lahir \t: %s \n", N[indeks].tanggal);
	printf("\n\t Nomor Rekening : %d", N[indeks].noRek);
	printf("\n\t PIN \t\t: %d", N[indeks].PIN);
	printf("\n\t Saldo \t\t: Rp %.2lf", N[indeks].saldo);
	
	for(j=0; j<3; j++)
	{
		if(N[indeks].B[j].berat != 0)
		{
			printf("\n\t\t == [Barang Nasabah %d] ==", j+1);
			printf("\n\t\t Nama \t: %s", N[indeks].B[j].nama);
			printf("\n\t\t Berat \t: %.2f", N[indeks].B[j].berat);
		}
	}
}

void hapusRekening (Nasabah N[], int indeks)
{
	int i, j;
	for(i=indeks; i<5; i++)
	{
		if(i<4)
		{
			N[i] = N[i+1];
		}
		else
		{
			strcpy(N[i].nama, "-");
			strcpy(N[i].tanggal, "-");
			strcpy(N[i].telp, "-");
			N[i].noRek = 0;
			N[i].PIN = 0;
			for(j=0; j<3; j++)
			{
				strcpy(N[i].B[j].nama, "-");
				N[i].B[j].berat = 0;
			}
		}
	}	
}

int cekKosongBarang (Nasabah N[], int indeks)
{
	int i;
	for(i=0; i<3; i++)
	{
		if(N[indeks].B[i].berat == 0)
		{
			return i;
		}
	}
	return -1;
}

int cariBarang (Nasabah N[], int indeks, string barang)
{
	int i;
	for(i=0; i<3; i++)
	{
		if(strcmp(N[indeks].B[i].nama, barang) == 0)
		{
			return i;
		}
	}
	return -1;
}

void hapusBarang (Nasabah N[], int indeks, int subIndeks)
{
	int i;
	for(i=subIndeks; i<3; i++)
	{
		if(i<2)
		{
			strcpy(N[indeks].B[i].nama, N[indeks].B[i+1].nama);
			N[indeks].B[i].berat = N[indeks].B[i+1].berat;
		}
		else
		{
			strcpy(N[indeks].B[i].nama, "-");
			N[indeks].B[i].berat = 0;
		}
	}	
}

double hitungTarikSaldo (Nasabah N[], int indeks, double tarik)
{
	return N[indeks].saldo - tarik;
}

double hitungSetorSaldo (Nasabah N[], int indeks, double tarik)
{
	return N[indeks].saldo + tarik;
}
