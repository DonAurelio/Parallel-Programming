public class Main {
	public static void main(String[] args) {
		Matrix a = new Matrix(10000,10000);
		Matrix b = new Matrix(10000,10000);
		a.initialize(1);
		b.initialize(1);

		MatrixMult matrixMult = new MatrixMult();
		Matrix c = matrixMult.multiply(a,b);
		

		System.out.print("Hello I'm main\n");	
	}
}