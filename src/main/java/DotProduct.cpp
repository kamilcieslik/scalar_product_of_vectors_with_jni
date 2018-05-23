#include <jni.h>
#include <iostream>
#include "DotProduct.h"
#include <climits>
#include <cfloat>
using namespace std;

// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_DotProduct_sayHello(JNIEnv *env, jobject thisObj) {
	cout << "Hello World from C++!" << endl;
    return;
}

JNIEXPORT jdouble JNICALL Java_DotProduct_multi01(JNIEnv *env, jobject thisObj, jdoubleArray vectorA, jdoubleArray vectorB) {
    jclass dotProductClass = env->FindClass("DotProduct");

    jsize number_of_elements = env->GetArrayLength(vectorA);

    jdouble *jdoubleArrayA = env->GetDoubleArrayElements(vectorA, NULL);
    jdouble *jdoubleArrayB = env->GetDoubleArrayElements(vectorB, NULL);

    jdouble result = 0;
    for (int i = 0; i < number_of_elements; i++)
    {
        result += jdoubleArrayA[i] * jdoubleArrayB[i];
    }

    jmethodID setC;
    setC = env->GetMethodID(dotProductClass, "setC", "(D)V");
    env->CallVoidMethod(thisObj, setC, result);

    env->DeleteLocalRef(dotProductClass);
    env->DeleteLocalRef(thisObj);
    env->DeleteLocalRef(vectorA);
    env->DeleteLocalRef(vectorB);
    return result;
}

JNIEXPORT jdouble JNICALL Java_DotProduct_multi02(JNIEnv *env, jobject thisObj, jdoubleArray vectorA) {
    jclass dotProductClass = env->FindClass("DotProduct");

    jsize number_of_elements = env->GetArrayLength(vectorA);

    jdouble *jdoubleArrayA = env->GetDoubleArrayElements(vectorA, NULL);

    jmethodID getB;
    getB = env->GetMethodID(dotProductClass, "getB", "()[D");
    jdoubleArray vectorB = (jdoubleArray) env->CallObjectMethod(thisObj, getB);

    jdouble *jdoubleArrayB = env->GetDoubleArrayElements(vectorB, NULL);

    jdouble result = 0;
    for (int i = 0; i < number_of_elements; i++)
    {
        result += jdoubleArrayA[i] * jdoubleArrayB[i];
    }

    jmethodID setC;
    setC = env->GetMethodID(dotProductClass, "setC", "(D)V");
    env->CallVoidMethod(thisObj, setC, result);

    env->DeleteLocalRef(dotProductClass);
    env->DeleteLocalRef(thisObj);
    env->DeleteLocalRef(vectorA);
    env->DeleteLocalRef(vectorB);
    return result;
}

JNIEXPORT void JNICALL Java_DotProduct_multi03(JNIEnv *env, jobject thisObj) {
    jclass dotProductClass = env->FindClass("DotProduct");
    int number_of_elements;
    double vectorElement;

    cout << "Podaj liczbę elementów w wektorze: " << endl;
    cin >> number_of_elements;

    while (!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Podaj liczbę elementów w wektorze: " << endl;
        cin >> number_of_elements;
    }

    jdoubleArray vectorA, vectorB;
    vectorA = env->NewDoubleArray(number_of_elements);
    vectorB = env->NewDoubleArray(number_of_elements);

    jdouble fillVectorA[number_of_elements];
    for (int i = 0; i < number_of_elements; i++) {
        cout << "Podaj " << i + 1 << ". element wektora A: " << endl;
        cin >> vectorElement;

        while (!cin.good()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Podaj " << i + 1 << ". element wektora A: " << endl;
            cin >> vectorElement;
        }

        fillVectorA[i] = vectorElement;
    }

    env->SetDoubleArrayRegion(vectorA, 0, number_of_elements, fillVectorA);
    jmethodID setA;
    setA = env->GetMethodID(dotProductClass, "setA", "([D)V");
    env->CallVoidMethod(thisObj, setA, vectorA);

    jdouble fillVectorB[number_of_elements];
    for (int i = 0; i < number_of_elements; i++) {
        cout << "Podaj " << i + 1 << ". element wektora B: " << endl;
        cin >> vectorElement;

        while (!cin.good()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Podaj " << i + 1 << ". element wektora B: " << endl;
            cin >> vectorElement;
        }

        fillVectorB[i] = vectorElement;
    }

    env->SetDoubleArrayRegion(vectorB, 0, number_of_elements, fillVectorB);
    jmethodID setB;
    setB = env->GetMethodID(dotProductClass, "setB", "([D)V");
    env->CallVoidMethod(thisObj, setB, vectorB);

    jmethodID multi04;
    multi04 = env->GetMethodID(dotProductClass, "multi04", "()V");
    env->CallVoidMethod(thisObj, multi04);

    env->DeleteLocalRef(dotProductClass);
    env->DeleteLocalRef(thisObj);
    env->DeleteLocalRef(vectorA);
    env->DeleteLocalRef(vectorB);
    return;
}
