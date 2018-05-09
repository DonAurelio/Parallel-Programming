# -*- coding: utf-8 -*-

"""Object oriented matrix multiplication classes

This module consider a set of classes to perform 
the matrix multiply operation using the object 
oriented approach. 
"""

class Cell:
    

    def __init__(self,value=None):
        """A cell of the matrix.

        Args:
            value (int): The current cell value.
        """

        #: int: The current cell value.
        self._value = value

    def get_value(self):
        """Return the value of the cell."""
        return self._value

    def set_value(self,value):
        """Sets cell value."""
        self._value = value

class Matrix:

    def __init__(self,rows,cols,value=0):
        """A matrix."""


        #: int: Matrix number of rows.
        self._rows = rows
        #: int: Matrix number of cols.
        self._cols = cols
        #: list of list: Matrix cells.
        self._cells = [[Cell(value) for i in range(cols)] for j in range(rows)]


    @property
    def rows(self):
        return self._rows

    @property
    def cols(self):
        return self._cols

    def get_cell_value(self,row,col):
        """Return the value of a cell given its location."""
        cell = self._cells[row][col]
        value = cell.get_value()

        return value

    def set_cell_value(self,row,col,value):
        """Change the value of a cell given its location."""
        cell = self._cells[row][col]
        cell.set_value(value)


class Math:
    """Covers operations between matrices."""

    def multyply(self,a,b):
        """Performs the matrix multiply.


        Args:
            a (Matrix): First matrix.
            b (Matrix): Second matrix.

        Returns: 
            A new Matrix as a result of the multiplication.
        """
        c = Matrix(a.rows,b.cols,1)
        for i in range(a.rows):
            for j in range(a.cols):
                for j in range(a.cols):
                    new_value = c.get_cell_value(i,j) + a.get_cell_value(i,j) * b.get_cell_value(i,j)
                    c.set_cell_value(i,j,new_value)
        return c


