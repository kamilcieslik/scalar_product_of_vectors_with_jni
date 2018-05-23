class DotProduct {
    static {
        System.loadLibrary("dotproduct"); // Load native library at runtime
        // hello.dll (Windows) or libhello.so (Unixes)
    }

    private double[] a;
    private double[] b;
    private double c;

    public double[] getA() {
        return a;
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

    /*
    zakładamy, że po stronie kodu natywnego wyliczony zostanie iloczyn skalarny dwóch wektorów
    */
    public native Double multi01(Double[] a, Double[] b);

    /*
    zakładamy, że drugi atrybut będzie pobrany z obiektu przekazanego do metody natywnej
    */
    public native Double multi02(Double[] a);

    /*
    zakładamy, że po stronie natywnej utworzone zostanie okienko na atrybuty,
    a po ich wczytaniu i przepisaniu do a,b obliczony zostanie wynik.
    Wynik powinna wyliczać metoda Javy multi04
    (korzystająca z parametrów a,b i wpisująca wynik do c).
    */
    public native void multi03();

    private void multi04() {
        // mnoży a i b, wynik wpisuje do c
    }

    public static void printDupa() {
        System.out.println("Dupsko");
    }

    // Declare a native method sayHello() that receives nothing and returns void
    private native void sayHello();

    // Test Driver
    public static void main(String[] args) {
        if (args.length==3){
            System.out.println("chujowo");
        }
        else if (args.length == 0) {
            new DotProduct().multi03();
            System.out.println("git");
        }
        else
            System.out.println("Podano niepoprawną ilość argumentów wejściowych.\n" +
                    "Program należy uruchomić z trzema parametrami lub bez parametrów.\n" +
                    "Opis parametrów wejściowych:\n" +
                    "\t* 1. argument - tryb działania\n" +
                    "\t\tT - okno do wprowadzania wektorów\n" +
                    "\t\tF - wprowadzenie wektorów przez argumenty wejściowe\n" +
                    "\t* 2. argument - wektor A\n" +
                    "\t* 3. argument - wektor B\n");
    }
}