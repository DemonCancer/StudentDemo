package com.example.test0524;

/**
 * Created by administrator on 2018-05-24.
 */

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.widget.Toast;

/**
 * Created by administrator on 2018-05-11.
 */

public class MyDatabaseHelper extends SQLiteOpenHelper {

    public static final String Create_Book="create table Book("
            +"id integer primary key autoincrement,"
            +"author text,"
            +"price real,"
            +"pages integer,"
            +"name text)";

    private Context myContext;

    public MyDatabaseHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
        myContext=context;  //获取当前的上下文对象
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(Create_Book);
        Toast.makeText(myContext, "数据库与表创建成功", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}

