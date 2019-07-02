package com.sunxy.sunbspatch;

public class BsDiffAndPatchUtils {

    static {
        System.loadLibrary("BsPatch");
    }

    public static native int diff(String oldApkFile, String newApkFile, String patchFile);

    public static native int patch(String oldApkFile, String newApkFile, String patchFile);

    public static native int test();
}
