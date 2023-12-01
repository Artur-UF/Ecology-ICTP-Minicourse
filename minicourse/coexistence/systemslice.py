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


N = 1000
rhoa = 0.9


sys = np.loadtxt(f'N_{N}/vid_N_{N}_rhoa_{rhoa:.2f}.dat', unpack=True)

sys = np.asarray(split(sys, -1))

plt.imshow(sys)
plt.savefig(f'video/f1.png', dpi=400)




