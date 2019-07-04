package com.sunxy.diffpatch;

public class BsDiffAndPatchUtils {

    static {
        System.loadLibrary("BsDiffPatch");
    }

    public static native int diff(String oldApkFile, String newApkFile, String patchFile);

    public static native int patch(String oldApkFile, String newApkFile, String patchFile);

}
