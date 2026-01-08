# Security Analysis of the Eightree ET21 Smart Socket
## 5-minute Presentation Notes

### Introduction
- Analyzed the Eightree ET21 smart socket.
- Goal: assess security from a network and communication perspective, in a controlled local network.

### Device Overview
- ET21 is a Wi-Fi smart plug controlled via the SmartLife / Tuya cloud.
- No local web interface or local authentication.
- Configurations and controls are cloud-mediated.

### Known Vulnerabilities
- No public CVEs were found for the Eightree ET21 specifically.
- The device appears to use common Tuya and ESP-based components.
- Multiple CVEs exist for related platforms and SDKs used in similar devices.
- These do not confirm vulnerabilities in the ET21 itself, but indicate potential inherited risk.
- Related devices in the same ecosystem have shown vulnerabilities affecting:
  - Cloud account authentication and authorization
  - MQTT communication handling and stability
  - Wi-Fi stack robustness on ESP-based hardware
  - Firmware update integrity and signature verification

### Network Exposure and Traffic Analysis
- Performed Nmap scan on the local network.
- Only one TCP port open: **6668**.
- No HTTP, HTTPS, SSH, or Telnet services exposed.
- Captured traffic using Wireshark during pairing and operation.
- Application traffic encrypted using **TLS 1.2**.
- Communication observed over:
  - HTTPS (TCP 443)
  - Secure MQTT (TCP 8883)
- No plaintext credentials or commands observed.

### Credential Handling
- Analyzed provisioning via EZ Mode, AP Mode, and Bluetooth.
- No WLAN credentials visible at the IP layer.
- Bluetooth provisioning used secure connections.
- No plaintext GATT payloads observed.
- Indicates credentials are encrypted before transmission.

### Attack Surface and MitM Considerations
- Local attack surface is small due to lack of local interfaces.
- Device relies heavily on cloud infrastructure.
- Based on TLS handshake observations, **MitM attacks**
  (e.g., timing-based attacks such as *Raccoon*) may be relevant
  if weak cryptographic parameters or mitigations exist.

### DoS Observation
- Tested a simple TCP SYN flood against port 6668.
- Device remained responsive and functional.
- Suggests basic resilience against simple DoS attempts.

### Firmware Updates and Transparency
- Firmware updates delivered exclusively via cloud-managed OTA
- No public information on firmware versions, changelogs, or update history
- Firmware images not publicly available
- Limits independent security verification and long-term risk assessment

### Conclusion
- ET21 provides acceptable baseline security for a consumer IoT device.
- Strengths: encrypted communication and minimal local exposure.
- Main limitation: strong dependence on vendor cloud and update practices.
- Limited firmware transparency restricts deeper analysis.
