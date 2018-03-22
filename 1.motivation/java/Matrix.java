public class Matrix {
	// Variables declared as final them value can not
	// be modified 
	final int nRows;
	final int nColums;

	// Matrix cells  
	Cell [][] cells;

	Matrix(int rows, int cols) {
		this.nRows = rows;
		this.nColums = cols;
		this.cells = new Cell [rows][cols]; 
	}

	public void initialize(int value){
		for (int i = 0; i < nRows; ++i) {
			for (int j = 0; j < nColums; ++j) {
				this.cells[i][j].setValue(value);
			}
		}
	}

	public int getCellValue(int row, int col){
		return this.cells[row][col].getValue();
	}


}