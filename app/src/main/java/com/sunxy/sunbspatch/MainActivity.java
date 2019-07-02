package com.sunxy.sunbspatch;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private String storePath = Environment.getExternalStorageDirectory().getAbsolutePath();

    String oldApkFile = storePath + "/apk/appOld.apk";
    String newApkFile = storePath + "/apk/appNew.apk";
    String patchFile = storePath + "/apk/apk.patch";

    private String newPathFile = storePath + "/apk/apk_new1.patch";
    String newnewApkFile = storePath + "/apk/appNewNew.apk";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.diff_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        int result = BsDiffAndPatchUtils.diff(oldApkFile, newApkFile, newPathFile);
                        Log.v("sunxy", "diff result: " + result);
                    }
                }).start();
            }
        });

        findViewById(R.id.patch_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        int result = BsDiffAndPatchUtils.patch(oldApkFile, newnewApkFile, newPathFile);
                        Log.v("sunxy", "patch result: " + result);
                    }
                }).start();
            }
        });
    }
}
