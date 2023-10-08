# Responsi-DasPro

1. Buka Rekening
Dapat diakses bila terdapat slot kosong pada array of record dari Nasabah.
Akan menginputkan seperti data nasabah serta error handlingnya.
Ada ketentuan agar tidak terjadinya penipuan maka nomor telepon nasabah harus
berbeda dari nomor telepon nasabah lainnya. Bank ini hanya bisa menampung 5 nasabah.
Ketentuan :
1. Nama harus ada isi dan tidak boleh kosong atau “-“ saja.
2. Nomor Telepon harus dirange 10 – 13 digit dan harus UNIK.
3. Tanggal Lahir tidak boleh kosong.
4. PIN harus 4 digit angka.
5. Nomor Rekening berupa 4 digit angka random yang akan di generate setelah
menginputkan 4 data diatas (Nama, No Telp, Tgl Lahir, PIN).
6. Saldo menggunakan tipe data float / double yang harus diisi minimal 100.000 ke
rekening nasabah.
7. Barang milik Nasabah akan diinputkan nasabah pada menu 5.

2. Info Rekening
Pada menu ini, akan menampilkan pilihan untuk menampilkan keseluruhan atau salah satu saja,
bila tidak terdapat minimal 1 rekening maka tidak dapat diakses.
Berikut tampilan menu untuk tampil rekening.
Menu 1: Menampilkan keseluruhan data 1 – 5 nasabah
Menu 2: akan diminta nomor rekening

4. Update Rekening
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan meminta
nomor rekening dan pin yang mau di edit, bila tidak ditemukan akan menunjukan
error handling. Bila ditemukan akan mengedit keseluruhan data dari rekening yang
ditemukan, kecuali nomor rekening, dan error handling tiap input tetap digunakan
seperti pada menu input.

5. Tutup Rekening
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan diminta
nomor rekening dan pin yang mau ditutup, bila tidak ditemukan akan memberikan
error handling.
(Bila sudah menutup rekening maka rekening tersebut akan hilang bila di
tampilkan lagi pada menu 2)

6. Input Barang
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan meminta
input nomor rekening dan pin yang mau diisi barangnya, bila tidak ditemukan berikan
error handling. Setiap nasabah dapat memiliki maksimal 3 barang.
Ketentuan :
1. Nama Barang Tidak boleh kosong atau “-“ saja.
2. Berat Barang tidak boleh <= 0.
(Bila sudah menambahkan barang akan muncul pada menu 2)

6. Ambil Barang
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan meminta
input nomor rekening dan pin yang mau diambil barangnya, bila tidak ditemukan berikan
error handling, bila ditemukan dan barang masih kosong akan diberikan error handling,
bila terdapat minimal 1 barang akan meminta inputan barang (case-sensitive) yang ingin
diambil, bila ditemukan akan langsung mengambil (hapus) barang dari nasabah tersebut.

7. Tarik Saldo
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan meminta
input nomor rekening dan pin yang mau ditarik saldonya, bila tidak ditemukan berikan
error handling, bila ditemukan akan meminta inputan saldo yang ingin ditarik.
Ketentuan :
1. Tidak dapat input melebihi saldo nasabah.
2. Tidak dapat input kurang dari 100.000.

8. Setor Tunai
Dapat diakses bila terdapat minimal 1 nasabah, pada menu ini akan meminta
input nomor rekening dan pin yang mau disetor saldonya, bila tidak ditemukan
berikan error handling, bila ditemukan akan meminta inputan saldo yang ingin disetor,
dengan ketentuan minimal setor 100.000.

0. Exit
Keluar dari BANK CENTRAL ATMA, berikan identitas saat keluar.
