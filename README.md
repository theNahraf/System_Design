# System_Design

🎯 **Objective** This repository serves as a comprehensive guide and code vault for **Software Architecture, Low-Level Design (LLD), and Object-Oriented Programming (OOP)** in C++. It contains structured learning materials, implementations of core design principles, and extensive machine-coding simulations of real-world scalable systems.

---

## 📁 Repository Structure

| Folder Name | Description |
| --- | --- |
| `Piller of Class/` | Foundational OOP concepts (Abstraction, Encapsulation). |
| `SOLID/` | Code examples demonstrating the violation and adherence to SOLID design principles (e.g., SRP, LSP). |
| `DesignPattern/` | Extensive implementations of standard Gang of Four (GoF) Design Patterns. |
| `Project/` | Hands-on, real-world Low-Level Design (LLD) machine-coding projects simulating popular applications. |
| `.vscode/` | Workspace configurations for local C++ development. |

---

## 🧱 Core Concepts Covered

### 1. Object-Oriented Programming (OOP)

* Abstraction
* Encapsulation
* Interfaces and Class Design

### 2. SOLID Principles

* Single Responsibility Principle (SRP)
* Liskov Substitution Principle (LSP)
* Method Argument & Return Type Rules

---

## 🧩 Design Patterns Implemented

Detailed C++ implementations categorized by their structural purpose:

* **Creational Patterns:** * Singleton (Thread-Safe Eager & Locking)
* Factory (Simple Factory, Factory Method, Abstract Factory)


* **Structural Patterns:** * Adapter
* Composite
* Decorator
* Facade
* Proxy (Protection, Remote, Virtual)


* **Behavioral Patterns:** * Chain of Responsibility (COR)
* Command
* Observer
* Strategy
* Template Method



---

## 🚀 Real-World LLD Projects

This repository features several full-scale machine coding projects that apply the above patterns and principles to design scalable systems:

* 🍔 **Food Delivery Application (Zomato Clone)**
* Features MVC-like structure with factories, managers, models, and robust payment strategies (Credit Card, UPI).


* 🎵 **Music Player Application (Spotify Clone)**
* Complex audio engine design supporting various external device APIs (Bluetooth, Wired, Headphones) and playback strategies.


* 📝 **Google Docs LLD**
* Showcases standard vs. highly optimized document editor design.


* 🛒 **Zepto Clone (Inventory Management)**
* Stock and inventory management system design.


* 💳 **Payment Gateway System**
* Routing and processing logic for payment transactions.


* 🔔 **Notification System**
* Scalable notification dispatcher utilizing Observer, Decorator, and Strategy patterns.


* 🎟️ **Discount Coupon System** & 💘 **Dating App**
* Additional LLD practice projects.



---

## 💻 Getting Started

### Prerequisites

* A C++ compiler (GCC, Clang, or MSVC) supporting C++11 or later.
* Make sure you have your build environment set up (the repo includes `.vscode` settings for ease of use).

### Installation & Execution

1. Clone the repository:
```bash
git clone https://github.com/thenahraf/System_Design.git

```


2. Navigate to the desired pattern or project directory:
```bash
cd System_Design/DesignPattern/Strategy\ Design\ Pattern/

```


3. Compile the C++ file:
```bash
g++ -o app StrategyDesignPattern.cpp

```


4. Run the executable:
```bash
./app

```
