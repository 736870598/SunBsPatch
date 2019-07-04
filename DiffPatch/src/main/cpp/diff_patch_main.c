
#include <jni.h>
#include "bzip2/bspatch.h"
#include "bzip2/bsdiff.h"


/*
 * Method:    diff
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL
Java_com_sunxy_diffpatch_BsDiffAndPatchUtils_diff(JNIEnv *env, jclass type, jstring oldPath_jstr,
                                                    jstring newPath_jstr, jstring patchPatch_jst) {

    int ret= -1;

    const char *oldPath = (*env) -> GetStringUTFChars(env, oldPath_jstr, NULL);
    const char *newPath = (*env) -> GetStringUTFChars(env, newPath_jstr, NULL);
    const char *patchPath = (*env) -> GetStringUTFChars(env, patchPatch_jst, NULL);

    int argc = 4;
    const char *argv[4];

    argv[0] = "SunBsPatch";
    argv[1] = oldPath;
    argv[2] = newPath;
    argv[3] = patchPath;

    //如果成功ret等于0
    ret = bsdiff_main(argc, argv);
    (*env) -> ReleaseStringUTFChars(env, oldPath_jstr, oldPath);
    (*env) -> ReleaseStringUTFChars(env, newPath_jstr, newPath);
    (*env) -> ReleaseStringUTFChars(env, patchPatch_jst, patchPath);
    return ret;

}


/*
 * Method:    patch
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL
    Java_com_sunxy_diffpatch_BsDiffAndPatchUtils_patch(JNIEnv *env, jclass type, jstring oldPath_jstr,
            jstring newPath_jstr, jstring patchPatch_jst) {

        int ret= -1;
//    LOGD(" jni patch begin");

        const char *oldPath = (*env) -> GetStringUTFChars(env, oldPath_jstr, NULL);
        const char *newPath = (*env) -> GetStringUTFChars(env, newPath_jstr, NULL);
        const char *patchPath = (*env) -> GetStringUTFChars(env, patchPatch_jst, NULL);

        int argc = 4;
        const char *argv[4];

    argv[0] = "SunBsPatch";
    argv[1] = oldPath;
    argv[2] = newPath;
    argv[3] = patchPath;

    //如果成功ret等于0
    ret = bspatch_main(argc,argv);
    (*env) -> ReleaseStringUTFChars(env, oldPath_jstr, oldPath);
    (*env) -> ReleaseStringUTFChars(env, newPath_jstr, newPath);
    (*env) -> ReleaseStringUTFChars(env, patchPatch_jst, patchPath);
    return ret;

}

JNIEXPORT jint JNICALL
Java_com_sunxy_sunbspatch_BsDiffAndPatchUtils_test(JNIEnv *env, jclass type) {

    return  123;

}
