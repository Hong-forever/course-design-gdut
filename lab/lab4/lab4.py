import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import re

N=246

f = open("net_info.txt")
countPinFlag = 0
nosPins = 0
for line in f:    
    #把最后的换行符去掉
    line = line.replace("\n","")
    r=re.match('net'+str(N)+'\t.+pins: (\d+)',line)
    if r:
        print(line)
        print(r.group(1))
        nosPins = int(r.group(1))
        pinCords = np.zeros([nosPins,2])   
        countPinFlag = 1
        continue
        
    if countPinFlag > 0 & countPinFlag<nosPins:
        [tmp, x,y] = re.split(',',line)
        pinCords[countPinFlag-1,0],pinCords[countPinFlag-1,1]=x,y
        #pinCords.append([x,y])
        countPinFlag = countPinFlag+1
        if countPinFlag-1==nosPins :
            break

print(pinCords.T)     


def drop_duplicates(pinCords):
    nos = len(pinCords)
    if nos<=1:
        return pinCords
    
    listToDrop = []
    for i in range(1,nos):
        for j in range(i):
            if all(pinCords[i]==pinCords[j]) & (i!=j):
                listToDrop.append(i)
                break
    print(listToDrop)
    if len(listToDrop) >0:
        listToDrop = list(set(listToDrop))
        listToDrop.sort()
        listToDrop.reverse()
        for ind in listToDrop:
            lst = [i for i in range(ind)] + [j+ind+1 for j in range(pinCords.shape[0]-ind-1)]
            pinCords = pinCords[lst,:]            
    return pinCords
                                 
pinCords = drop_duplicates(pinCords)

print(pinCords.T)    


Xcord = list(set(pinCords[:,0]))
Ycord = list(set(pinCords[:,1]))
Xmesh, Ymesh = np.meshgrid(Xcord,Ycord)



#plt.plot(Xmesh, Ymesh, marker='1', color='red', linestyle='')
#plt.show()

def CreateGraph(filename, Xmesh, Ymesh):
	G = nx.Graph()
  	# Adds egdes along with their weights to the graph 
	for i in range(n) :
		for j in range(n)[i:] :
			if wtMatrix[i][j] > 0 :
					G.add_edge(i, j, length = wtMatrix[i][j]) 
	return G

G=nx.grid_2d_graph(len(Xmesh),len(Ymesh))

nx.draw(G)
plt.show()
pass