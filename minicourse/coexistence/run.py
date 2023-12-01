import os
import sys
import numpy as np

rhoa = np.arange(.1, 1., .1)

for i in rhoa:
    print(f'rhoa = {i:.2f}', end='\r')
    os.system(f'./a.out {i:.2f}')
    #os.system(f'python3 analise.py {i:.2f}')
print()

