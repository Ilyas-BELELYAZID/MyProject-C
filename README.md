# 📚 Library Management System for ENSA-H

<div align="center">

![C Language](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Console App](https://img.shields.io/badge/Platform-Console%20Application-brightgreen)
![File Based](https://img.shields.io/badge/Persistence-File%20Storage-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

</div>

---

## 🌟 Project Overview

This project presents a complete and efficient **Library Management System** developed for the **ENSA-H library**. It is designed to automate and simplify the daily operations of a university library by managing books, students, borrowing transactions, and access restrictions.

The system is implemented in the **C programming language** and uses a **file-based persistence model** rather than a traditional database management system. This makes it a lightweight, portable, and practical solution for academic and small-scale institutional environments.

The application is organized around two primary user profiles:

- 👨‍🎓 **Student**: authentication, book search, availability consultation, and borrowing management.
- 🛠️ **Administrator**: inventory management, returns, statistics, and blacklist administration.

---

## 🎯 Objectives

The system aims to:

- ✅ streamline library operations;
- ✅ provide a clear separation between student and administrator roles;
- ✅ maintain persistent records using text files;
- ✅ optimize book search and management;
- ✅ ensure secure borrowing and return tracking;
- ✅ enforce library policy through blacklist management;
- ✅ provide a modular and maintainable software architecture.

---

## 🏗️ Architecture

The architecture follows a modular, three-layer design:

```text
┌──────────────────────────────────────────────────────────────┐
│                    Presentation Layer                        │
│  Student Interface               Administrator Interface      │
└──────────────────────────────┬───────────────────────────────┘
                               │
                               ▼
┌──────────────────────────────────────────────────────────────┐
│                    Business Logic Layer                       │
│  Authentication  │  Book Management  │  Borrowing          │
│  Search          │  Validation       │  Blacklist Mgmt     │
└──────────────────────────────┬───────────────────────────────┘
                               │
                               ▼
┌──────────────────────────────────────────────────────────────┐
│                  File-Based Persistence Layer                 │
│  eleve.txt  │  livre.txt  │  emprunter.txt  │  listeNoire.txt │
└──────────────────────────────────────────────────────────────┘
```

### 📂 Core Entities

#### 1) Élève (Student)

| Field | Type | Description |
|------|------|-------------|
| CIN | String | Student identity number |
| nom | String | Last name |
| prenom | String | First name |
| email | String | Email address |
| adresse | String | Address |
| mot_de_passe | String | Password |

#### 2) Livre (Book)

| Field | Type | Description |
|------|------|-------------|
| id | Integer | Unique book ID |
| titre | String | Book title |
| auteur | String | Author |
| editeur | String | Publisher |
| date_publication | Date | Publication date |
| quantite | Integer | Available quantity |
| prix | Decimal | Price |

#### 3) Emprunter (Borrowing)

| Field | Type | Description |
|------|------|-------------|
| id | Integer | Borrowing ID |
| CIN | String | Student ID |
| id_livre | Integer | Book ID |
| nom | String | Student last name |
| prenom | String | Student first name |
| date_debut | Date/Time | Borrowing start date |
| date_fin | Date/Time | Return date |
| adresse | String | Student address |
| statut | String | Borrowing status |

#### 4) ListeNoire (Blacklist)

| Field | Type | Description |
|------|------|-------------|
| CIN | String | Student ID |
| nom | String | Last name |
| prenom | String | First name |
| email | String | Email |
| adresse | String | Address |
| CNE | String | Student code |
| statut | String | Restriction status |

---

## 🧩 Functional Modules

### 👨‍🎓 Student Module

The student interface includes:

- 🔐 registration and login;
- 📜 acceptance of the terms and conditions;
- 🔎 search for books by identifier;
- 📚 consultation of available books;
- 📤 borrow request management;
- 🧾 tracking of borrowed items.

### 🛠️ Administrator Module

The administrator interface includes:

- ➕ adding books;
- ✏️ modifying records;
- ❌ deleting unavailable books;
- 🔄 managing returns;
- 📊 viewing statistics;
- 🔎 searching books efficiently;
- 🚫 blacklist management;
- 👥 controlling student access rights.

### 🚫 Blacklist Management

This module is essential for enforcing library policy. It allows administrators to:

- add students to the blacklist;
- remove students from the blacklist;
- prevent restricted students from borrowing books;
- maintain a clear record of violations and restrictions.

---

## 💻 Technical Stack

| Component | Technology |
|-----------|-----------|
| Programming Language | C |
| User Interface | Console-based GUI / terminal interface |
| Persistence | File-based text storage |
| Data Storage | `eleve.txt`, `livre.txt`, `emprunter.txt`, `listeNoire.txt` |
| Version Control | Git & GitHub |
| Build Tool | GCC / Makefile |

---

## 🗂️ Project Structure

```text
MyProject-C/
├── src/
│   ├── main.c
│   ├── auth.c
│   ├── student.c
│   ├── admin.c
│   ├── book.c
│   ├── borrow.c
│   ├── blacklist.c
│   ├── search.c
│   ├── file_manager.c
│   └── utils.c
│
├── include/
│   ├── auth.h
│   ├── student.h
│   ├── admin.h
│   ├── book.h
│   ├── borrow.h
│   ├── blacklist.h
│   ├── search.h
│   ├── file_manager.h
│   └── utils.h
│
├── data/
│   ├── eleve.txt
│   ├── livre.txt
│   ├── emprunter.txt
│   └── listeNoire.txt
│
├── Makefile
├── README.md
├── LICENSE
├── .gitignore
├── docs/
│   └── project_description.txt
└── screenshots/
    └── architecture_diagram.png
```

> The architecture is intentionally structured around file persistence, which matches the real implementation of this project.

---

## ⚙️ Installation and Setup

### Prerequisites

- 🖥️ GCC compiler or equivalent C compiler
- 💾 terminal access
- 📁 writable project directory
- 🧩 basic understanding of C source compilation

### Clone the Repository

```bash
git clone https://github.com/Ilyas-BELELYAZID/MyProject-C.git
cd MyProject-C
```

### Create Data Directory

```bash
mkdir -p data
```

### Compile the Project

Using GCC directly:

```bash
gcc -I include -o library_manager src/*.c
```

Using a Makefile (if available):

```bash
make
```

### Run the Application

```bash
./library_manager
```

### File-Based Persistence

This project does not rely on a database engine. Instead, it stores records in plain text files in the `data/` folder. This keeps the application lightweight and easy to understand.

---

## 📊 Main Workflow

### Student Workflow

```text
Start
  ├── Register / Login
  ├── Accept Terms & Conditions
  ├── Browse books
  ├── Search books by ID
  ├── Borrow available books
  └── View borrowing status
```

### Administrator Workflow

```text
Start
  ├── Login as admin
  ├── Add / modify / remove books
  ├── Process returns
  ├── View library statistics
  ├── Search books
  ├── Manage blacklist
  └── Monitor circulation
```

---

## 🔐 Security and Validation

The system includes essential validation and control mechanisms:

- 🔑 login verification for registered users;
- 👤 role separation between students and administrators;
- 🚫 blacklist checking before borrowing approval;
- ✅ validation of book and user data before processing operations;
- 🧾 handling of file-based records with consistency checks.

---

## 📈 Advantages of the Current Design

- ✅ lightweight and portable;
- ✅ no external database required;
- ✅ easy to understand and maintain;
- ✅ suitable for educational and small institutional use;
- ✅ directly aligned with the project’s file-based architecture.

---

## ⚠️ Limitations

This architecture also has some constraints:

- 📉 less scalable than database-driven systems;
- ⏳ slower operation for very large datasets;
- 🔒 limited concurrency support;
- 🧠 no built-in advanced query engine.

These limitations can be addressed in future versions by migrating to a database-backed model.

---

## 🚀 Future Improvements

- [ ] migrate to a relational database;
- [ ] develop a graphical user interface;
- [ ] add advanced reporting dashboards;
- [ ] integrate email notifications;
- [ ] improve search performance and indexing;
- [ ] add barcode or QR-based book identification.

---

## 🧾 Conclusion

The **Library Management System for ENSA-H** is a practical and well-structured academic project that addresses the essential needs of a university library. By combining modular programming, file-based data persistence, and role-specific interfaces, the system creates an effective solution for managing books, users, borrowing records, and access restrictions.

It represents a solid example of how the **C programming language** can be used to build a functional and maintainable software system in a realistic institutional context.

---

## 📌 Repository

- GitHub: https://github.com/Ilyas-BELELYAZID/MyProject-C

---

<div align="center">

<strong>📚 Ensa-H Library Management System</strong>

<i>Efficient, practical, and designed for academic library operations.</i>

</div>
