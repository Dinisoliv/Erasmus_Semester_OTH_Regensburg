# Information Security – Exam Cheat Sheet

---

# IS-03 – Vulnerabilities & Attacks

## 1. Vulnerabilities
A vulnerability is a weakness in:
- Software
- Hardware
- Configuration
- Protocols
- Human behavior

That can be exploited to violate:
- Confidentiality
- Integrity
- Availability

---

## 2. Buffer Overflow

### Definition
Occurs when more data is written to a buffer than allocated.

### Impact
- Overwrite return addresses
- Execute injected shellcode
- Gain root/admin privileges

### Typical Exploitation
1. Find vulnerable program
2. Determine buffer size
3. Overwrite instruction pointer
4. Inject shellcode
5. Gain control

### Mitigations
- Stack canaries
- ASLR
- DEP / NX
- Safe languages

---

## 3. Web Vulnerabilities

### Cross-Site Scripting (XSS)
- Cause: missing input validation / output encoding
- Types:
  - Stored
  - Reflected
  - DOM-based
- Impact:
  - Cookie theft
  - Session hijacking
- Prevention:
  - Output encoding
  - CSP
  - Avoid `innerHTML`

### SQL Injection
- Cause: user input concatenated into SQL queries
- Impact:
  - Auth bypass
  - Data theft
- Prevention:
  - Prepared statements
  - Parameterized queries

---

# IS-04 – Encryption

## Encryption Goals
- Confidentiality
- Integrity
- Authentication
- Non-repudiation

---

## Symmetric Encryption
- Same key for encrypt/decrypt
- Fast
- Key distribution problem
- Example: AES
- Secure modes: CBC, GCM
- Insecure: ECB

---

## Asymmetric Encryption
- Public key encrypts
- Private key decrypts
- Solves key distribution
- Slower than symmetric
- Example: RSA, ECC

---

## Hybrid Encryption
- Asymmetric → key exchange
- Symmetric → data encryption
- Used in TLS, HTTPS, VPNs

---

## Diffie–Hellman
- Secure key agreement
- No key transmitted
- No authentication → MITM possible

---

## Certificates (PKI)
- Bind identity to public key
- Signed by CA
- Trust depends on CA
- Used in HTTPS


# IS-05 – System Security & Malware

## 11. Malware

### Types
- Virus
- Worm
- Trojan
- Rootkit
- Ransomware
- Spyware

### Rootkits
- Hide malware
- Modify kernel or system tools
- System cannot be trusted after infection

---

## 12. Botnets
- Infected machines controlled remotely
- Used for:
  - DDoS
  - Spam
  - Credential theft

---

## 13. APT (Advanced Persistent Threat)
- Long-term
- Stealthy
- Often state-sponsored
- Uses zero-days

---

# IS-06 – Authentication

## 14. Authentication Basics

### Definition
Authentication = **Who are you?**

### Factors
- Knowledge
- Possession
- Biometrics

### MFA
- ≥ 2 factors
- Best practice

---

## 15. Cryptographic Authentication

### Challenge–Response
- Uses nonces
- Prevents replay attacks

### Needham–Schroeder (Symmetric)
- Uses trusted Authentication Server
- Distributes session keys
- Uses nonces
- Basis of Kerberos

---

## 16. Diffie–Hellman vs Needham–Schroeder

| Aspect | DH | NS |
|----|----|----|
| Key exchange | Yes | Yes |
| Authentication | No | Yes |
| Trusted server | No | Yes |

---

# IS-07 – Authorization

## 17. Authorization Basics

### Definition
Authorization = **What are you allowed to do?**

### Depends on
- Authenticated identity
- Security policy

---

## 18. Access Control Models

### Access Control Matrix
- Subjects × Objects × Rights

### ACLs
- Object-centric

### Capabilities
- Subject-centric
- Possession = permission

---

## 19. OS Authorization

### Unix/Linux
- Inode ACLs
- File descriptors as capabilities

### Windows
- Security Descriptors
- DACL / SACL
- Deny > Allow

---

## 20. Kerberos
- Centralized authentication & authorization
- Ticket-based
- Single Sign-On

---

# IS-08 – Communication Encryption

## 21. Why Communication Encryption Is Needed
IP provides:
- ❌ No confidentiality
- ❌ No integrity
- ❌ No authentication

---

## 22. IPsec

### Layer
- Network layer

### Modes
- Transport
- Tunnel

### Protocols
- AH: integrity/authentication
- ESP: encryption + authentication

### Key Management
- IKE / IKEv2

### Use
- VPNs

---

## 23. TLS

### Layer
- Transport layer

### Used by
- HTTPS
- Secure email

### Versions
- TLS 1.2 ✅
- TLS 1.3 ✅ (recommended)

---

# FINAL EXAM TAKEAWAYS

- Vulnerabilities enable attacks
- Encryption alone ≠ trust
- Certificates bind identity to keys
- DH exchanges keys, NS authenticates
- Authentication ≠ Authorization
- MFA + modern crypto is best practice
- IPsec secures networks, TLS secures applications
