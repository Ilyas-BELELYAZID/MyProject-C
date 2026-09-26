# Library Management System – ENSA-H

![C Language](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License](https://img.shields.io/badge/License-MIT-orange)
![Contributors](https://img.shields.io/badge/Contributors-Team-success)

---

## 📋 Executive Summary

A comprehensive **Library Management System (LMS)** designed and developed for the ENSA-H library. This institutional platform optimizes library operations through role-based user interfaces tailored for students and administrators. Built with the C programming language, the system integrates robust database management, responsive user interfaces, and scalable architecture to streamline book circulation, inventory management, and user access control.

---

## 🎯 Project Objectives

The system was developed to achieve the following goals:

- **Operational Efficiency:** Automate and streamline ENSA-H library management workflows
- **User Accessibility:** Provide intuitive interfaces for both student and administrative users
- **Data Integrity:** Maintain accurate, reliable records of books and borrowing transactions
- **Policy Enforcement:** Implement institutional access controls and compliance mechanisms
- **Statistical Insight:** Enable informed decision-making through library activity analytics

---

## 🏗️ Architecture Overview

### System Components

```
┌─────────────────────────────────────────────────────────┐
│         Library Management System (LMS)                 │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  ┌──────────────────┐         ┌──────────────────┐    │
│  │  Student Portal  │         │  Admin Dashboard │    │
│  ├──────────────────┤         ├──────────────────┤    │
│  │ • Authentication │         │ • Collection Mgmt│    │
│  │ • Book Search    │         │ • Circulation    │    │
│  │ • Book Borrow    │         │ • Statistics     │    │
│  │ • Availability   │         │ • Blacklist      │    │
│  └──────────────────┘         └──────────────────┘    │
│           │                            │               │
│           └────────────┬───────────────┘               │
│                        │                               │
│                  ┌─────────────┐                       │
│                  │  Database   │                       │
│                  │  Management │                       │
│                  └─────────────┘                       │
└─────────────────────────────────────────────────────────┘
```

---

## 👥 User Roles & Features

### 🟢 Student Profile

**Authentication & Compliance**
- Secure registration and login mechanism
- Mandatory acceptance of library Terms and Conditions
- Role-based access control

**Book Discovery & Management**
- Advanced search functionality (by book ID)
- Real-time availability checking
- Comprehensive catalog browsing
- Borrowing request management and tracking

**Key Features:**
| Feature | Description |
|---------|-------------|
| 📚 **Browse Catalog** | Access the complete list of available books |
| 🔎 **Search Books** | Locate books by ID or other identifiers |
| 📤 **Borrow Books** | Submit borrowing requests and track borrowed items |
| 📊 **View Status** | Monitor personal borrowing history and due dates |

---

### 🟡 Administrator Profile

**System Administration & Control**
- Exclusive administrator authentication
- Comprehensive dashboard for all operations
- Advanced reporting and analytics

**Collection Management**
- Add new books to the inventory
- Update and modify book records
- Remove outdated or unavailable materials
- Track book conditions and status

**Circulation Management**
- Process book returns
- Manage borrow/return transactions
- Monitor overdue items
- Generate circulation reports

**User & Access Control**
- Maintain the student blacklist
- Restrict access for policy violators
- Reinstate access when appropriate
- View user activity logs

**Analytics & Reporting**
- Generate library statistics and insights
- Analyze borrowing patterns
- Monitor collection usage
- Track operational metrics

**Key Features:**
| Feature | Description |
|---------|-------------|
| ➕ **Add Books** | Expand library collection with new materials |
| ✏️ **Modify Books** | Update book information and metadata |
| ❌ **Remove Books** | Delete unavailable or outdated entries |
| 🔄 **Process Returns** | Manage incoming book check-ins |
| 📊 **Statistics** | Analyze library activity and trends |
| 🚫 **Blacklist Mgmt** | Control student access privileges |

---

### 🔴 Blacklist Management System

The platform includes a dedicated blacklist module to enforce institutional policies:

- **Add Restrictions:** Blacklist students who violate library policies
- **Remove Restrictions:** Reinstate access when policy violations are resolved
- **Audit Trail:** Maintain records of all blacklist actions
- **Integration:** Seamlessly integrated with authentication system

---

## 💻 Technology Stack

| Component | Technology |
|-----------|-----------|
| **Language** | C |
| **Database** | Relational Database Management System |
| **UI Framework** | Custom C-based UI Libraries |
| **Version Control** | Git & GitHub |
| **Architecture** | Role-based, modular design |

### Technical Highlights

- ✅ **Modular Architecture:** Clean separation of concerns for maintainability
- ✅ **Database Integration:** Persistent data storage with integrity constraints
- ✅ **Responsive Interfaces:** Optimized user experience across student and admin portals
- ✅ **Security:** Role-based access control and authentication mechanisms
- ✅ **Scalability:** Designed to accommodate institutional growth

---

## 📂 Project Structure

```
MyProject-C/
├── src/                    # Source code
│   ├── student/           # Student portal implementation
│   ├── admin/             # Administrator dashboard
│   ├── auth/              # Authentication & authorization
│   ├── database/          # Database operations
│   └── utils/             # Utility functions
├── include/               # Header files
├── data/                  # Database files & schemas
├── docs/                  # Project documentation
└── README.md             # This file
```

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or equivalent C compiler)
- Standard C libraries
- Database engine (specify if applicable)
- Terminal/Command prompt access

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Ilyas-BELELYAZID/MyProject-C.git
   cd MyProject-C
   ```

2. **Compile the project:**
   ```bash
   gcc -o library_manager src/*.c -I include/
   ```

3. **Initialize the database:**
   ```bash
   # Database setup commands here
   ./library_manager --init-db
   ```

4. **Run the application:**
   ```bash
   ./library_manager
   ```

---

## 📊 System Workflow

```
User Access
    │
    ├─→ Unauthenticated User
    │       ├─→ Login/Registration
    │       └─→ Accept T&C
    │
    ├─→ Student User
    │       ├─→ View Catalog
    │       ├─→ Search Books
    │       └─→ Manage Borrowing
    │
    └─→ Administrator User
            ├─→ Collection Management
            ├─→ Circulation Control
            ├─→ User Management
            └─→ Generate Reports
```

---

## 📚 Core Functionalities

### Authentication Module
- Dual-role authentication (Student/Admin)
- Secure credential validation
- Session management
- Terms & Conditions enforcement

### Book Management Module
- CRUD operations for book inventory
- Book metadata management
- Availability tracking
- Search and filtering capabilities

### Circulation Module
- Borrow transaction processing
- Return management
- Overdue tracking
- Transaction history

### User Management Module
- Student profile management
- Blacklist administration
- Access control enforcement
- User activity logging

### Reporting Module
- Statistical analysis
- Borrowing trends
- Collection utilization metrics
- Custom report generation

---

## 👥 Team & Collaboration

This project was developed through collaborative teamwork, combining:

- **Programming Skills:** C language implementation and software design
- **Database Design:** Relational database modeling and SQL operations
- **UI/UX Development:** User interface design and implementation
- **Version Control:** Git workflow and GitHub collaboration
- **Project Management:** Coordinated development and delivery

---

## 🔍 Key Achievements

✨ **Complete institutional library management solution**

✨ **Dual-interface design** optimized for different user roles

✨ **Robust database architecture** ensuring data consistency

✨ **Comprehensive feature set** covering all library operations

✨ **Professional-grade implementation** following software engineering best practices

---

## 📋 Future Enhancements

Potential improvements and extensions:

- [ ] Web-based interface using modern frameworks
- [ ] Mobile application for student borrowing on-the-go
- [ ] Advanced analytics and data visualization dashboards
- [ ] Email notification system for overdue items
- [ ] Integration with institutional systems
- [ ] Barcode/QR code scanning for books
- [ ] Multi-language interface support

---

## 📖 Documentation

For detailed technical documentation, implementation details, and API references, please refer to the `/docs` directory.

---

## 📝 License

This project is made available under the MIT License. See LICENSE file for details.

---

## 🔗 Project Links

- **Repository:** [Ilyas-BELELYAZID/MyProject-C](https://github.com/Ilyas-BELELYAZID/MyProject-C)
- **Issues & Discussions:** [GitHub Issues](https://github.com/Ilyas-BELELYAZID/MyProject-C/issues)
- **Pull Requests:** [GitHub Pull Requests](https://github.com/Ilyas-BELELYAZID/MyProject-C/pulls)

---

## 👨‍💻 Contributing

Contributions to this project are welcome. To contribute:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/enhancement`)
3. Commit changes with descriptive messages
4. Push to your fork (`git push origin feature/enhancement`)
5. Open a Pull Request with a clear description of changes

---

## 📞 Support & Contact

For questions, suggestions, or support, please:

- Open an issue on [GitHub Issues](https://github.com/Ilyas-BELELYAZID/MyProject-C/issues)
- Contact the development team through the repository

---

<div align="center">

**Developed with ❤️ for ENSA-H Library Management**

*Optimizing library operations through technology and collaboration*

</div>