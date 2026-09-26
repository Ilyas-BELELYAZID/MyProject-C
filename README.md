# Library Management System for ENSA-H

## A Thesis-Style Documentation

![C Language](https://img.shields.io/badge/Language-C-blue?logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-brightgreen)
![Architecture](https://img.shields.io/badge/Architecture-File--Based-orange)
![Status](https://img.shields.io/badge/Status-Completed-success)

---

## Abstract

This document presents a comprehensive Library Management System (LMS) developed for the National School of Applied Sciences of Al Hocaima (ENSA-H). The system addresses the institutional need for efficient library operations through a dual-interface architecture, designed specifically for two distinct user roles: students and library administrators. Implemented entirely in the C programming language with file-based persistence, the system demonstrates principles of modular design, data integrity, and role-based access control. The architecture incorporates structured data storage mechanisms using file I/O operations, providing a lightweight yet robust solution for managing library resources and user interactions without dependency on external database management systems.

---

## 1. Introduction

### 1.1 Context and Motivation

The ENSA-H library requires an integrated information system to automate and streamline its daily operations. The traditional manual management of library resources—including book inventory, student borrowing records, administrative operations, and policy enforcement—presents significant challenges in terms of efficiency, accuracy, and scalability.

### 1.2 Project Objectives

The primary objectives of this LMS are:

1. **Operational Efficiency:** Automate library workflows and reduce manual administrative overhead
2. **Data Management:** Maintain accurate, persistent records of books and transactions through file-based storage
3. **User Role Differentiation:** Provide specialized interfaces tailored to student and administrative needs
4. **Access Control:** Implement policy enforcement mechanisms through authentication and blacklist management
5. **Information Retrieval:** Enable efficient search, filtering, and reporting capabilities
6. **System Scalability:** Design a modular architecture supporting future extensions and enhancements

### 1.3 Scope

This document covers the design, implementation, and deployment of the Library Management System for ENSA-H, including architectural design, functional requirements, technical specifications, and usage guidelines.

---

## 2. System Architecture

### 2.1 Architectural Overview

The LMS employs a layered, file-based architecture with clear separation of concerns. The system comprises three primary layers:

```
┌────────────────────────────────────────────────────┐
│         Presentation Layer (User Interfaces)       │
├────────────────────────────────────────────────────┤
│    Student Portal    │    Administrator Dashboard  │
│   (Role: Student)    │    (Role: Administrator)   │
└──────────┬───────────┴──────────────┬──────────────┘
           │                          │
┌──────────▼──────────────────────────▼──────────────┐
│     Business Logic Layer (Core Operations)        │
├────────────────────────────────────────────────────┤
│  • Authentication & Authorization                 │
│  • Book Management Operations                     │
│  • Circulation & Borrowing Logic                  │
│  • Blacklist Management                           │
│  • Search & Filtering Operations                  │
└──────────┬─────────────────────────────────────────┘
           │
┌──────────▼─────────────────────────────────────────┐
│     Data Persistence Layer (File-Based Storage)   │
├────────────────────────────────────────────────────┤
│  eleve (Students)     │  livre (Books)             │
│  listeNoire (Blacklist) │  emprunter (Borrowing)  │
└────────────────────────────────────────────────────┘
```

### 2.2 Data Entity Relationship Model

The system manages four primary data entities with the following structure:

#### 2.2.1 Élève (Student Entity)

| Field | Type | Description |
|-------|------|-------------|
| CIN | Long | National Identification Number (Primary Key) |
| nom | String | Student surname |
| prenom | String | Student given name |
| email | String | Electronic mail address |
| adresse | String | Residential address |
| mot_de_passe | String | Encrypted password |

#### 2.2.2 Livre (Book Entity)

| Field | Type | Description |
|-------|------|-------------|
| id | Integer (Primary Key) | Unique book identifier |
| titre | String | Book title |
| auteur | String | Author name |
| editeur | String | Publishing house |
| date_publication | Date | Year of publication |
| quantite | Integer | Current stock quantity |
| prix | Decimal | Acquisition cost |

#### 2.2.3 Emprunter (Borrowing Transaction Entity)

| Field | Type | Description |
|-------|------|-------------|
| id | Integer (Primary Key) | Transaction identifier |
| CIN | Long | Student identification (Foreign Key) |
| id_livre | Integer | Book identification (Foreign Key) |
| prenom | String | Student given name (Denormalized) |
| date_debut | Date & Time | Borrowing commencement date |
| date_fin | Date & Time | Expected return date |
| statut | String | Transaction status (Active/Returned/Overdue) |

#### 2.2.4 ListeNoire (Blacklist Entity)

| Field | Type | Description |
|-------|------|-------------|
| CIN | Long | Student identification (Primary Key) |
| nom | String | Student surname |
| ebe_emprunteur | Date & Time | Blacklist entry timestamp |

---

## 3. Functional Requirements

### 3.1 Student Portal

The student interface provides the following capabilities:

#### 3.1.1 Authentication Module
- User registration with validation
- Secure login mechanism with credential verification
- Mandatory acceptance of library Terms and Conditions
- Session management

#### 3.1.2 Book Discovery and Management
- **Catalog Browsing:** Access comprehensive list of available books with complete metadata
- **Advanced Search:** Locate books by identifier
- **Availability Checking:** Real-time verification of book stock status
- **Borrowing Operations:** Submit requests to borrow available books
- **Transaction Tracking:** Monitor personal borrowing history and due dates

### 3.2 Administrator Dashboard

The administrator interface provides comprehensive management capabilities:

#### 3.2.1 Collection Management
- **Add Books:** Expand library inventory with new materials and metadata
- **Modify Records:** Update book information including title, author, quantity, and publication details
- **Remove Entries:** Delete obsolete, damaged, or unavailable materials from inventory
- **Inventory Oversight:** Monitor current stock levels and collection status

#### 3.2.2 Circulation Management
- **Borrow Processing:** Approve and record borrowing transactions
- **Return Processing:** Manage book check-ins and update inventory accordingly
- **Overdue Tracking:** Identify and monitor overdue items
- **Transaction History:** Maintain complete audit trail of all circulation activities

#### 3.2.3 User Access Control
- **Blacklist Administration:** Add students who violate institutional policies
- **Access Restoration:** Remove blacklist entries and reinstate privileges when appropriate
- **Violation Enforcement:** Prevent blacklisted users from borrowing materials
- **Compliance Monitoring:** Track policy violations and enforcement actions

#### 3.2.4 Reporting and Analytics
- **Borrowing Statistics:** Analyze circulation patterns and trends
- **Collection Utilization:** Determine popular materials and underutilized inventory
- **User Activity:** Monitor student borrowing behavior
- **Operational Metrics:** Generate reports for institutional decision-making

---

## 4. Technical Architecture

### 4.1 Technology Stack

| Component | Specification |
|-----------|---------------|
| **Programming Language** | C (ISO/IEC 9899:1999 or later) |
| **Data Persistence** | File-based I/O operations (text files) |
| **User Interface** | Terminal-based console application |
| **Data Format** | Structured text files with delimited fields |
| **Version Control** | Git and GitHub |
| **Compiler** | GCC or compatible C compiler |

### 4.2 File-Based Data Storage

Rather than employing a traditional relational database management system, the LMS implements file-based persistence through structured text files. Each data entity is stored in dedicated files:

```
data/
├── eleve.txt              # Student records
├── livre.txt              # Book inventory
├── emprunter.txt          # Borrowing transactions
└── listeNoire.txt         # Blacklist entries
```

**Data Storage Format:** Records are stored as text with pipe-delimited (|) field separators, enabling efficient parsing and manipulation while maintaining human readability for administrative review.

### 4.3 Modular Design Principles

The system architecture adheres to modular design principles:

- **Separation of Concerns:** Distinct modules for authentication, book management, circulation, and user administration
- **Reusability:** Common utility functions abstracted for use across modules
- **Maintainability:** Clear function interfaces and documentation
- **Extensibility:** Modular structure facilitates addition of new features

---

## 5. Project Structure

```
MyProject-C/
│
├── src/                          # Source code directory
│   ├── main.c                    # Application entry point
│   ├── auth.c                    # Authentication module
│   ├── student_portal.c          # Student interface implementation
│   ├── admin_dashboard.c         # Administrator interface implementation
│   ├── book_management.c         # Book CRUD operations
│   ├── borrowing.c               # Borrowing/return transaction handling
│   ├── blacklist.c               # Blacklist management
│   ├── search.c                  # Search and filtering operations
│   ├── file_io.c                 # File I/O utilities
│   └── utils.c                   # General utility functions
│
├── include/                      # Header files
│   ├── auth.h
│   ├── student_portal.h
│   ├── admin_dashboard.h
│   ├── book_management.h
│   ├── borrowing.h
│   ├── blacklist.h
│   ├── search.h
│   ├── file_io.h
│   └── utils.h
│
├── data/                         # Data persistence directory
│   ├── eleve.txt                 # Student records storage
│   ├── livre.txt                 # Book inventory storage
│   ├── emprunter.txt             # Borrowing transactions storage
│   └── listeNoire.txt            # Blacklist storage
│
├── Makefile                      # Build configuration
├── README.md                     # Project documentation
├── LICENSE                       # Project license
└── .gitignore                    # Git exclusion rules
```

---

## 6. Installation and Deployment

### 6.1 System Requirements

- **Operating System:** Linux, macOS, or Windows (with MinGW)
- **Compiler:** GCC 4.8 or higher (or compatible C compiler)
- **Build Tools:** Make (optional but recommended)
- **Storage:** Minimum 10 MB available disk space
- **Runtime Memory:** Minimum 64 MB RAM

### 6.2 Installation Procedure

#### 6.2.1 Clone the Repository

```bash
git clone https://github.com/Ilyas-BELELYAZID/MyProject-C.git
cd MyProject-C
```

#### 6.2.2 Prepare the Build Environment

Ensure data directory exists and is writable:

```bash
mkdir -p data
chmod 755 data
```

#### 6.2.3 Compile the Application

**Using Makefile (Recommended):**

```bash
make clean
make all
```

**Manual Compilation:**

```bash
gcc -I include/ -o library_manager \
    src/main.c src/auth.c src/student_portal.c \
    src/admin_dashboard.c src/book_management.c \
    src/borrowing.c src/blacklist.c src/search.c \
    src/file_io.c src/utils.c
```

#### 6.2.4 Initialize Data Files

Create initial data files (if not present):

```bash
./library_manager --init
```

This creates empty data files and sets up the initial system state.

#### 6.2.5 Run the Application

```bash
./library_manager
```

### 6.3 File-Based Data Initialization

The system automatically initializes file-based storage upon first execution. Initial data files contain:

- **eleve.txt:** Empty or sample student records
- **livre.txt:** Initial book inventory
- **emprunter.txt:** Empty borrowing transaction log
- **listeNoire.txt:** Empty blacklist

---

## 7. User Workflows

### 7.1 Student Workflow

```
START
  │
  ├─→ [Registration/Login]
  │      ├─→ Register new account
  │      └─→ Authenticate credentials
  │
  ├─→ [Accept Terms & Conditions]
  │      └─→ Acknowledge institutional policies
  │
  ├─→ [Main Menu]
  │      ├─→ [1] Browse Available Books
  │      │      └─→ View complete catalog
  │      │
  │      ├─→ [2] Search Books
  │      │      └─→ Locate by book ID
  │      │
  │      ├─→ [3] Borrow Book
  │      │      ├─→ Verify blacklist status
  │      │      ├─→ Check availability
  │      │      └─→ Create borrowing transaction
  │      │
  │      └─→ [4] View My Borrowing History
  │             └─→ Display active and past transactions
  │
  └─→ [Exit]
        └─→ Terminate session
```

### 7.2 Administrator Workflow

```
START
  │
  ├─→ [Administrator Login]
  │      └─→ Authenticate with admin credentials
  │
  ├─→ [Admin Dashboard]
  │      ├─→ [1] Book Management
  │      │      ├─→ Add new books
  │      │      ├─→ Modify book records
  │      │      ├─→ Remove books
  │      │      └─→ View inventory
  │      │
  │      ├─→ [2] Circulation Management
  │      │      ├─→ Process book returns
  │      │      ├─→ View active borrowings
  │      │      └─→ Identify overdue items
  │      │
  │      ├─→ [3] User Management
  │      │      ├─→ View student profiles
  │      │      ├─→ Manage blacklist
  │      │      └─→ Track user activity
  │      │
  │      ├─→ [4] Reports & Analytics
  │      │      ├─→ Borrowing statistics
  │      │      ├─→ Collection utilization
  │      │      └─→ Operational metrics
  │      │
  │      └─→ [5] Search
  │             └─→ Advanced search operations
  │
  └─→ [Exit]
        └─→ Logout and terminate session
```

---

## 8. Key Features and Capabilities

### 8.1 Authentication and Security

- **Credential Validation:** Verify username and password against stored records
- **Role-Based Access:** Enforce distinct permission levels for students and administrators
- **Session Management:** Maintain user context throughout session lifetime
- **Policy Enforcement:** Require explicit acceptance of Terms and Conditions

### 8.2 Book Inventory Management

- **CRUD Operations:** Complete Create, Read, Update, Delete functionality
- **Metadata Management:** Store and maintain comprehensive book information
- **Availability Tracking:** Real-time stock level management
- **Search Capabilities:** Efficient retrieval by multiple criteria

### 8.3 Borrowing and Circulation

- **Transaction Recording:** Comprehensive logging of all borrowing activities
- **Date Management:** Automatic tracking of borrowing and return dates
- **Status Monitoring:** Track borrowing state (active, returned, overdue)
- **History Maintenance:** Complete audit trail of circulation activities

### 8.4 Access Control and Compliance

- **Blacklist Enforcement:** Prevent unauthorized borrowing by restricted users
- **Policy Violations:** Track and manage policy breach incidents
- **Access Reinstatement:** Restore privileges when appropriate
- **Compliance Audit:** Maintain records for institutional oversight

---

## 9. Technical Specifications

### 9.1 File I/O Operations

All data persistence operations employ standard C file I/O functions:

- **fopen():** Open file streams for reading/writing
- **fwrite()/fprintf():** Write structured data to files
- **fread()/fgets():** Read and parse stored records
- **fclose():** Properly close file resources

### 9.2 Data Validation

The system implements validation mechanisms:

- **Input Sanitization:** Validate user input for format and content
- **Constraint Checking:** Enforce business logic constraints (e.g., positive quantities)
- **Referential Integrity:** Validate foreign key relationships during transactions
- **Error Handling:** Graceful handling of file I/O errors and data inconsistencies

### 9.3 Error Management

Comprehensive error handling includes:

- **File Operation Errors:** Handle read/write failures gracefully
- **Data Consistency:** Detect and report integrity violations
- **User Input Errors:** Validate and reject invalid user input
- **Recovery Procedures:** Implement fallback mechanisms for critical failures

---

## 10. Limitations and Considerations

### 10.1 Current Limitations

- **Concurrency:** File-based storage does not support concurrent access without synchronization mechanisms
- **Scalability:** Performance degrades with very large datasets
- **Data Querying:** Limited query capabilities compared to SQL databases
- **Security:** File-based storage provides minimal encryption capabilities

### 10.2 Design Considerations

- **File Locking:** Implement mechanisms to prevent concurrent modification
- **Performance Optimization:** Consider indexing strategies for large datasets
- **Data Backup:** Establish regular backup procedures for data files
- **Migration Path:** Plan for potential migration to database systems

---

## 11. Future Enhancements

Potential improvements and extensions include:

- [ ] **Database Migration:** Transition to SQL-based storage for improved scalability
- [ ] **Web Interface:** Develop web-based UI using modern web technologies
- [ ] **Mobile Application:** Create mobile app for student borrowing on-the-go
- [ ] **Email Notifications:** Implement notification system for overdue items
- [ ] **Advanced Analytics:** Develop comprehensive reporting and visualization dashboards
- [ ] **Barcode System:** Integrate barcode/QR scanning for efficient book handling
- [ ] **Multi-language Support:** Provide interface in multiple languages
- [ ] **Fine Management:** Implement system for tracking and collecting late fees

---

## 12. Conclusion

This Library Management System represents a comprehensive solution to the operational challenges facing the ENSA-H library. Through modular design, file-based persistence, and role-differentiated interfaces, the system provides an efficient, scalable platform for library management. The implementation in C demonstrates sound software engineering principles while maintaining accessibility and maintainability.

The system successfully addresses institutional requirements for automation, data integrity, and user accessibility, while providing a foundation for future enhancements and scalability improvements.

---

## 13. References and Resources

### 13.1 Documentation

- **ISO/IEC 9899:1999:** C Language Standard Specification
- **POSIX File I/O:** Standard C File Operations
- **Software Engineering Best Practices:** Modular design and architecture patterns

### 13.2 Tools and Technologies

- **GCC Compiler:** GNU Compiler Collection for C
- **Git:** Version control and collaboration platform
- **GitHub:** Repository hosting and project management

---

## 14. Appendices

### Appendix A: Build Instructions

**Compilation Commands:**

```bash
# Clean previous builds
make clean

# Full compilation
make all

# Compile with debugging symbols
make DEBUG=1

# Run application
make run
```

### Appendix B: File Format Specifications

**Data File Format (Pipe-Delimited):**

```
field1|field2|field3|...|fieldN
```

**Example - Students (eleve.txt):**
```
12345678|Dupont|Jean|jean.dupont@example.com|123 Rue Main|motdepasse123
```

**Example - Books (livre.txt):**
```
1|Introduction to Algorithms|Thomas H. Cormen|MIT Press|2009|5|45.99
```

---

## Contact and Support

For technical inquiries, bug reports, or feature requests, please:

- Open an issue on [GitHub Issues](https://github.com/Ilyas-BELELYAZID/MyProject-C/issues)
- Contact the development team through the repository

---

<div align="center">

**Library Management System for ENSA-H**

*A Comprehensive Solution for Institutional Library Operations*

Developed with precision and attention to academic excellence.

</div>