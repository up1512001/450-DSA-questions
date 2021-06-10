class FirstFit:
    def __init__(self,ps,bs) -> None:
        self.ps = ps
        self.bs = bs
    
    def firstFit(self):
        alloc = [-1]*(len(self.ps))

        for i in range(len(self.ps)):
            for j in range(len(self.bs)):
                if self.bs[j] >= self.ps[i]:
                    alloc[i] = j
                    self.bs[j] -= self.ps[i]
                    break
        
        print('Process ID || Process Size || Block ID')
        for i in range(len(alloc)):
            print(f'  {i+1}\t\t{self.ps[i]}\t\t',end=" ")
            if alloc[i] != -1: 
                print(alloc[i]+1)
            else :
                print('Not Allocated')

n = int(input('Enter Total Process Number : '))
ps = []
for i in range(n):
    ps.append(int(input('Enter Process Size : ')))
n = int(input('Enter Total BLock Size :'))
bs = []
for i in range(n):
    bs.append(int(input('Enter Block Size : ')))

obj = FirstFit(ps,bs)
obj.firstFit()
