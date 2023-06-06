class Computer:
    def __init__(self, serial_number) -> None:
        self.serial = serial_number
        self.memory = None
        self.hdd = None
        self.gpu = None

    def __str__(self) -> str:
        info = (f'Memory: {self.memory}GB',
                f'Hard Disk: {self.hdd}GB',
                f'Graphics Card: {self.gpu}')
        return '\n'.join(info)

class ComputerBuilder:
    def __init__(self) -> None:
        self.computer = Computer('Ag23385193')

    def configure_memory(self, amount):
        self.computer.memory = amount
    
    def configure_hdd(self, amount):
        self.computer.hdd  = amount

    def configure_gpu(self, gpu_model):
        self.computer.gpu = gpu_model

class HardwareEngineer:
    def __init__(self) -> None:
        self.builder = None

    def construct_computer(self, memory, hdd, gpu):
        self.builder = ComputerBuilder()
        [step for step in (self.builder.configure_memory(memory),
                           self.builder.configure_hdd(hdd),
                           self.builder.configure_gpu(gpu))]
    
    @property
    def computer(self):
        return self.builder.computer

def main():
    engineer = HardwareEngineer()
    engineer.construct_computer(hdd=500, memory=8, gpu='GeForce GTX 650 Ti')
    computer = engineer.computer
    print(computer)

if __name__ == '__main__':
    print('Builder Method')
    main()
