class DotProduct {
    static {
        Runtime.getRuntime().loadLibrary("dotproduct");
    }

    private double[] a;
    private double[] b;
    private double c;

    private native void sayHello();

    public double[] getA() {
        return this.a;
    }

    public void setA(double[] a) {
        this.a = a;
    }

    public double[] getB() {
        return b;
    }

    public void setB(double[] b) {
        this.b = b;
    }

    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }

    public native double multi01(double[] a, double[] b);

    public native double multi02(double[] a);

    public native void multi03();

    private void multi04() {
        double result = 0;
        for (int i = 0; i < a.length; i++) {
            result += a[i] * b[i];
        }

        c = result;
    }

    public static void main(String[] args) {
        DotProduct dotProduct = new DotProduct();
        if (args.length > 0) {
            if ((args.length - 1) % 2 == 1) {
                System.out.println("Nieparzysta ilość elementów wektorów.");
                System.exit(1);
            }

            int number_of_elements = (args.length - 1) / 2;
            dotProduct.setA(new double[number_of_elements]);
            dotProduct.setB(new double[number_of_elements]);

            try {
                for (int i = 0; i < number_of_elements; i++) {
                    dotProduct.getA()[i] = Double.parseDouble(args[i + 1]);
                    dotProduct.getB()[i] = Double.parseDouble(args[i + number_of_elements + 1]);
                }
            } catch (NumberFormatException e) {
                System.out.println("Niepoprawny format co najmniej jednego elementu wektorów.");
                System.exit(2);
            }

            if (args[0].equals("T"))
                System.out.println("Wynik (multi01): " + dotProduct.multi01(dotProduct.getA(), dotProduct.getB()));
            else
                System.out.println("Wynik (multi02): " + dotProduct.multi02(dotProduct.getA()));
        } else {
            dotProduct.multi03();
            System.out.println("Wynik (multi03): " + dotProduct.getC());
        }
    }
}