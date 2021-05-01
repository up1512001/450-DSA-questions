class FCFS:
    def __init__(self,pro,bust):
        self.pro = pro
        self.bust = bust
        self.wt = []
        self.tat = []
    
    def wating(self,pro,bust,wt):
        self.wt.append(0)
        for i in range(1,len(pro)):
            self.wt.append(self.bust[i-1]+self.wt[i-1])
        return self.wt

    def turnaround(self,pro,bust,wt):
        for i in range(len(pro)):
            self.tat.append(self.wt[i]+self.bust[i])
        return self.tat

    def detail(self):
        self.wt=self.wating(self.pro, self.bust, self.wt)
        self.tat=self.turnaround(self.pro, self.bust, self.wt)
        tot_wt=0
        tot_tat=0
        for i in range(len(pro)):
            tot_wt+=self.wt[i]
            tot_tat+=self.tat[i]
        
        print(tot_wt, tot_tat,len(pro))
        print(f'Average Wating Time:{tot_wt/len(pro)}\nAverage Turn Around Time:{tot_tat/len(pro)}')

pro = []
bust = []
n = int(input("Enter Total Number Of Process:"))
print('Enter Process:')
for i in range(n):
    x=int(input(f"Enter {i+1}th Process:"))
    pro.append(x)
print('Enter Bust:')
for i in range(n):
    x = int(input(f'Enter {i+1}th Process Bust:'))
    bust.append(x)
a = FCFS(pro,bust)
a.detail()
