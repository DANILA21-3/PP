#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace chrono;

struct multiplyresult{
    vector<vector<int>> matrix;
    long long time;
};

vector<vector<int>> read_matrix(const string& name_matrix, 
                                    const int size_matrix) {
    vector<vector<int>> matrix(size_matrix, vector<int>(size_matrix));
    ifstream file(name_matrix);
    
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++) {
            file >> matrix[i][j];
        }
    }
    
    file.close();
    return matrix;  
}

void write_matrix_to_file(const vector<vector<int>>& matrix, 
                            const string& name_matrix,
                                const int size_matrix) {

    ofstream file(name_matrix);

    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++) {
            file << matrix[i][j];
            if (j < size_matrix - 1) {
                file << " ";  
            }
        }
        file << endl;  
    }
    
    file.close();
}


multiplyresult multiply_matrix(const vector<vector<int>>& Matrix1 , 
                                const vector<vector<int>>& Matrix2 ){
    int size = Matrix1.size();

    vector<vector<int>> result(size, vector<int>(size, 0));

    auto start = high_resolution_clock::now();

    for (int i = 0; i < size; i++) {   
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return {result, duration.count()};
}

int main(int argc, char* argv[]) {
    int size = 200;

    if (argc > 1){
        size = atoi(argv[1]);
    }

    vector<vector<int>> matrix1 = read_matrix("matrix1.txt", size);
    vector<vector<int>> matrix2 = read_matrix("matrix2.txt", size);

    multiplyresult result = multiply_matrix(matrix1, matrix2);
     
    write_matrix_to_file(result.matrix, "result_matrix.txt", size);
    cout << "Time: " << result.time << "ms" << endl;

    return 0;
}