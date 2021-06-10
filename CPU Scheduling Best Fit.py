class BestFit:
    def __init__(self,ps,bs) -> None:
        self.ps = ps
        self.bs = bs
    
    def firstFit(self):
        alloc = [-1]*(len(self.ps))

        for i in range(len(self.ps)):
            ind = -1
            for j in range(len(self.bs)):
                if self.bs[j] >= self.ps[i]:
                    if ind==-1:
                        ind = j
                    elif self.bs[ind] > self.bs[j]:
                        ind = j
            if ind != -1:
                alloc[i] = ind
                self.bs[ind] = self.bs[ind] - self.ps[i]
        
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

obj = BestFit(ps,bs)
obj.firstFit()
