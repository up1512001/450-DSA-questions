class SJf:
    def __init__(self,arr):
        self.arr=arr

    def arrange(self):
        for i in range(len(self.arr)):
            for j in range(len(self.arr)-i-1):
                # print(j+1)
                if self.arr[j][1] > self.arr[j+1][1]:
                    for k in range(6):
                        temp = self.arr[j][k]
                        self.arr[j][k] = self.arr[j+1][k]
                        self.arr[j+1][k] = temp

        return self.arr

    def compute(self):
        self.arr = self.arrange()
        self.arr[0][3] = self.arr[0][1] + self.arr[0][2]
        self.arr[0][5] = self.arr[0][3] - self.arr[0][1]
        self.arr[0][4] = self.arr[0][5] - self.arr[0][2]
        val = 0
        for i in range(len(self.arr)):
            temp = arr[i-1][3]
            low = arr[i][2]
            for j in range(i,len(self.arr)):
                if temp>=self.arr[j][1] and low>=self.arr[j][2]:
                    low = self.arr[j][2]
                    val = j
            
            self.arr[val][3] = temp + self.arr[val][2]
            self.arr[val][5] = self.arr[val][3] - self.arr[val][1]
            self.arr[val][4] = self.arr[val][5] - self.arr[val][2]
            
            for j in range(6):
                x = self.arr[val][j]
                self.arr[val][j] = self.arr[i][j]
                self.arr[i][j] = x
            
        tot_wt=0
        tot_tat=0
        print('Process || Arrival || Bust || Waiting || Turn Around')
        for i in range(len(arr)):
            tot_tat+=self.arr[i][5]
            tot_wt+=self.arr[i][4]
            print(f'   {self.arr[i][0]}\t     {self.arr[i][1]} \t\t{self.arr[i][2]} \t {self.arr[i][4]}\t\t{self.arr[i][5]} ')

        print(f'Average Waiting Time:{tot_wt/len(self.arr)}')
        print(f'Average Turn Around Time:{tot_tat/len(self.arr)}')


arr = []
n = int(input('Enter Number Of Process:'))
for i in range(n):
    a = []
    a.append(int(input('Enter Process Number:')))
    a.append(int(input('Enter Arrival Time:')))
    a.append(int(input('Enter Bust Time:')))
    a.append(0)
    a.append(0)
    a.append(0)
    arr.append(a.copy())
    # print(arr)
    a.clear()
# print(len(arr))
# print(arr)
sjf = SJf(arr)
sjf.compute()
