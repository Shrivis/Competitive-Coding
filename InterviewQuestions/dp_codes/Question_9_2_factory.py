MINI14 = '1.4GHz Mac Mini'

class AppleFactory:
    class MacMini14:
        def __init__(self) -> None:
            self.memory = 4
            self.hdd = 500
            self.gpu = 'Intel HD Graphics 5000'
        
        def __str__(self) -> str:
            info = (f'Model: {MINI14}',
                    f'Memory: {self.memory}GB',
                    f'Hard Disk: {self.hdd}GB',
                    f'Graphics Card: {self.gpu}')
            return '\n'.join(info)
        
    def build_computer(self, model):
        if (model == MINI14):
            return self.MacMini14()
        else:
            print(f'Cant build {model}')
if __name__ == '__main__':
    afac = AppleFactory()
    mac_mini = afac.build_computer(MINI14)
    print('Factory Method')
    print(mac_mini)
