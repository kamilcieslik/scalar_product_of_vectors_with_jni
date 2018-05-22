#include <jni.h>
#include <iostream>
#include "DotProduct.h"
using namespace std;

// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_DotProduct_sayHello(JNIEnv *env, jobject thisObj) {
    jclass hello_world_class = env->FindClass("DotProduct");

    jmethodID print_dupa_method;
    print_dupa_method = env->GetStaticMethodID(hello_world_class, "printDupa","()V");
    env->CallStaticIntMethod(hello_world_class, print_dupa_method);

	cout << "Hello World from C++!" << endl;
   return;
}