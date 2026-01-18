# Information Security – Exam Cheat Sheet
## From IS-03: Vulnerabilities → Communication Encryption

---

# IS-03 – Vulnerabilities & Attacks

## 1. What Is a Vulnerability?
A **vulnerability** is a weakness in:
- software
- hardware
- configuration
- protocols
- human behavior

that can be **exploited by an attacker**.

### Common sources
- Programming errors (buffer overflow)
- Missing input validation
- Weak authentication
- Misconfiguration
- Outdated software

---

## 2. Buffer Overflow

### Definition
A buffer overflow occurs when:
- more data is written into memory than allocated
- adjacent memory is overwritten

### Why dangerous
- Overwrites return addresses
- Allows execution of injected shellcode
- Can lead to **root/admin access**

### Typical exploitation steps
1. Identify vulnerable program
2. Find buffer size
3. Overwrite instruction pointer
4. Inject shellcode
5. Gain control

### Mitigations
- Stack canaries
- ASLR
- DEP / NX bit
- Safe programming languages

---

## 3. Web Vulnerabilities

### Cross-Site Scripting (XSS)

#### Definition
Injection of malicious scripts into trusted websites, executed in the victim’s browser.

#### Root cause
- Missing input validation
- Missing output encoding

#### Types
- **Stored XSS**: script stored on server (most dangerous)
- **Reflected XSS**: script reflected via request
- **DOM-based XSS**: client-side JS manipulation

#### Impact
- Cookie theft
- Session hijacking
- Phishing
- User impersonation

#### Prevention
- Input validation
- Output encoding
- Content Security Policy (CSP)
- Avoid `innerHTML`

---

### SQL Injection (SQLi)

#### Definition
Injection of SQL code via user input.

#### Root cause
- Concatenating user input into SQL queries

#### Impact
- Authentication bypass
- Data theft
- Database manipulation

#### Prevention
- Prepared statements
- Parameterized queries
- Least-privilege DB accounts

---

# IS-05 – System Security & Malware

## 4. Malware Overview

### Malware = malicious software

#### Main types
- Virus
- Worm
- Trojan
- Rootkit
- Spyware
- Ransomware
- Botnet malware

---

## 5. Malware Types

### Virus
- Attaches to host file
- Needs execution
- Spreads by infecting files

### Worm
- Standalone
- Self-spreading via networks
- Fast propagation

### Trojan
- Disguised as legitimate software
- Installs malware silently

### Rootkit
- Hides malware
- Modifies OS/kernel
- System can no longer be trusted

---

## 6. Botnets
- Network of infected machines
- Controlled via C&C
- Used for:
  - DDoS
  - Spam
  - Credential theft

---

## 7. Targeted Attacks / APT
- Advanced Persistent Threats
- Long-term, stealthy
- Often state-sponsored
- Use zero-days

---

# IS-06 – Authentication

## 8. Authentication Basics

### Definition
Authentication = **Who are you?**

### Authentication factors
- Something you know (password)
- Something you have (token)
- Something you are (biometrics)

### MFA
- Combines ≥2 factors
- Best practice

---

## 9. Biometrics
- Physiological: fingerprint, face
- Behavioral: voice, typing

### Issues
- Cannot be changed
- Privacy risks
- Should not be used alone

---

## 10. Cryptographic Authentication

### Challenge–Response
- Server sends nonce
- Client proves secret knowledge

### Needham–Schroeder (Symmetric)
- Uses trusted Authentication Server
- Provides authentication + session key
- Uses nonces
- Basis of Kerberos

---

## 11. Diffie–Hellman

### Purpose
- Secure key exchange over insecure network

### Properties
- No trusted third party
- No authentication
- Vulnerable to MITM

---

# IS-07 – Authorization

## 12. Authorization Basics

### Definition
Authorization = **What are you allowed to do?**

### Depends on
- Authenticated identity
- Security policy

---

## 13. Access Control Models

### Access Control Matrix
- Subjects × Objects × Rights

### ACLs
- Stored with objects
- Object-centric

### Capabilities
- Stored with subjects
- Possession = permission

---

## 14. OS Authorization

### Unix/Linux
- ACLs in inode
- File descriptor acts as capability

### Windows
- Security Descriptors
- DACL, SACL
- Deny > Allow

---

## 15. Kerberos
- Authentication + Authorization
- Trusted KDC
- Ticket-based
- Single Sign-On

---

# IS-08 – Communication Encryption

## 16. Why Encryption Is Needed
IP provides:
- ❌ No confidentiality
- ❌ No integrity
- ❌ No authentication

---

## 17. IPsec

### Layer
- Network layer

### Modes
- Transport
- Tunnel

### Protocols
- AH: integrity/authentication
- ESP: encryption (+ auth)

### Key Management
- IKE / IKEv2

### Use case
- VPNs

---

## 18. TLS

### Layer
- Transport layer

### Used by
- HTTPS
- Mail protocols

### Components
- Handshake
- Record
- Alert

### Secure versions
- TLS 1.2
- TLS 1.3 (recommended)

---

## 19. IPsec vs TLS

| Aspect | IPsec | TLS |
|----|----|----|
| Layer | Network | Transport |
| Scope | All traffic | Application traffic |
| Use | VPN | Web/apps |

---

# FINAL EXAM TAKEAWAYS

- Vulnerabilities enable attacks
- Input validation is critical
- Malware is the main attack vehicle
- Authentication ≠ Authorization
- Encryption ≠ Trust
- Protocol design matters
- MFA + modern crypto is best practice
