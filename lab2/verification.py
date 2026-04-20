import numpy as np

matrix1 = np.loadtxt('matrix1.txt')
matrix2 = np.loadtxt('matrix2.txt')

result = np.dot(matrix1, matrix2)

test_matrix = np.loadtxt('result_matrix.txt')

if np.array_equal(result, test_matrix):
    print("Верификация пройдена успешно!")
else:
    print("Верификация не пройдена!")