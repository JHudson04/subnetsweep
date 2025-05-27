# 🛰️ SubNetSweep

**SubNetSweep** is a lightweight, cross-platform C++ CLI tool that scans a local subnet to identify live hosts using ICMP ping.

Built for learning, diagnostics, and cyberpunk flair.

---

## 🚀 Features

- 🔍 Scans IP ranges (e.g., `192.168.1.1` to `192.168.1.254`)
- ✅ Detects online hosts via ICMP echo requests
- 💻 Cross-platform: Windows, Linux, and macOS
- ⚙️ Minimalist C++ with no external libraries
- 🧠 Great for C++ learners and beginner network diagnostics

---

## 🧱 How It Works

For each host in the specified subnet range:
1. Sends a single ping request
2. Waits briefly for a response
3. Prints status as **online** or **offline**

Uses `system()` to call native ping tools:
- Windows: `ping -n 1 -w 100`
- Linux/macOS: `ping -c 1 -W 1` or similar

---

## ⚙️ Requirements

- C++ compiler (`g++`, `clang++`, or MinGW)
- Terminal (Linux/macOS) or PowerShell (Windows)

---

## 🛠️ Compilation

### 🪟 On Windows (MinGW)
```powershell
g++ -o SubNetSweep.exe SubNetSweep.cpp
