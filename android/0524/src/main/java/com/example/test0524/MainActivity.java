package com.example.test0524;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final MyDatabaseHelper  dbHelper=new MyDatabaseHelper(this,"BookStore.db",null,1);
        // 自己的包名下/databases


        Button btnCreate=findViewById(R.id.btnCreate);
        btnCreate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dbHelper.getWritableDatabase();
            }
        });



        Button btnInsert=findViewById(R.id.btnInsert);
        btnInsert.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SQLiteDatabase db=dbHelper.getWritableDatabase();
                ContentValues values=new ContentValues();
                values.put("name","第一行Android代码");
                values.put("author","郭霖");
                values.put("pages",500);
                values.put("price",87.2);
                db.insert("Book",null,values);
                values.clear();

                values.put("name","Android程序设计与实践");
                values.put("author","青岛英谷教育");
                values.put("pages",200);
                values.put("price",37);
                db.insert("Book",null,values);
                values.clear();

                Toast.makeText(MainActivity.this, "插入完成", Toast.LENGTH_SHORT).show();

            }
        });


        Button btnQuery=findViewById(R.id.btnquery);
        btnQuery.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String  queryResult="";
                SQLiteDatabase db=dbHelper.getWritableDatabase();
                //查询结果放到Cursor
                Cursor cursor=db.query("Book",null,null,null,null,null,null);
                while (cursor.moveToNext()){
                    String name=cursor.getString(cursor.getColumnIndex("name"));
                    String author=cursor.getString(cursor.getColumnIndex("author"));
                    int pages=cursor.getInt(cursor.getColumnIndex("pages"));
                    double price=cursor.getDouble(cursor.getColumnIndex("price"));

                    queryResult=queryResult+name+"\t"+author+"\t"+pages+"\t"+price+"\n";
                }

                cursor.close();

                TextView tvmsg=findViewById(R.id.tvMsg);
                tvmsg.setText(queryResult);
            }
        });
    }
}
