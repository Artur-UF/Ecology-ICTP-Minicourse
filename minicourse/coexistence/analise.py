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
order = 6 
T = 15000000

rhoa = float(sys.argv[1])
sys = np.loadtxt(f'out_N_{N}_rhoa_{rhoa:.2f}_bi.dat', unpack=True)

sys = np.asarray(split(sys, -1))


numB = np.sum(sys, 1)
numA = N - numB 

plt.figure(layout='constrained')
plt.plot(numA, label='A')
plt.plot(numB, label='B')
plt.legend()
plt.xlabel(f't(10^{order})')
plt.ylabel(r'$N_{A,B}$')
plt.title(f'N = {N} '+r'$\mid \rho_{A} = $'+f'{rhoa:.2f}')
plt.ylim(0, N)
plt.savefig(f'N_{N}/nums_N_{N}_rhoa_{rhoa:.2f}_bi.png', dpi=400)
#plt.show()

