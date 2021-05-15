class RoundRobin:
    def __init__(self,arr,q):
        self.arr=arr
        self.q=q
    
    def waiting(self):
        t = 0
        while(True):
            f=True
            for i in range(len(self.arr)):
                if self.arr[i][4] > 0:
                    f=False
                    if self.arr[i][4] > self.q:
                        t+=self.q
                        self.arr[i][4] -= self.q
                    else:
                        t += self.arr[i][4]
                        self.arr[i][2] = t - self.arr[i][1]
                        self.arr[i][4] = 0
            
            if f==True:
                break
    
    def turnAround(self):
        for i in range(len(self.arr)):
            self.arr[i][3] = self.arr[i][1] + self.arr[i][2]
        
    def detail(self):
        self.waiting()
        self.turnAround()
        tot_wt =0 
        tot_turn =0
        print('Process || Bust || Waiting || Turn Around')
        for i in range(len(self.arr)):
            tot_wt += self.arr[i][2]
            tot_turn += self.arr[i][3]
            print(f'   {self.arr[i][0]}\t   {self.arr[i][1]}\t   {self.arr[i][2]}\t\t{self.arr[i][3]}')

        print(f'Average Waiting Time :{tot_wt/len(self.arr)}')
        print(f'Average Turn Around Time :{tot_turn/len(self.arr)}')
arr = []
n = int(input('Enter Number Of Process :'))
for i in range(n):
    a = []
    a.append(int(input('Enter Process:')))
    a.append(int(input('Enter Bust :')))
    a.append(0)
    a.append(0)
    a.append(a[1])
    arr.append(a.copy())
    a.clear()
q = int(input('Enter Quantum:'))
robin = RoundRobin(arr,q)
robin.detail()