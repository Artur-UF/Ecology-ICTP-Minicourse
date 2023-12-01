import numpy as np
import matplotlib.pyplot as plt
import sys

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

N = 10000
order = 3 

sys = list()
for i, r in zip(range(9), np.arange(.1, 1., .1)):
    sys.append(np.loadtxt(f'N_{N}/out_N_{N}_rhoa_{r:.2f}_ga_0.dat', unpack=True))

for i in range(9):
    sys[i] = np.asarray(split(sys[i], -1))

numB = list()
numA = list()
for i in range(9):
    numB.append(np.sum(sys[i], 1))
    numA.append(N - numB[i])


plt.figure(layout='constrained')
for i, r in zip(range(9), np.arange(.1, 1., .1)):
    plt.plot(numA[i][:150], label=r'$\rho_{A} = $'+f'{r:.2f}')
plt.legend(loc='upper right')
plt.xlabel(f't(10^{order})')
plt.ylabel(r'$N_{A}$')
plt.title(f'N = {N} ')
plt.ylim(0, N)
plt.savefig(f'N_{N}/plot_N_{N}_ga_0.png', dpi=400)
#plt.show()

