import numpy as np
import sys
import os

#rhoa = float(sys.argv[1])
#gb = float(sys.argv[1])

gb = np.linspace(.1, 1., 30)
rhoa = np.linspace(.1, 1., 30)


print('N = 500')
for g in gb:
    for r in rhoa:
        print(f'rhoa: {r:.4f} | gb: {g:.4f}', end='\r')
        os.system(f'./mid {r} {g}')
print()

