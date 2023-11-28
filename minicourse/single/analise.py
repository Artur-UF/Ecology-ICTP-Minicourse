import numpy as np
import matplotlib.pyplot as plt

def split(array, flag):
    '''
    Faz a separação de um array numérico de acordo com uma flag numérica
    '''
    arrnd = list()
    a = list()
    for i in range(len(array)):
        if array[i] == flag and type(flag) == int:
            arrnd.append(a)
            a = list()
        else: a.append(array[i])
    arrnd.append(a)
    return arrnd[:-1]

N = 50

sys = np.loadtxt('out.dat', unpack=True)

sys = np.asarray(split(sys, -1))


numB = np.sum(sys, 1)
numA = N - numB 


plt.plot(numA)
plt.plot(numB)

plt.savefig('nums.png', dpi=400)
