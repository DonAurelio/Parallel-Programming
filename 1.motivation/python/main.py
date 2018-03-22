from matrix import Matrix
from matrix import Math


if __name__ == '__main__':
    Rows = 300
    Cols = 300

    A = Matrix(Rows,Cols)
    B = Matrix(Rows,Cols)

    math = Math()
    C = math.multyply(A,B)