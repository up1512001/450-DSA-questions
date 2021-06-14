pageFaults = 0
pages = int(input("Enter Number of Pages : "))
rs = []
for i in range(pages):
    rs.append(int(input(f"Enter value of {i+1} : ")))
frame = int(input("Enter Frame Numbers : "))
temp = [-1]*frame
for i in range(pages):
    s = 0
    for j in range(frame):
        if rs[i] == temp[j]:
            s+=1
            pageFaults -= 1
    
    pageFaults += 1
    if pageFaults <= frame and s == 0:
        temp[i] = rs[i]
    elif s == 0:
        temp[(pageFaults-1)%frame] = rs[i]
    
    for j in range (frame):
        print(f'{temp[j]}\t',end=" ")
    print('\n',end="")
print(f'\nTotal page Faults : {pageFaults}')