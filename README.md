# ⚽ FC Cakrawala - Sistem Manajemen Tim Sepak Bola (C++ + OOP + Factory Method)

Ini adalah program C++ simulasi sistem manajemen tim sepak bola **FC Cakrawala**, klub binaan Universitas Cakrawala. Program ini menampilkan penerapan konsep **Object-Oriented Programming (OOP)** lengkap dengan **polimorfisme**, **inheritance**, serta penerapan **Factory Method Design Pattern**.

<img width="3199" height="3840" alt="OOP_UAS2_SuciFransiscaSisiliaR_24120500008" src="https://github.com/user-attachments/assets/6577f852-3f6c-41d3-8b1b-3229fc42fd7f" />


## 🧠 Fitur Utama
- Membuat struktur tim sepak bola U-23 (FC Cakrawala Muda)
- Mengelola data:
  - Head Coach & Assistant Coach
  - 15 Pemain utama
- Menampilkan detail informasi tim secara terstruktur
- Mengimplementasikan Factory Method untuk menciptakan objek `Coach` dan `Player` melalui abstraksi `PersonFactory`

## 🏗️ Struktur Kelas
Person (abstract)
├── Coach
├── Player

PersonFactory (abstract)
├── CoachFactory
└── PlayerFactory

Club
└── Team
├── Coach* (head & assistant)
└── Player* (up to 15)


## 🛠️ Teknologi
- Bahasa: C++
- Paradigma: Object-Oriented Programming (OOP)
- Design Pattern: Factory Method

## ▶️ Cara Menjalankan

### Compile
```bash
g++ -o fccakrawala main.cpp
Jalankan
```

```bash
./fccakrawala
```

```bash
Contoh output:
Club: FC Cakrawala
Team: FC Cakrawala Muda
Head Coach - Name: Pak Budi, Age: 45
Assistant Coach - Name: Pak Andi, Age: 40
Players:
Player - Name: Player 1, Age: 21, Position: Midfielder
```

## 📁 Struktur File
.
├── main.cpp       # Source code utama
├── README.md      # Dokumentasi

📌 Catatan
Semua alokasi memori dilakukan dengan new, dan telah dikelola dengan delete di destructor untuk menghindari memory leak.

Kode ini modular dan mudah diperluas, misalnya untuk menambah Staff, Match, atau Schedule.

## 👩‍💻 Author
Suci Fransisca Sisilia
Mahasiswa Data Science | Universitas Cakrawala
