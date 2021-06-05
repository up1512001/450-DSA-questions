class Priority:
    def __init__(self,arr):
        self.arr = arr

    def waiting(self):
        self.arr[0][3] = 0
        for i in range(1,len(self.arr)):
            self.arr[i][3] = self.arr[i-1][1] + self.arr[i-1][3]
        # return self.arr

    def turnAround(self):
        for i in range(len(self.arr)):
            self.arr[i][4] = self.arr[i][1] + self.arr[i][3]
        # return self.arr

    def priorityScheduling(self):
        # print(self.arr)
        self.arr = sorted(self.arr,key=lambda x:(x[2]),reverse=True)
        # print(self.arr)
        self.waiting()
        # print(self.arr)
        self.turnAround()
        # print(self.arr)
        tot_wt,tot_tat = 0,0
        print('Process || Bust || Priority || Waiting || Turn Around')
        for i in range(len(self.arr)):
            tot_wt += self.arr[i][3]
            tot_tat += self.arr[i][4]
            print(f'   {self.arr[i][0]}\t   {self.arr[i][1]}\t\t{self.arr[i][2]}\t  {self.arr[i][3]}\t  {self.arr[i][4]}')
        print(f'Average Waiting Time :->{tot_wt/len(self.arr)}')
        print(f'Average Turn Around Time :->{tot_tat/len(self.arr)}')

if __name__=='__main__':
    arr = []
    n = int(input('Enter Number Of Process:->'))
    for i in range(n):
        temp = []
        temp.append(int(input('Enter Process ID: ')))
        temp.append(int(input('Enter Bust : ')))
        temp.append(int(input('Enter Priority : ')))
        temp.append(0)
        temp.append(0)
        # print(temp)
        arr.append(temp.copy())
    
    # print(arr)
    obj = Priority(arr)
    obj.priorityScheduling()