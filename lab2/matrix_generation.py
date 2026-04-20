import numpy as np
import sys

size = 200
if(len(sys.argv) > 1):
    size = int(sys.argv[1])

matrix1 = np.random.randint(0, 10, (size,size)) 
np.savetxt('matrix1.txt', matrix1, fmt='%d', delimiter=' ')

matrix2 = np.random.randint(0, 10, (size,size)) 
np.savetxt('matrix2.txt', matrix2, fmt='%d', delimiter=' ')
