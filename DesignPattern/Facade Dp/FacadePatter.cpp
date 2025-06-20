#include <iostream>
using namespace std;

class PowerSupply {
public:
    void providePower() {
        cout << "Power supply is providing power." << endl;
    }
};

class CoolingSystem {
public:
    void startFans() {
        cout << "Cooling system fans are started." << endl;
    }
};

class CPU{
public:
    void initialize() {
        cout << "CPU is initialized." << endl;
    }
};

class Memory {
public:
    void selfTest() {
        cout << "Memory self-test is completed." << endl;
    }
};
class HardDrive {
public:
    void spinUp() {
        cout << "Hard drive is spinning up." << endl;
    }
};


class OperatingSystem {
public:
    void load() {
        cout << "Operating system is loading into memory" << endl;
    }
};
class BIOS{
    public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: booting cpu and memory checks...." << endl;
        cpu.initialize();
        memory.selfTest();
        cout << "BIOS: boot sequence completed." << endl;
    }
};

//facade
class ComputerFacade{
private:
    PowerSupply powerSupply;
    CoolingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;
public:
    void startComputer() {
        cout << "Starting computer..." << endl;
        powerSupply.providePower();
        coolingSystem.startFans();
        bios.boot(cpu, memory);
        hardDrive.spinUp();
        os.load();
        cout << "Computer started successfully!" << endl;
    }
};
int main() {
    ComputerFacade computer;
    computer.startComputer();
    cout << "Computer is now ready to use." << endl;
    

    return 0;
}