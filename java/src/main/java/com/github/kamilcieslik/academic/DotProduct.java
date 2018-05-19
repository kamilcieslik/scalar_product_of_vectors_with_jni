package com.github.kamilcieslik.academic;

class DotProduct {
    public native void helloNative();

    public static void main(String[] args)
    {
        System.loadLibrary("scalar_product_of_vectors_with_jni_native");
        new DotProduct().helloNative();
    }
}